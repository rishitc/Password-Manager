seepassk.out : seepass.o ui.o rsa.o
	gcc seepass.o ui.o rsa.o -o seepassk.out -lm
seepass.o : seepass.c 
	gcc -c seepass.c -lm
ui.o : ui.c
	gcc -c ui.c -lm
rsa.o : rsa.c
	gcc rsa.c -c -lm
