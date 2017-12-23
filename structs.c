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
void Addcopy(char * isbn, int nc)
{
    int i;
    for(i=0;i<1000;i++)
    {
        if(strcmp(books[i].ISBN,isbn)==0)
        {
            books[i].copies=books[i].copies+nc;
            break;
        }

    }
    if(i==1000)
    printf("Wrong ISBN");

}
void Addbook()
{
    int i,n=0;

    for(i=0;i<10000;i++)
    {
        if(members[i].visibility==0)
        break;
        else
            n++;
    }
    printf("Enter title\n");
    fgets(books[n].title,100,stdin);
    trim(books[n].title);
    printf("Specify the author");
    fgets(books[n].author,100,stdin);
    trim(books[n].author);
    printf("Specify the publisher");
    fgets(books[n].publisher,100,stdin);
    trim(books[n].publisher);
    printf("Enter book ISBN");
    fgets(books[n].ISBN,14,stdin);
    trim(books[n].ISBN);
    printf("Enter Number of copies");
    scanf("%d",&books[n].copies);
    fflush(stdin);
    printf("Specify Category");
    fgets(books[n].category,50,stdin);
    printf("Please enter date book was published in form dd/mm/yy");
    fgets("%d%d%D",books[n].date.day,stdin);
    fgets("%d%d%D",books[n].date.month,stdin);
    fgets("%d%d%D",books[n].date.year,stdin);
    books[n].visibility=1;



}
void Memberegister()
{
    int i,n = 0;
    for(i=0;i<10000;i++)
    {
        if(members[i].visibility==0)
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
                        members[n].visibility=1;
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
    for(i=0;i<1000;i++)
    {
        if(strcmp(books[i].ISBN,isbn)==0)
        {
            break;
        }

    }
    if(i==1000)
    printf("Wrong ISBN");
else
    books[i].visibility=0;

}
Book Searchbook1(char * isbn)
{
    int j;
    Book b;
    b.copies=0;

    for(j=0;j<1000;j++)
    {
        if(strcmp(isbn,books[j].ISBN)==0)
        {
            break;
        }



    }
    if (j==1000)
        return b;
    else
    return books[j];
}
Book Searchbook2(char * title)
{
    int i; // variable f??
     Book b;
    b.copies=0;

    for(i=0;i<1000;i++)
    {

        if(strcmp(title,books[i].title)==0)
            break;
 }
  if (j==1000)
        return b;
    else
        return books[i];
}
Book Searchbook3(char * author)
{
    int i;
     Book b;
    b.copies=0;

    for(i=0;i<1000;i++)
    {

        if(strcmp(author,books[i].author)==0)
            break;
    }
     if (j==1000)
        return b;
    else
        return books[i];
}

void Overduebooks(void)
{
    Date datecmp;
    int i;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    datecmp.year=tm->tm_year;
    datecmp.month=tm->tm_mon;
    datecmp.day=tm->tm_mday;


    for(i=0;i<10000;i++)
    {
        if((Comparedate(datecmp,borrowing[i].date))==0)
        {
            printf("Overdue Books:/n");
            printf("Borrower's ID : %d/t",borrowing[i].member.ID);
            printf("Book's name : %s/n",borrowing[i].book.title);
        }
    }
}
void Memberborrow(int StID,char * isbn)//Add Due Date!!!!!!!!!
{
    int i,n = 0,f=0;
    for(i=0;i<10000;i++)
    {
        if(borrowing[i].visibility==0)
            break;
        else
            n++;
    }
    for(i=0;i<10000;i++)
    {
        if(members[i].ID==StID)// check the number of books borrowed.
        {
            borrowing[n].member.ID=StID;
            break;
        }
    }
    for(i=0;i<10000;i++)
    {
        if(strcmp(books[i].ISBN,isbn)==0)
        {
            if(books[i].copiesborrowed>=books[i].copies)
            {
                break;
                f=1;

            }
            strcpy(borrowing[n].book.ISBN,isbn);
            books[i].copiesborrowed++;
            break;
        }

    }
    if(f==0)
        borrowing[n].visibility=1;



}
void Mostpopular(Book book[])
{
    int i,max=0,m1= 0,m2= 0,m3= 0,m4= 0,m5 = 0;
    for (i=0;i<10000;i++)
    {
        if(books[i].copiesborrowed>max)
        {
            max=books[i].copiesborrowed;
            m1=i;
        }
    }
    max=0;
    for(i=0;i<10000;i++)
    {
        if (books[m1].copiesborrowed)
            continue;
        if(books[i].copiesborrowed>max)
        {
            max=books[i].copiesborrowed;
            m2=i;
        }
    }
    max=0;
    for(i=0;i<10000;i++)
    {
        if (books[m1].copiesborrowed||books[m2].copiesborrowed)
            continue;
        if(books[i].copiesborrowed>max)
        {
            max=books[i].copiesborrowed;
            m3=i;
        }
    }
    max=0;
    for(i=0;i<10000;i++)
    {
        if (books[m1].copiesborrowed||books[m2].copiesborrowed||books[m3].copiesborrowed)
            continue;
        if(books[i].copiesborrowed>max)
        {
            max=books[i].copiesborrowed;
            m4=i;
        }
    }
    max=0;
    for(i=0;i<10000;i++)
    {
        if (books[m1].copiesborrowed||books[m2].copiesborrowed||books[m3].copiesborrowed||books[m4].copiesborrowed)
            continue;
        if(books[i].copiesborrowed>max)
        {
            max=books[i].copiesborrowed;
            m5=i;
        }
    }
    printf("Top 5 Most Popular Books are :/n1)%s/n2)%s/n3)%s/n4)%s/n5)%s",books[m1].title,books[m2].title,books[m3].title,books[m4].title,books[m5].title);
}
void Bookreturn(int StID,char * isbn)
{

    int i,j ;
    for (i=0;i<1000;i++)
    {
        if (borrowing.member.ID==StID)
            break;
    }


}
