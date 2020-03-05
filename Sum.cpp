#include "Sum.hpp"

int** balfull(int** bal, int size)
{
    int a=2;
    for (int n = 0; n < size; n++)
    {
        bal[n]=new int [a];
    }
    for (int i = 0; i < size; i++)
	{
		bal[i][0] = 0; bal[i][1] = i;
	}
	return bal;
}

int** balserch(long int** voteArr, int size, int**bal) 
{
	for (int j = 0; j < size; j++)
	{
		for (int n = 0; n < 10; n++)
		{
			long int max = 0;
			for (int i = 0; i < size; i++)
			{
				if (max < voteArr[i][j]) { max = voteArr[i][j]; }
			}
			for (int i = 0; i < size; i++)
			{
				if (max == voteArr[i][j]) 
				{
					int num=0;
					if (n == 0) { num = 12; }
					if (n == 1) { num = 10; }
					if (n != 1 && n != 0) { num = 10 - n; }
					bal[i][0]=bal[i][0]+num; 
					voteArr[i][j] = 0;
                    break;
				}
			}
		}
	}
	return bal;
}

int** balsort(int** bal, int size)
{
	for (int j = 0; j < size; j++)
	{
		for (int i = 1; i < size; i++)
		{
			if (bal[i - 1][0] < bal[i][0])
			{
				int a = bal[i][0];
				bal[i][0] = bal[i - 1][0];
				bal[i - 1][0] = a;
				int b = bal[i][1];
				bal[i][1] = bal[i - 1][1];
				bal[i - 1][1] = b;
			}
		}
	}
	return bal;
}
