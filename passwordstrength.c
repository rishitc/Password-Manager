/*
This program processes the entered password and tells the user whether
it is valid or not.
It also tells the user how strong the entered password is.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//function to clear the stdin (standard input stream)
void flush()
{
  while(getchar()!='\n');
}

//here, we will take a string along with it's length as parameters
int main()
{
// the variable c will hold the password entered by the user
char c[100];

box('-');
line("Rules to follow for the password:", );

printf("ENTER the password you want to check for\n");
scanf("%[^\n]s",c);
flush();

int flag=0;
int alpc=0,non=0,noc=0,alpl=0,k;

//first we check that the length of the password is greater than 9 characters
if (strlen(c)>9)
{
  for (int i = 0;i < strlen(c);i++)
  {
    k = (int)c[i];
    if (isupper(k))
      ++alpc;
    else if (islower(k))
      ++alpl;
    else if (isdigit(k))
      non++;
    else if (k!=32)
      noc++;
    else if (k == 32)
      printf("ERROR: you can't have space in the password, please try again !");
  }
}
else
{
  flag=1;
}
if (flag==0 && alpc+alpl>0 && non>0 && noc>0)
{
  printf("-> Valid Password !\n");
}
else
{
  printf("-> Invalid Password !\n");
}
getchar();
system("./cproject.out");
}
