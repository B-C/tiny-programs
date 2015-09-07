CC=gcc
CFLAGS=-Wall -c
LDFLAGS=
EXEC=Huffman

all: $(EXEC)

Huffman: main.o algo.o
	$(CC) -o $(EXEC) algo.o main.o $(LDFLAGS)
	
	
algo.o: algo.c algo.h
	$(CC) -o algo.o -c algo.c $(CFLAGS)



main.o: main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

