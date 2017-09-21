#include <stdio.h>
#include <stdlib.h>

int main()
{
	int case_num;
	scanf("%d", &case_num);
	int i, j, N;
	double total, percent, result[case_num];
	for (i = 0 ; i < case_num ; ++i)
	{
		total = 0;
		percent = 0;
		scanf("%d", &N);
		int space[N];
		for (j = 0 ; j < N ; ++j)
		{
			scanf("%d", &space[j]);
			total = total + space[j];
		}
		total = total / N;
		for (j = 0 ; j < N ; ++j)
		{
			if (space[j] > total)
				++percent;
		}
		result[i] = percent / N * 100;
	}
	for (i = 0 ; i < case_num ; ++i)
		printf("%.3f%%\n", result[i]);
}
