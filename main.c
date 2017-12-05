//
//  main.c
//  Library System
//
//  Created by SHProductions on 11/29/17.
//  Copyright © 2017 Marwan Salem. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "structs.h"
#include "structs.c"



Member members[1000];
Book books[10000];
Borrowing borrowing[10000];
int main()
{
               int f1=0,f2,fblock=0; //f1 flag for password verification.
    //f2 to check the password when entered.
    char password[100],password1[100],passwordinput[100];

    int i,x=0,y=0,j,f=0,e;//x is the number of members desired to initialize.
    //f is the flag needed for the error handling and
    //y is the number of books desired to initialize
    //e variable to hold the number to the function to execute.
    FILE * fp;
    if((fp=fopen("members.txt","r")))// to show the startup menu anytime but the first time.
    {
        printf("Enter Function Index to execute:\n1)  Check Date\n2)  Add Book\n3)  Search For A Book\n4)  Add Copy\n5)  Delete Book\n6)  Member Register\n7)  Member Borrowing\n8)  Returning Book\n9)  Remove Member\n10) Overdue Books\n11) Most Popular Books ");
        do
            scanf("%d",&e);
        while(e>11 && e<0);

       /* switch(e)
        {
            case 1 :
            {

                break;
            }
            case 2 :
                {

                    break;
                }
            case 3 :
                {

                    break;
                }
            case 4 :
                {

                    break;
                }
            case 5 :
                {

                    break;
                }
            case 6 :
                {
                    Memberegister();

                    break;
                }
            case 7 :
                {

                    break;
                }
            case 8 :
                {

                    break;
                }
            case 9 :
                {

                    break;
                }
            case 10 :
                {
                    do{
                            fblock++;
                        printf("Enter the admin password");
                        clearinputbuffer();
                        fgets(passwordinput,100,stdin);
                        fp=fopen("password.txt","r");
                        fgets(password,100,fp);
                        if (strcmp(password,passwordinput)!= 0)
                            f2=1;
                        else
                            f2=0;
                        if (fblock>4)
                            {
                                exit(1);
                            }

                        }
                        while (f2!=0 && fblock<5);
                    break;
                }
            case 11 :
                {
                    printf("Enter the admin password");

                    break;
                }

        }
*/
    }
    else
        {

    do {
            if (f1 != 0)
                printf("Error (does not match) \n");

            printf("Enter the password you want to set for the admin\n");
            fgets(password,100,stdin);
            printf("Re enter the password\n");
            fgets(password1,100,stdin);
            if(strcmp(password,password1)!=0)
                f1=1;
            else
                f1=0;
    }
    while(f1!=0);
    fp=fopen("password.txt","w");
    fprintf(fp,"%s",password);
    fclose(fp);

            fp=fopen("members.txt","w");
            printf("Please enter the initial number of members\n");
            scanf("%d",&x);
            clearinputbuffer();
            for(i=0;i<x;i++)
            {
                        printf("Enter First name\n");
                        fgets(members[i].firstname,25,stdin);
                        trim(members[i].firstname);
                        printf("Enter Last name\n");
                        fgets(members[i].lastname,25,stdin);
                        trim(members[i].lastname);
                        printf("Enter ID\n");
                        scanf("%d",&members[i].ID);
                        printf("Enter age\n");
                        scanf("%d", &members[i].age);
                        clearinputbuffer();
                        printf("Enter phone number\n");
                        fgets(members[i].phonenumber,20,stdin);
                        trim(members[i].phonenumber);
                        printf("Enter E-Mail\n");
                        fgets(members[i].email,100,stdin);
                        trim(members[i].email);
                        printf("Enter Address with 'enters' between the city, the name and the address\n");
                        fgets(members[i].address.city,25,stdin);
                        trim(members[i].address.city);
                        fgets(members[i].address.street,25,stdin);
                        trim(members[i].address.street);
                        fgets(members[i].address.building,25,stdin);
                        trim(members[i].address.building);

                    fprintf(fp,"%s,%s%d,%d,%s,%s,%s,%s,%s",members[i].firstname,members[i].lastname,members[i].age,members[i].ID,members[i].phonenumber,members[i].email,members[i].address.city,members[i].address.street,members[i].address.street);

                    fprintf(fp,"\n");



            }
            fclose(fp);
           /* fp=fopen("Books.txt","w");
           printf("Enter number of Books you want to initialize the library with\n");
            scanf("%d",&y);
            clearinputbuffer();
            for(i=0;i<y;i++)
            {
                printf("Book [%d]",(i+1));
                printf(" Enter Category\n");
                fgets(books[i].category,50,stdin);
                trim(books[i].category);
                printf("Enter Title\n");
                fgets(books[i].title,100,stdin);
                trim(books[i].title);
                printf("Enter ISBN\n");
                fgets(books[i].ISBN,14,stdin);
                trim(books[i].ISBN);
                printf("Enter number of copies\n");
                scanf("%d",&books[i].copies);
                fprintf(fp,"%s_%s_%s_%d",books[i].category,books[i].title,books[i].ISBN,books[i].copies);
            }
*/           printf("Please restart the program\n");

       }
    return 0;
}
