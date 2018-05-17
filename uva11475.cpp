#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string target;
string target_r;
int pi[100005];

void fail()
{
	memset(pi, 0, sizeof(pi));
	pi[0] = -1;
	for(int i = 1, cur_pos = -1 ; i < target_r.size() ; ++i)
	{
		while(cur_pos != -1 && target_r.at(i) != target_r.at(cur_pos + 1))
			cur_pos = pi[cur_pos];
		if (target_r.at(i) == target_r.at(cur_pos + 1))
			++cur_pos;
		pi[i] = cur_pos;
	}
}

int main()
{
	while(cin >> target)
	{
		target_r = target;
		reverse(target_r.begin(), target_r.end());
		fail();
		int cur_pos = -1;
		for(int i = 0; i < target.size() ; ++i)
		{
			while(cur_pos != -1 && target.at(i) != target_r.at(cur_pos + 1))
				cur_pos = pi[cur_pos];
			if (target.at(i) == target_r.at(cur_pos + 1))
				++cur_pos;
		}
		cout << target <<target_r.substr(cur_pos + 1, target_r.size()) << endl;
	}
	return 0;
}
