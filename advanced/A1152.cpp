#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>

using namespace std;

bool isprime(long long a)
{
  if(a<=0)
  {
    return false;
  }
	if (a == 2 || a == 3 || a == 5||a == 7)
	{
		return true;
	}

  if(a==1)
  {
    return false;
  }
  
	if (a % 2 == 0)
	{
		return false;
	}

	for (int i = 3; i <= sqrt(a); ++i)
	{
		if (a%i == 0)
		{
			return false;
		}
	}

	return true;
};

int main(void)
{
	int n, l;
	//scanf("%d%d", &n, &l);
	cin >> n >> l;
	char str[1010];
	long long judge = 0;

	for (int i = 0; i<n; ++i)
	{
		//scanf("%c", &char[i]);
		cin >> str[i];
	}

	for (int i = 0; i<n + 1 - l; ++i)
	{
		judge = 0;
		for (int j = i; j<i + l; ++j)
		{
			judge = 10 * judge + int(str[j] - '0');
		}

		if (isprime(judge))
		{
			//printf("lld", judge);
            for(int j=i;j<i+l;++j)
            {
                cout << str[j];
            }
			//cin >> n;
			return 0;
		}
	}

	//printf("404\n");
	cout << "404" << endl;
	//cin >> n;
	return 0;
}