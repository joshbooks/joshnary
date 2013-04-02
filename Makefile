node : node.c main.c node.h
	gcc -o node node.c main.c
clean : 
	rm node *~
