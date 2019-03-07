#include <iostream>

static int counter = 0;

// n
int skalar(int a[], int b[], int n)
{
	int result = 0;
	
	for(int i = 0; i < n; ++i)
	{
		result += a[i] * b[i];
		++counter;
	}
	return result;
}

// n(n+1)/2 - 1
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

//(n1(n1+1)/2 - 1) + (n2(n2+1)/2 - 1) + 1
int iloczynWielomianow(int a[], int b[], int n1, int n2, int x)
{
	int result1 = wielomian(a, n1, x);
	int result2 = wielomian(b, n2, x);
	++counter;
	return result1 * result2;
}

//n^3
void iloczynMacierzy(int a[][3], int b[][3], int n)
{
	int m3[n][n];
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
        {
            m3[i][j] = 0;
        }
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			for(int k = 0; k < n; ++k)
			{
				m3[i][j] += a[i][k] * b[k][j];
				++counter;
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

//n!
int wyznacznikMacierzy(int a[3][3], int n)
{
	int wyzn = 0;
	int b[3][3];
	
	if (n == 2)
	{
		++counter;
		++counter;
		return ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1]));
	}
    else
    {
	for (int x = 0; x < n; x++) 
	{
	int subi = 0; 
	for (int i = 1; i < n; i++) 
	{
		int subj = 0;
		for (int j = 0; j < n; j++) 
		{
			if (j == x)
			continue;
			b[subi][subj] = a[i][j];
			subj++;
		}
		subi++;
		}

		int pow = -1;
		if(x % 2 == 0)
		{
			pow = 1;
		}

		wyzn = wyzn + pow * a[0][x] * wyznacznikMacierzy(b, n - 1);
		++counter;
		++counter;
	}
      	}
	return wyzn;
}

int main()
{
	int n1 = 3;
	int n2 = 4;
	int n3 = 3;
	int x = 10;
	int s1[n1] = {1,2,3};
	int s2[n1] = {1,1,1};
	int w1[n1+1] = {5,4,3,2};
	int w2[n2+1] = {3,2,4,4,1};
	int m1[3][3] = {{2, 5, 1}, {1, -2, 7}, {1, 5, 6}};
	int m2[3][3] = {{3, -1, 6}, {7, 4, 2}, {1, 2, 3}};
	int m3[3][3] = {{1, 2, 3}, {3, 2, 1}, {2, 1, 3}};
	
	std::cout << skalar(s1, s2, n1) << " Number of multiplications: " << counter << std::endl;
	counter = 0;
	std::cout << wielomian(w1, n1, x) << " Number of multiplications: " << counter << std::endl;
	counter = 0;
	std::cout << iloczynWielomianow(w1, w2, n1, n2, x) << " Number of multiplications: " << counter << std::endl;
	counter = 0;
	iloczynMacierzy(m1, m2, n3);
	std::cout << " Number of multiplications: " << counter << std::endl;
	counter = 0;
	std::cout << wyznacznikMacierzy(m3, n3) << std::endl;
	std::cout << " Number of multiplications: " << counter << std::endl;
}
