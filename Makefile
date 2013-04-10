node : node.c main.c node.h
	gcc -lpthread -o node node.c main.c
clean : 
	rm node *~
