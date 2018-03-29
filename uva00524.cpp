#include <iostream>
#include <cstring>
using namespace std;

bool prime[17];
int N;
bool visited[17];

void makePrime()
{
	memset(prime, false, sizeof(prime));
	prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] = prime[19] = prime[23] = prime[29] = prime[31] = prime[37] = prime[41] = prime[43] =true;
}

void backtracking(int *array, int index, int num)
{
	array[index] = num;
	if (index == N - 1)
	{
		if (!prime[array[0] + array[index]])
			return;
		cout << array[0];
		for(int i = 1 ; i < N ; ++i)
			cout << " " << array[i];
		cout << endl;
	}
	for(int i = 2 ; i < N + 1 ; ++i)
	{
		if (visited[i])
			continue;
		if (prime[i + array[index]])
		{
			visited[i] = true;
			backtracking(array, index + 1, i);
			visited[i] = false;
		}
	}
}

int main()
{
	int case_num = 0;
	makePrime();
	while(cin >> N)
	{
		int array[N];
		if (case_num++) 
			cout << endl;
		memset(array, 0, sizeof(array));
		memset(visited, false, sizeof(visited));
		cout << "Case " << case_num << ":" << endl;
		backtracking(array, 0, 1);
	}
	return 0;
}
