CC= g++ 
PLATFORM= -DCYGWIN			# uncomment for cygwin
#PLATFORM= -DMACOS  		# uncomment for macos
LDFLAGS= -lncurses -lrt	-lm # uncomment linux/cygwin
#LDFLAGS= -lncurses 		# uncomment for macos
INCPATH= include			# path to engine includes
#ENG= lib/libdragonfly.a	# dragonfly engine
GAMESRC= 	Manager.cpp \
			LogManager.cpp \
			GameManager.cpp \
			Utility.cpp \
			Clock.cpp \
			Object.cpp \
			Position.cpp \
			ObjectList.cpp \
			ObjectListIterator.cpp \
			Event.cpp \
			EventStep.cpp \
			WorldManager.cpp \
			GraphicsManager.cpp \
			InputManager.cpp \
			EventMouse.cpp \
			EventKeyboard.cpp \
			EventCollision.cpp \
			EventOut.cpp \
			Frame.cpp \
			Sprite.cpp \
			ResourceManager.cpp \
			EventView.cpp \
			Box.cpp \
			Wall.cpp \
			Saucer.cpp
GAME= main.cpp
EXECUTABLE= test
OBJECTS= $(GAMESRC:.cpp=.o)

all: $(EXECUTABLE) makefile

$(EXECUTABLE): $(OBJECTS) $(GAME) $(GAMESRC) 
	$(CC) $(GAME) $(OBJECTS) $(ENG) -o $@ -I$(INCPATH) $(LDFLAGS)

.cpp.o: 
	$(CC) -c $(DEBUG) -I$(INCPATH) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) core dragonfly.log Makefile.bak *~

depend: 
	makedepend *.cpp 2> /dev/null

# DO NOT DELETE

Box.o: Box.h Position.h LogManager.h /usr/include/stdio.h
Box.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Box.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Box.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Box.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Box.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Box.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
Box.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Box.o: /usr/include/bits/wordsize.h Utility.h /usr/include/time.h
Box.o: /usr/include/machine/time.h Manager.h Event.h Object.h Sprite.h
Box.o: Frame.h /usr/include/string.h /usr/include/sys/string.h ObjectList.h
Box.o: ObjectListIterator.h
Clock.o: Clock.h /usr/include/time.h /usr/include/_ansi.h
Clock.o: /usr/include/newlib.h /usr/include/sys/config.h
Clock.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Clock.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Clock.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Clock.o: /usr/include/sys/lock.h /usr/include/machine/time.h
Clock.o: /usr/include/sys/types.h /usr/include/machine/types.h
Event.o: Event.h
EventCollision.o: EventCollision.h Event.h Object.h Position.h Sprite.h
EventCollision.o: Frame.h /usr/include/string.h /usr/include/_ansi.h
EventCollision.o: /usr/include/newlib.h /usr/include/sys/config.h
EventCollision.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
EventCollision.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
EventCollision.o: /usr/include/machine/_types.h
EventCollision.o: /usr/include/machine/_default_types.h
EventCollision.o: /usr/include/sys/lock.h /usr/include/sys/cdefs.h
EventCollision.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
EventCollision.o: /usr/include/sys/string.h Box.h
EventKeyboard.o: EventKeyboard.h Event.h
EventMouse.o: EventMouse.h Event.h
EventOut.o: EventOut.h Event.h
EventStep.o: EventStep.h Event.h
Frame.o: Frame.h
GameManager.o: GameManager.h /usr/include/time.h /usr/include/_ansi.h
GameManager.o: /usr/include/newlib.h /usr/include/sys/config.h
GameManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
GameManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
GameManager.o: /usr/include/machine/_types.h
GameManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
GameManager.o: /usr/include/machine/time.h /usr/include/sys/types.h
GameManager.o: /usr/include/machine/types.h /usr/include/unistd.h
GameManager.o: /usr/include/sys/unistd.h Manager.h Event.h Object.h
GameManager.o: Position.h Sprite.h Frame.h /usr/include/string.h
GameManager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
GameManager.o: /usr/include/bits/wordsize.h /usr/include/sys/string.h Box.h
GameManager.o: ObjectList.h ObjectListIterator.h GraphicsManager.h
GameManager.o: /usr/include/curses.h /usr/include/ncurses_dll.h
GameManager.o: /usr/include/stdio.h /usr/include/sys/stdio.h
GameManager.o: /usr/include/unctrl.h LogManager.h Utility.h InputManager.h
GameManager.o: WorldManager.h Clock.h EventStep.h EventMouse.h
GameManager.o: EventKeyboard.h
GraphicsManager.o: GraphicsManager.h /usr/include/curses.h
GraphicsManager.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
GraphicsManager.o: /usr/include/_ansi.h /usr/include/newlib.h
GraphicsManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
GraphicsManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
GraphicsManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
GraphicsManager.o: /usr/include/machine/_default_types.h
GraphicsManager.o: /usr/include/sys/lock.h /usr/include/sys/types.h
GraphicsManager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
GraphicsManager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
GraphicsManager.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
GraphicsManager.o: Manager.h Event.h Object.h Position.h Sprite.h Frame.h
GraphicsManager.o: /usr/include/string.h /usr/include/sys/string.h Box.h
GraphicsManager.o: ObjectList.h ObjectListIterator.h LogManager.h Utility.h
GraphicsManager.o: /usr/include/time.h /usr/include/machine/time.h
InputManager.o: InputManager.h Manager.h Event.h Object.h Position.h Sprite.h
InputManager.o: Frame.h /usr/include/string.h /usr/include/_ansi.h
InputManager.o: /usr/include/newlib.h /usr/include/sys/config.h
InputManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
InputManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
InputManager.o: /usr/include/machine/_types.h
InputManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
InputManager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
InputManager.o: /usr/include/bits/wordsize.h /usr/include/sys/string.h Box.h
InputManager.o: ObjectList.h ObjectListIterator.h GameManager.h
InputManager.o: /usr/include/time.h /usr/include/machine/time.h
InputManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
InputManager.o: /usr/include/unistd.h /usr/include/sys/unistd.h
InputManager.o: GraphicsManager.h /usr/include/curses.h
InputManager.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
InputManager.o: /usr/include/sys/stdio.h /usr/include/unctrl.h LogManager.h
InputManager.o: Utility.h WorldManager.h EventMouse.h EventKeyboard.h
LogManager.o: /usr/include/time.h /usr/include/_ansi.h /usr/include/newlib.h
LogManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
LogManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
LogManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
LogManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
LogManager.o: /usr/include/machine/time.h /usr/include/sys/types.h
LogManager.o: /usr/include/machine/types.h LogManager.h /usr/include/stdio.h
LogManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
LogManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Utility.h
LogManager.o: Position.h Box.h Manager.h Event.h Object.h Sprite.h Frame.h
LogManager.o: /usr/include/string.h /usr/include/sys/string.h ObjectList.h
LogManager.o: ObjectListIterator.h
main.o: GameManager.h /usr/include/time.h /usr/include/_ansi.h
main.o: /usr/include/newlib.h /usr/include/sys/config.h
main.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
main.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
main.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
main.o: /usr/include/sys/lock.h /usr/include/machine/time.h
main.o: /usr/include/sys/types.h /usr/include/machine/types.h
main.o: /usr/include/unistd.h /usr/include/sys/unistd.h Manager.h Event.h
main.o: Object.h Position.h Sprite.h Frame.h /usr/include/string.h
main.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
main.o: /usr/include/bits/wordsize.h /usr/include/sys/string.h Box.h
main.o: ObjectList.h ObjectListIterator.h GraphicsManager.h
main.o: /usr/include/curses.h /usr/include/ncurses_dll.h /usr/include/stdio.h
main.o: /usr/include/sys/stdio.h /usr/include/unctrl.h InputManager.h
main.o: LogManager.h Utility.h WorldManager.h ResourceManager.h Clock.h
main.o: Saucer.h Wall.h
Manager.o: Manager.h Event.h Object.h Position.h Sprite.h Frame.h
Manager.o: /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h
Manager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Manager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Manager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Manager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Manager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Manager.o: /usr/include/bits/wordsize.h /usr/include/sys/string.h Box.h
Manager.o: ObjectList.h ObjectListIterator.h LogManager.h
Manager.o: /usr/include/stdio.h /usr/include/sys/types.h
Manager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h Utility.h
Manager.o: /usr/include/time.h /usr/include/machine/time.h
Object.o: Object.h Position.h Event.h Sprite.h Frame.h /usr/include/string.h
Object.o: /usr/include/_ansi.h /usr/include/newlib.h
Object.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Object.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Object.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Object.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Object.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Object.o: /usr/include/bits/wordsize.h /usr/include/sys/string.h Box.h
Object.o: LogManager.h /usr/include/stdio.h /usr/include/sys/types.h
Object.o: /usr/include/machine/types.h /usr/include/sys/stdio.h Utility.h
Object.o: /usr/include/time.h /usr/include/machine/time.h Manager.h
Object.o: ObjectList.h ObjectListIterator.h GameManager.h
Object.o: /usr/include/unistd.h /usr/include/sys/unistd.h WorldManager.h
Object.o: InputManager.h GraphicsManager.h /usr/include/curses.h
Object.o: /usr/include/ncurses_dll.h /usr/include/unctrl.h
Object.o: /usr/include/math.h
ObjectList.o: ObjectList.h Object.h Position.h Event.h Sprite.h Frame.h
ObjectList.o: /usr/include/string.h /usr/include/_ansi.h
ObjectList.o: /usr/include/newlib.h /usr/include/sys/config.h
ObjectList.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
ObjectList.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
ObjectList.o: /usr/include/machine/_types.h
ObjectList.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
ObjectList.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
ObjectList.o: /usr/include/bits/wordsize.h /usr/include/sys/string.h Box.h
ObjectList.o: ObjectListIterator.h
ObjectListIterator.o: ObjectListIterator.h Object.h Position.h Event.h
ObjectListIterator.o: Sprite.h Frame.h /usr/include/string.h
ObjectListIterator.o: /usr/include/_ansi.h /usr/include/newlib.h
ObjectListIterator.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
ObjectListIterator.o: /usr/include/sys/features.h /usr/include/sys/reent.h
ObjectListIterator.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
ObjectListIterator.o: /usr/include/machine/_default_types.h
ObjectListIterator.o: /usr/include/sys/lock.h /usr/include/sys/cdefs.h
ObjectListIterator.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
ObjectListIterator.o: /usr/include/sys/string.h Box.h ObjectList.h
Position.o: Position.h
ResourceManager.o: ResourceManager.h Manager.h Event.h Object.h Position.h
ResourceManager.o: Sprite.h Frame.h /usr/include/string.h
ResourceManager.o: /usr/include/_ansi.h /usr/include/newlib.h
ResourceManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
ResourceManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
ResourceManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
ResourceManager.o: /usr/include/machine/_default_types.h
ResourceManager.o: /usr/include/sys/lock.h /usr/include/sys/cdefs.h
ResourceManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
ResourceManager.o: /usr/include/sys/string.h Box.h ObjectList.h
ResourceManager.o: ObjectListIterator.h LogManager.h /usr/include/stdio.h
ResourceManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
ResourceManager.o: /usr/include/sys/stdio.h Utility.h /usr/include/time.h
ResourceManager.o: /usr/include/machine/time.h /usr/include/stdlib.h
ResourceManager.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
Saucer.o: Saucer.h Object.h Position.h Event.h Sprite.h Frame.h
Saucer.o: /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h
Saucer.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Saucer.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Saucer.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Saucer.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Saucer.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Saucer.o: /usr/include/bits/wordsize.h /usr/include/sys/string.h Box.h
Saucer.o: LogManager.h /usr/include/stdio.h /usr/include/sys/types.h
Saucer.o: /usr/include/machine/types.h /usr/include/sys/stdio.h Utility.h
Saucer.o: /usr/include/time.h /usr/include/machine/time.h Manager.h
Saucer.o: ObjectList.h ObjectListIterator.h GraphicsManager.h
Saucer.o: /usr/include/curses.h /usr/include/ncurses_dll.h
Saucer.o: /usr/include/unctrl.h EventStep.h EventMouse.h EventKeyboard.h
Saucer.o: EventCollision.h WorldManager.h ResourceManager.h
Sprite.o: Sprite.h Frame.h /usr/include/string.h /usr/include/_ansi.h
Sprite.o: /usr/include/newlib.h /usr/include/sys/config.h
Sprite.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Sprite.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Sprite.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Sprite.o: /usr/include/sys/lock.h /usr/include/sys/cdefs.h
Sprite.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Sprite.o: /usr/include/sys/string.h GraphicsManager.h /usr/include/curses.h
Sprite.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
Sprite.o: /usr/include/sys/types.h /usr/include/machine/types.h
Sprite.o: /usr/include/sys/stdio.h /usr/include/unctrl.h Manager.h Event.h
Sprite.o: Object.h Position.h Box.h ObjectList.h ObjectListIterator.h
Sprite.o: LogManager.h Utility.h /usr/include/time.h
Sprite.o: /usr/include/machine/time.h
Utility.o: Utility.h /usr/include/stdio.h /usr/include/_ansi.h
Utility.o: /usr/include/newlib.h /usr/include/sys/config.h
Utility.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Utility.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Utility.o: /usr/include/machine/_types.h
Utility.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Utility.o: /usr/include/sys/types.h /usr/include/machine/types.h
Utility.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Utility.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Utility.o: /usr/include/time.h /usr/include/machine/time.h Position.h Box.h
Wall.o: Wall.h Object.h Position.h Event.h Sprite.h Frame.h
Wall.o: /usr/include/string.h /usr/include/_ansi.h /usr/include/newlib.h
Wall.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Wall.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Wall.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Wall.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Wall.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Wall.o: /usr/include/bits/wordsize.h /usr/include/sys/string.h Box.h
Wall.o: GraphicsManager.h /usr/include/curses.h /usr/include/ncurses_dll.h
Wall.o: /usr/include/stdio.h /usr/include/sys/types.h
Wall.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
Wall.o: /usr/include/unctrl.h Manager.h ObjectList.h ObjectListIterator.h
WorldManager.o: WorldManager.h Manager.h Event.h Object.h Position.h Sprite.h
WorldManager.o: Frame.h /usr/include/string.h /usr/include/_ansi.h
WorldManager.o: /usr/include/newlib.h /usr/include/sys/config.h
WorldManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
WorldManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
WorldManager.o: /usr/include/machine/_types.h
WorldManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
WorldManager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
WorldManager.o: /usr/include/bits/wordsize.h /usr/include/sys/string.h Box.h
WorldManager.o: ObjectList.h ObjectListIterator.h Utility.h
WorldManager.o: /usr/include/stdio.h /usr/include/sys/types.h
WorldManager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
WorldManager.o: /usr/include/time.h /usr/include/machine/time.h LogManager.h
WorldManager.o: EventCollision.h GraphicsManager.h /usr/include/curses.h
WorldManager.o: /usr/include/ncurses_dll.h /usr/include/unctrl.h EventOut.h
