OBJS = main.cpp cell.cpp PathFinder.cpp
CC = g++
CFLAGS = -w -Wall
LFLAGS = -lSDL2
OBJNAME = program

all:
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(OBJNAME)
