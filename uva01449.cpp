#include <iostream>
#include <cstring>
using namespace std;

string str;
string targets[155];
int count[155];
int pi[100005];

void fail(string target)
{
	memset(pi, 0, sizeof(pi));
	pi[0] = -1;
	for(int i = 1, cur_pos = -1 ; i < target.size() ; ++i)
	{
		while(cur_pos != -1 && target.at(i) != target.at(cur_pos + 1))
			cur_pos = pi[cur_pos];
		if (target.at(i) == target.at(cur_pos + 1))
			++cur_pos;
		pi[i] = cur_pos;
	}
}

int main()
{
	int k;
	while(cin >> k)
	{
		memset(count, 0, sizeof(count));
		if (k == 0)
			break;
		for(int i = 0 ; i < k ; ++i)
			cin >> targets[i];
		cin >> str;
		for(int i = 0 ; i < k ; ++i)
		{
			fail(targets[i]);
			for(int j = 0, cur_pos = -1 ; j < str.size() ; ++j)
			{
				while(cur_pos != -1 && str.at(j) != targets[i].at(cur_pos + 1))
					cur_pos = pi[cur_pos];
				if(str.at(j) == targets[i].at(cur_pos + 1))
					++cur_pos;
				if (cur_pos + 1 == targets[i].size())
				{
					count[i]++;
					cur_pos = pi[cur_pos];
				}
			}
		}
		int max_index = 0;
		int max_value = 0;
		for(int i = 0 ; i < k ; ++i)
		{
			if (max_value < count[i])
			{
				max_value = count[i];
				max_index = i;
			}
		}
		cout << max_value << endl;
		for(int i = 0 ; i < k ; ++i)
			if (count[i] == max_value)
				cout << targets[i] << endl;
	}
	return 0;
}
