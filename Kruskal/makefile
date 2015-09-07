CC=gcc
CFLAGS=-Wall -c
LDFLAGS=-lm -L/usr/local/lib -lgraphique -L/usr/X11R6/lib -lX11
EXEC=Kruskal

all: $(EXEC)

Kruskal: kruskal.o in_out.o main.o tri.o affichage.o
	$(CC) -o $(EXEC) tri.o kruskal.o in_out.o main.o affichage.o $(LDFLAGS)
	
kruskal.o: kruskal.c kruskal.h general.h tri.h
	$(CC) -o kruskal.o -c kruskal.c $(CFLAGS)
	
tri.o: tri.c tri.h general.h
	$(CC) -o tri.o -c tri.c $(CFLAGS)

in_out.o: in_out.c in_out.h general.h
	$(CC) -o in_out.o -c in_out.c $(CFLAGS)
	
affichage.o: affichage.c affichage.h general.h
	$(CC) -o affichage.o -c affichage.c $(CFLAGS)

main.o: main.c in_out.h kruskal.h general.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

