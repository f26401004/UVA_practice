#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	char line[8192];
	while(fgets(line, sizeof(line), stdin))
	{
		if (line[0] == '0')
			break;
		vector<int> list;
		stringstream ss(line);
		int value;
		while(ss >> value)
		{
			if (value == 0)
				break;
			list.push_back(value);
		}
		int max_remainder = 0;
		for (int i = 1 ; i < list.size() ; ++i)
			max_remainder = gcd(max_remainder, list.at(i - 1) - list.at(i));
		max_remainder *= (max_remainder < 0 ? -1 : 1 );
		cout << max_remainder << endl;

	}
	return 0;
}
