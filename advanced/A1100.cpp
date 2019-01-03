#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

string unitdigit[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string tendigit[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

string numtostr[170];
map<string, int> strtonum;

void init()
{
	for (int i = 0; i < 13; ++i)
	{
		numtostr[i] = unitdigit[i];
		strtonum[numtostr[i]] = i;
		numtostr[i * 13] = tendigit[i];
		strtonum[tendigit[i]] = i * 13;
	}

	for (int i = 1; i < 13; ++i)
	{
		for (int j = 1; j < 13; ++j)
		{
			string str = tendigit[i] + " " + unitdigit[j];
			numtostr[i * 13 + j] = str;
			strtonum[str] = i * 13 + j;
		}
	}
};

int main(void)
{
	init();
	int t;
	scanf("%d", &t);
	getchar();
	//cout << t << endl;
	while (t)
	{
		string str;
		getline(cin, str);
		//cout << str << endl;
		if (str[0] >= '0'&&str[0] <= '9')
		{
			int num = 0;
			for (int i = 0; i < str.length(); ++i)
			{
				num = num * 10 + str[i] - '0';
			}
			cout << numtostr[num] << endl;
		}
		else
		{
			cout << strtonum[str] << endl;
		}
		--t;
	}
	return 0;
}