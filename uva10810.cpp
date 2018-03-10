#include <iostream>
using namespace std;

long long step = 0;

void merge(int* array, int low, int high)
{
	int combine[high - low + 1];
	int k = 0;
	int mid = (low + high) / 2;
	int i = low, j = mid + 1;
	while(i <= mid && j <= high) {
		if (array[i] <= array[j]) {
			combine[k++] = array[i++];
		}
		else
		{
			step = step + mid + 1 - i;
			combine[k++] = array[j++];
		}
	}
	while(i <= mid) {
		combine[k++] = array[i++];
	} 
	while(j <= high) combine[k++] = array[j++];
	for (int i = low, j = 0 ; i < high + 1 ; ++i, ++j)
		array[i] = combine[j];
}

void merge_sort(int* array, int low, int high)
{
	if (high > low) {
		merge_sort(array, low, (low + high) / 2);
		merge_sort(array, (low + high) / 2 + 1, high);
		merge(array, low, high);
	}
}

int main()
{
	int case_num;
	while(cin >> case_num) {
		if (case_num == 0) break;
		int data[case_num];
		step = 0;
		for (int i = 0 ; i < case_num ; ++i) {
			cin >> data[i];
		}
		merge_sort(data, 0, case_num - 1);
		cout << step << endl;
		step = 0;
	}
	return 0;
}
