#include<cstdio>
#include<algorithm>
#include <math.h>

using namespace std;

int main(void)
{
	long long n;
	int maxlen = 0;
	int minnum = 0;
	long long multitmp = 1;
	scanf("%lld", &n);
	for (int i = 2; i <= sqrt(1.0*n) + 1; ++i)
	{
		//int tmplen = 0;
		if (maxlen == 0 && n%i == 0)
		{
			maxlen = 1;
			minnum = i;
		}
		//int tmp = n;
		multitmp = i;
		int j = 1;
		while (n%multitmp == 0)
		{
			multitmp *= (i + j);
			++j;
		}
		if (j-1 > maxlen)
		{
			maxlen = j-1;
			minnum = i;
		}
	}

	if (maxlen == 0)//考虑n为质数的情况下，此时得到的结果为maxlen=0，因此需要将这种情况加进去
	{
		maxlen = 1;
		minnum = n;
	}
	printf("%d\n", maxlen);
	for (int i = 0; i < maxlen; ++i)
	{
		printf("%d", minnum + i);
		if (i != maxlen - 1)
		{
			printf("*");
		}
	}
	return 0;
}