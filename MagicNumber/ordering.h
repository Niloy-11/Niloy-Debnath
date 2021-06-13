// make number as high to low order
int descending_order(int number, int length_of_number) {
    int *number_array = (int*) calloc(sizeof(int), length_of_number);
    if (number_array == NULL) {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length_of_number; i++) {
        number_array[i] = number % 10;
        number /= 10;
    }
    number = 0;

    ascending_sort(number_array, length_of_number);
    for (int i = 0; i < length_of_number; i++) {
        number += number_array[i] * ((int) pow(10, i));
    }

    free(number_array);
    return number;
}

// make number as low to high number
int ascending_order(int number, int length_of_number) {
    int *number_array = (int*) calloc(sizeof(int), length_of_number);
    if (number_array == NULL) {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < length_of_number; i++) {
        number_array[i] = number % 10;
        number /= 10;
    }
    number = 0;

    descending_sort(number_array, length_of_number);
    for (int i = 0; i < length_of_number; i++) {
        number += number_array[i] * ((int) pow(10, i));
    }
    
    free(number_array);
    return number;
}
