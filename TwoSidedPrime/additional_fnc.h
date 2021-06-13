// count how many integer in a number
int integer_count(int num) {
    int integer = 0;
    while (num) {
        integer++;
        num /= 10;
    }

    return integer;
}

// whether a number prime nor
int is_prime(int num) {
    if (num <= 1) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0;
    else {
        int square_root = sqrt(num);
        for (int i = 3; i <= square_root; i += 2) {
            if (!(num % i)) return 0;
        }
    }

    return 1;
}

// check whether 'num' is a left sided prime
int LeftSided_prime(int *number, int size) {
    int loop_time = size - 1;

    for (int i = 0; i < loop_time; i++) {
        int num = 0;
        for (int j = i + 1; j < size; j++) {
            num += number[j] * ((int)pow(10, loop_time - j));
        }
        
        if (is_prime(num)) {
            continue;
        } else return 0;
    }

    return 1;
}

// check whether 'num' is a right sided prime
int RightSided_prime(int *number, int size) {
    int loop_time = size - 1;

    for (int i = loop_time; i > 0; i--) {
        int num = 0;
        for (int j = i - 1, k = 0; j >= 0; j--, k++) {
            num += number[j] * ((int)pow(10, k));
        }
        
        if (is_prime(num)) {
            continue;
        } else return 0;
    }

    return 1;
}

// whether TwoSidedPrime or NOR
int TwoSided_prime(int num, int size) {
    int right_sided, left_sided;
    int *arr_num = (int*) calloc(sizeof(int), size);
    if (arr_num == NULL) {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = size - 1; i >= 0; i--) { 
        arr_num[i] = num % 10;
        num /= 10;
    }

    left_sided = LeftSided_prime(arr_num, size);
    right_sided = RightSided_prime(arr_num, size);
    free(arr_num);

    if (left_sided == right_sided) return 1;
    else return 0;
}
