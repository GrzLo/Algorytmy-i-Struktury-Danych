
void countingSort(int tab[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    
    for (i = 0; i < n; i++)
        count[ (tab[i]/exp)%10 ]++;

    
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (tab[i]/exp)%10 ] - 1] = tab[i];
        count[ (tab[i]/exp)%10 ]--;
    }

  
    for (i = 0; i < n; i++)
        tab[i] = output[i];
}