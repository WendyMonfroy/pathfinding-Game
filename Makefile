#compil
CC = gcc

CFLAGS =  -Wall -ansi -pedantic -Wextra -g -lm
LDFLAGS= -lX11
#liste fichiers objets
OBJ = main.o pile.o map.o path.o

all:path
#règle finale
path : $(OBJ)
	$(CC) $(OBJ)   -o path $(CFLAGS)
#règles pour chaque fichier
%.o: %.c
	$(CC)  -c  $< $(CFLAGS)
