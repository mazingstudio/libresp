TEST_TARGET := resp_test.o

test: libresp.so
	gcc -L$(PWD) -Wall -pedantic -o $(TEST_TARGET) resp_test.c -lresp && \
	LD_LIBRARY_PATH=$(PWD):$$LD_LIBRARY_PATH ./$(TEST_TARGET)

libresp.so:
	gcc -c -Wall -Werror -fpic resp.c
	gcc -shared -o libresp.so resp.o

clean:
	rm -f *.o
	rm -f *.so
