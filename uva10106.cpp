#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

int multiply(int x[], int y[], int z[], int x_size, int y_size)
{
	int z_size = 0;
	for (int i = 0 ; i < x_size ; ++i)
		for (int j = 0 ; j < y_size ; ++j)
			z[i + j] += x[i] * y[j];
	for (int i = 0 ; i < 510 ; ++i)
	{
		z[i + 1] += z[i] / 10;
		z[i] = z[i] % 10;
		if (z_size < i && z[i] > 0)
			z_size = i;
	}
	return z_size;
}

int main()
{
	int x[510], y[510], z[510];
	memset(x, -1, sizeof(x));
	memset(y, -1, sizeof(y));
	memset(z, 0, sizeof(z));
	char line1[1024], line2[1024];
	while(fgets(line1, sizeof(line1), stdin))
	{
		memset(x, -1, sizeof(x));
		memset(y, -1, sizeof(x));
		memset(z, 0, sizeof(z));
		fgets(line2, sizeof(line2), stdin);
		int x_size = 0, y_size = 0, z_size = 0;
		for (x_size = 0 ; x_size < sizeof(line1) ; ++x_size)
		{
			if (line1[x_size] == '\0')
				break;
		}
		x_size = x_size - 1;
		for (int i = 0 ; i < x_size ; ++i)
			x[i] = line1[x_size - i - 1] - '0';
		for (y_size = 0 ; y_size < sizeof(line2) ; ++y_size)
		{
			if (line2[y_size] == '\0')
				break;
		}
		y_size = y_size - 1;
		for (int i = 0 ; i < y_size ; ++i)
			y[i] = line2[y_size - i - 1] - '0';
		z_size = multiply(x, y, z, x_size, y_size);
		if (z_size == 0)
			cout << 0 << endl;
		else
		{
			for (int i = 0 ; i < z_size + 1 ; ++i)
				cout << z[z_size - i];
			cout << endl;
		}
	}
	return 0;
}
