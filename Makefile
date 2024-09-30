col: main.c
	gcc -o main main.c cache.c collatz.c

clean:
	rm main
	
time: col
	bash time.sh

cache: col
	bash cache.sh