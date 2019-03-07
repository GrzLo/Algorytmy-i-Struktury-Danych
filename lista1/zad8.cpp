#include <iostream> 
#include <string>

class Ulamek
{
public:
	int licznik;
	int mianownik;
	
	Ulamek(int licz = 0, int mian = 1) :
	licznik(licz),
	mianownik(mian)
	{
		int nwd = nWD(licznik, mianownik);
		licznik /= nwd;
		mianownik /= nwd;
	}
	
	int nWD(int a, int b)
	{
		//algorytm Euklidesa
		if(a < 0)
		{
			a *= -1;
		}
		else if(b < 0)
		{
			b *= -1;
		}
		int c = 0;
		while(b != 0)
		{
			c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
	
	Ulamek operator+ (Ulamek rhs)
	{
		int newLicznik;
		int newMianownik;
		
		newLicznik = licznik * rhs.mianownik + rhs.licznik * mianownik;
		newMianownik = mianownik * rhs.mianownik;
		
		return Ulamek(newLicznik, newMianownik);
	}
	
	Ulamek operator- (Ulamek rhs)
	{
		int newLicznik;
		int newMianownik;
		
		newLicznik = licznik * rhs.mianownik - rhs.licznik * mianownik;
		newMianownik = mianownik * rhs.mianownik;
		
		return Ulamek(newLicznik, newMianownik);
	}
	
	Ulamek operator* (Ulamek rhs)
	{
		int newLicznik;
		int newMianownik;
		
		newLicznik = licznik * rhs.licznik;
		newMianownik = mianownik * rhs.mianownik;
		return Ulamek(newLicznik, newMianownik);
	}
	
	Ulamek operator/ (Ulamek rhs)
	{
		int newLicznik;
		int newMianownik;
		
		newLicznik = licznik * rhs.mianownik;
		newMianownik = mianownik * rhs.licznik;
		return Ulamek(newLicznik, newMianownik);
	}
	
	Ulamek operator= (Ulamek rhs)
	{
		int newLicznik;
		int newMianownik;
		
		newLicznik = rhs.licznik;
		newMianownik = rhs.mianownik;
		return Ulamek(newLicznik, newMianownik);
	}
	

	
	Ulamek operator- ()
	{
		return Ulamek(licznik *-1, mianownik);
	}
	
	friend std::ostream& operator<< (std::ostream& out, const Ulamek& a)
	{
		return out << a.licznik << "/" << a.mianownik;
	}
	
	friend std::istream& operator>> (std::istream& in, Ulamek& a)
	{
		std::cout << "Podaj ułamek (format 'a/b')" << std::endl;
		std::string ulamek;
		in >> ulamek;
		//taki hack, żeby przekonwertowac char na int
		a.licznik = (int)ulamek[0] - 48;
		a.mianownik = (int)ulamek[2] - 48;
		return in;
	}

};

int main()
{
	Ulamek ulamek1;
	Ulamek ulamek2;
	
	std::cin >> ulamek1;
	std::cin >> ulamek2;
	
	Ulamek dodawanie = ulamek1 + ulamek2;
	Ulamek odejmmowanie = ulamek1 - ulamek2;
	Ulamek mnozenie = ulamek1 * ulamek2;
	Ulamek dzielenie = ulamek1 / ulamek2;
	
	std::cout << ulamek1 << " + " << ulamek2 << " = " << dodawanie << std::endl;
	std::cout << ulamek1 << " - " << ulamek2 << " = " << odejmmowanie << std::endl;
	std::cout << ulamek1 << " * " << ulamek2 << " = " << mnozenie << std::endl;
	std::cout << ulamek1 << " / " << ulamek2 << " = " << dzielenie << std::endl;
}
