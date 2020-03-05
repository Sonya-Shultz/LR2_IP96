#include <iostream>
#include <iomanip>

using namespace std;

void bublesort(int** tempMas, int tempRow);
void CreatMarkArr(long int** tempMas, long int** tempFirstArr, long int** tempMarkArr, int tempRow);
void markPoint(long double** tempMas, long int** tempFirstArr, int tempRow);
void deleteBigArrD(long double** tampleArr, int tempSize);
void showArr(long int** tempMas, int tempRow);
void zirroArr(long int** tempFirstArr, int tempRow);
void summBigArr(long int** tempMarks, int** tempPointArr, int tempSize);
void showSmallArr(int* tempPointArr, int tempRow);
void timeAddArr(int** tempResultArr, int tempSize);
void showArrD(long double** tempMas, int tempRow);
void deleteBigArr(long int** tampleArr, int tempSize);

void bublesort(int** tempMas, int tempRow) {
	
		for (int i = 0; i < tempRow - 1; i++) {
			for (int j = 0; j < tempRow - i - 1; j++) {
				if (tempMas[j][0] < tempMas[j + 1][0]) {
					// меняем элементы местами
					int temp0 = tempMas[j][0];
					tempMas[j][0] = tempMas[j + 1][0];
					tempMas[j + 1][0] = temp0;
					int temp1 = tempMas[j][1];
					tempMas[j][1] = tempMas[j + 1][1];
					tempMas[j + 1][1] = temp1;
				}
			}
		}
	
}

void showArrD(long double** tempMas, int tempRow) {
	for (int i = 0; i < tempRow; i++) {
		for (int j = 0; j < tempRow; j++) {
			cout <<setw(7) <<tempMas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void showArr(long int** tempMas, int tempRow) {
	for (int i = 0; i < tempRow; i++) {
		for (int j = 0; j < tempRow; j++) {
			cout << setw(6) << tempMas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void CreatMarkArr(long int** tempMas, long int** tempFirstArr, long int** tempMarkArr, int tempRow) {
	int mark = 12;
	for (int k = 0; k < tempRow; k++) {
		for (int i = 0; i < tempRow; i++) {
			for (int j = 0; j < tempRow; j++) {
				if (tempMas[k][i] == tempFirstArr[k][j]) { tempMarkArr[k][j] = mark; }
			}
			mark = mark - 2;
		}
	}
}

void markPoint(long double** tempMas, long int** tempFirstArr, int tempRow) {
	int a = tempMas[0][0];
	int numb = 0;
	int count = 10;
	for (int i = 0; i < tempRow; i++) {
		int mark = 10;

		for (int n = 0; n < count; n++) {
			a = tempMas[0][i];
			int max = 0;
			for (int j = 1; j < tempRow; j++) {
				if (a < tempMas[j][i]) { a = tempMas[j][i]; }
			}
			max = a;
			for (int j = 0; j < tempRow; j++) {
				if (tempMas[j][i] == max && n == 0) { tempFirstArr[j][i] = 12; tempMas[j][i] = 0; break; }
				if (tempMas[j][i] == max && n == 1) { tempFirstArr[j][i] = 10; tempMas[j][i] = 0; break; }
				if (tempMas[j][i] == max && n != 1 && n != 0) { tempFirstArr[j][i] = mark - n;  tempMas[j][i] = 0; break; }

			}

		}
	}
}

void deleteBigArrD(long double** tampleArr, int tempSize) {
	for (int i = 0; i < tempSize; i++) {
		delete[] tampleArr[i];
	}
	delete[] tampleArr;
}

void deleteBigArr(long int** tampleArr, int tempSize) {
	for (int i = 0; i < tempSize; i++) {
		delete[] tampleArr[i];
	}
	delete[] tampleArr;
}

void zirroArr(long int** tempFirstArr, int tempRow) {
	for (int i = 0; i < tempRow; i++) {
		for (int j = 0; j < tempRow; j++) {
			tempFirstArr[i][j] = 0;
		}
	}

}

void summBigArr(long int** tempMarks, int** tempResultArr, int tempSize) {
	int a, sum;
	sum = 0;
	for (int i = 0; i < tempSize; i++) {
		for (int j = 0; j < tempSize; j++) {
			a = tempMarks[i][j];
			sum = sum + a;
		}
		tempResultArr[i][0]= sum;
		sum = 0;
	}
}

void showSmallArr(int* tempPointArr, int tempRow) {
	for (int i = 0; i < tempRow; i++) {
		cout << tempPointArr[i] << " ";
	}
	cout << endl;
}

void timeAddArr(int** tempResultArr, int tempSize) {
	int two = 2;
	for (int i = 0; i < tempSize; i++) {
		tempResultArr[i] = new int[two];
	}
	for (int i = 0; i < tempSize; i++) {
		tempResultArr[i][0] = 0;
		tempResultArr[i][1] = i;
	}
}
