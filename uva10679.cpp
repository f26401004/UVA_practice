#include <iostream>
#include <cstring>
using namespace std;

string str;
string target;
int pi[100005];

void fail()
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
	cin >> k;
	while(k--)
	{
		int q;
		cin >> str;
		cin >> q;
		while(q--)
		{
			cin >> target;
			fail();
			bool flag = false;
			for(int i = 0, cur_pos = -1 ; i < str.size() ; ++i)
			{
				while(cur_pos != -1 && str.at(i) != target.at(cur_pos + 1))
					cur_pos = pi[cur_pos];
				if(str.at(i) == target.at(cur_pos + 1))
					++cur_pos;
				if (cur_pos + 1 == target.size())
				{
					flag = true;
					break;
				}
			}
			if (flag)
				cout << "y" << endl;
			else
				cout << "n" << endl;
		}
	}
	return 0;
}
