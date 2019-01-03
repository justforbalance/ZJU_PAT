#include<cstdio>
#include<iostream>
#include <string>
#include<map>

using namespace std;

map<string,int> total;

bool isuseful(char c)
{
	if (c >= 'a'&&c <= 'z')
	{
		return true;
	}
	if (c >= '0'&&c <= '9')
	{
		return true;
	}
	if (c >= 'A'&&c <= 'Z')
	{
		return true;
	}
	return false;
}

int main(void)
{
	string str;
	getline(cin, str);
	int i;
	while (i < str.length())
	{
		string word;
		while (isuseful(str[i]) && i < str.length())
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
			{
				str[i] += 32;
			}
			word += str[i];
			++i;
		}

		if (word != "")
		{
			if (total.find(word) != total.end())
			{
				++total[word];
			}
			else
			{
				total[word] = 1;
			}
		}

		while (i < str.length() && (isuseful(str[i] == false)))
		{
			++i
		}
	}

	string ans;
	int maxnum = 0;
	for (map<string, int>::iterator it = total.begin(); it != total.end(); ++it)
	{
		if (it->second > maxnum)
		{
			maxnum = it->second;
			ans = it->first;
		}
	}

	cout << ans << " " << maxnum << endl;
	return 0;
}