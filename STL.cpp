#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include <stack>
#include<pair>
#include <algorithm>

using namespace std

vector
{
    vector<int> num;
    vector<vector<int>> num1;
    vector<int> a[6];

    vector<int>::iterator it=num.begin();
    en = num.end();
    num.push_back();
    num.pop_back();
    num.size();
    num.clear();
    num.insert(it + 2, 2);支持迭代器直接加数字
    num.erase(it + 2);
    num.erase(it + 2, it + 4);
}

set//自动递增不重复排序
{
    set<int> a;
    a.begin();
    a.end();
    a.insert(2);
    set<int>::iterator st = a.find(2);//不支持迭代器直接加数字
    a.erase();
    a.size();
    a.clear();
}

string//输入输出只能用cin,cout，支持迭代器直接加数字
{
    string s1, s2;
    s1 = s2;
    s1 < s2;
    s1.length();
    s2.size();
    s1.insert();
    s1.erase();
    s1.clear();
    s1.substr();
    s1.find();
    s1.replace();
}

map//map创建字符串映射只可以使用string，first is key,and second is value
{
    map<string, int> mp;
    mp["ad"] = 20;
    map<string, int>::iterator it = mp.begin();
    it->first;
    it->second;
    it = mp.find("ab");
    mp.size();
    mp.erase("ab");
    mp.erase(it);
    mp.clear();
}

queue
{
    queue<int> q;
    q.front();
    q.push();
    q.back();
    q.pop();
    q.empty();
    q.size();
}

priority_queue//默认是大的数字在前面
{
    priority_queue<int> q;
    q.push();
    q.top();
    q.pop();
    q.empty();
    q.size();
    priority_queue<int, vector<int>, less<int>> q;//less 表示优先级大的是数值大的，greater表示相反
    //结构体的优先级设置

    struct fruit
    {
        strinf name;
        int price;
        friend bool operator < (fruit f1,fruit f2)//不可以重载大于号>
        {
            return f1.price < f2.price;
        }
    } 
    priority_queue<fruit> f;
}

stack
{
    
}
