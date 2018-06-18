#include <iostream>
#include <cstring>
#define MAX 210
using namespace std;

int N;

int BIT[MAX][MAX];

int low_bit(int target)
{
	return target & (-target);
}

void modify(int x, int y)
{
	int buffer_y;
	while(x < MAX)
	{
		buffer_y = y;
		while(buffer_y < MAX)
		{
			BIT[x][buffer_y]++;
			buffer_y += low_bit(buffer_y);
		}
		x += low_bit(x);
	}
}

int query(int x, int y)
{
	int ans = 0, buffer_y;
	while(x > 0)
	{
		buffer_y = y;
		while(buffer_y > 0)
		{
			ans += BIT[x][buffer_y];
			buffer_y -= low_bit(buffer_y);
		}
		x -= low_bit(x);
	}
	return ans;
}

bool check_empty(int x1, int x2, int y1, int y2)
{
	return (query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1) == 0); 
}

int main()
{
	int test_case;
	cin >> test_case;
	for(int i = 0 ; i < test_case ; ++i)
	{
		memset(BIT, 0, sizeof(BIT));
		cin >> N;
		int area = 0;
		while(N--)
		{
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1 += 100;
			x2 += 99;
			y1 += 100;
			y2 += 99;
			if (check_empty(x1, x2, y1, y2))
			{
				for(int j = x1 ; j <= x2 ; ++j)
				{
					for(int k = y1 ; k <= y2 ; ++k)
					{
						area++;
						modify(j, k);
					}
				}
			}
		}
		cout << "Case " << i + 1 << ": " << area << endl;
	}
	return 0;
}
