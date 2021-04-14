#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Determine_SumOfdivisor(int);
void Determine_Amicable(int);

int main(void) {
    int *All_Numbers, Range;

    printf("Input RANGE: ");
    scanf("%d", &Range);

    Determine_Amicable(Range);

    return 0;
}

int Determine_SumOfdivisor(int number) {
    int sumOf_ProperDivisor = 1, square_root = sqrt(number);

    for (int i = 2; i <= square_root; i++) {
        if (!(number % i)) {
            sumOf_ProperDivisor += (i + number / i);
        }
    }

    return sumOf_ProperDivisor;
}

void Determine_Amicable(int range) {
    int amicable;
    int* All_Numbers = (int*) calloc(range, sizeof(int));

    for (int i = 1; i < range; i++) {
        amicable = Determine_SumOfdivisor(i);

        if (amicable <= range) {
            if (Determine_SumOfdivisor(amicable) == i) {
                if (i < amicable) {
                    All_Numbers[i] = amicable;
                }
            }
        }
    }

    for (int i = 1; i < range; i++) {
        if (All_Numbers[i]) {
            printf("(%d, %d)\n", i, All_Numbers[i]);
        }
    }

    free(All_Numbers);
}
