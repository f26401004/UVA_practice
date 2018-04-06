#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int p, q, r, s, t, u;

double equation(double x)
{
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}


int main()
{
	while(cin >> p >> q >> r >> s >> t >> u)
	{
		if (equation(1) == 0)
		{
			printf("1.0000\n");
			continue;
		}
		if (equation(0) == 0)
		{
			printf("0.0000\n");
			continue;
		}
		if (equation(0) * equation(1) > 0)
		{
			printf("No solution\n");
			continue;
		}
		double left = 0.0, right = 1.0, middle;
		while(right - left >= 1e-8)
		{
			middle = (left + right) / 2;
			double middle_value = equation(middle);
			if (middle_value > 0)
				left = middle;
			else
				right = middle;
			
		}
		printf("%.4lf\n", left);
	}
	return 0;
}
