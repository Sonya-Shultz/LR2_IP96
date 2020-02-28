
#include "Reedfrom.hpp"
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>


using namespace std;

void way(char* ans, int* arrSize, char** name);
void findefile( char* ans, string ans2, char ans3, char** name, int number );
void kilkist (char** name, int number, int* arrSize);
void readallfile(char** name, int* size, int number, char**countryArr, long int ** voteArr );
long int konvert(char* ptr);


void way( int* arrSize, char** name, int number)
{
    char *ans = new char [70];
    cout<<"ВВедіть повний шлях до тeки з файлами (приклад: ~/Download/laba/): \n";
    cin>>ans;
    string ans2;
    char ans3;
    cout<<"you os is windows? y/n\n";
    cin>>ans3;
    findefile (ans, ans2, ans3, name, number );
    kilkist (name, number, arrSize);
}

void readallfile(char** name, int* size, int number, char**countryArr, long int ** voteArr )
{
 int p=0;
 while (p<number)
 {
    ifstream nameFile;
     char* helpmas=new char [300];
    nameFile.open(name[p]);
     int riz=0;
     if (p==0){riz=0;}
     else {for (int x=0; x<p-1;x++){riz=riz+size[x];}}
     nameFile.getline( helpmas,4, '\n');
     for (int i=riz; i<size[p]+riz; i++)
    {
        nameFile.getline(countryArr[i+riz], 50, ',');
        cout<<endl<<countryArr[i]<<endl;
            nameFile>>helpmas;
            char *ptr=0;
            ptr=strtok(helpmas, ",\n");
            int j=0;
            while (ptr!=NULL)
            {
                voteArr[i+riz][j]= konvert(ptr);
                cout<<voteArr[i+riz][j]<<" ";
                ptr=strtok(0, ",\n");
                j++;
            }
            cout<<endl;
    }
    nameFile.close();
    p++;
 }
}

long int konvert(char* ptr)
{
    long int a=0;
    int i;
    i=0;
    while (ptr[i]!='\0')
    {int b= ptr[i] - 48;
        a=b+a*10;
        i++;
    }
    return a;
}

void findefile( char* ans, string ans2, char ans3, char** name, int number )
{
    if (ans3=='y' or ans3=='Y'){ans2+="dir";}
        else {ans2+="ls ";}
    ans2+=ans;
    if (ans3=='y' or ans3=='Y'){ans2+="\*.csv/B >NameOfAllFile.txt\n";}
    else {ans2+="/*.csv > NameOfAllFile.txt\n";}
    char*q = new char[100];
    int i=0;
    while (ans2[i]!='\n')
    {
        q[i]=ans2[i];
        i++;
    }
    system(q);
    int j=0;
    ifstream nameFile;
    nameFile.open("NameOfAllFile.txt");
    if (nameFile.is_open()){
    while (nameFile.peek()!=EOF)
    {
            nameFile>>name[j];
            j++;
    }}
    else {cout<<endl<<" gg "<<endl;}
}

void kilkist (char** name, int number, int* arrSize)
{
    for (int i=0; i<number; i++)
    {
        ifstream resultfile;
        resultfile.open(name[i]);
        resultfile>>arrSize[i];
        resultfile.close();
    }
}
