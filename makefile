SRC:=$(wildcard *.c)
OBJ:=$(patsubst %.c, %.o, $(SRC))
inverted_index.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm -f *.exe  *.o
