#include <iostream>

double oblicz(double a[], int n, double x)
{
	double result = 0;

	for(int i = n; i > 0; --i)
	{
		// obliczanie wielomianu według schematu Horner'a
        result = (a[i] + result) * x;
	}
	return result + a[0];
}


int main()
{
	//Stopień wielomianu
	int n = 3;
	//Przykładowa wartość X
	double x = 10;
	//Tablica w kolejności rosnącej (x^0 + x^1 + x^2 + ... + x^n)
	double a [n+1] = {4, 5, 5, 3};

	std::cout << oblicz(a, n, x) << std::endl;
}

/*  
	Q: Ile potrzeba mnożeń, aby wyliczyć wartość wielomianu stopnia n,
	o wspołczynnikach zawartych w tablicy a?
	A: Potrzeba n mnożeń.
*/
