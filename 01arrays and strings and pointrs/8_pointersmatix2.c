#include<stdio.h>
 
int main()
{
  int arr[5] = { 1, 2, 3, 4, 5 };
//   int *ptr = arr;
 
//   printf("%p\n", ptr);


   // Pointer to an integer
    int *p;
     
    // Pointer to an array of 5 integers
    int (*ptr)[5];
    
     
    // Points to 0th element of the arr.
    p = arr;
     
    // Points to the whole array arr.
    ptr = &arr;
     
    printf("p = %p, ptr = %p\n", p, ptr);
     
    p++;
    ptr++;
     
    printf("p = %p, ptr = %p\n", p, ptr);

    printf("p = %p, ptr = %p\n", p, ptr);
    printf("*p = %d, *ptr = %p\n", *p, *ptr);
     
    printf("sizeof(p) = %lu, sizeof(*p) = %lu\n",sizeof(p), sizeof(*p));
    printf("sizeof(ptr) = %lu, sizeof(*ptr) = %lu\n",sizeof(ptr), sizeof(*ptr));

    ptr++;
    printf("*p = %d, *ptr = %p\n", *p, *ptr);
    return 0;
 
}