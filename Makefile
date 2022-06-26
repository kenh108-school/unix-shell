CC = gcc
CFLAGS = -g -Wall
DEPS = command.h input.h
OBJ = main.o input.o command.o
TARGET = unix_shell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.o $(TARGET)