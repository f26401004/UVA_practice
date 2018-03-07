#include <stdio.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int main() {
	int num;
	while(scanf("%d", &num) != EOF) 
	{
		int array[num], i, j;
		for (i = 0 ; i < num ; ++i)
			scanf("%d", &array[i]);
		int step = 0;
		for (i = num - 1 ; i > 0 ; --i) {
			for (j = 0 ; j < i ; ++j) {
				if (array[j] > array[j + 1]) {
					++step;
					int temp;
					SWAP(array[j], array[j + 1], temp);	
				}
			}
		}	
		printf("Minimum exchange operations : %d\n", step);
	}
	return 0;
}
