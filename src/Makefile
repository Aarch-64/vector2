##
## Makefile
## vector2
##
## Created by Aarch-64 on 10/12/2022
## Copyright © 2022 Aarch-64. All rights reserved.
##

CC=clang
CLIBS=-lncurses -lvlc
CFLAGS=-Wall -Wextra -O2 -g -std=gnu99

OBJS= \
	files.o \
	game.o \
	main.o \
	menu.o \
	cli.o \
	version.o \
	vlc.o

default: all

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o ../vector $(OBJS) $(CLIBS)
	
clean:
	@rm -rf cli.o version.o files.o game.o main.o menu.o vlc.o ../vector
	
run: 
	@.././vector

install:

	-sudo cp ../vector /usr/bin/ -r
	-sudo cp ../misc/logo.png /usr/share/icons/ -r
	-sudo cp ../misc/vector.desktop /usr/share/applications/ -r
	@cp ../songs/ $(HOME)/.vector/resourses/ -r

uninstall:
	-sudo rm /usr/bin/vector -r
	-sudo rm /usr/share/icons/logo.png
	-sudo rm /usr/share/applications/vector.desktop
