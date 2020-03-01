# Name: Sally Chung
# Project: Lab 1: Time and Forking Children

EXECUTABLES=time-4-baby-and-me
SRC=time-4-baby-and-me.c
OBJ=time-4-baby-and-me.o

CC=gcc
CFLAGS=-g
all: $(EXECUTABLES)

$(EXECUTABLES): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -f $(EXECUTABLES) $(OBJ) *~
