#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

int main(void)
{
    string str1;
    string str2;
    bool hashtable[200]={false};
    getline(cin,str1);
    getline(cin,str2);

    int len1=str1.length();
    int len2=str2.length();

    for(int i=0;i<len2;++i)
    {
        hashtable[str2[i]]=true;
    }

    for(int i=0;i<len1;++i)
    {
        if(!hashtable[str1[i]])
        {
            printf("%c",str1[i]);
        }
    }

    return 0;

}