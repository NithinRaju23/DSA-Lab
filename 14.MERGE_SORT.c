                                                  //MERGE SORT//

//Aim : To sort an array of elements using the Merge Sort algorithm based on Divide and Conquer technique.//

🧭 Algorithm:

BEGIN
🔷 1. merge(arr, left, mid, right)
(Merge two sorted subarrays)
Set i = left (start of left subarray).
Set j = mid + 1 (start of right subarray).
Set k = 0 (index of temporary array).
Create a temporary array temp[] to store merged elements.
While both subarrays have elements:
a. If arr[i] < arr[j], copy arr[i] to temp[k], increment i and k.
b. Else copy arr[j] to temp[k], increment j and k.

Copy remaining elements from left subarray (if any).

Copy remaining elements from right subarray (if any).
Copy all elements from temp[] back to the original array from index left to right.
🔷 2. mergeSort(arr, left, right)
If left < right:
a. Find middle index:
→ mid = (left + right) / 2
b. Recursively sort the left half:
→ mergeSort(arr, left, mid)
c. Recursively sort the right half:
→ mergeSort(arr, mid + 1, right)
d. Call merge() to merge the two sorted halves.
🔷 3. Main Program
Read number of elements n.
Read n elements into arr.
Call mergeSort(arr, 0, n - 1).
Print the sorted array.
End program.
END

  🧭 Code:

#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

        while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);      
        mergeSort(arr, mid + 1, right); 
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

OUTPUT:
Input:
Enter number of elements: 6
Enter 6 elements:
5 2 8 0 13 4

Program Output:
Sorted array (Merge Sort): 0 2 4 5 8 13

RESULT:
The Merge Sort program successfully:
Reads input elements from the user.
Divides the array into smaller subarrays.
Sorts them recursively.
Merges them back into a fully sorted array.
For the sample input, the final sorted array is:
0 2 4 5 8 13
