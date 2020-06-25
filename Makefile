CC= gcc
CFLAGS= -std=c99 -Wall -ledit -lm
DEPS= parsing.c mpc.c

parsing: parsing.c mpc.c
	$(CC) $(CFLAGS) $(DEPS) -o parsing
