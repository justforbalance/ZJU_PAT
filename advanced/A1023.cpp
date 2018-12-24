#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
struct bign
{
	int d[23];
	int len;
	bign()
	{
		memset(d, 0, sizeof(d));
		len = 0;
	}
} num1, num2;

bign char_to_bign(char s[])//高位存储在高位，低位存储在数组低位
{
	bign tmp;
	int k = strlen(s);
	tmp.len = k;
	for (int i = 0; i < tmp.len; ++i)
	{
		tmp.d[k - 1 - i] = int(s[i] - '0');
	}
	return tmp;
};

int main(void)
{
	int hashnum[13] = { 0 };
	char str[23];
	scanf("%s", str);
	num1 = char_to_bign(str);

	// for (int i = 0; i < num1.len; ++i)
	// {
	// 	printf("%d", num1.d[num1.len - 1 - i]);
	// }
	// printf("\n");

	int k = num1.len;
	for (int i = 0; i < k; ++i)
	{
		++hashnum[num1.d[i]];
	};

	//计算乘法；
	int tmp = 0;
	for (int i = 0; i < k; ++i)
	{
		tmp = tmp + 2 * num1.d[i];
		num2.d[i] = tmp % 10;
		tmp = tmp / 10;
	}
	num2.len = num1.len;
	if (tmp > 0)
	{
		++num2.len;
		num2.d[k] = tmp;
	}

	// for (int i = 0; i < num2.len; ++i)
	// {
	// 	printf("%d", num2.d[num2.len - 1 - i]);
	// }
	// printf("\n");

	bool flag = true;
	k = num2.len;
	for (int i = 0; i < k; ++i)
	{
		--hashnum[num2.d[i]];
		if (hashnum[num2.d[i]] < 0)
		{
			printf("No\n");
			flag = false;
			break;
		}
	}

	if (flag)
	{
		printf("Yes\n");
	}

	for (int i = 0; i < num2.len; ++i)
	{
		printf("%d", num2.d[num2.len - 1 - i]);
	}
	printf("\n");

	return 0;
}