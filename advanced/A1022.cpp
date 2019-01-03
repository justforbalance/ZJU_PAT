#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include <set>

using namespace std;

map<string, set<int>> ttitle, tauthor, tkey, tpublisher, tyear;

void query(map<string, set<int>>& mp, string& str)
{
	if (mp.find(str) != mp.end())
	{
		for (set<int>::iterator it = mp[str].begin(); it != mp[str].end(); ++it)
		{
			printf("%07d\n", *it);
		}
	}
	else
	{
		printf("Not Found\n");
	}
}

int main(void)
{
	int n;
	int id;
	string title, author, key, publisher, year;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &id);
		char c = getchar();
		getline(cin, title);
		ttitle[title].insert(id);
		getline(cin, author);
		tauthor[author].insert(id);
		while (cin >> key)
		{
			tkey[key].insert(id);
			c = getchar();
			if (c == '\n')
			{
				break;
			}
		}
		getline(cin, publisher);
		tpublisher[publisher].insert(id);
		getline(cin, year);
		tyear[year].insert(id);
	}

	int m;
	scanf("%d", &m);
	int k;
	string queryname;

	for (int i = 0; i < m; ++i)
	{
		scanf("%d: ", &k);
		getline(cin, queryname);
		//printf("%d: %s\n", k, queryname);
		cout << k << ": " << queryname << endl;

		if (k == 1)
		{
			query(ttitle, queryname);
		}
		else if (k == 2)
		{
			query(tauthor, queryname);
		}
		else if (k == 3)
		{
			query(tkey, queryname);
		}
		else if (k == 4)
		{
			query(tpublisher, queryname);
		}
		else if (k == 5)
		{
			query(tyear, queryname);
		}
	}
	return 0;
}