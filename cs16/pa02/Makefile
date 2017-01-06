#
# C++ Makefile
# 
# Compiles your *.cpp files and makes an executable to run.
#
# 0. cp Makefile-C or Makefile-CPP to Makefile
# 1. CHANGE YOUR EXE name!
# 2. Add libraries to CFLAGS, if necessary (e.g., math lib)
# 3. To build your program, type: make all
# 4. To clean object files ane executable, type: make clean
#

# C++ Compiler
# Comment in correct compiler
CC = g++

# CHANGE THIS Executable name (This is what you run) the file with main in it.
# Name of the file with the main in it.
EXE = sum

# This doesn't matter (C or C++)
# Add/Remove libraries here that you need.
# C/C++  System libs are in /usr/lib so just add -l<libname> e.g., -lm is math
# If using your own C library, -L/path/to/the/library -l<libname> 
#CFLAGS = -g -L/usr/X11R6/lib -lX11 -lGL -lglut -lGLU -lm -ljpeg -lz `libpng12-config --cflags --libs`
CFLAGS =

# C Files or C++ Files
SRC = $(wildcard *.cpp)

# C Object Files or C++ Object Files 
# (object files *.o are like .class files in Java)
OBJ = $(SRC:.cpp=.o)

all: $(EXE)
.PHONY: all

#compile sources to obj files
# C++
%.o: %.cpp
	$(CC) -g -c $^ -o $@

# compile obj files and link
$(EXE): $(OBJ)
	$(CC) *.o -g -o $(EXE) $(CFLAGS)

clean:
	@rm -f *~ *.o  $(EXE)
