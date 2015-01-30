all: game.o coise
	gcc game.o field.o -Wall -std=c99 -o ola 
	
coise:
	gcc -c -Wall -std=c99 field.c
