#include <cstring>
#include <cstdio>
#define MAX (1<<24)+5 
using namespace std;

int N, current;
int BIT[MAX];
int visits[MAX];
int ans[50];
int cache_limit[50];

int low_bit(int target)
{
	return target & (-target);
}

int get_sum(int index)
{
	int ans = 0;
	while(index > 0)
	{
		ans += BIT[index];
		index -= low_bit(index);
	}
	return ans;
}

void modify(int index, int delta)
{
	for(int i = index ; i < MAX ; i += low_bit(i))
		BIT[i] += delta;
}

void add(int index, int value)
{
	while(index < MAX)
	{
		BIT[index] += value;
		index += low_bit(index);
	}
}

void access(int target)
{
	if (visits[target])
	{
		int len = get_sum(current) - get_sum(visits[target] - 1);
		for(int i = 0 ; i < N ; ++i)
		{
			if (cache_limit[i] >= len)
				break;
			ans[i]++;
		}
		add(visits[target], -1);
	}
	else
	{
		for(int i = 0 ; i < N ; ++i)
			ans[i]++;
	}
	visits[target] = ++current;
	add(current, 1);
}

void init()
{
	current = 0;
	memset(cache_limit, 0, sizeof(cache_limit));
	memset(BIT, 0, sizeof(BIT));
	memset(ans, 0, sizeof(ans));
	memset(visits, 0, sizeof(visits));
}

int main()
{
	char list[124];
	while(~scanf("%d", &N))
	{
		init();
		for(int i = 0 ; i < N ; ++i)
			scanf("%d", &cache_limit[i]);
		while(scanf("%s", list))
		{
			if (list[0] == 'E')
				break;
			else if (list[0] == 'S')
			{
				printf("%d", ans[0]);
				for(int i = 1 ; i < N ; ++i)
					printf(" %d", ans[i]);
				memset(ans, 0, sizeof(ans));
				printf("\n");
			}
			else if (list[0] == 'A')
			{
				int value;
				scanf("%d", &value);
				access(value);
			}
			else if (list[0] == 'R')
			{
				int b, y, n;
				scanf("%d%d%d", &b, &y, &n);
				for(int i = 0 ; i < n ; ++i)
					access(b + y * i);
			}
		}
	}
	return 0;
}
