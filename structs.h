//
//  structs.h
//  Library System
//
//  Created by ASHProductions on 11/29/17.
//  Copyright © 2017 ASHProductions. All rights reserved.
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
    int visibility; //0 invisible , 1 visible
}Borrowing;


int Comparedate(Date date1, Date date2);//Done
void Addbook(void); // Done
Book Searchbook1(char * isbn); //Done
void Addcopy(char * isbn, int nc);//done
void Deletebook(char * isbn);//done
void Memberegister(void);//done
void Memberborrow(int StID,char * isbn);//lesa
void Bookreturn(int StID,char * isbn);//Done
void Removemember(int ID);//Done
void Overduebooks(void);//Done
void Mostpopular();//lesa
Book Searchbook2(char * title);
Book Searchbook3(char * author);
void scanningmembers(void);
void scanningbooks(void);
void scanningborrow(void);
void savingmembers(void);
void savingbooks(void);
void savingborrow(void);
char * trim(char *  str);
extern Member members[];
extern Book books[];
extern Borrowing borrowing[];
extern FILE * fp;
extern FILE * fpointm;
extern FILE * fpointbk;
extern FILE * fpointbr;
void clearinputbuffer(void);


#endif /* structs_h */
