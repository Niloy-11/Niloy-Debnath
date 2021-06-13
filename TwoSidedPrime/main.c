// Two Sided Prime
// For example 739397 is a 'Two Sided Prime' Number
// if we turncate the number from right to left or left to right
// we get all sub set of the this number element as a prime number

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "additional_fnc.h"

int main(void) {
    int num, size;

    printf("Enter number: ");
    scanf("%d", &num);

    size = integer_count(num);
    TwoSided_prime(num, size) ? puts("Two sided prime\n") : puts("Nor\n");

    return 0;
}
