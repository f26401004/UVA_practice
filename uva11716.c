#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int i, j, k, test_num;
	scanf("%d", &test_num);
	getchar();
	char result[test_num][10001];
	for (i = 0 ; i < test_num ; ++i)
	{
		char text[10001];
		gets(text);
		int n = (int)sqrt(strlen(text));
		if (n * n != strlen(text))
		{
			strcat(result[i], "INVALID");
			continue;
		}
		else
		{
			for (j = 0 ; j < n ; ++j)
				for (k = 0 ; k < n ; ++k)
					strncat(result[i], &text[k * n + j], 1);
		}
	}
	for (i = 0 ; i < test_num ; ++i)
		printf("%s\n", result[i]);
	return 0;
}
