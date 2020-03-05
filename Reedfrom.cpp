


#include "Reedfrom.hpp"


void way( int* arrSize, char** name, int number)
{
    //char *ans = new char [70];
    string ans;
    cout<<"ВВедіть повний шлях до тeки з файлами (приклад: ~/Download/laba/): \n";
    cin>>ans;
    string ans2;
    char ans3;
    cout<<"you os is windows? y/n\n";
    cin>>ans3;
    findefile (ans, ans2, ans3, name, number );
    kilkist (name, number, arrSize);
}

void readallfile(char** name, int* size, int number, char** countryArr, long int** voteArr, string ans2)
{
    int p = 0;
    while (p < number)
    {
        string q = ans2;
        q += name[p];
        char*mastemp=new char[100];
        ifstream nameFile;
        char* helpmas = new char[300];
        nameFile.open(q);
        int riz = 0;
        if (p == 0) { riz = 0; }
        else { for (int x = 0; x < p ; x++) { riz = riz + size[x]; } }
        nameFile.getline(helpmas, 4, '\n');
        for (int i =0; i < size[p] ; i++)
        {
            char h;
            nameFile.get(h);
            if (h=='"'){nameFile.getline(countryArr[i + riz], 50, '"'); nameFile.get(h);}
            else
            {nameFile.getline(mastemp, 49, ',');
                int d=0;
                countryArr[i+riz][0]=h;
                while(mastemp[d]!='\0'){countryArr[i+riz][d+1]=mastemp[d];d++; }}
            std::cout <<countryArr[i+riz] << endl;
            nameFile >> helpmas;
            char* ptr = 0;
            ptr = strtok(helpmas, ",\n");
            int j = 0;
            while (ptr != NULL)
            {
                voteArr[i + riz][j] = konvert(ptr);
                ptr = strtok(0, ",\n");
                j++;
            }
            nameFile.get(h);
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

void findefile( string ans, string ans2, char ans3, char** name, int number )
{
    ans2="ls ";
    ans2+=ans;
    ans2+="/*.csv > NameOfAllFile.txt\n";
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
