#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int gys(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
		return gys(b, a % b);
};

void transarr(int a[], int k, int m, int n)//in array a,from k move m number
{
	int tmp = a[k];
	int now = k;
	int pernow;
	for (int i = 0; ; ++i)
	{
		pernow = now;
		now = now - m;
		if (now < 0)
		{
			now = now + n;
		}
		if (now == k)
		{
			break;
		}
		a[pernow] = a[now];
	}
	a[pernow] = tmp;
};

int main(void)
{
	int n, m;
	//cin >> n >> m;
	scanf("%d%d", &n, &m);
	int num[110];
	for (int i = 0; i < n; ++i)
	{
		//cin >> num[i];
		scanf("%d", num + i);
	}

    if(m>=n)
    {
        m = m % n;
    }
	int end = n - m + gys(n, m) - 1;

	for (int i = n - m; ;)
	{   
		transarr(num, i, m, n);
        if(i==end)
        {
            break;
        }
        ++i;
    }

	for (int i = 0; i < n; ++i)
	{
		printf("%d", num[i]);
		if (i != n - 1)
		{
			printf(" ");
		}
		else
			printf("\n");
	}

	//cin >> n;
	return 0;
}