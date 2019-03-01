1.
    scanf的%c可以读取空格以及换行，然而%d是不会的，遇到就结束
    getchar可以识别换行
    %s不可以识别空格以及换行，遇到就会结束
    字符：a=getchar(),putchar(a)
    scanf("%c",&a)
    字符串：char a[10] scanf("%s",a) 
    gets(a)读取一行 
    string a,getline(cin,a)读取一行
2.最大公约数
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
    {
        return gcd(b, a % b);
    }
}
3.大数运算
    struct bign
    {
        int d[1000];
        int n;
        bign()
        {
            memset(d, 0, sizeof(d));
            n = 0;
        }
    };
4.
