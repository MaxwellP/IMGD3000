Maxwell Perlman
mhperlman@wpi.edu
10/1/2013

Developed on a windows 7 64bit operating system, coded in eclipse, and tested in cygwin for windows.

How to Compile:
-go to folder with all files in it
-run make
-execute ./test (in cygwin)

Drawing Issues/ Errors
-I am having an issue drawing/loading frames in my resource manager, however I was able to fix this somehow with the following line:
--lm.writeLog("TEXT %s\n",sprites[sprite_count-1]->getFrame(0).getString().c_str());