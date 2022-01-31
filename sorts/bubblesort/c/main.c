#include <stdio.h>

void Swap(double *y, double *x)
{
    // swap two values in memory
    const double tmp = *y;
    *y = *x;
    *x = tmp;
}

int main() {
    double array[] = {1000.0, 2.0, 3.4, 7.0, 50.0, 3.14, 71, 28, 12}; // values to sort
    const unsigned int arrayLength = sizeof array / sizeof *array;    // get array length

    // sort
    for (unsigned int i = 0; i < arrayLength - 1; i++) {
        for (unsigned int j = 0; j < arrayLength - 1 - i; j++) {
            if (array[j] > array[j + 1]) // if two elements are not sort, swap them
                Swap(&array[j], &array[j + 1]); 
        }
    }

    // print
    printf("sorted array: ");
    // print every element in array
    for (unsigned int i = 0; i < arrayLength - 1; i++) { 
        // if it's frist element don't print comma
        if(i == 0) 
            printf("%g",array[i]);
        else 
            printf(", %g ",array[i]);
    }
    printf("\n");

    return 0;
}