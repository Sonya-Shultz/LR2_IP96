// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
//#include <windows.h>
using namespace std;

#include "Reedfrom.hpp"

int sizeSumm(int* tempArrSize, int tempNumb);
void timeAddArr(long int** timeArr, int timeSize);
void deleteBigArr(long int** tampleArr, int tempSize);
void timeAddChar(char** timeArr, int number);

int main()
{

	string ans2;
	int number = 0; //ê³ëüê³ñòü ôàéë³â .csv
	cin >> number;
	char** name = new char* [number];
	timeAddChar(name, number);
	int* arrSize = new int[number];
	int size;
	ans2=way(arrSize, name, number);
	size = sizeSumm(arrSize, number);
	cout << size;
	char** countryArr = new char* [size];		//ñîçäàíèå ìàñèâà ñòðàí
	timeAddChar(countryArr, size);

	long int** voteArr = new long int* [size];		// ñîçäàíèå ìàñèâà ãîëîñîâ
	timeAddArr(voteArr, size);

	readallfile(name, arrSize, number, countryArr, voteArr, ans2);

	int* pointArr = new int[size];		//ñîçäàíèÿ ìàñèâà äëÿ áàëîâ

	int marksArr[10];					// ìàñèâ 10 òîï ñòðàí

	deleteBigArr(voteArr, size);
	delete[] arrSize;
	delete[] countryArr;
}

int sizeSumm(int* tempArrSize, int tempNumb) {
	int a = 0;
	int sum = 0;
	for (int i = 0; i < tempNumb; i++) {
		a = tempArrSize[i];
		sum = sum + a;
	}
	return sum;
}

void timeAddArr(long int** timeArr, int timeSize) {		//ñîçäàíèå äâóìåðíîãî ìàññèâà
	for (int i = 0; i < timeSize; i++) {
		timeArr[i] = new long int[timeSize];
	}
}

void timeAddChar(char** timeArr, int number) {
	for (int i = 0; i < number; i++) {
		timeArr[i] = new char[50];
	}
}

void deleteBigArr(long int** tampleArr, int tempSize) {   //÷èñòêà
	for (int i = 0; i < tempSize; i++) {
		delete[] tampleArr[i];
	}
	delete[] tampleArr;
}