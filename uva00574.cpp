#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int sum, num;
int list[100];
vector<int> result;
bool visited[1100];
map<vector<int>, bool> check;
int answer;

bool compare(int a, int b)
{
	return a > b;
}

void backtracking(int index, int current_sum)
{
	if (current_sum > sum)
		return;
	if (current_sum == sum)
	{
		if (check[result])
			return;
		++answer;
		check[result] = true;
		cout << result.at(0);
		for(int i = 1 ; i < result.size() ; ++i)
			cout << "+" << result.at(i);
		cout << endl;
	}
	for(int i = index ; i < num ; ++i)
	{
		if (visited[i])
			continue;
		if (list[i] > sum)
			continue;
		visited[i] = true;
		result.push_back(list[i]);
		backtracking(i + 1, current_sum + list[i]);
		result.pop_back();
		visited[i] = false;
	}
}

void reset()
{
	check.clear();
	answer = 0;
	memset(list, 0, sizeof(list));
	memset(visited, false, sizeof(visited));

}

int main()
{
	while(scanf("%d%d", &sum, &num))
	{
		if (sum == 0 && num == 0)
			break;
		reset();
		int buffer;
		for(int i = 0 ; i < num ; ++i)
		{
			scanf("%d", &buffer);
			list[i] = buffer;	
		}
		cout << "Sums of " << sum << ":" << endl;
		backtracking(0, 0);
		if (!answer)
			cout << "NONE" << endl;
	}
}
