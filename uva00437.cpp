#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
	if (a.at(0) == b.at(0))
		return a.at(1) < b.at(1);
	return a.at(0) < b.at(0);
}

int main()
{
	int n, test_num = 1;
	while(cin >> n)
	{
		if (n == 0)
			break;
		vector< vector<int> > type;
		for (int i = 0 ; i < n ; ++i)
		{
			int data[3] = {0};
			for (int j = 0 ; j < 3 ; ++j)
				cin >> data[j];
			
			type.push_back(vector<int>({data[0], data[1], data[2]}));
			type.push_back(vector<int>({data[0], data[2], data[1]}));
			type.push_back(vector<int>({data[1], data[0], data[2]}));
			type.push_back(vector<int>({data[2], data[0], data[1]}));
			type.push_back(vector<int>({data[1], data[2], data[0]}));
			type.push_back(vector<int>({data[2], data[1], data[0]}));
		}
		sort(type.begin(), type.end(), compare);
		int LIS[type.size()];
		for (int i = 0 ; i < type.size() ; ++i)
		{
			LIS[i] = type.at(i).at(2);
			for (int j = 0 ; j < i ; ++j)
			{
				if (type.at(i).at(0) > type.at(j).at(0) && type.at(i).at(1) > type.at(j).at(1) && LIS[j] + type.at(i).at(2) > LIS[i])
					LIS[i] = LIS[j] + type.at(i).at(2);
			}
		}
		cout << "Case " << test_num++ << ": maximum height = " << *max_element(LIS, LIS + type.size()) << endl;

	}
	return 0;
}
