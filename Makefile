IN = main.c

CC = gcc

OUT = program

all: program
program:
	${CC} ${IN} -o ${OUT}