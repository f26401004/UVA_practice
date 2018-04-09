#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int buffer, test_num = 1;
	vector<int> list;
	while(cin >> buffer)
	{
		if (buffer != -1)
			list.push_back(buffer);
		else
		{
			if (list.size() > 0)
			{
				if (test_num > 1)
					cout << endl;
				int LIS[list.size()];
				for(int i = 0 ; i < list.size() ; ++i)
				{
					LIS[i] = 1;
					for (int j = 0 ; j < i ; ++j)
					{
						if (list.at(j) >= list.at(i) && LIS[j] + 1 > LIS[i])
							LIS[i] = LIS[j] + 1;
					}
				}
				cout << "Test #" << test_num++ << ":" << endl;
				cout << "  maximum possible interceptions: " << *max_element(LIS, LIS + list.size()) << endl;
				list.clear();
			}
			else
				break;
		}
	}
	return 0;
}
