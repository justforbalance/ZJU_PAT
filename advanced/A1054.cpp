#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

map<int, int> num;

int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);
	int maxnum = 0;
	int maxcolor = 0;
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &tmp);
			if (num.find(tmp) != num.end())
			{
				++num[tmp];
			}
			else {
				num[tmp] = 1;
			}
			if (num[tmp] > maxnum)
			{
				maxnum = num[tmp];
				maxcolor = tmp;
			}
		}
	}
	cout << maxcolor << endl;
	return 0;
}