#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[5] = {1, 3, 7, 4, 0};
    int *P[5], *pA;
    int i, x, y;

    // Set pointer to the base address of array
    //
    // Problem: pA was dereferenced which is not how you assign a pointer to point at an array
    //          the pointer was pointing at the memory address of the array i.e. &A which is not possible,
    //          arrays are called by reference
    // *pA = &A;
    //

    pA = A;

    // Assign A[1] to x and y
    pA = pA + 1;
    x = *pA;
    y = A[1];

    printf("x = %d\t", x);
    printf("y = %d\t", y);

    // *P[0] = 10;
    // printf("pointer: %d\t", *P[0]);

    // Set every pointer to one array element
    for (i = 0; i < 5; i++)
    {
        P[i] = &A[i];
        // printf("%d\t", *P[i]);
        // printf("%d\t", A[i]);
    }

    // print array elements using pointers
    for (i = 0; i < 5; i++)
    {
        printf("%d\t", *P[i]);
    }

    return 0;
}