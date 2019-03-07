#include <iostream>

static int comparisons1, comparisons2, comparisons3 = 0;

// wersja (a) iteracyjna n-1 porównań
int maks1(int t[], int n)
{
    int x = t[--n];
    while(n--)
    {
		++comparisons1; 
        if(t[n] > x)
        {
            x = t[n];
        }
    }
    return x;
}

//wersja (b) rekurencyjna, n porównań
int maks2(int t[], int n)
{
	++comparisons2;
	if(n == 1)
	{
		return t[0];
	}

	int max = maks2(t, (n - 1));
	return max > t[n - 1] ? max : t[n-1];
}

//wersja (c) rekurencyjna n porównań

int maks3(int t[], int start, int end)
{
	
	if(start == end)
	{
		return t[end];
	}
	
	int mid = (start + end) / 2; // 4
	int max1 = maks3(t, start, mid); // 4
	int max2 = maks3(t, mid+1, end); // 4
	
	++comparisons3;
	return max1 > max2 ? max1 : max2; // 4
}

int main()
{
    int n = 7;
    int tab[n] = {3, 2, 7, 15, 2, 5, 8};
    
    std::cout << "Wersja 1" << std::endl;
    std::cout << "Max: " << maks1(tab, n) << " Number of comparisons: " << comparisons1 << std::endl << std::endl;
    std::cout << "Wersja 2" << std::endl;
    std::cout << "Max: " <<  maks2(tab, n) << " Number of comparisons: " << comparisons2 << std::endl << std::endl;
    std::cout << "Wersja 3" << std::endl;
    std::cout << "Max: " <<  maks3(tab, 0, n-1) << " Number of comparisons: " << comparisons3 << std::endl << std::endl;
}
