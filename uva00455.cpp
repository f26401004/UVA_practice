#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string list;
int N;

void compare()
{
	int num = 0;
	for(int i = 1 ; i < list.size() + 1 ; ++i)
	{
		string target(list, 0, i);
		int j;
		for(j = 0; j < list.size() + 1 ; j += target.size())
		{
			if (list.compare(j, target.size(), target) != 0)
				break;
		}
		if (j == list.size())
		{
			num = i;
			break;
		}
	}
	cout << num << endl;
}

int main()
{
	cin >> N;
	for(int i = 0 ; i < N ; ++i)
	{
		if ( i != 0)
			cout << endl;
		cin >> list;
		compare();
	}	
	return 0;
}
