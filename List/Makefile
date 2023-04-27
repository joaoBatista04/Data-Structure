FLAGS = -Wall -Wno-unused-result

DEPS = list.h
OBJ = list.c main.c

%.o: %.c $(DEPS)
	gcc -g -c -o $@ $< $(FLAGS)

all: $(OBJ)
	gcc -g -o main $(OBJ) $(FLAGS)

clean:
	rm -f main *.o

run: 
	./main