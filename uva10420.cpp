#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
	map<string, int> data;
	int case_num;
	cin >> case_num;
	char country[256];
	for (int i = 0 ; i < case_num ; ++i)
	{
		scanf("%s%*[^\n]", country);
		++data[string(country)];
	}
	for (map<string, int>::iterator iter = data.begin() ; iter != data.end() ; ++iter)
		cout << iter->first << " " << iter->second << endl;
	return 0;
}
