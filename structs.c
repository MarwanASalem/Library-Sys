//
//  structs.c
//  Library System
//
//  Created by ASHProductions on 11/29/17.
//  Copyright © 2017 ASHProductions. All rights reserved.
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
    fflush(stdin);
    fgets(books[n].title,100,stdin);
    trim(books[n].title);
    printf("Specify the author\n");
    fflush(stdin);
    fgets(books[n].author,100,stdin);
    trim(books[n].author);
    printf("Specify the publisher\n");
    fflush(stdin);
    fgets(books[n].publisher,100,stdin);
    trim(books[n].publisher);
    printf("Enter book ISBN\n");
    fflush(stdin);
    fgets(books[n].ISBN,14,stdin);
    trim(books[n].ISBN);
    printf("Enter Number of copies\n");
    scanf("%d",&books[n].copies);
    fflush(stdin);
    printf("Specify Category\n");
    fflush(stdin);
    fgets(books[n].category,50,stdin);
    printf("Please enter date book was published in form dd/mm/yy");
    fflush(stdin);
    fgets("%d%d%D",books[n].date.day,stdin);
    fflush(stdin);
    fgets("%d%d%D",books[n].date.month,stdin);
    fflush(stdin);
    fgets("%d%d%D",books[n].date.year,stdin);
    books[n].visibility=1;



}
void Memberegister()
{
    int i,n = 0,f;
    do{  for(i=0;i<10000;i++)
    {
        if(members[i].visibility==0)
        break;
        else
            n++;
    }
                        printf("Enter First name\n");
                        fgets(members[n].firstname,25,stdin);
                        trim(members[n].firstname);
    clearinputbuffer();
                        printf("Enter Last name\n");
                        fgets(members[n].lastname,25,stdin);
                        trim(members[n].lastname);
                        printf("Enter ID\n");
                        scanf("%d",&members[n].ID);
    clearinputbuffer();
    printf("Enter age\n");
                        scanf("%d", &members[n].age);
    clearinputbuffer();
                        printf("Enter phone number\n");
                        fgets(members[n].phonenumber,20,stdin);
                        trim(members[n].phonenumber);
    clearinputbuffer();
                        printf("Enter E-Mail\n");
                        fgets(members[n].email,100,stdin);
                        trim(members[n].email);
    clearinputbuffer();
                        printf("Enter Address with 'enters' between the city, the name and the address\n");
                        fgets(members[n].address.city,25,stdin);
                        trim(members[n].address.city);
    clearinputbuffer();
                        fgets(members[n].address.street,25,stdin);
                        trim(members[n].address.street);
    clearinputbuffer();
                        fgets(members[n].address.building,25,stdin);
                        trim(members[n].address.building);
                        members[n].visibility=1;
    
    printf("To stop adding members enter 0");
    scanf("%d",&f);
    }
    while(f!=0);


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
    printf("Wrong ISBN\n");
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
  if (i==1000)
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
     if (i==1000)
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
                f=1;
                break;
                
}
            strcpy(borrowing[n].book.ISBN,isbn);
            books[i].copiesborrowed++;
            Date datecmp;
            time_t t = time(NULL);
            struct tm *tm = localtime(&t);
            datecmp.year=tm->tm_year;
            datecmp.month=tm->tm_mon;
            datecmp.day=tm->tm_mday;
            borrowing[i].date.year=datecmp.year;
            borrowing[i].date.month=datecmp.month+1;
            borrowing[i].date.day=datecmp.day;
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
        if (i==m1)
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
        if (i==m1||i==m2)
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
        if (i==m1||i==m2||i==m3)
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
        if (i==m1||i==m2||i==m3||i==m4)
            continue;
        if(books[i].copiesborrowed>max)
        {
            max=books[i].copiesborrowed;
            m5=i;
        }
    }
    printf("Most Popular Books are :\n1)%s\n2)%s\n3)%s\n4)%s\n5)%s",books[m1].title,books[m2].title,books[m3].title,books[m4].title,books[m5].title);
}
void Bookreturn(int StID,char * isbn)
{

    int i,j ;
    for (i=0;i<1000;i++)
    {
        if (borrowing[i].member.ID==StID)
        {
            for (j=0;j<1000;j++)
            {
                if(strcmp(borrowing[j].book.ISBN,isbn)==0)
                {
                    if (j==i)
                        break;
                }
            }
        }
    }

borrowing[i].visibility=0;
}
void Removemember(int ID)
{
     int i;
    for(i=0;i<1000;i++)
    {
        if(members[i].ID==ID)
        {
            break;
        }

    }
    if(i==1000)
    printf("Invalid ID\n");
else
    members[i].visibility=0;
}

void savingmembers(void){
    
    fpointm=fopen("Members.txt","w");
    int i;
    for(i=0;i<10000;i++){
        
        if(members[i].visibility==1) {
            fprintf(fpointm,"%s,",members[i].firstname);
            fprintf(fpointm,"%s,",members[i].lastname);
            fprintf(fpointm,"%d,",members[i].ID);
            fprintf(fpointm,"%s,",members[i].address.building);
            fprintf(fpointm,"%s,",members[i].address.street);
            fprintf(fpointm,"%s,",members[i].address.city);
            fprintf(fpointm,"%s,",members[i].phonenumber);
            fprintf(fpointm,"%d,",members[i].age);
            fprintf(fpointm,"%s,",members[i].email);
            fprintf(fpointm,"\n");
        }
        else  continue;
        
    }
    fclose(fpointm);
}

void savingbooks(void){
    
    fpointbk=fopen("Books.txt","w");
    int j;
    for(j=0;j<10000;j++){
        if(books[j].visibility==1) {
            fprintf(fpointbk,"%s,",books[j].title);
            fprintf(fpointbk,"%s,",books[j].author);
            fprintf(fpointbk,"%s,",books[j].publisher);
            fprintf(fpointbk,"%s,",books[j].ISBN);
            fprintf(fpointbk,"%d,",books[j].copies);
            fprintf(fpointbk,"%d,",books[j].copiesborrowed);
            fprintf(fpointbk,"%s,",books[j].category);
            fprintf(fpointbk,"%d,",books[j].date.day);
            fprintf(fpointbk,"%d,",books[j].date.month);
            fprintf(fpointbk,"%d,",books[j].date.year);
            fprintf(fpointbk,"\n");
        }
        
        else  continue;
    }
    fclose(fpointbk);
}
void savingborrow(void){
    
    fpointbr=fopen("Borrow.txt","w");
    int k;
    for(k=0;k<10000;k++){
        if(borrowing[k].visibility==1){
            fprintf(fpointbr,"%d,",borrowing[k].member.ID);
            fprintf(fpointbr,"%s,",borrowing[k].book.ISBN);
            fprintf(fpointbr,"%d,",borrowing[k].date.day);
            fprintf(fpointbr,"%d,",borrowing[k].date.month);
            fprintf(fpointbr,"%d,",borrowing[k].date.year);
            fprintf(fpointbr,"\n");
        }
        else continue;
    }
    fclose(fpointbr);
}
void scanningmembers(void){
    int i=0;
    fpointm=fopen("Members.txt","r");
    if(fpointm!=NULL){
        while(!feof(fpointm)){
            fscanf(fpointm,"%[^,],",members[i].firstname);
            fscanf(fpointm,"%[^,],",members[i].lastname);
            fscanf(fpointm,"%d,",&members[i].ID);
            fscanf(fpointm,"%[^,],",members[i].address.building);
            fscanf(fpointm,"%[^,],",members[i].address.street);
            fscanf(fpointm,"%[^,],",members[i].address.city);
            fscanf(fpointm,"%[^,],",members[i].phonenumber);
            fscanf(fpointm,"%d,",&members[i].age);
            fscanf(fpointm,"%[^,],",members[i].email);
}
        
    }
    fclose(fpointm);
}
void scanningbooks(void){
    int i=0;
    fpointbk=fopen("Books.txt","r");
    if(fpointbk!=NULL){
        while(!feof(fpointbk)){
            fscanf(fpointbk,"%[^,],",books[i].title);
            fscanf(fpointbk,"%[^,],",books[i].author);
            fscanf(fpointbk,"%[^,],",books[i].publisher);
            fscanf(fpointbk,"%[^,],",books[i].ISBN);
            fscanf(fpointbk,"%d,",&books[i].copies);
            fscanf(fpointbk,"%d,",&books[i].copiesborrowed);
            fscanf(fpointbk,"%[^,],",books[i].category);
            fscanf(fpointbk,"%d,",&books[i].date.day);
            fscanf(fpointbk,"%d,",&books[i].date.month);
            fscanf(fpointbk,"%d,",&books[i].date.year);
        }
    }
    fclose(fpointbk);
}
void scanningborrow(void){
    int i=0;
    fpointbr=fopen("Borrow.txt","r");
    if(fpointbr!=NULL){
        while(!feof(fpointbr)){
            fscanf(fpointbr,"%d,",&borrowing[i].member.ID);
            fscanf(fpointbr,"%[^,],",borrowing[i].book.ISBN);
            fscanf(fpointbr,"%d,",&borrowing[i].date.day);
            fscanf(fpointbr,"%d,",&borrowing[i].date.month);
            fscanf(fpointbr,"%d,",&borrowing[i].date.year);
        }
    }
    fclose(fpointbr);
}

void clearinputbuffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
}








