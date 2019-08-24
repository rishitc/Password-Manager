devpassk.out : devpass.o ui.o rsa.o 
	gcc devpass.o ui.o rsa.o -o devpassk.out -lm
devpass.o : devpass.c 
	gcc -c devpass.c -lm
ui.o : ui.c
	gcc -c ui.c -lm
rsa.o : rsa.c
	gcc rsa.c -c -lm
