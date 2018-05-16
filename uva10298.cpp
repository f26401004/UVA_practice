#include <iostream>
using namespace std;

string list;
int pi[1000005];

void fail()
{
	pi[0] = -1;
	for(int i = 1, cur_pos = -1 ; i < list.size() ; ++i)
	{
		while(cur_pos != -1 && list.at(i) != list.at(cur_pos + 1))
			cur_pos = pi[cur_pos];
		if (list.at(i) == list.at(cur_pos + 1))
			++cur_pos;
		pi[i] = cur_pos;
	}
}


int main()
{
	while(cin >> list)
	{
		if (list.compare(".") == 0)
			break;
		fail();
		if (list.size() % (list.size() - pi[list.size() - 1] - 1 ) == 0)
			cout << list.size() / (list.size() - pi[list.size() - 1] - 1) << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}
