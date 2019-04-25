#include<stdio.h>
#include<conio.h>   // header file 

 struct student    // structure start for every function 
 {
    int roll;
    char name[40];
    char gender[5];
    int age;
    char adr[40];
    char cou[5];
    char phn[15];
    char doj[40];
 }bca;


void login()

{
	char password[10]={"abdul"};
	char pwd[10],ch;
	int i=0;
	printf("\n\n\t\t\t STUDENT DATABASE");
	printf("\n\n\n\n\t\t\t EnterPassWord :");
	ch=getch();
	while (ch!=13)
	{
		if(ch!=13 &&i<=9)
		{
			printf("*");
			pwd[i]=ch;
			i++;
			ch=getch();
		}
		else
		{
			printf("\n\n\n\n\n\t\t Max limit Exceeded");
			printf("\n\n\n\n\n\n\n\t\t\t Please Re_Enter PassWord");
			login();

		}
	 }

      pwd[i]='\0'; // NULL character
	if(strcmp(password,pwd)==0)
	{
		printf("\n\n\n\n\n\t\t\t PassWord Match ");
		printf("\n\n\n\n\n\n\n\t\t\t continuning in 3 second...");
		delay(3000);
		clrscr();

	}
	else
	{
		printf("\n\n\n\n\n\t\t\t Incorrect PassWord");
		printf("\n\n\n\n\n\n\n\t\t\t Re-Enter PassWord in 3 second...");
		clrscr();
		login();
	}

}
void insert()
{
	int i,n=0;
	FILE *fp;
	clrscr();
	fp=fopen("stddetails.dat","wb"); //open the  file pointer 
	if(fp == NULL)
	{

		printf("\n\n\n\n\t\t\t Error to open the file ");
		getch();
		exit(1);
	}
	printf("\n\n\n\n\t\t\t HOW MANY RECORD YOU WANT TO ENTER ?");
	scanf("%d",&n);
	clrscr();
	for(i=0;i<n;i++)
	{

		printf("\n\n\t\t\t### ENTER STUDENT DETAILS ###");
		printf("\n\n\t\t\t Enter Roll NO =");
		scanf("%d",&bca.roll);
		printf("\n\t\t\t Enter Name Of Student =");
		scanf("%s",&bca.name);
		flushall();
		printf("\n\t\t\t Enter Gender OF Student [M/F]=");
		scanf("%s",&bca.gender);
		printf("\n\t\t\t Enter Age OF Student =");
		scanf("%d",&bca.age);
		printf("\n\t\t\t Enter Address OF Student =");
		scanf("%s",&bca.adr);
		printf("\n\t\t\t Enter Student Courses =");
		scanf("%s",&bca.cou);
		printf("\n\t\t\t Enter Student Phone Number =");
		scanf("%s",&bca.phn);
		printf("\n\t\t\t Enter Dare OF Join[DD/MM/YYYY]=");
		scanf("%s",bca.doj);
		printf("\n\n\t\t\t ******************************************");
		fwrite(&bca,sizeof(bca),1,fp);

	}
	fclose(fp);
	clrscr();
	printf("\n\n\n\n\n\n\n\n\n\t\t\t *STUDENT RECORD ADDED SUCCESSFULLU !!");



}
void search()
{
	FILE *fp;
	int se;
	clrscr();
	fp=fopen("stddetails.dat","r");
	printf("\n\n\n\t\t\t Enter Roll Number To Search =");
	scanf("%d",&se);
	if(fp == NULL)
	{

	      printf("\n\n\n\t\t\t Cannot be found !!");
	      clrscr();
	      getch();
	      exit(1);
	}
	else
	{
		while(fread(&bca,sizeof(bca),1,fp)==1)
		{
			if(bca.roll == se)
			{
				clrscr();
				printf("\n\n\t\t\t##STUDENT INFORMATION##");
				printf("\n\n\t\t\t=> Student Roll Number=%d",bca.roll);
				printf("\n\t\t\t=> Student Name =%s",bca.name);
				printf("\n\t\t\t=> Student gender =%s",bca.gender);
				printf("\n\t\t\t=> Student Age =%d",bca.age);
				printf("\n\t\t\t=> Student Address =%s",bca.adr);
				printf("\n\t\t\t=> Student course =%s",bca.cou);
				printf("\n\t\t\t=> Student Phone Number =%s",bca.phn);
				printf("\n\t\t\t=> Date OF Student Joining =%s",bca.doj);
				printf("\n\n\t\t\t _________________________________");

				break;
			}
		}

	}

}
void Delete()
{
	int d;
	FILE *fp;
	FILE*fp2;
	clrscr();
	printf("\n\n\t\t\t| Delete Student Record |");
	printf("\n\n\t\t\t -Please Enter Student ROLL NO To Delete =");
	scanf("%d",&d);
	fp =fopen("stddetails.dat","r");
	fp2 =fopen("temp.dat","wb");
	rewind(fp);
	while((fread(&bca,sizeof(bca),1,fp) > 0))
	{
		if(bca.roll != d)
		{
			fwrite(&bca,sizeof(bca),1,fp2);
		}
	}
	fclose(fp);
	fclose(fp2);
	remove("stddetails.dat");
	rename("temp.dat","stddetails.dat");
	printf("\n\n\n\t\t\tRecord Deleted !!");




}
void main()
{

int ch;
char i;
clrscr();
login();
clrscr();
do  // main menu start 
{

	printf("\n\n\n\n\t\t\t######STUDENT DATABASE######");
	printf("\n********************************************************************************");
	printf("\n\n\n\t\t\t<Press 1> To INSERT RECORD");
	printf("\n\t\t\t<Press 2> To Search By Roll No");
	printf("\n\t\t\t<Press 3> To Delete The Record");
	printf("\n\t\t\t<Press 4> To EXIT");
	printf("\n\n\t\t\t\tEnter choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1:
		insert();
		break;
	    case 2:
		search();
		break;
	    case 3:
		Delete();
		break;
	    case 4:
		    exit(0);
	    default:
		printf("\n\t\t\t Wrong choise !!");

	}
	printf("\n\t\t\t Do you Want to contuine [Y/N]?");
	scanf("%s",&i);


}while(i!='N');


}
