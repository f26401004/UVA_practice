#include <stdio.h>
#include <stdlib.h>

int main()
{
	int array_num, query_num, i, j, l, k, v;
	while(scanf("%d%d", &array_num, &query_num) != EOF)
	{
		int array[array_num], result[query_num], re;
		for (i = 0 ; i < array_num ; ++i)
			scanf("%d", &array[i]);
		for (j = 0 ; j < query_num ; ++j)
		{
			re = 0;
			scanf("%d%d", &k, &v);
			for (l = 0; l < array_num ; ++l)
			{
				if(array[l] == v)
				{
					result[j] = l + 1;
					++re;
				}
				if (re == k)
					break;
			}
			if (re != k)
				result[j] = 0;
		}
		for (i = 0 ; i < query_num ; ++i)
			printf("%d\n", result[i]);
	}
	return 0;
}
