wgrep: wgrep.o isStringInSubstring.o
	gcc -o wgrep isStringInSubstring.o wgrep.o -lm
wgrep.o: wgrep.c
	gcc -O -Wall -c wgrep.c
isStringInSubstring.o: isStringInSubstring.c
	gcc -O -Wall -c isStringInSubstring.c
clean:
	rm -f wgrep.o wgrep isStringInSubstring.o