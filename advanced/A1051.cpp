#include<cstdio>
#include<iostream>
#include<stack>

using namespace std;

int main(void)
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	int check[1010];


	for (int i = 0; i < k; ++i)
	{
		bool flag = true;
		stack<int> num;

		for (int j = 0; j < m; ++j)
		{
			scanf("%d", check + j);
		}

		int size = 0;
		//int current = 0;
		int pushnum = 1;

		for (int j = 0; j < m; ++j)
		{
			if (num.size() == 0)
			{
				num.push(pushnum);
				++pushnum;
				++size;
			}
			while (num.top() != check[j] && pushnum <= m && size < n)
			{
				num.push(pushnum);
				++pushnum;
				++size;
			}
			if (num.top() == check[j])
			{
				num.pop();
				--size;
			}
			else {
				printf("NO\n");
				flag = false;
				break;
			}
		}
		if (flag)
		{
			printf("YES\n");
		}
	}

	return 0;
}