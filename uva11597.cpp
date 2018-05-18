#include <iostream>
using namespace std;

int main()
{
	int n, case_num = 0;;
	while(cin >> n)
	{
		if (n == 0)
			break;
		cout << "Case " << ++case_num << ": " << n / 2 << endl;
	}
	
	return 0;
}
