#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef struct Node {
	int min_value;
	int left, right;
} node;

int N, Q;
int data[200000];
node tree[800000];

void build(int current, int left, int right)
{
	tree[current].left = left;
	tree[current].right = right;
	if (left == right)
	{
		tree[current].min_value = data[left];
		return;
	}
	int mid = (left + right) >> 1;
	build(current * 2, left, mid);
	build(current * 2 + 1, mid + 1, right);
	tree[current].min_value = min(tree[current * 2].min_value, tree[current * 2 + 1].min_value);
}

void update(int current, int pos, int value)
{
	if (tree[current].left == tree[current].right)
	{

		tree[current].min_value = value;
		return;
	}
	int mid = (tree[current].left + tree[current].right) >> 1;
	if (pos <= mid)
		update(current * 2, pos, value);
	else
		update(current * 2 + 1, pos, value);
	tree[current].min_value = min(tree[current * 2].min_value, tree[current * 2 + 1].min_value);
}

int query_min(int current, int left, int right)
{
	int ans = 9999999;
	if (left <= tree[current].left && tree[current].right <= right)
		return tree[current].min_value;
	int mid = (tree[current].left + tree[current].right) >> 1;
	if (left <= mid)
		ans = min(ans, query_min(current * 2, left, right));
	if (right > mid)
		ans = min(ans, query_min(current * 2 + 1, left, right));
	return ans;
}


int main()
{
	while(scanf("%d%d", &N, &Q) == 2)
	{
		for(int i = 1 ; i <= N ; ++i)
			scanf("%d", &data[i]);
		build(1, 1, N);
		for(int i = 0 ; i < Q ; ++i)
		{
			int start, end;
			vector<int> shift;
			char input[7];
			scanf("%6s", &input);
			if (input[0] == 'q')
			{
				char buffer;
				scanf("%d,%d)", &start, &end);
				printf("%d\n", query_min(1, start, end));
			}
			else if (input[0] == 's')
			{
				while(true)
				{
					int num;
					char buffer;
					scanf("%d%c", &num, &buffer);
					shift.push_back(num);
					if (buffer == ')')
						break;
				}
				int first = data[shift.at(0)];
				for(int j = 1 ; j < shift.size() ; ++j)
				{
					data[shift.at(j - 1)] = data[shift.at(j)];
					update(1, shift.at(j - 1), data[shift.at(j - 1)]);
				}
				data[shift.at(shift.size() - 1)] = first;
				update(1, shift.at(shift.size() - 1), first);
			}
		}
	}
	return 0;
}
