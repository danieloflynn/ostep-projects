wcat: wcat.o
	gcc -o wcat wcat.o -lm
wcat.o: wcat.c
	gcc -O -Wall -c wcat.c
clean:
	rm -f wcat.o wcat