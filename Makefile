all:
	gcc -Wall -pedantic -o resp_test resp.h resp.c resp_test.c

clean:
	rm -f resp_test
