#include <iostream> 

double exp_i(double x, int n)
{
	// sprawdzam czy wykładnik lub x wynosi 0
	double result = 1;
	
	if(n == 0)
	{
		return result;
	}
	else if(x == 0)
	{
		return 0;
	}
	
	// właściwy algorytm
	else
	{
		while (n > 0)
		{
			if (n % 2 != 0)
			{
				result *= x;
			}
			n /= 2;
			x *= x;
		}
	}
	return result;
}

double exp_r(double x, int n, double res)
{
	// sprawdzam czy wykładnik lub x wynosi 0
	if(n == 0)
	{
		return res;
	}
	else if(x == 0)
	{
		return 0;
	}
	
	// właściwy algorytm
	else if(n % 2 != 0)
	{
		return exp_r((x * x), (n / 2), (res * x));
	}
	
	return exp_r((x * x), (n / 2), (res));
}


int main()
{
	std::cout << exp_i(3, 10) << std::endl;
	std::cout << exp_r(3, 10, 1) << std::endl;
}
