#include<cstdio>
#include<algorithm>
#include<math.h>

using namespace std;
//int hashnum[10010] = {0};
bool hashtable[10010] = { false };

bool isprime(int a)
{
	if (a <= 1)
	{
		return false;
	}
	else
		for (int i = 2; i <= int(sqrt(1.0 * a)); ++i)
		{
			if (a%i == 0)
			{
				return false;
			}
		}
	return true;
};

int hashfc(int a, int t)
{
	return a % t;
}

int main(void)
{
	int m, n;//n<m
	scanf("%d%d", &m, &n);
	int Tsize = m;
	for (int i = 0;; ++i)
	{
		if (isprime(Tsize))
		{
			break;
		}
		++Tsize;
	}

	int tmp;
	for (int i = 0; i < n ; ++i)
	{
		int loc = -1;
		scanf("%d", &tmp);
		loc = hashfc(tmp, Tsize);
		if (hashtable[loc] == false)
		{
			//hashnum[loc] = tmp;
			hashtable[loc] = true;
			printf("%d", loc);
		}
		else
		{
			int k =0 ;
			for (int j = 1; j <= Tsize; ++j)
			{
				k = hashfc(tmp + j * j, Tsize);
				if (hashtable[k] == false)
				{
					hashtable[k] = true;
					//hashnum[k] = tmp;
					printf("%d", k);
					break;
				}
				if (j == Tsize)
				{
					printf("-");
				}
			}
		}
		if (i < n - 1)
		{
			printf(" ");
		}
	}

	return 0;
}