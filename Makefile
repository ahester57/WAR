FLAGS = -lm

default: war

%.o: %.c
	gcc $(FLAGS) -c $<

war: war.o
	gcc $(FLAGS) $< -o $@

clean:
	-rm -f *.o
