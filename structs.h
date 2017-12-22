//
//  structs.h
//  Library System
//
//  Created by  on 11/29/17.
//  Copyright © 2017 Marwan Salem and Mohamed Alharouni. All rights reserved.
//

#ifndef structs_h
#define structs_h

#include <stdio.h>

typedef struct  {
    char building[25];
    char street [25];
    char city [25];

} Address;
typedef struct {
    char firstname[50];
    char lastname[50];
    int ID;
    Address address;
    char phonenumber[20];
    int age;
    char email[100];
    int visibility; //0 invisible , 1 visible //
    } Member;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char title[100];
    char author[100];
    char publisher[100];
    char ISBN[14];
    int copies;
    int copiesborrowed;
    char category[50];
    Date date;
    int visibility; //0 invisible , 1 visible

}Book;

typedef struct{
    Member member;
    Book book;
    Date date;
}Borrowing;


int Comparedate(Date date1, Date date2);//Done
void Addbook(); // Done
Book Searchbook(char * isbn); //Done
void Addcopy(Book book,int nc);//done
void Deletebook(char * isbn);//done
void Memberegister(int ID, char * isbn);//done
void Memberborrow(int StID,char * isbn);//lesa
void Bookreturn(Borrowing book[]);//lesa
void Removemember(Member member);//Done
void Overduebooks(void);//Done
void Mostpopular(Book book[]);//lesa
Book Searchbook(char * title);
Book Searchbook(char * author);
char * trim(char *  str);
extern Member members[];
extern Book books[];
extern Borrowing borrowing[];


#endif /* structs_h */
