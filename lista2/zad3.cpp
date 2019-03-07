#include <iostream>

static int counter = 0;

int skalar(int a[], int b[], int n)
{
	int result = 0;
	int counter = 0;
	
	for(int i = 0; i < n; ++i)
	{
		result += a[i] * b[i];
		++counter;
	}
	
	std::cout << "Number of multiplications: " << counter << std::endl;
	return result;
}

int wielomian(int a[], int n, int x)
{
	int result = 0;
	int partial;
	
	for(int i = 0; i < n; ++i)
	{
		partial = 1;
		
		for(int j = n-i; j > 0; --j)
		{
			partial *= x;
			++counter;
		}
		partial *= a[i];
		++counter;
		result += partial;
	}
	result += a[n];
	return result;
}

int iloczynWielomianow(int a[], int b[], int n1, int n2, int x)
{
	int result1 = wielomian(a, n1, x);
	int result2 = wielomian(b, n2, x);
	++counter;
	return result1 * result2;
}

void iloczynMacierzy(int a[][2], int b[][2], int n)
{
	int m3[n][n];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			for(int k = 0; k < n; ++k)
			{
				m3[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j <  n; ++j)
		{
			std::cout << " " << m3[i][j];
		}
	}
}

int main()
{
	int n1 = 3;
	int n2 = 4;
	int n3 = 2;
	int x = 10;
	int s1[n1] = {1,2,3};
	int s2[n1] = {1,1,1};
	int w1[n1+1] = {5,4,3,2};
	int w2[n2+1] = {3,2,4,4,1};
	int m1[2][2] = {{2, 5}, {1, -2}};
	int m2[2][2] = {{3, -1}, {7, 4}};
	
	std::cout << skalar(s1, s2, n1) << " Number of multiplications: " << counter << std::endl;
	counter = 0;
	std::cout << wielomian(w1, n1, x) << " Number of multiplications: " << counter << std::endl;
	counter = 0;
	std::cout << iloczynWielomianow(w1, w2, n1, n2, x) << " Number of multiplications: " << counter << std::endl;
	counter = 0;
	
	std::cout << m1[0] << m2[0] << std::endl;
	iloczynMacierzy(m1, m2, n3);
}
