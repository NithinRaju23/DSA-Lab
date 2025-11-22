

/*
===========================================================
                        AIM
===========================================================
To write a C program to search an element in a sorted array 
using Binary Search technique.

===========================================================
                      ALGORITHM
===========================================================
1. Start the program.
2. Read how many elements (n) the user wants to enter.
3. Read 'n' sorted numbers into an array.
4. Ask the user for the number to search (target).
5. Set two variables: left = 0 and right = n - 1.
6. Repeat while left <= right:
      a) Find mid = left + (right - left) / 2
      b) If arr[mid] == target → element found, return mid.
      c) If arr[mid] < target → move left to mid + 1.
      d) Else → move right to mid - 1.
7. If not found, return -1.
8. Display result on the screen.
9. Stop the program.
===========================================================
                        PROGRAM
===========================================================


#include <stdio.h>
int main()
{
    int size, targetElement, start, mid, end;
    printf("Enter the size of array: ");
    scanf("%d",&size);
   

    int searchSpace[size];

    //Reading elements into array
    for(int i=0;i<size;i++)
    {
        printf("Enter element %d of %d: ",i, size-1);
        scanf("%d",&searchSpace[i]);
    }

    printf("Enter the element to search ");
    scanf("%d",&targetElement);

    start = 0;
    end = size-1;

    while (start<=end)
    {
        mid = (start + end)/2;
        if(searchSpace[mid] == targetElement)
        {
            printf("Element found at index of %d (i.e. at position %d)", mid, mid+1);
            return 0;
        }
        else if(searchSpace[mid] < targetElement)
        {
            start = mid +1;
        }
        else
        {
            end = mid - 1;
        }
    }
    printf("ELement doesn't exist in the given search set");
    
   return 0;
}

