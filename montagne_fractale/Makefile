CC=gcc
CFLAGS=-Wall -c
LDFLAGS=-Iglut -lglut -lGL -lGLU -lm
EXEC=Montagne

all: $(EXEC)

Montagne: main.o affichage.o decoupage.o lecture.o materiaux.o
	$(CC) -o $(EXEC) main.o decoupage.o affichage.o materiaux.o lecture.o $(LDFLAGS)

materiaux.o: materiaux.c materiaux.h general.h
	$(CC) -o materiaux.o -c materiaux.c $(CFLAGS)	

affichage.o: affichage.c affichage.h general.h
	$(CC) -o affichage.o -c affichage.c $(CFLAGS)	

decoupage.o: decoupage.c decoupage.h general.h
	$(CC) -o decoupage.o -c decoupage.c $(CFLAGS)	

lecture.o: lecture.c lecture.h general.h
	$(CC) -o lecture.o -c lecture.c $(CFLAGS)	

main.o: main.c general.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

