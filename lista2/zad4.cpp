#include <iostream>

void reverse(int *tab, int begin, int end)
{
    int tmp;

    while(begin < end) 
    {
        tmp = tab[begin];
        tab[begin] = tab[end];
        tab[end] = tmp;
        ++begin;
        --end;
    }
}


void move(int *tab, int n, int k)
{
    reverse(tab, 0, n-1); //6 5 | 4 3 2 1
    reverse(tab, 0, k-1); //5 6 | 4 3 2 1 
    reverse(tab, k, n-1); //5 6 | 1 2 3 4
}

int main()
{
	int n = 6;
	int a[n] = {1, 2, 3, 4, 5, 6};
	move(a, n, 2);
	
	for(int i = 0; i < n; ++i)
	{
		std::cout << a[i] << " ";
	}
}
