//
//  structs.c
//  Library System
//
//  Created by Marwan Salem and Mohamed Alharouni on 11/29/17.
//  Copyright © 2017 Marwan Salem. All rights reserved.
//

#include "structs.h"

int Comparedate(Date date1, Date date2 ) // Date 1 is the current date date 2 is he due date
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
// 2= over due
void Addcopy(Book book1, int nc)
{
    int a;
    a=nc+book1.copies;
    book1.copies = a;
}
void Memberegister()
{
    int i,n;
    FILE *fp;
    for(i=0;i<10000;i++)
    {
        if(! members[i].firstname)
        break;
        else
            n++;
    }
        printf("Enter First name\n");
                        fgets(members[n+1].firstname,25,stdin);
                        trim(members[n+1].firstname);
                        printf("Enter Last name\n");
                        fgets(members[n+1].lastname,25,stdin);
                        trim(members[n+1].lastname);
                        printf("Enter ID\n");
                        scanf("%d",&members[n+1].ID);
                        printf("Enter age\n");
                        scanf("%d", &members[n+1].age);
                        clearinputbufffer();
                        printf("Enter phone number\n");
                        fgets(members[n+1].phonenumber,20,stdin);
                        trim(members[n+1].phonenumber);
                        printf("Enter E-Mail\n");
                        fgets(members[n+1].email,100,stdin);
                        trim(members[n+1].email);
                        printf("Enter Address with 'enters' between the city, the name and the address\n");
                        fgets(members[n+1].address.city,25,stdin);
                        trim(members[n+1].address.city);
                        fgets(members[n+1].address.street,25,stdin);
                        trim(members[n+1].address.street);
                        fgets(members[n+1].address.building,25,stdin);
                        trim(members[n+1].address.building);
                        fp=fopen("members.txt","a");
                        fprintf(fp,"%s-%s-%d-%d-%s-%s-%s-%s-%s",members[n+1].firstname,members[n+1].lastname,members[n+1].age,members[n+1].ID,members[n+1].phonenumber,members[n+1].email,members[n+1].address.city,members[n+1].address.street,members[n+1].address.street);



}
char * trim(char *  str) //To handle a problem with the buffer in the file.
{
    int n;
    n=strlen(str);
    str[n-1]='\0';
    return str;

}
int clearinputbufffer()
{
    int ch;
    while(((ch = getchar())!= EOF) && (ch != '\n'))
     return ch;
}
