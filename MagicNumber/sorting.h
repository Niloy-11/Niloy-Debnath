// determine size of integer
int how_many_integers(int number) {
    int integer_count = 0;

    while (number) {
        integer_count++;
        number /= 10;
    }
    return integer_count;
}

// sort lower to higher
void ascending_sort(int *number_array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        for (int j = i + 1; j < array_size; j++) { 
            if (number_array[i] > number_array[j]) {
                int temp = number_array[i];
                number_array[i] = number_array[j];
                number_array[j] = temp;
            }
        }
    }
}

// sort higher to lower
void descending_sort(int *number_array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        for (int j = i + 1; j < array_size; j++) { 
            if (number_array[i] < number_array[j]) {
                int temp = number_array[i];
                number_array[i] = number_array[j];
                number_array[j] = temp;
            }
        }
    }
}
