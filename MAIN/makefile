all:
	make plug
	make clean
	make run

COMPILER = gcc

plug : vmslib.o fvmslib.o trablib.o cliente.o gerente.o main.o
	$(COMPILER)   vmslib.o fvmslib.o trablib.o cliente.o gerente.o main.o -o plug_n_play

main.o: main.c
	$(COMPILER) -c main.c

cliente.o: cliente.c cliente.h
	$(COMPILER) -c cliente.c

gerente.o: gerente.c gerente.h
	$(COMPILER) -c gerente.c

trablib.o: trablib.c trablib.h
	$(COMPILER) -c trablib.c

vmslib.o: vmslib.c vmslib.h
	$(COMPILER) -c vmslib.c

fvmslib.o: fvmslib.c fvmslib.h
	$(COMPILER) -c fvmslib.c



clean:
	rm vmslib.o
	rm fvmslib.o
	rm trablib.o
	rm cliente.o
	rm gerente.o
	rm main.o

run:
	./plug_n_play


