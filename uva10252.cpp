#include <iostream>
#include <string>
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
			cout << endl;
			continue;
		}
		int count1[26] = {0};
		int count2[26] = {0};
		for(int i = 0 ; i < str1.size() ; ++i)
			++count1[str1.at(i) - 'a'];
		for(int i = 0 ; i < str2.size() ; ++i)
			++count2[str2.at(i) - 'a'];
		for(int i = 0 ; i < 26 ; ++i)
		{
			int time = min(count1[i], count2[i]);
			for(int j = 0 ; j < time ; ++j)
				cout << (char)(i + 'a');	
		}
		cout << endl;
	}
}
