#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool check[14];

void DFS(int num, int* array, int* choose, int size, int index)
{
	if (size == 6)
	{
		cout << choose[0];
		for (int i = 1 ; i < size ; ++i)
			cout << " " << choose[i];
		cout << endl;
		return;
	}
	for(int i = index ; i < num ; ++i)
	{
		if (!check[i])
		{
			check[i] = true;
			choose[size] = array[i];
			DFS(num, array, choose, size + 1, i + 1);
			check[i] = false;
		}
	}
	return;	
}


int main()
{
	int num, time = 0;
	while(cin >> num)
	{
		if (!num)
			break;
		if (time > 0)
			cout << endl;
		int data[num], choose[6];
		memset(choose, 0, sizeof(choose));
		memset(check, false, sizeof(check));
		for(int i = 0 ; i < num ; ++i)
			cin >> data[i];
		sort(data, data + num);
		DFS(num, data, choose, 0, 0);
		++time;
	}
	return 0;
}
