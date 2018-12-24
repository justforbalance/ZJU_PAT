#include<cstdio>
#include<algorithm>
#include <math.h>

using namespace std;

bool isprime(long long a)
{
	if (a <= 1)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(1.0 * a) + 1; ++i)
	{
		if (a%i == 0 && i != a)
		{
			return false;
		}
	}
	return true;
};

long long prime_factor[100];
int mi[100] = { 1 };

int main(void)
{
	long long n;
	scanf("%lld", &n);
	long long tmp = n;
	int factor_num = 0;
    if(n==1)
    {
        printf("1=1\n");
        return 0;
    }

	if (isprime(n))
	{
		printf("%lld=%lld\n", n, n);
		return 0;
	}
	else
	{
		for (long long i = 2; i < sqrt(1.0 * tmp) + 1; ++i)
		{
			if (isprime(i))
			{
				if (n%i == 0)
				{
					prime_factor[factor_num] = i;
					mi[factor_num] = 1;
					n = n / i;
					while (n%i == 0)
					{
						++mi[factor_num];
						n = n / i;
					}
					++factor_num;
				}
			}
			if (n == 1)
			{
				break;
			}
		}	
	}
	printf("%lld=", tmp);
	for (int i = 0; i < factor_num; ++i)
	{
		printf("%lld", prime_factor[i]);
		if (mi[i] > 1)
		{
			printf("^%d", mi[i]);
		}
		if (i != factor_num - 1)
		{
			printf("*");
		}
	}
	printf("\n");
	return 0;
}