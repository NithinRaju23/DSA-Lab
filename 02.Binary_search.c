🧭 Aim:
  To write a C program that performs Binary Search on a sorted array to find the position of a given element.
⚙️ Algorithm:
  • Divide the search space into two halves by finding the middle index "mid".
  • Compare the middle element of the search space with the key.
  • If the key is found at middle element, the process is terminated.
  • If the key is not found at middle element, choose which half will be used as the next
  search space.
  – If the key is smaller than the middle element, then the left side is used for next
  search.
  – If the key is larger than the middle element, then the right side is used for next
  search.
  • This process is continued until the key is found or the total search space is exhausted.   
code:
#include <stdio.h>
int binary_search(int arr[], int size, int term) 
{
    int left = 0;               
    int right = size - 1;       
    while (left <= right) 
	{
        int mid = left + (right - left) / 2; 
     if (arr[mid] == term)                
            return mid;                      
        else if (arr[mid] < term)           
            left = mid + 1;
        else
            right = mid - 1;
   	 }
    return -1;                               
}
int main() 
{
    int size, term;
    printf("Enter size of array: ");          
    scanf("%d", &size);
    int arr[size];                           
    printf("Enter %d sorted numbers:\n", size);
    for (int i = 0; i < size; i++)
	 {         
        scanf("%d", &arr[i]);
    	  }
     printf("Enter number to search: ");      
    scanf("%d", &term);

    int result = binary_search(arr, size, term); 
    if (result != -1)                         
        printf("Found at index %d\n", result);
    else                                      
        printf("Not found\n");

    return 0;  
}

Output:
Enter the number of elements : 5
Enter the 5 elements in sorted order : 4 8 12 16 20
Enter the element to search : 12
The Element 12 is found at position 3

Result:
This program uses binary search to quickly find an element in a sorted array and displays whether the element is found or not.





