FLAGS = -lm 

default: war

%.o: %.c cards.h
	gcc -w $(FLAGS) -c $<

war: war.o cards.o
	gcc -w $(FLAGS) cards.o $< -o $@

clean:
	-rm -f *.o
	-rm -f log.out
