#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sorting.h"
#include "ordering.h"

int step_count;
int magic_number(int num) {
    int sizeOF_number, high_num, low_num, carry, HighLow_diff;

    sizeOF_number = how_many_integers(num);
    high_num = descending_order(num, sizeOF_number);
    low_num = ascending_order(num, sizeOF_number);
    carry = num;
    HighLow_diff = high_num - low_num;
    if (!HighLow_diff || !(num / 100)) {
        puts("Number don't fill requirments\n");
        exit(1);
    }

    while (carry != HighLow_diff) {
        carry = HighLow_diff;
        sizeOF_number = how_many_integers(carry);
        high_num = descending_order(carry, sizeOF_number);
        low_num = ascending_order(carry, sizeOF_number);
        HighLow_diff = high_num - low_num;
        step_count++;
    }

    return HighLow_diff;
}

int main(void) {
    int number;
    scanf("%d", &number);
    printf("Magic number: %d", magic_number(number));
    printf("\tStep to reach: %d\n", step_count);

    return 0;
}