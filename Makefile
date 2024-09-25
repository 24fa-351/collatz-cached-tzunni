col: collatz.c
	gcc -o collatz collatz.c

clean:
	rm collatz

test: col
	bash test.sh

time: col
	bash time.sh