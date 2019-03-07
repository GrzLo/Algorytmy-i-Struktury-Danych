#include <iostream>
#include <utility>

std::pair<int, int> findMinMax(int a[], int start, int end) 
{
	std::pair<int, int> left, right;
	
	int min, max;
	int mid = (start + end) / 2;
	
	//sprawdzenie czy dana tablica lub jej część jest jednoelementowa
	if (start == end)
	{
		min = max = a[start];
		return std::make_pair(min, max);
	}
	//lub dwuelementowa, wtedy porównaj elementy
	else if ( end - start == 1)
	{
		min = a[start] < a[end] ? a[start] : a[end];
		max = a[start] > a[end] ? a[start] : a[end];
		return std::make_pair(min, max);
	}
	
	//podział tablicy na 2 czesci, rekurencja
	left = findMinMax(a, start, mid);
	right = findMinMax(a, mid +1, end);
	
	//końcowe porównanie
	min = left.first < right.first ? left.first : right.first;
	max = left.second > right.second ? left.second : right.second;
	
	return std::make_pair(min, max);
}

int main()
{
	int n = 10;
	int a[n] = {1, 25, 4, -13, 5, 6, 123, 45, 44, 2};
	
	std::pair<int, int>  minMax = findMinMax(a, 0, n-1);
	std::cout << "Min = " << minMax.first << std::endl;
	std::cout << "Max = " << minMax.second << std::endl;
}
