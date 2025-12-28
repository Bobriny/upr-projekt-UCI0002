program: 
	gcc main.c tga.c kresleni.c prikazy.c -o program -lm
clean: 
	rm -f program
