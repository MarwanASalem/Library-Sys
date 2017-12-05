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
    char category[50];
    Date date;

}Book;

typedef struct{
    Member member;
    Book book;
    Date date;
    int counter;
}Borrowing;


int Comparedate(Date date1, Date date2);
void Addbook(Book book1);
void Searchbook(Book book1);
void Addcopy(Book book1,int nc);
void Deletebook(Book book1);
void Memberegister(void);
void Memberborrow(Borrowing book1);
void Bookreturn(Borrowing book1);
void Removemember(Member member1);
void Overduebooks(Borrowing book1);
void Mostpopular(Borrowing book1);
char * trim(char *  str);
int clearinputbuffer(void);
extern Member members[];
extern Book books[];
extern Borrowing borrowing[];


#endif /* structs_h */
