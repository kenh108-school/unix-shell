CC = gcc
CFLAGS = -g -Wall
TARGET = unix_shell

all: $(TARGET)

$(TARGET): main.o
	$(CC) main.o -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	$(RM) *.o $(TARGET)