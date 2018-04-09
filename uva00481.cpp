#include <iostream>
#include <vector>
using namespace std;

int list[100000], index = 1;
int result[100000] = {0};
int front[100000] = {0};

void print(int target)
{
	if (front[target])
		print(front[target]);
	cout << list[target] << endl;
}

int binary(int right, int target)  
{  
	int left = 1;  
	while (left < right) 
	{  
		int mid = (left + right) / 2;  
		if ( list[result[mid]] < target )  
			left = mid + 1;  
		else
			right = mid;  
	}  
	return right;  
}  

int main()
{
	while(cin >> list[index++]);
	int end = 0;
	result[++end] = 1;
	for (int i = 2 ; i < index ; ++i)
	{
		if (list[result[end]] < list[i])
		{
			result[++end] = i;
			front[i] = result[end - 1];
		}
		else
		{
			int pos = binary(end, list[i]);
			result[pos] = i;
			front[i] = result[pos - 1];
		}
	}
	cout << end << endl;
	cout << "-" << endl;
	print(result[end]);
	return 0;
}
