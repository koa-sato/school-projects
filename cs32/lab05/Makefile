#Kekoa Sato, John Rehbein, 05/14/16

CC = g++                      # for the compiler we are going to use                                             
CFLAGS = -c -g -Wall               # options to pass to the compiler
DEPS = bankaccount.h
LDFLAGS =                          # for linker/loader options like -lm
SOURCES = buggy2.cpp bankaccount.cpp
OBJECTS = $(SOURCES:.cpp=.o)       # means copy .cpp names to .o names ;-)
EXECUTABLE = buggy2                 # for the executable program's name                                                

all: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE) : $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ 

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) *.cpp

clean: 
	rm $(EXECUTABLE) $(OBJECTS)
