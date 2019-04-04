#include <iostream>
void maxSum(int a[], int n, int k) 
{
    if (k > n) 
    {
        std::cout << "K musi byc mniejsze od N!" << std::endl;
        return;
    }

    int sum = 0;
    for (int i = 0; i < k; i++) 
    {
        sum += a[i];
    }

    int newSum = sum;
    for (int i = k; i < n; i++) 
    {
        newSum -= a[i-k];
        newSum += a[i];

        if (newSum > sum) 
        {
            sum = newSum;
        }
    }
    std::cout << sum;
}

int main() 
{
	int n = 10;
	int k = 5;
    int t[n] = {1, 20, 3, 40, 5, 60, 7, 80, 9, 0};
    maxSum(t, n, k);
}
