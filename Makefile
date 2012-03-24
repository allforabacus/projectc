abacus: main.o menu.o
	gcc -o abacus main.o menu.o

main.o: src/main.c src/projectc.h
	gcc -c src/main.c

menu.o: src/menu.c src/projectc.h
	gcc -c src/menu.c

clean:
	rm -f *.o abacus

