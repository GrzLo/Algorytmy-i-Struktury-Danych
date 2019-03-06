#include <iostream>

bool * sito_eratostenesa(int n)
{
	//tworzenie tablicy
	bool* prime = new bool[n];
	//inicjalizacja elementów na true
	for(int i = 0; i < n; ++i)
	{
		if(i == 0 || i == 1)
		{
			prime[i] = false;
		}
		else
		{
			prime[i] = true;			
		}
	}
	
	//właściwy algorytm
	for(int i = 2; i < n; ++i)
	{
		if(prime[i] == true)
		{
			for(int j = 2; j < n; ++j)
			{
				if(prime[j] == true)
				{
					if(j != i)
					{
						if(j % i == 0)
						{
							prime[j] = false;
						}
					}
				}
			}
		}
	}
	
	return prime;
}

int main()
{
	//ilość liczb, które mają zostać sprawdzone (nie licząc 0 i 1)
	int n = 1000;
	bool * prime;
	
	prime = sito_eratostenesa(n);
	
	//wypisywanie liczb pierwszych
	for(int i = 0; i < n; ++i)
	{
		if(prime[i] == true)
		{
			std::cout << i << ", ";
		}
	}
	
	delete prime;
}
