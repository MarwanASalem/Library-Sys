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
               int flag=1, f1=0,f2,fblock=0; //f1 flag for password verification.
    //f2 to check the password when entered.
    char password[100],password1[100],passwordinput[100];

    int i,x=0,y=0,j,f=0,e;//x is the number of members desired to initialize.
    //f is the flag needed for the error handling and
    //y is the number of books desired to initialize
    //e variable to hold the number to the function to execute.
    FILE * fp;
    FILE * fpoint;
    FILE * fpoint1;
    if((fp=fopen("members.txt","r")))// to show the startup menu anytime but the first time.
    {
        fpoint=fopen("Books.txt","a");
        fpoint1=fopen("members.txt","a");

        printf("Enter Function Index to execute:\n\n1)  Check Date\n\n2)  Add Book\n\n3)  Search For A Book\n\n4)  Add Copy\n\n5)  Delete Book\n\n6)  Member Register\n\n7)  Member Borrowing\n\n8)  Returning Book\n\n9)  Remove Member\n\n10) Overdue Books\n\n11) Most Popular Books\n\n12)Exit\n\n");
        do
            scanf("%d",&e);
        while(e>12 || e<0);

        do{ switch(e)
        {
            case 1 ://check date
            {

                break;
            }
            case 2 ://ADD A BOOK
                {
                    Addbook();

                    break;
                }
            case 3 :// SEARCH FOR S BOOK
                {

                    char bookname[100];
                    fflush(stdin);
                    fgets(bookname,100,stdin);

                    Book Searchbook(char * isbn);


                    break;
                }
            case 4 ://ADD COPY
                {
                    Book b;
                    int nc=0,q=0;
                    char IS[14];
                    printf("Enter book's ISBN\n");
                    fflush(stdin);
                    fgets(IS,14,stdin);
                    printf("Enter number of copies u wish to add\n");
                    scanf("%d",&nc);
                    Addcopy(IS,nc);
                    printf("Enter Function Index to execute:\n\n1)  Check Date\n\n2)  Add Book\n\n3)  Search For A Book\n\n4)  Add Copy\n\n5)  Delete Book\n\n6)  Member Register\n\n7)  Member Borrowing\n\n8)  Returning Book\n\n9)  Remove Member\n\n10) Overdue Books\n\n11) Most Popular Books\n\n12)Exit\n\n");
                    break;
                }
            case 5 :// DELETE BOOK//done
                {
                    char IS1[14];
                    printf("Enter book's ISBN\n");
                    fflush(stdin);
                    fgets(IS1,14,stdin);
                    Deletebook(IS1);

                    break;
                }
            case 6 ://MEMBER REGISTER
                {
                    Memberegister();

                    break;
                }
            case 7 ://MEMBER BORROW// add current time to the fn.
                {

                    break;
                }
            case 8 ://RETURN BOOK
                {
                    char IS2[14];
                    printf("Enter book's ISBN\n");
                    fflush(stdin);
                    fgets(IS2,14,stdin);
                    int stid;
                    do{printf("Enter member ID\n");
                    scanf("%d",&stid);}
                    while(stid<=0 || stid>10000 );


                    break;
                }
            case 9 ://REMOVE MEMBER
                {

                    break;
                }
            case 10 ://OVERDUE BOOKS
                {
                    do{
                            fblock++;
                        printf("Enter the admin password");
                        fflush(stdin);
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
                        fblock=0;

                    break;
                }
            case 11 ://MOST POP
                {

                    do{
                            fblock++;
                        printf("Enter the admin password");
                        fflush(stdin);
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
        case 12 :
        {
            exit(1);
            break;
        }
         }
         while(flag);
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
            fflush(stdin);
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
                        fflush(stdin);
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
                        members[i].visibility=1

                    fprintf(fp,"%s,%s,%d,%d,%s,%s,%s,%s,%s,%d",members[i].firstname,members[i].lastname,members[i].age,members[i].ID,members[i].phonenumber,members[i].email,members[i].address.city,members[i].address.street,members[i].address.street,members[i].visibility);

                    fprintf(fp,"\n");



            }
            fclose(fp);
           /* fp=fopen("Books.txt","w");
           printf("Enter number of Books you want to initialize the library with\n");
            scanf("%d",&y);
            fflush(stdin);
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
