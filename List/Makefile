FLAGS = -Wall -Wno-unused-result

DEPS = node.h list.h interator.h
OBJ = node.c list.c iterator.c main.c

%.o: %.c $(DEPS)
	gcc -g -c -o $@ $< $(FLAGS)

all: $(OBJ)
	gcc -g -o main $(OBJ) $(FLAGS)

clean:
	rm -f main *.o

run: 
	./main