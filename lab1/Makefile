main: main.c
	gcc main.c -std=c89 -Wall -pedantic -o main

test: main.c main_test.c
	gcc main.c main_test.c -std=c89 -Wall -pedantic -Dmain=_main -o test
