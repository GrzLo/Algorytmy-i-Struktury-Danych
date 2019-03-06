#include <iostream> 

double f(double x)
{
	// Prosta przykładowa funkcja liniowa spełniająca warunek f(0) < 0 < f(1)
	// f(0) = -0.6
	// f(1) = 0.4
	// Wiemy, że pierwiastek funkcji to: x = 0.6
	return x - 0.6;
}

double findRoot(double x1, double x2)
{
	double x; 
	int operations = 0;
	
	while(true)
	{
		x = (x1 + x2) * 0.5;
		
		if(f(x) > (0 + 1.e-10))
		{
			x2 = x;
			++operations;
		}
		else if(f(x) < (0 - 1.e-10))
		{
			x1 = x;
			++operations;
		}
		else
		{
			std::cout << "Liczba operacji: " << operations << std::endl;
			return x;
		}
	}
}


int main()
{
	//zakres, w którym szukamy miejsca zerowego
	double x1;
	double x2;
	
	x1 = 0;
	x2 = 1;
	std::cout << findRoot(x1, x2) << std::endl;
	x1 = -128;
	x2 = 128;
	std::cout << findRoot(x1, x2) << std::endl;
	x1 = -256;
	x2 = 256;
	std::cout << findRoot(x1, x2) << std::endl;

}
