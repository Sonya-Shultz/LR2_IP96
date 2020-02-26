#include <iostream>
#include <windows.h>
using namespace std;

int sizeSumm(int* tempArrSize, int tempNumb);
void timeAddArr(long int** timeArr, int timeSize);
void deleteBigArr(long int** tampleArr, int tempSize);

int main()
{
	

	int number=0; //кількість файлів .csv
	cin << number;
	int* arrSize = new int[number];
	
	size = sizeSumm(arrSize, number);
	cin << size;
	string* countryArr = new int[size];		//создание масива стран
	
	long int* voteArr;
	voteArr = new long int* [size];		// создание масива голосов
	timeAddArr(voteArr, size);

	int* pointArr = new int[size];		//создания масива для балов

	int marksArr[10];					// масив 10 топ стран

	deleteBigArr(voteArr, size);
	delete[] arrSize;
	delete[] coutryArr;
}

int sizeSumm(int* tempArrSize, int tempNumb) {
	int a = 0;
	int sum = 0;
	for (int i = 0; i < tempNumb; tempNumb++) {
		a = tempArrSize[i];
		sum = sum + a;
	}
	return sum;
}

void timeAddArr(long int** timeArr, int timeSize) {		//создание двумерного массива
	for (int i = 0; i < timeSize; i++) {
		timeArr[i] = new int[timeSize];
	}
}

void deleteBigArr(long int** tampleArr, int tempSize) {   //чистка
	for (int i = 0; i < tempSize; i++) {
		delete[] tampleArr[i];
	}
	delete[] tampleArr;
}



