#include <stdio.h>
void printArray(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void insertionSort(int *A, int n)
{
    int key, j;
    for (int i = 1; i <=n - 1; i++)
    {
        key = A[i]; // element which will insert/move
        j = i - 1;  // j would be one step before the key index
        while (j >= 0 && A[j] > key)   //loop for each pass
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
int main()
{
    int A[]= {12, 54, 65, 9, 67, 8};
    int n = 6;
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    // printArray(A, n);

    return 0;
}