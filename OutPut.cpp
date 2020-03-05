
#include "OutPut.hpp"


string oneryad(int** balisort, char** name, int i, string ans)
{
    ans='"'; ans+=name[balisort[i][1]]; ans+='"';
	ans += ",";
	return ans;
}

void result(int** balisort, char** name)
{
	string ans;
	ofstream outPut;
	outPut.open("result.csv");
	if (outPut.is_open())
	{
		int n = 10;
		for (int i = 0; i < n; i++)
		{
			ans = oneryad( balisort, name, i, ans);
			outPut << ans<< balisort[i][0]<<'\n';
		}
	}
	else { cout << "Something wrong with file!"; }
}
