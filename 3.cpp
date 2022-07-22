#include<stdio.h>
#include<iostream.h> 
#include<fstream.h> 
#include<conio.h> 
#include<string.h> 
#include<stdlib.h> 
class student 
{ 
public: 
char name[20], usn[10], sem[10], branch[20], buffer[50]; 
public: 
void writerec( ); 
void displayrec( ); 
void searchrec( ); 
void modifyrec( ); 
}; 
void student :: writerec( ) 
{ 
fstream 
fp; 
student 
s; 
fp.open("stu2.txt", ios :: app); 
cout<<"\nEnter name"; 
cin>>s.name; 
cout<<"\nEnter usn"; 
cin>>s.usn; 
cout<<"\nEnter sem"; 
cin>>s.sem; 
cout<<"\nEnter branch"; 
cin>>s.branch; 
strcpy(s.buffer, s.name); 
strcat(s.buffer, "|"); 
strcat(s.buffer, s.usn); 
strcat(s.buffer, "|"); 
strcat(s.buffer, s.sem); 
strcat(s.buffer, "|"); 
strcat(s.buffer, s.branch);
strcat(s.buffer, "\n"); 
fp<<s.buffer; 
fp.close( ); 
} 
void student :: displayrec( ) 
{ 
int 
i; 
student 
s; 
fstream 
fp; 
fp.open("stu2.txt", ios :: in); 
i = 0; 
cout<<"Name\t\tUSN\t\tSem\t\tBranch\n"; 
while(!fp.eof( )) 
{ 
fp.getline(s.name, 20, '|'); 
fp.getline(s.usn, 10, '|'); 
fp.getline(s.sem, 10, '|'); 
fp.getline(s.branch, 20, '\n'); 
cout<<s.name<<"\t\t"<<s.usn<<"\t\t"<<s.sem<<"\t\t"<<s.branch; 
cout<<"\n"; 
i++; 
} 
fp.close( ); 
getch( ); 
} 
void student :: searchrec( ) 
{ 
fstream 
fp; 
student 
s; 
char reg[10], buff[50]; 
fp.open("stu2.txt", ios :: in); 
cout<<"\n Enter the USN of the record which is to be searched"; 
cin>>reg; 
while(!fp.eof( )) 
{ 
fp.getline(s.name, 20, '|'); 
fp.getline(s.usn, 10, '|');
fp.getline(s.sem, 10, '|'); 
fp.getline(s.branch, 20, '\n'); 
if(strcmp(s.usn, reg) = = 0) 
{ 
cout<<"\n Record Found"; 
cout<<"\n"<<s.name<<"\t\t"<<s.usn<<"\t\t"<<s.sem<<"\t\t"; 
cout<<s.branch; 
cout<<"\n"; 
getch( ); 
return; 
} 
} 
cout<<"\n Record not Found"; 
getch( ); 
return; 
} 
void student :: modifyrec( ) 
{ 
fstream 
fp; 
student 
s[20]; 
char reg[10]; 
char buff[50]; 
int 
i, j; 
fp.open("stu2.txt", ios :: in); 
cout<<"\nEnter the usn"; 
cin>>reg; 
i = 0; 
while(!fp.eof( )) 
{ 
fp.getline(s[i].name, 20, '|'); 
fp.getline(s[i].usn, 10, '|'); 
fp.getline(s[i].sem, 10, '|'); 
fp.getline(s[i].branch, 20, '\n'); 
i++; 
} 
i - -; 
for(j=0; j<i; j++) 
{ 
if(strcmp(reg, s[j].usn) = = 0)
{ 
cout<<"\n The old values of the record with usn"<<reg<<"are\n"; 
cout<<"\n Name="<<s[j].name; 
cout<<"\n USN="<<s[j].usn; 
cout<<"\n sem="<<s[j].sem; 
cout<<"\n Branch="<<s[j].branch; 
cout<<"\n Enter new values"; 
cout<<"\n Name="; cin>>s[j].name; 
cout<<"\n USN="; cin>>s[j].usn; 
cout<<"\n sem="; cin>>s[j].sem; 
cout<<"\n Branch="; cin>>s[j].branch; 
break; 
} 
} 
if(j = = i) 
{ 
cout<<"\n The record with usn"<<reg<<"is not present\n"; 
getch( ); 
return; 
} 
fp.close( ); 
fstream fp1; 
fp1.open("stu2.txt",ios::out); 
for(j=0; j<i; j++) 
{ 
// fp1<<s[j].name<<'|'<<s[j].usn<<'|'<<s[j].sem<<'|'<<s[j].branch<<'\n'; 
strcpy(buff, s[j].name); 
strcat(buff, "|"); 
strcat(buff, s[j].usn); 
strcat(buff, "|"); 
strcat(buff, s[j].sem); 
strcat(buff, "|"); 
strcat(buff,s[j].branch); 
strcat(buff, "\n"); 
fp1<<buff; 
} 
fp1.close( ); 
} 
void main( ) 
{
fstream fp; 
int 
ch; 
student 
s; 
fp.open("stu2.txt", ios :: out); 
fp.close( ); 
for(;;) 
{ 
clrscr( ); 
cout<<"\n 1. write record"; 
cout<<"\n 2. display record"; 
cout<<"\n 3. search record"; 
cout<<"\n 4. modify record"; 
cout<<"\n 5. exit"; 
cout<<"\n Enter your choice"; 
cin>>ch; 
switch(ch) 
{ 
case 1: s.writerec( ); 
break; 
case 2: s.displayrec( ); 
break; 
case 3: s.searchrec( ); 
break; 
case 4: s.modifyrec( ); 
break; 
case 5: exit(0); 
break; 
} 
} 
} 
