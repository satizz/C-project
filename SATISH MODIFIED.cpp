# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include <dos.h>
# include <string.h>
int total(int a, int b);
int total(a,b)
{
	return (a*b);
}
void financial ()
{
	int size,remain,t,count=0;
	char std[50],stf[50];
	FILE *expenditure,*staff,*student,*cu;
	cu=fopen("temp.dat","rb+");
	if(cu==NULL)
		{
			cu=fopen("temp.dat","wb+");
		}
	if(cu==NULL)
		{
			printf("File Cannot be Opened\n");
		}
	expenditure=fopen("expenditure.dat","rb+");
	if(expenditure==NULL)
		{
			expenditure=fopen("expenditure.dat","wb+");
		}
	if(expenditure==NULL)
		{
			printf("Cannot Open File");
		}
	staff=fopen("staff.dat","rb+");
	if(staff==NULL)
		{
			staff=fopen("staff.dat","wb+");
		}
	if(staff==NULL)
		{
			printf("Cannot Open File");
		}
	student=fopen("student.dat","rb+");
	if(student==NULL)
		{
			student=fopen("student.dat","wb+");
		}
	if(student==NULL)
		{
			printf("File Cannot Be Opened");
		}
		struct student
			{
				char name[60];
				char course[60];
				int time;
				int fees;
				int advance;
				char address[70];
				int contact ;
			} s;
		struct staff1
			{
				char name[60];
				char post[60];
				char g;
				int salary;
				char qualification[50];
				int contact;
				char address [50];
			} st;
         struct expenditure
         {
         	char name[50];
            int quantity;
            int rate;
            int total;
         }e;
	int y,pass,task,task1,task2,task3,task4;
	clrscr ();
	printf("\n**********************welcome to financial department***********************");
top:
		printf("\nENTER THE PASSWORD TO LOG ON::");
	scanf("%d",&pass);
	if(pass==100)
		{
			goto menu;
		}
	if (pass!=100)
		{
p:
			printf("\n please press 1 to try again");
			printf("\n please press 2 to exit");
			scanf("%d",&y);
			switch (y)
				{
					case 1:
						goto top;
						break;

					case 2:
						exit(0);
						break;
					default :
						printf("Wrong INPUT!!!.Try Again");
						sleep(1);
						goto top;
						break;
				}
		}
menu:
	printf("\npress 1 to add information");
	printf("\npress 2 to view information");
	printf("\npress 3 to delete information");
	printf("\npress 4 to modify the information");
	printf("\npress 5 to exit");
	printf("\nenter your task::");
   scanf("%d",&task);
	switch (task)
		{
			case 1:
try1:
				printf("\nplease press 1 to add staff information");
				printf("\nplease press 2 to add student information");
				printf("\nplease press 3 to add expenditure information");
				printf("\nenter your task::");

				scanf("%d",&task1);

				switch (task1)
					{
						case 1:
							printf("ENTER NAME OF STAFF::");
							getchar();
							gets(st.name);
g:
							printf("ENTER GENDER OF STAFF(f/m)::");
							scanf("%c",&st.g);
							if(st.g=='m')
								{
									printf("ENTER HIS POST::");
									scanf("%s",&st.post);
									printf("ENTER HIS ADDRESS::");
									scanf("%s",&st.address);
									printf("ENTER HIS CONTACT::");
									scanf("%d",&st.contact);
									printf("ENTER HIS SALARY::");
									scanf("%d",&st.salary);
									printf("ENTER HIS QUALIFICATION::");
									scanf("%s",&st.qualification);
                           fwrite(&st,sizeof(st),1,staff);
									//fprintf(staff,"%s %c %s %d %d %d %s",st.name,st.g,st.post,st.salary,st.qualification,st.contact,st.address);
								}
							if(st.g=='f')
								{
									printf("ENTER HER POST::");
									scanf("%s",&st.post);
									printf("ENTER HER ADDRESS::");
									scanf("%s",&st.address);
									printf("ENTER HER CONTACT::");
									scanf("%d",&st.contact);
									printf("ENTER HER SALARY::");
									scanf("%d",&st.salary);
									printf("ENTER HER QUALIFICATION::");
									scanf("%s",&st.qualification);
									fwrite(&st,sizeof(st),1,staff);
								}
							if ((st.g!='m')&&(st.g!='f'))
								{
									printf("please try the correct character\n");
									goto g;
									goto last;
									break;
								}
                        clrscr();
                        goto last;
						case 2:
							printf("ENTER NAME OF STUDENT::");
							scanf("%s",&s.name);
							printf("ENTER THE COURSE OF STUDENT::");
							scanf("%s",&s.course);
							printf("ENTER HIS ADDRESS::");
							scanf("%s",&s.address);
							printf("ENTER HIS CONTACT NO::");
							scanf("%d",&s.contact);
							printf("ENTER TIME FOR THE COURSE::");
							scanf("%d",&s.time);
							printf("ENTER THE FEES OF COURSE::");
							scanf("%d",&s.fees);
							printf("ENTER THE ADVANCE FEES PAID::");
							scanf("%d",&s.advance);
							remain=(s.fees-s.advance);
							printf("%s has paid Rs.%d and have to pay Rs.%d",s.name,s.advance,remain);
							fwrite(&s,sizeof(s),1,student);
							printf("\nthank you");
                     sleep(1);
							goto last;
							break;
						case 3:
							printf("ENTER THE NAME OF OBJECT BOUGHT::");
							scanf("%s",&e.name);
							printf("ENTER THE QUANTITY OF OBJECT BOUGHT::");
							scanf("%d",&e.quantity);
							printf("ENTER THE RATE OF OBJECT BOUGHT::");
							scanf("%s",&e.rate);
							t=total(e.rate,e.quantity);
							fwrite(&e,sizeof(e),1,expenditure);
							printf("thank you");
                     sleep(1);
							goto menu;
							break;
						default :
							printf("plz try again" );
							goto try1;
							break;
					}
			case 2:
try2:
				printf("\nplease press 1 to view staff information");
				printf("\nplease press 2 to view student information");
				printf("\nplease press 3 to view  expenditure information");
				printf("\nenter your task::");
				scanf("%d",&task2);
				switch (task2)
					{
						case 1:
							rewind(staff);
                     while(fread(&st,sizeof(st),1,staff)==1)
                     {
                     printf("NAME ::%s\nGENDER ::%c\nADDRESS ::%s\nCONTACT ::%d\nSALARY ::%d\n",st.name,st.g,st.post,st.address,st.contact,st.salary);
                     printf("QUALIFICATION ::%s\n",st.qualification);
                     sleep(2);
                     goto last;
                  	}
                     getch();
						case 2:
							rewind(student);
								while(fread(&s,sizeof(s),1,student)==1)
									{
										printf("\nNAME ::%s\nCOURSE ::%s\nTIME ::%d\nFEE ::%d\nADDRESS ::%s\nCONTACT ::%d\n",s.name,s.course,s.time,s.fees,s.address,s.contact);
									}
							sleep(2);
							goto last;
							break;
						case 3:
							rewind(expenditure);
							while(fread(&e,sizeof(e),1,expenditure)==1)
							{
							printf("\nOBJECT BOUGHT ::%s\nQUANTITY BOUGHT ::%s\nRATE ::%d\nTOTAL ::%d\n",e.name,e.quantity,e.rate,e.total);
							}
							sleep(2);
							getch();
						  	goto last;
							break;
					default :
							printf("plz try again" );
							goto try2;
							break;
					}
				case 3:
del:
					clrscr();
					printf("\npress 1 to delete the staffs' information");
					printf("\npress 2 to delete the students' information");
					printf("\npress 3 to delete the expenditures' information");
					printf("\nenter your task::");
					scanf("%d",&task3);
					if (task3==1)
						{
							printf("Enter name of staff to Delete ::");
							scanf("%s",&stf);
							clrscr();
							printf("please wait......");
							sleep (1);
							printf(".");
							sleep (1);
							printf(".");
							sleep (1);
							printf(".");
							sleep (1);
							printf(".");
							sleep (1);
							printf(".");
							rewind(staff);
                     while(fread(&st,sizeof(st),1,staff)==1)
                     {
									if(strcmp(st.name,stf)!=0)
										{
											fwrite(&st,sizeof(st),1,cu);

										}
                     }
							fclose(staff);
							remove("staff.dat");
							fclose(cu);
							rename("temp.dat","staff.dat");
							clrscr();
							printf("deleted");
							getch();
							exit(0);
							goto last;
						}
					if (task3==2)
						{
							printf("Enter name of student to Delete ::");
							scanf("%s",&std);
							rewind(student);
		     while(fread(&s,sizeof(s),1,student)==1)
                        {
									if(strcmp(s.name,std)!=0)
										{
											fwrite(&s,sizeof(s),1,cu);
										}
								}
							fclose(student);
							remove("student.dat");
							fclose(cu);
							rename("temp.dat","student.dat");
							getch();
							goto last;
						}
					if (task3==3)
						{
							printf("Enter name of object bought to Delete ::");
							scanf("%s",&stf);
							clrscr();
							printf("please wait......");
							sleep (1);
							printf(".");
							sleep (1);
							printf(".");
							sleep (1);
							printf(".");
							sleep (1);
							printf(".");
							sleep (1);
							printf(".");
							rewind(expenditure);
							while(fread(&e,sizeof(e),1,expenditure)==1)
							{
									if(strcmp(e.name,stf)!=0)
										{
											fwrite(&e,sizeof(e),1,cu);

										}
								}
							fclose(expenditure);
							remove("expenditure.dat");
							fclose(cu);
							rename("temp.dat","expenditure.dat");
							clrscr();
							printf("deleted");
							getch();
                     goto last;
						}
					if ((task3!=1)&&(task3!=2)&&(task3!=3))
						{
							printf ("invalid input");
							printf ("plz try again");
							goto del;
						}
					break ;
				case 4:
modi:
					clrscr();
					printf("\npress 1 to  modify the staffs' information");
					printf("\npress 1 to modify the students' information");
					scanf("%d",&task4);
					if (task4==1)
						{
							   printf("Enter name of staff to edit ::");
							   scanf("%s",&stf);
							   clrscr();
							   printf("please wait......");
							   sleep (1);
							   printf(".");
							   sleep (1);
							   printf(".");
							   sleep (1);
							   printf(".");
							   sleep (1);
							   printf(".");
							   sleep (1);
							   printf(".");
							   rewind(staff);
                     	while(fread(&st,sizeof(st),1,staff)==1)
                     		{
										if(strcmp(st.name,stf)==0)
											{
												printf("%s",st.name);
												fseek(staff,0,SEEK_CUR);
												printf("enter salary of staff:: ");
												scanf("%d",st.salary);
												printf("enter post of staff:: ");
												scanf("%s",st.post);
												printf("enter qualification of staff:: ");
												scanf("%s",st.qualification);
												printf("enter address of staff:: ");
												scanf("%s",st.address);
												printf("enter contact of staff:: ");
												scanf("%d",st.contact);
												fwrite(&st,sizeof(st),1,staff);
											}
									}
								getch();
								goto last;
						}
					if (task4==2)
						{
							rewind(student);
							printf("Enter name of student to Delete ::");
							scanf("%s",&std);
							rewind(student);
                     while(fread(&s,sizeof(s),1,student)==1)
                        {
									if(strcmp(s.name,std)==0)
										{
											printf("%s",s.name);
											fseek(student,0,SEEK_CUR);
											printf("ENTER THE ADDRESS OF THE STUDENT::");
											scanf("%s",&s.address);
											printf("ENTER THE CONTACT NO. OF THE STUDENT::");
											scanf("%d",&s.contact);
											printf("ENTER THE ADVANCE PAID BY THE STUDENT::");
											scanf("%d",&s.advance);
											printf("ENTER THE COURSE OF THE STUDENT::");
											scanf("%d",&s.course);
                                 fwrite(&s,sizeof(s),1,student);
										}
								}
							getch();
							goto last;
						}
					if ((task4!=1)&&(task4!=2))
						{
							printf ("invalid input");
							printf ("plz try again");
							goto modi;
						}

				case 5:
					goto last;
					exit(0);
					break;
				default :
					printf("plz try again") ;
					goto menu;
					break;
		}
last:
   clrscr();
	printf("enter m to view menu");
	printf("enter e to exit");
	printf("enter your choice::") ;
	char l;
	scanf("%c",&l);
	if (l=='m')
	{
		goto menu;
	}
	if (l=='e')
	{
		goto ex;
	}
ex:
	printf("\n ESCOL COMPUTER INSTITUTE");
	printf("\n MAHENDRAPOOL,POKHARA,NEPAL");
	exit(0);
	getch();
}
