//Name:Supriya Das  Roll-301910501008
//2.	In a library, for each book book-id, serial number (denotes copy number of a book), title, author, publisher and price are stored. Book-id and serial number together will be unique identifier for a book. Members are either student or faculty. Each member has unique member-id. Name, e-mail, address are also to be stored. For any transaction (book issue or return), members are supposed to place transactions slip. User will submit member-id, book-id, and serial number (only for book return). While processing a transaction, check the validity of the member. While issuing, availability of a copy of the book is to be checked. While returning a book, it is to be checked whether this copy was issued to the member or not. A student member can have 2 books issued at a point of time. For faculty members it is 10. Transaction information is to be stored like date of transaction, member-id, book-id, serial number, returned or not. An entry is made when book is issued and updated when the book is returned.
//Design the classes and implement. For list consider memory data structure.


#include<bits/stdc++.h>
using namespace std;
class book
{
float sl,id,pri,z=0;
char aut[10],ti[10],pub[10];
public:
friend class mem;
friend class trans;
void bput()
{
cout<<"\nBOOK ID : ";
cin>>id;
cout<<"\nSERIAL NO : ";
cin>>sl;
cout<<"\nPRICE : ";
cin>>pri;
cout<<"\nAUTHOR : ";
cin>>aut;
cout<<"\nTITLE : ";
cin>>ti;
cout<<"\nPUBLISHER : ";
cin>>pub;
z=z+1;
}
void bget()
{
cout<<"\nBOOK ID : "<<id<<"\nSL NO. : "<<sl<<"\nAUTHOR : "<<aut<<"\nTITLE : "<<ti<<"\nPUBLISHER : "<<pub<<"\nPRICE : "<<pri;
}

};
class mem
{
char e[30],a[10];
int id;
public:
void mput()
{
cout<<"\nENTER MEMBER ID (ID<200 FOR STUDENTS | ID>=200 FOR TEACHERS) : ";
cin>>id;
cout<<"\nEMAIL ID : ";
cin>>e;
cout<<"\nADDRESS : ";
cin>>a;
}
void mget()
{
cout<<"\nMEMBER ID : "<<id<<"\nEMAIL ID : "<<e<<"\nADDRESS : "<<a;
}
int rid()
{return id;
}
};
class trans
{
public:
friend class mem ;
friend class book;
void wit(mem m, book b)
{
cout<<"\n\t\tWITHDRAW SLIP\n";
m.mget();
b.bget();
}
void dep(mem m, book b)
{
cout<<"\n\tDEPOSIT SLIP\n";
m.mget();
b.bget();
}
};

int main()
{
int i,j,k,n,arr[100][2];
book b;
mem m;
trans t;
for(i=0;i<100;i++)
{arr[i][0]=i+1;
arr[i][1]=0;
}
while(1)
{
cout<<"\n\tLIBRARY MEMBERS\n1.WITHDRAW\n2.RETURN\n3.NO. OF BOOKS PRESENT FOR A STUDENT\n4.EXIT\n";
cin>>n;
switch(n)
{
case 1:
 m.mput();
b.bput();
k=m.rid();
for(i=0;i<100;i++)
{
if(arr[i][0]==k)
{arr[i][1]++;
break;
}
}
if(k<50)
{if(arr[i][1]>2)
{cout<<"NOT AVAILABLE";
}
else{
t.wit(m,b);
cout<<"\nNO OF BOOKS HE HAVE: "<<arr[i][1]<<endl;}}
else
{if(arr[i][1]>10)
{cout<<"NOT AVAILABLE";
}
else{
t.wit(m,b);
cout<<"\nNO OF BOOKS HE HAS: "<<arr[i][1]<<endl;}}

break;
case 2: m.mput();
b.bput();
k=m.rid();
for(i=0;i<100;i++)
{
if(arr[i][0]==k)
{arr[i][1]--;
break;
}
}
t.dep(m,b);
cout<<"NO OF BOOKS HE HAVE: "<<arr[i][1]<<endl;
break;
case 3:cout<<"GIVE THE MEMBER ID ";
cin>>j;
for(i=0;i<100;i++)
{
if(arr[i][0]==j)
{cout<<arr[i][1]<<endl;
}
}
case 4:return 0;

}
}
}
