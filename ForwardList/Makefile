FLAGS = -Wall -Wno-unused-result

DEPS = forward_list.h
OBJ = forward_list.c main.c

%.o: %.c $(DEPS)
	gcc -g -c -o $@ $< $(FLAGS)

all: $(OBJ)
	gcc -g -o main $(OBJ) $(FLAGS)

clean:
	rm -f main *.o

run: 
	./main

git:
	@ git add .
	@ git commit -m "$(r)"
	