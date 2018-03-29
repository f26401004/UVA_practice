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
vector<int> answer;
bool visited[1100];
map<vector<int>, bool> check;
bool flag = false;
int max_sum;


bool compare(int a, int b)
{
	return a > b;
}

void backtracking(int index, int current_sum)
{
	if (current_sum > sum)
		return;
	if (flag)
		return;
	if (current_sum == sum)
	{
		flag = true;
		cout << result.at(0);
		for (int i = 1 ; i < result.size() ; ++i)
			cout << " " << result.at(i);
		cout << " sum:" << sum << endl;
		return;
	}
	if (current_sum > max_sum)
	{
		if (check[result])
			return;
		max_sum = 0;
		check[result] = true;
		answer.clear();
		for (int i = 0 ; i < result.size() ; ++i)
		{
			answer.push_back(result.at(i));
			max_sum = max_sum + result.at(i);
		}
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
	answer.clear();
	memset(list, 0, sizeof(list));
	memset(visited, false, sizeof(visited));
	max_sum = 0;
	flag = false;
}

int main()
{
	while(cin >> sum >> num)
	{
		if (sum == 0 && num == 0)
			break;
		reset();
		int buffer;
		for(int i = 0 ; i < num ; ++i)
		{
			cin >> buffer;
			list[i] = buffer;	
		}
		backtracking(0, 0);
		if (flag == false)
		{
			cout << answer.at(0);
			for(int i = 1 ; i < answer.size() ; ++i)
				cout << " " << answer.at(i);
			cout << " sum:" << max_sum << endl;
		}
	}
}
