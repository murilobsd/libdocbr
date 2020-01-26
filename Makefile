docbr.o: docbr.c docbr.h
	cc -c docbr.c
example: docbr.o
	cc example.c docbr.o -o example
libdocbr.a: docbr.o
	ar -rcs libdocbr.a docbr.o
all: docbr.o libdocbr.a example
clean:
	rm -f *.o *.core example *.a
