#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

int hashtable[30]={0};

using namespace std;

int main(void)
{
    /* string str;
    getline(cin,str); */
    string str;
    getline(cin, str);
    int len =str.length();
    for(int i=0;i<len;++i)
    {
        str[i]=tolower(str[i]);  
    }

    for(int i=0;i<len;++i)
    {
        if(islower(str[i]))
        {
            hashtable[str[i]-'a']++;
        }
    }

    int k=0;
    for(int i=0;i<26;++i)
    {
        if(hashtable[i]>hashtable[k])
        {
            k=i;
        }
    }

    printf("%c %d\n",'a'+k,hashtable[k]);
    return 0;
}