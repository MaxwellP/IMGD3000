//
// game.cpp
// 

#include <stdlib.h>		// for exit()

// Engine includes
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"

// Game includes
#include "Saucer.h"

// Function prototypes
void loadResources(void);
void populateWorld(void);

int main(int argc, char *argv[])
{
  LogManager &log_manager = LogManager::getInstance();

  // Start up Game Manager
  GameManager &game_manager = GameManager::getInstance();
  if (game_manager.startUp())
  {
    log_manager.writeLog("Error starting game manager!");
    game_manager.shutDown();
    exit(1);
  }

  // Load game resources
  loadResources();

  // Setup some objects
  populateWorld();

  // Run the game (this blocks until the game loop is over)
  game_manager.run();

  // Shut everything down
  game_manager.shutDown();
}

// load resources (sprites, here)
void loadResources(void)
{
  ResourceManager &resource_manager = ResourceManager::getInstance();
  resource_manager.loadSprite("sprites/saucer-spr.txt", "saucer");
}

// populate world with some objects
void populateWorld(void)
{
  // create a Saucer (note, it automatically registers with 
  // the game world in it's constructor)
  new Saucer;
}