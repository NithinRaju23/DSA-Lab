
#include <stdio.h>

// Swap two numbers using pointers (changes persist in the original array)
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// and arranges smaller elements to the left, larger to the right
int partition(int list[], int low, int high)
{
    int pivot = list[high];  // choosing the last element as pivot
    int i = low - 1;         // index of the smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than the pivot
        if (list[j] < pivot)
        {
            i++;
            swap(&list[i], &list[j]); 
        }
    }
    // Place pivot in correct position
    swap(&list[i + 1], &list[high]);
    return i + 1;
}

// Recursive Quick Sort function
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(list, low, high);  

        quickSort(list, low, pi - 1); 
        quickSort(list, pi + 1, high); 
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int list[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    quickSort(list, 0, n - 1);

    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);

    return 0;
}
