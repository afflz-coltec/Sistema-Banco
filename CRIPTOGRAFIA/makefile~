all:
	make plug
	make clean
	make run

COMPILER = gcc

plug : vmslib.o fvmslib.o extra.o
	$(COMPILER)   vmslib.o fvmslib.o extra.o -o plug_n_play

extra.o: extra.c
	$(COMPILER) -c extra.c

vmslib.o: vmslib.c vmslib.h
	$(COMPILER) -c vmslib.c

fvmslib.o: fvmslib.c fvmslib.h
	$(COMPILER) -c fvmslib.c


clean:
	rm vmslib.o
	rm fvmslib.o
	rm extra.o

run:
	./plug_n_play


