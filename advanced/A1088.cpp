#include<cstdio>
#include<algorithm>
#include<math.h>
#include<iostream>

using namespace std;

long long gys(long long a, long long b)
{
	a = abs(a);
	b = abs(b);
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gys(b, a % b);
	}
};

struct fen
{
	long long son = 0;
	long long mother = 0;
} num1, num2;

fen stdform(fen a)//解决了分母为负数，分子为0以及分子分母有公约数的情况；
{
	fen res;
	if (a.son == 0)
	{
		res.son = 0;
		res.mother = 1;
		return res;
	}

	if (a.mother < 0)
	{
		a.mother *= (-1);
		a.son *= (-1);
	}

	long long up, down;
	up = a.son;
	down = a.mother;
	long long k = gys(up, down);
	up = up / k;
	down = down / k;
	res.son = up;
	res.mother = down;
	return res;
};

int show(fen a)
{
	if (a.son == 0)
	{
		printf("0");
		return 0;
	}

	if (a.son < 0)
	{
		printf("(-");
		long long leader = 0;
		a.son *= (-1);
		if (a.son >= a.mother)
		{
			leader = a.son / a.mother;
			a.son = a.son % a.mother;
		}

		if (leader != 0)
		{
			printf("%lld", leader);
		}
		if (a.son != 0)
		{
			if (leader != 0)
			{
				printf(" ");
			}
			printf("%lld/%lld)", a.son, a.mother);
			return 0;
		}
		else
		{
			printf(")");
			return 0;
		}
	}
	else
	{
		long long leader = 0;
		if (a.son >= a.mother)
		{
			leader = a.son / a.mother;
			a.son = a.son % a.mother;
		}

		if (leader != 0)
		{
			printf("%lld", leader);
		}
		if (a.son != 0)
		{
			if (leader != 0)
			{
				printf(" ");
			}
			printf("%lld/%lld", a.son, a.mother);
			return 0;
		}
		else
		{
			//printf("");
			return 0;
		}
	}
};

fen add(fen a, fen b)
{
	fen result;
	//long long up, down;
	result.son = a.son * b.mother + b.son * a.mother;
	result.mother = a.mother * b.mother;
	result = stdform(result);
	return result;
};

fen sub(fen a, fen b)
{
	b.son = -1 * b.son;
	b = stdform(b);
	return add(a, b);
};

fen multi(fen a, fen b)
{
	fen res;
	res.son = a.son * b.son;
	res.mother = a.mother * b.mother;
	return stdform(res);
};

fen divition(fen a, fen b)
{
	fen tmp;
	if (b.son != 0)
	{
		tmp.son = b.mother;
		tmp.mother = b.son;
		tmp = stdform(tmp);
	}
	return multi(a, tmp);
};

int main(void)
{
	scanf("%lld/%lld %lld/%lld", &num1.son, &num1.mother, &num2.son, &num2.mother);
	num1 = stdform(num1);
	num2 = stdform(num2);

	show(num1);
	printf(" + ");
	show(num2);
	printf(" = ");
	show(stdform(add(num1, num2)));
	printf("\n");

	show(num1);
	printf(" - ");
	show(num2);
	printf(" = ");
	show(stdform(sub(num1, num2)));
	printf("\n");

	show(num1);
	printf(" * ");
	show(num2);
	printf(" = ");
	if (num2.mother != 0)
	{
		show(stdform(multi(num1, num2)));
	}
	else
	{
		printf("Inf");
	}
	printf("\n");

	show(num1);
	printf(" / ");
	show(num2);
	printf(" = ");
	if (num2.son != 0)
	{
		show(stdform(divition(num1, num2)));
		printf("\n");
	}
	else
	{
		printf("Inf\n");
	}

	//  int n;
	//  cin >> n;
	return 0;
}

//2/3 -4/2
// 2/3 + (-2) = (-1 1/3)
// 2/3 - (-2) = 2 2/3
// 2/3 * (-2) = (-1 1/3)
// 2/3 / (-2) = (-1/3)