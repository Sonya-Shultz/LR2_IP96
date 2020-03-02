#include "Reedfrom.hpp"
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <Windows.h>


using namespace std;

string way(int* arrSize, char** name, int number);
void findefile( string ans2, char ans3, char** name, int number);
void kilkist(char** name, int number, int* arrSize, string ans2);
void readallfile(char** name, int* size, int number, char** countryArr, long int** voteArr, string ans2);
long int konvert(char* ptr);
string findefileWin(char** name, int p);

string way(int* arrSize, char** name, int number)
{
	string ans2;
	char ans3;
	std::cout << "you os is windows? y/n\n";
	cin >> ans3;
	if (ans3 == 'Y' or ans3 == 'y') { ans2=findefileWin(name, number); }
	else { findefile( ans2, ans3, name, number); }
	kilkist(name, number, arrSize, ans2);
	return ans2;
}

void readallfile(char** name, int* size, int number, char** countryArr, long int** voteArr, string ans2)
{
	int p = 0;
	while (p < number)
	{
		string q = ans2;
		q += name[p];
		ifstream nameFile;
		char* helpmas = new char[300];
		nameFile.open(q);
		int riz = 0;
		if (p == 0) { riz = 0; }
		else { for (int x = 0; x < p - 1; x++) { riz = riz + size[x]; } }
		nameFile.getline(helpmas, 4, '\n');
		for (int i = riz; i < size[p] + riz; i++)
		{
			nameFile.getline(countryArr[i + riz], 50, ',');
			std::cout << endl << countryArr[i] << endl;
			nameFile >> helpmas;
			char* ptr = 0;
			char* context = NULL;
			ptr = strtok_s(helpmas, ",\n",&context);
			int j = 0;
			while (ptr != NULL)
			{
				voteArr[i + riz][j] = konvert(ptr);
				std::cout << voteArr[i + riz][j] << " ";
				ptr = strtok_s(0, ",\n",&context);
				j++;
			}
			std::cout << endl;
		}
		nameFile.close();
		p++;
	}
}

long int konvert(char* ptr)
{
	long int a = 0;
	int i;
	i = 0;
	while (ptr[i] != '\0')
	{
		int b = ptr[i] - 48;
		a = b + a * 10;
		i++;
	}
	return a;
}

void findefile( string ans2, char ans3, char** name, int number)
{
	std::cout << "ВВедіть повний шлях до тeки з файлами (приклад: ~/Download/laba/): \n";
	char* ans = new char[70];
	cin >> ans;
	ans2 += "ls ";
	ans2 += ans;
	ans2 += "/*.csv > NameOfAllFile.txt"; 
	char* q = new char[100];
	int i = 0;
	while (ans2[i] != '\n')
	{
		q[i] = ans2[i];
		i++;
	} 
	system(q); 
	int j = 0;
	ifstream nameFile;
	nameFile.open("NameOfAllFile.txt");
	if (nameFile.is_open()) {
		while (nameFile.peek() != EOF)
		{
			nameFile >> name[j];
			j++;
		}
	}
	else { std::cout << endl << " gg " << endl; }
	nameFile.close();
	cout << "banana";
}

string findefileWin(char** name, int p )
{
	WIN32_FIND_DATA FindFileData;
	FILE* nameoffile;
	fopen_s(&nameoffile, "NameOfAllFile.txt", "w+");
	HANDLE hf;
	string q1, q3 /*= "C:\\Users\\Schulz\\Desktop\\*.csv"*/;
	cout << "Enter a way to file (C:\\Users\\Schulz\\Desktop\\)";
	cin >> q1;
	q3 = q1;
	q1 += "*.csv";
	wstring a = wstring(q1.begin(), q1.end());
	LPCWSTR sw = a.c_str();
	hf = FindFirstFile(sw, &FindFileData);
	if (hf != INVALID_HANDLE_VALUE)
	{
		do { fprintf(nameoffile, "%ws \0", FindFileData.cFileName);
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
	fclose(nameoffile);
	ifstream nameFile;
	nameFile.open("NameOfAllFile.txt");
	string q4;
	if (nameFile.is_open()) {
		for (int j=0; j<p; j++)
		{
			nameFile >> q4;
			for (int i=0;i<q4.size()+1;i++)
			{
				name[j][i] = q4[i];
			}
		}
	}
	else { std::cout << endl << " gg " << endl; }
	nameFile.close();
	return q3;
}

void kilkist(char** name, int number, int* arrSize, string ans2)
{
	string q=" ", q1;
	for (int i = 0; i < number; i++)
	{
		q = ans2;
		ifstream resultfile;
		q += name[i];
		resultfile.open(q);
		resultfile >> q1;
		int j = 0;
		arrSize[i] = 0;
		while (q1[j] != '\0')
		{
			arrSize[i] = ((int)q1[j] - 48)+arrSize[i]*10;
			j++;
		}
		resultfile.close();
	}
}