#include <stdio.h>


void selectionSort(int *arr, int n)
{
    int i, j, min, temp;
    for(i= 0; i < n; i ++)
    {
        min = i;
        for(j = i+1; j < n-1; j ++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


int main()
{
    int a[100], i, n;
    printf("Enter the no of items:");
    scanf("%d",&n);
    printf("Enter the numbers:\n");
    for(i = 0;i < n;i ++)
    {
        scanf("%d",&a[i]);
    }
    selectionSort(a,n);
    for(i = 0; i < n; i ++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
