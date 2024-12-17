#include <stdio.h>
int binarysearch(int arr[],int left, int key, int right)
{
    if(left>right)
    {
        return -1;
    }
    int mid = (left + right)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    else if(key < arr[mid])
    {
        return binarysearch(arr, key, left, mid-1);
    }
    else
    {
        return binarysearch(arr, key, mid+1, right);
    }
    
}

int main()
{
   int n, key;
   printf("enter the number of elements in the list");
   scanf("%d", &n);
   int arr[n];
   printf("enter the element in ascending order:\n");
   for(int i=0; i<n; i++)
   {
    scanf("%d", &arr[i]);
   } 
   printf("enter the key element");
   scanf("%d", &key);
   int result = binarysearch(arr, key, 0, n-1);

   if(result != -1)
   {
    printf("the key element found at location ");
   }
   else{
    printf("the key element not found");
   }
   return 0;
}