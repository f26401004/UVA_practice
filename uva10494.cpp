#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;

void divideOrMod(string a, int b, int type)
{
	int pos = 0;
	long long int buffer = 0;
	char result[10000];
	for(int i = 0 ; a[i] ; ++i)
	{

		buffer = buffer * 10 + (a[i] - '0');
		result[pos++] = (char)('0' + buffer / b);
		buffer = buffer % b;
	}
	if (type == 0)
	{
		int outputPos = 0;
		for (outputPos = 0 ; outputPos < 10000 ; ++outputPos)
			if (result[outputPos] - '0' > 0)
				break;
		for(int i = outputPos ; i < pos ; ++i)
			cout << result[i];
		cout << endl;
	}
	else
		cout << buffer << endl;
}
int main()
{
	char line[1024];
	while (fgets(line, sizeof(line), stdin))
	{
		stringstream sin(line);
		string a;
		char type;
		long long int b;
		sin >> a >> type >> b;
		int bsize = to_string(b).length();
		if (bsize <= a.length())
			divideOrMod(a, b, type == '/' ? 0 : 1);
		else
		{
			if (type == '/')
				cout << 0 << endl;
			else
				cout << a << endl;
		}
	}
	return 0;
}
