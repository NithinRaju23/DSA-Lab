                                             //LINEAR SEARCH//                                 

🎯 Aim:
     To find a given number in a list using the Linear Search method, checking each element one by one.
Algorithm:
    Step 1: start from index 0 and compare each element with target.
    Step 2: if arr[i] is not equal to target, increment i.
    Step 3: Continue until you find arr[i] equals the target.
    Step 4: Return the index i where the target is found.
    Step 5: If end is reached and target is not found return -1.
code:
    #include <stdio.h>

int linear_search(int arr[], int size, int term) 
{
   
    for (int i = 0; i < size; i++) 
	{
     
        if (arr[i] == term)
            return i; 
    	}
   
    return -1; 
}

int main() 
{
    int size, term;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) 
	{
        scanf("%d", &arr[i]);
    	}

    printf("Enter number to search: ");
    scanf("%d", &term);

   
    int result = linear_search(arr, size, term);
    
    
    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}

Output:
Enter the size of the array : 5
Enter the elements of the array : 2 4 6 8 10
Enter the element to search : 6
Element found at position 3

Result:
This program searches an element in an array using linear search and correctly displays whether the element is found or not.


