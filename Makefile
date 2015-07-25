CC ?= gcc
TEST_TARGET := resp_test

test: libresp.so
	gcc -L$(PWD) -Wall -pedantic -o $(TEST_TARGET).o $(TEST_TARGET).c -lresp && \
	LD_LIBRARY_PATH=$(PWD):$$LD_LIBRARY_PATH ./$(TEST_TARGET).o

libresp.so:
	$(CC) -c -Wall -Werror -fpic resp.c
	$(CC) -shared -o libresp.so resp.o

clean:
	rm -f *.o
	rm -f *.so
