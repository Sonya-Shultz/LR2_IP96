#include <iostream>
using namespace std;

void bublesort(int** tempMas, int tempRow);
void CreatMarkArr(long int** tempMas, long int** tempFirstArr, long int** tempMarkArr, int tempRow);
void markPoint(long int** tempMas, long int** tempFirstArr, int tempRow);
void deleteBigArr(long int** tampleArr, int tempSize);
void showArr(long int** tempMas, int tempRow);
void zirroArr(long int** tempFirstArr, int tempRow);
void summBigArr(long int** tempMarks, int** tempPointArr, int tempSize);
void showSmallArr(int* tempPointArr, int tempRow);
void timeAddArr( int** tempResultArr, int tempSize);