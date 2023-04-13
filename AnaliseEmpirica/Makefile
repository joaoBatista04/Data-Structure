FLAGS = -Wall -Wno-unused-result

DEPS = vector.h
OBJ = vector.c buscaBinaria.c

%.o: %.c $(DEPS)
	gcc -g -c -o $@ $< $(FLAGS)

all: $(OBJ)
	gcc -g -o buscaBinaria $(OBJ) $(FLAGS)

clean:
	rm -f buscaBinaria *.o

run: 
	./busca > dadosBuscaBinaria.txt