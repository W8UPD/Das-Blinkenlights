CC = gcc

all:
	$(CC) -o morse morse_convert.c


clean:
	rm -f morse