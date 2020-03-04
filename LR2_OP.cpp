// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>

using namespace std;
#include "Header.h"
#include "Reedfrom.hpp"
#include "OutPut.hpp"

int sizeSmallSumm(int* tempArrSize, int tempNumb);
void timeAddArr(long int** timeArr, int timeSize);
void timeAddChar(char** timeArr, int number);

int main()
{

	string ans2;
	int number = 0; 
	cout << "Number of file: ";
	cin >> number;
	char** name = new char* [number];		//number of file
	timeAddChar(name, number);
	int* arrSize = new int[number];		
	int size;
	ans2=way(arrSize, name, number);
	size = sizeSmallSumm(arrSize, number);
	cout << size;

	char** countryArr = new char* [size];		// Arr of country
	timeAddChar(countryArr, size);

	long int** voteArr = new long int* [size];		// Arr with number of vote
	timeAddArr(voteArr, size);
	readallfile(name, arrSize, number, countryArr, voteArr, ans2);
	showArr(voteArr, size);

	

	int** resultArr = new int* [size];	 // the sum of marks
	timeAddArr(resultArr, size);

	int marksArr[10];			

	long int** markArr = new long int* [size];		//Arr with marks
	for (int i = 0; i < size; i++) { markArr[i] = new long int[size]; }

	long int** firstArr = new long int* [size];			//Arr too safe first data
	for (int i = 0; i < size; i++) { firstArr[i] = new long int[size]; }

	zirroArr(firstArr, size);
	markPoint(voteArr, firstArr, size);
	showArr(firstArr, size);
	summBigArr(firstArr, resultArr, size);
	bublesort(resultArr, size);
	result(resultArr, countryArr);
	

	deleteBigArr(voteArr, size);
	deleteBigArr(firstArr, size);
	deleteBigArr(markArr, size);
	delete[] arrSize;
	delete[] countryArr;
}

int sizeSmallSumm(int* tempArrSize, int tempNumb) {
	int a = 0;
	int sum = 0;
	for (int i = 0; i < tempNumb; i++) {
		a = tempArrSize[i];
		sum = sum + a;
	}
	return sum;
}

void timeAddArr(long int** timeArr, int timeSize) {		
	for (int i = 0; i < timeSize; i++) {
		timeArr[i] = new long int[timeSize];
	}
}

void timeAddChar(char** timeArr, int number) {
	for (int i = 0; i < number; i++) {
		timeArr[i] = new char[50];
	}
}

