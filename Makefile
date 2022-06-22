CC = gcc
CFLAGS = -g -Wall
TARGET = unix_shell

all: $(TARGET)

$(TARGET): main.o input.o
	$(CC) main.o input.o -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

input.o: input.c input.h
	$(CC) $(CFLAGS) -c input.c

clean:
	$(RM) *.o $(TARGET)