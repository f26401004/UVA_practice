#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int number;
	vector<long long int> list;
	list.push_back(0);
	list.push_back(1);
	int j, k;
	j =  k = 0;
	for (int i = 2 ; i < 1000 ; ++i)
	{
		while(list.at(j) * 2 <= list.at(i - 1))
			++j;
		while(list.at(k) * 3 <= list.at(i - 1))
			++k;
		list.push_back(min(list.at(j) * 2, list.at(k) * 3));
	}
	while(cin >> number)
	{
		if (number == 0)
			break;
		cout << *lower_bound(list.begin(), list.end(), number) << endl;
	}
	return 0;
}
