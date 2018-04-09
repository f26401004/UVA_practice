#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.get();
	int order[n];
	char list[1024];
	fgets(list, sizeof(list), stdin);
	stringstream sin1(list);
	int buffer, index = 0;
	int correct[n];
	memset(correct, 0, sizeof(correct));
	while(sin1 >> buffer)
		correct[index++] = buffer;
	while(fgets(list, sizeof(list), stdin))
	{
		stringstream sin(list);
		int buffer, index = 1;
		int result[n];
		memset(result, 0, sizeof(result));
		while(sin >> buffer)
			order[buffer - 1] = index++;
		for (int i = 0 ; i < n ; ++i)
		{
			result[i] = 1;
			for (int j = 0 ; j < i ; ++j)
				if (correct[order[j] - 1] < correct[order[i] - 1] && result[j] + 1 > result[i])
					result[i] = result[j] + 1;
				
		}
		cout << *max_element(result, result + n) << endl;
	}
	return 0;
}
