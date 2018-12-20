#include<cstdio>
#include<algorithm>

using namespace std;

int main(void)
{
    int n;
    double arr=0;
    double total = 0;
    scanf("%d", &n);
    for (int i = 0; i < n;++i)
    {
        scanf("%lf",&arr);
        //total += arr * ((i + 1) * (n - i));
        total += arr * (i + 1) * (n - i);//上面的写法是错误的，因为i+1与n-i的乘积会超出int的范围
    }
    printf("%.2f\n", total);
    return 0;
}