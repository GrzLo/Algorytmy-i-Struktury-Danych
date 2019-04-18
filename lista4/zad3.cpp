#include <iostream>
#include <cmath>

int k_th(int x, int k) {
    int length = floor(log10(x)) + 1;
    int result = 0;
    for (int i = length; i != k; i--) 
    {
        result = x % 10;
        x = x / 10;
    }
    return result;
}

void countingSort(int t[], int n, int c)
{
    int max = t[0];
    int min = t[0];

    for (int i = 0; i < n; i++)
    {
        if (t[i] > max)
            max = t[i];
        if (t[i] < min)
            min = t[i];
    }

    std::cout << "Min = " << min << ", max = " << max << std::endl;

    int range = max - min + 1; 
    int count[range] = {0};
    
    int i;
    int out[n];
    c = pow(10, c);
    
    for(i=0;i<n;i++)
        ++count[(t[i]/c)%10];
    
    for(i=1;i<range;i++)
        count[i]+=count[i-1];
     
    for(i=n-1;i>=0;i--){
        out[count[(t[i]/c)%10]-1]=t[i];
        --count[(t[i]/c)%10];
    }
    
    for(i=0;i<n;i++)
        t[i]=out[i];
}

void print(int t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << t[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int array[10] = {51,12,23,94,15,26,27,58,29,61};
    print(array, 10);
    countingSort(array, 10, 0);
    print(array, 10);
    countingSort(array, 10, 1);
    print(array, 10);

}
