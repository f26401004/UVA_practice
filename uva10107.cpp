#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int input, num = 0, med = 0;
	vector<int> list;
	while(cin >> input) {
		++num;
		list.push_back(input);
		sort(list.begin(), list.end());
		if (num % 2 != 0)
			med = *(list.begin() + num / 2);
		else
			med  = (*(list.begin() + num / 2 -1 ) + *(list.begin() + num / 2)) / 2;
		cout << med << endl;
	}
	return 0;
}
