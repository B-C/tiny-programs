CC = gcc
CFLAGS = -I. -Wall -Werror -g -std=c99 -O2
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

clean::
	@rm -f $(TARGET) $(OBJ)
