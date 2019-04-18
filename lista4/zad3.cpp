#include <iostream>
#include <cmath>

void countingSort(int t[], int n, int c)
{
    int count[10] = {0};
    
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
    int array[10] = {21,72,14,13,15,28,27,58,29,61};
    print(array, 10);
    countingSort(array, 10, 0);
    print(array, 10);
    countingSort(array, 10, 1);
    print(array, 10);

}
