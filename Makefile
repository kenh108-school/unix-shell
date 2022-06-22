unix_shell: main.o
	gcc main.o -o unix_shell

main.o: main.c
	gcc -c main.c

clean:
	rm *.o unix_shell