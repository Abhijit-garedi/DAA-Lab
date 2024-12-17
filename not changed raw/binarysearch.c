#include <stdio.h>

int binarysearch(int arr[], int left, int key, int right) 
{
    if (left > right) 
    {
        return -1;
    }




    int mid = (left + right) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
     else if (key < arr[mid])
      {
        return binarysearch(arr, left, key, mid - 1); 
      } 
    else 
    {
        return binarysearch(arr, mid + 1, key, right); 
    }
}









int main() 
{
    int n, key;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in ascending order:\n");
    for (int i = 0; i < n; i++)
     {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key element: ");
    scanf("%d", &key);
    int result = binarysearch(arr, 0, key, n - 1);

    if (result != -1) 
    {
        printf("The key element is found at location %d\n", result + 1); 
        printf("The key element is not found\n");
    }
    return 0;
}
