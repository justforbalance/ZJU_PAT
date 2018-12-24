#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>

using namespace std;

struct bign
{
	int d[1010];
	int len;
	bign()
	{
		memset(d, 0, sizeof(d));
		len = 0;
	}
}a, c;

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
	int b;
	char str[1010];
	scanf("%s %d", str, &b);
	int len = strlen(str);
	a = char_to_bign(str);
	c.len = a.len;
	//接下来求解a/b,即c
	int tmp = 0;
	int k = a.len;
	for (int i = 0; i < a.len; ++i)
	{
		tmp = tmp * 10 + a.d[k - 1 - i];
		c.d[k - 1 - i] = tmp / b;
		tmp = tmp % b;
	}
	bool flag = true;//bool is used to 过滤高位的0；
	for (int i = 0; i < c.len; ++i)
	{
		if (c.d[k-i-1] == 0 && flag)
		{
			continue;
		}
		flag = false;
		printf("%d", c.d[k - i - 1]);
		if (i == c.len - 1)
		{
			printf(" ");
		}
	}

	if (flag)//如果此时flag仍旧为true，说明结果的商为0，需要输出一个0；
	{
		printf("0 ");
	}
	printf("%d\n", tmp);
	return 0;
}