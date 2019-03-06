#include <iostream>
#include <fstream>

int * countAscii(char* arg)
{
	//tworzenie tablicy
	//128 = ilosc znaków + 0
	int* ascii = new int[128];
	
	//właściwy algorytm
	std::fstream file (arg);
	if(file.is_open())
	{
		char currentChar;
		while ( file.get(currentChar) )
		{
			ascii[(int)currentChar] += 1;
		}
	}
	return ascii;
}

int main(int argc, char* argv[])
{
	int * ascii;
	ascii = countAscii(argv[1]);
	
	//wypisywanie ilości wystąpień, zaczynam od 32, gdyż tylko te znaki
	//mają reprezentację graficzną
	for(int i = 32; i <= 127; ++i)
	{
		std::cout << "Znak: | " << (char)i << " |, liczba wystąpień: " << ascii[i] << std::endl;
	}
	
	delete ascii;
}
