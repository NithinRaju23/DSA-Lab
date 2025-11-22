
#include <stdio.h>
void merge(int arr[], int left, int mid, int right)
{
    int i = left;        // pointer for left half
    int j = mid + 1;
    int k = 0;           // pointer for temp array
    int temp[right - left + 1];
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    // Copy remaining elements from the left half (if any)
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    // Move merged elements back into the original array
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2; 

        mergeSort(arr, left, mid);     
        mergeSort(arr, mid + 1, right); // sort right section
        merge(arr, left, mid, right); 
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
