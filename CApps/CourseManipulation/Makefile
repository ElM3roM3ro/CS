muapitest : lab13.o libuniversity.a
	gcc -std=c11 -g -Wall -Werror lab13.o -luniversity -L. -o muapitest

lab13.o : lab13.c university.h
	gcc -std=c11 -g -Wall -Werror -c lab13.c

clean:
	@rm -f *.o
	@rm -f muapitest
	@echo "All clean!"
