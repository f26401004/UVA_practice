#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

string str[10000];
bool visited[26] = {0};
stack<char> result;
vector<int> adjacent[26];

void DFS(int i)
{
	visited[i] = true;
	for(int j = 0 ; j < adjacent[i].size() ; ++j)
	{
		if (!visited[adjacent[i].at(j)])
			DFS(adjacent[i].at(j));
	}
	result.push((char)(i +  'A'));
}


int main()
{
	int num = 0;
	memset(visited, false, sizeof(visited));
	while(cin >> str[num])
	{
		if(str[num].compare("#") == 0)
			break;
		++num;
	}
	for(int i = 1 ; i < num ; ++i)
	{
		for(int j = 0 ; j < str[i-1].size() && j < str[i].size() ; ++j)
			if (str[i - 1].at(j) != str[i].at(j))
			{
				adjacent[str[i-1].at(j) - 'A'].push_back(str[i].at(j) - 'A');
				break;
			}
	}
	for(int i = 0 ; i < 26 ; ++i)
	{
		if (!visited[i] && adjacent[i].size() > 0)
			DFS(i);	
	}
	while(!result.empty())
	{
		cout << result.top();
		result.pop();
	}
	cout << endl;
	return 0;
}
