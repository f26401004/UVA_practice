#include <iostream>
#include <cmath>
using namespace std;

int max(double array[], int size) {
	int max_index = 0;
	double max_cost = 0;
	for (int i = 0 ; i < size ; ++i) {
		if (max_cost < array[i] && array[i] != static_cast<double>(INFINITY)) {
			max_index = i;
			max_cost = array[i];
		}
	}
	return max_index;
}

int main() {
	int case_num, task_num;
	cin >> case_num;
	for (int j = 0 ; j < case_num ; ++j) {
		cin >> task_num;
		double time[task_num], cost[task_num];
		for (int i = 0 ; i < task_num ; ++i) {
			cin >> time[i] >> cost[i];
		}
		double cost_list[task_num];
		for (int i = 0 ; i < task_num; ++i) {
			cost_list[i] = cost[i] / time[i];
		}
		for (int i = 0 ; i < task_num ; ++i) {
			if (i != 0) cout << " ";
			int max_index = max(cost_list, task_num);
			cost_list[max_index] = static_cast<double>(INFINITY);
			cout << max_index + 1;
		}
		cout << endl;
		if (j != case_num - 1)
			cout << endl;
	}
	return 0;
}
