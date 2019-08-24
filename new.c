#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include"maininterface.h"
#include"rsa.h"

//Clear the input buffer : stdin
void flush()
{
	while(getchar() != '\n');
}

//encrypt the given data
void dev_encrypt(netinfo*);

//dencrypt the given data
void dev_decrypt(netinfo*);

//
void numcpy(int *msg_int, int *en);


int main()
{
	while(1)
	{
		//store the option of the user in n
		int n;

		printf("ENTER\n1:For seeing one of your passwords\n2:For seeing all  your passwords\n0:For going back\n");
		scanf("%d",&n);
		flush(stdin);

		switch(n)
		{
			case 1:
			//we use {} to restrict the scope of the variables inside it, basically to prevent variable names from overlapping in the code inside the {} and outside it
			{
				/*
				username1 stores the entered username of the user
				pin1 stores the unique identification pin entered by user
				useo stores the use or website name entered by the user
				*/

				char username1[100], pin1[5], useo[50];

				printf("Enter the userid\n");
				scanf("%[^\n]s",username1);
				flush(stdin);

				printf("Enter the 4 digit pin\n");
				scanf("%[^\n]s",pin1);
				flush(stdin);

				printf("Enter the USE i.e. WEBSITE name\n");
				scanf("%[^\n]s",useo);
				flush(stdin);

				//open file "userdetails.bin" and handle if failure to open the file takes place
				char file_name[] = "userdetails.bin";
				FILE *fp=fopen(file_name,"rb+");
				if(fp == NULL)
				{
					printf("The file \"%s\" could not be opened... Please try again or create new RECORDS !", file_name);
					return 1;
				}

				//netinfo is a struct which contains the details that will be encrypted or decrypted as required
				netinfo det;
				int flag=0;
				while(fread(&det,sizeof(netinfo),1,fp))
				{
					dev_decrypt(&det);
					if (strcmp(det.username,username1)==0 && strcmp(det.pin,pin1)==0 && strcmp(det.use,useo)==0)
					{
						char *pwdstored=(char *)malloc(sizeof(char)*11);
						for(int i=0;i<10;i++)
						{
							*(pwdstored+i)=*(det.userkey+9-i)^*(det.pass+i);
							printf("%c",*(pwdstored+i));
						}
						printf("\n");flag=1;
						break;
					}
				}
				if (flag==0)
					printf("RECORD NOT FOUND !\n");
			}
			break;

case 2:{char username1[100];char pin1[5];
	printf("Enter the userid\n");
	scanf("%s",username1);flush(stdin);
	printf("Enter the 4 digit pin\n");
	scanf("%[^\n]s",pin1);flush(stdin);
	FILE *fp=fopen("userdetails.bin","rb+");
	netinfo det;
	int flag=0;
	while(fread(&det,sizeof(netinfo),1,fp))
		{	dev_decrypt(&det);
			if (strcmp(det.username,username1)==0 && strcmp(det.pin,pin1)==0)
			{char *pwdstored=(char *)malloc(sizeof(char)*11);
			for(int i=0;i<10;i++)
				{*(pwdstored+i)=*(det.userkey+9-i)^*(det.pass+i);
				printf("%c",*(pwdstored+i));}
			printf("\n");flag=1;
			}}
	if (flag==0)
		printf("RECORD not FOUND\n");
	break;}}}}


void dev_encrypt(netinfo *det)
{
	str rc;
	strcpy(rc.msg, det->use);
	numcpy(det->use_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->username);
	numcpy(det->username_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->emailid);
	numcpy(det->emailid_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->phonenumber);
	numcpy(det->phonenumber_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->pin);
	numcpy(det->pin_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->userkey);
	numcpy(det->userkey_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->pass);
	numcpy(det->pass_i, encry_inter(1, rc).msg_int);
}

void dev_decrypt(netinfo *det)
{
	str rc;
	numcpy(rc.msg_int, det->use_i);
	strcpy(det->use, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->username_i);
	strcpy(det->username, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->emailid_i);
	strcpy(det->emailid, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->phonenumber_i);
	strcpy(det->phonenumber, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->pin_i);
	strcpy(det->pin, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->userkey_i);
	strcpy(det->userkey, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->pass_i);
	strcpy(det->pass, encry_inter(2, rc).msg);
}

void numcpy(int *msg_int, int *en)
{
	int i;
	for(i=0;en[i] != -1;i++)
    	msg_int[i] = en[i];
	msg_int[i] = -1;
}

seepass.c
Displaying seepass.c.
