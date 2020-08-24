CC=gcc
CFLAGS=-I.

DayOne: DayOne.c
	$(CC) DayOne.c -lm -o ./Executables/DayOne.out

DayTwo: DayTwo.c
	$(CC) DayTwo.c -lm -o ./Executables/DayTwo.out

all: DayOne DayTwo