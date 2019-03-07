#include <iostream>

static int comparisons = 0;

int find(int a[], int start, int end, int x)
{
	int mid = (start + end) / 2;
	
	++comparisons;
	if(a[mid] == x)
	{
		
		std::cout << "Element found at index: " << mid << " Number of comparisons: " << comparisons << std::endl;
		return mid; 
	}
	
	else if(start == end)
	{
		std::cout << "Element not found. Number of comparisons: " << comparisons << std::endl;
		return 0;	
	}
	
	else
	{
		a[mid] > x ? end = mid : start = mid+1;
		
		find(a, start, end, x);
	}
	
	comparisons = 0;
	return 0;
}


int main()
{
	
	int a1[8] = {1, 4, 5, 7, 10, 22, 23, 24};
	int a2[15] = {1, 4, 5, 7, 10, 22, 23, 24, 33, 36, 38, 40, 42, 43, 49};
	int a3[16] = {1, 4, 5, 7, 10, 22, 23, 24, 33, 36, 38, 40, 42, 43, 49, 50};
	
	std::cout << "Element present" << std::endl;
	find(a1, 0, 8, 24);
	find(a2, 0, 15, 49);
	find(a3, 0, 16, 50);
	std::cout << "Element not present" << std::endl;
	find(a1, 0, 8, 100);
	find(a2, 0, 15, 100);
	find(a3, 0, 16, 100);
}
