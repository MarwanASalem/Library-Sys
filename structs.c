//
//  structs.c
//  Library System
//
//  Created by Marwan Salem and Mohamed Alharouni on 11/29/17.
//  Copyright © 2017 Marwan Salem. All rights reserved.
//

#include "structs.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int Comparedate(Date date1, Date date2 ) // Date 1 is the current date, date 2 is the due date
{

    if(date1.year<date2.year)
        return 1;
    else if (date1.year>date2.year)
        return 0;
    else if(date1.month<date2.month)
        return 1;
    else if (date1.month>date2.month)
        return 0;
    else if (date1.day<date2.day)
        return 1;
    else
        return 0;
}// 1= not due
// 0= over due
void Addcopy(Book book1, int nc)
{
    int a;
    a=nc+book1.copies;
    book1.copies = a;
}
void Addbook()
{
    int i,n=0;
    FILE *fp;
    for(i=0;i<10000;i++)
    {
        if(members[i].visibility==0)
        break;
        else
            n++;
    }
    printf("Enter title\n");
    fgets(books[n+1].title,100,stdin);
    trim(books[n+1].title);
    printf("Specify the author");
    fgets(books[n+1].author,100,stdin);
    trim(books[n+1].author);
    printf("Specify the publisher");
    fgets(books[n+1].publisher,100,stdin);
    trim(books[n+1].publisher);
    printf("Enter book ISBN");
    fgets(books[n+1].ISBN,14,stdin);
    trim(books[n+1].ISBN);
    printf("Enter Number of copies");
    scanf("%d",&books[n+1].copies);
    fflush(stdin);
    printf("Specify Category");
    fgets(books[n+1].category,50,stdin);
    printf("Please enter date book was published in form dd/mm/yy");
    fgets("%d%d%D",books[n+1].date.day,stdin);
    fgets("%d%d%D",books[n+1].date.month,stdin);
    fgets("%d%d%D",books[n+1].date.year,stdin);



}
void Memberegister()
{
    int i,n = 0;
    for(i=0;i<10000;i++)
    {
        if(members[i].visibility==0) //check this and apply to add book if applicable.....
        break;
        else
            n++;
    }
                        printf("Enter First name\n");
                        fgets(members[n].firstname,25,stdin);
                        trim(members[n].firstname);
                        printf("Enter Last name\n");
                        fgets(members[n].lastname,25,stdin);
                        trim(members[n].lastname);
                        printf("Enter ID\n");
                        scanf("%d",&members[n].ID);
                        printf("Enter age\n");
                        scanf("%d", &members[n].age);
                        fflush(stdin);
                        printf("Enter phone number\n");
                        fgets(members[n].phonenumber,20,stdin);
                        trim(members[n].phonenumber);
                        printf("Enter E-Mail\n");
                        fgets(members[n].email,100,stdin);
                        trim(members[n].email);
                        printf("Enter Address with 'enters' between the city, the name and the address\n");
                        fgets(members[n].address.city,25,stdin);
                        trim(members[n].address.city);
                        fgets(members[n].address.street,25,stdin);
                        trim(members[n].address.street);
                        fgets(members[n].address.building,25,stdin);
                        trim(members[n].address.building);
                      //  fp=fopen("members.txt","a");
                        //fprintf(fp,"%s-%s-%d-%d-%s-%s-%s-%s-%s",members[n+1].firstname,members[n+1].lastname,members[n+1].age,members[n+1].ID,members[n+1].phonenumber,members[n+1].email,members[n+1].address.city,members[n+1].address.street,members[n+1].address.street);



}
 char * trim(char *  str) //To handle a problem with the buffer in the file.
{
    int n;
    n=strlen(str);
    str[n-1]='\0';
    return str;

}

void Deletebook(char * isbn)//Done
{
    int i;
    for(i=0;i<10000;i++)
    {
        if(strcmp(books[i].ISBN,isbn)==0)
        {
            break;
        }

    }
    books[i].visibility=0
}
Book Searchbook(char * isbn)
{
    int f=0,i,j,n = 0; // variable f??

    for(i=0;i<10000;i++)
    {

        if(books[i].visibility==0) // apply here if works in add member
            break;
        else
            n++;
    }
    for(j=0;j<n;j++)
    {
        if(strcmp(isbn,books[j].ISBN)==0)
        {
            break;
        }


    }
    return books[j];
}
Book Searchbook(char * title)
{
    int f=0,i,j,n = 0; // variable f??

    for(i=0;i<10000;i++)
    {

        if(strcmp(title,books[j].title)==0) // apply here if works in add member
            break;
        else
            n++;
 }
    return books[j];
}
Book Searchbook(char * author)
{
    int f=0,i,j,n = 0; // variable f??

    for(i=0;i<10000;i++)
    {

        if(strcmp(author,books[j].author)==0) // apply here if works in add member
            break;
        else
            n++;
    }
    return books[j];
}
