#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

string way(int* arrSize, char** name, int number);
void findefile(string ans2, char ans3, char** name, int number);
void kilkist(char** name, int number, int* arrSize, string ans2);
void readallfile(char** name, int* size, int number, char** countryArr, long double** voteArr, string ans2);
long double konvert(char* ptr);
string findefileWin(char** name, int p);