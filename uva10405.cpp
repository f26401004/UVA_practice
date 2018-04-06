#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


int main()
{
	string str1, str2;
	while(getline(cin, str1))
	{
		getline(cin, str2);
		if (str1.empty() || str2.empty())
		{
			cout << "0" << endl;
			continue;
		}
		int d[str1.size() + 1][str2.size() + 1];
		memset(d, 0, sizeof(d));
		for(int i = 1 ; i <= str1.size() ; ++i)
		{
			for(int j = 1 ; j <= str2.size() ; ++j)
			{
				if (str1.at(i - 1) == str2.at(j - 1))
					d[i][j] = d[i - 1][j - 1] + 1;
				else
					d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
		cout << d[str1.size()][str2.size()] << endl;
	}
}
