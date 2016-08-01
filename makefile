#makefile

PROGRAM = main.exe
OBJS = main.o direct.o rnd.o kpdir.o
CC = gcc

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS)

main.o: main.c
	$(CC) -c $<

direct.o: direct.c
	$(CC) -c $<

rnd.o: rnd.c
	$(CC) -c $<

kpdir.o: kpdir.c
	$(CC) -c $<

clean:
	rm -f $(PROGRAM) $(OBJS)

