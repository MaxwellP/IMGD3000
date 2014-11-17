//
// Saucer.cpp
//

#include "Saucer.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "EventOut.h"

Saucer::Saucer()
{
  LogManager &log_manager = LogManager::getInstance();
  WorldManager &world_manager = WorldManager::getInstance();
  ResourceManager &resource_manager = ResourceManager::getInstance();

  // setup "saucer" sprite
  Sprite *p_temp_sprite = resource_manager.getSprite("saucer");
  if (!p_temp_sprite)
  {
    log_manager.writeLog("Saucer::Saucer(): Warning! Sprite '%s' not found", 
			 "saucer");
  }
  else
  {
    setSprite(p_temp_sprite); // center and define bounding box
    setSpriteSlowdown(4);		
  }

  // set object type
  setType("Saucer");

  // set speed in horizontal direction
  setXVelocity(-0.5);

  // set starting location in the middle of the screen
  int world_horiz = world_manager.getBoundary().getHorizontal();
  int world_vert = world_manager.getBoundary().getVertical();
  Position pos(world_horiz/2, world_vert/2);
  setPosition(pos);
}

int Saucer::eventHandler(Event *p_e)
{

    if (p_e->getType() == OUT_EVENT)
    {
      out();
      return 1;
    }
    return 0;
}
void Saucer::out()
{
  if (getPosition().getX() >= 0)
    return;
}
void Saucer::moveToStart()
{
  
}