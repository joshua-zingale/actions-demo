#include<stdio.h>
#include<stdlib.h>

#include<src/mymath.h>


int validate_double(double *result, const char *str) {
    char *endptr;

    double val = strtod(str, &endptr);


    if (str == endptr) {
        return 1;
    }

    if (*endptr != '\0') {
        return 1;
    }

    *result = val;

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
     fprintf(stderr, "Usage: %s INPUT [COEFFICIENTS ...]\n", argv[0]);
     return 1;   
    }


    double x;

    if (validate_double(&x, argv[1]) != 0) {
        fprintf(stderr, "Invalid number, '%s'\n", argv[1]);
        return 1;
    }

    DoubleArray coefficients;
    coefficients.length = argc - 2;
    coefficients.numbers = malloc(sizeof(double) * coefficients.length);

    for (int i = 0; i < coefficients.length; i++) {
        int argvIdx = i + 2;
        if (validate_double(&coefficients.numbers[i], argv[argvIdx]) != 0) {
            fprintf(stderr, "Invalid number, '%s'\n", argv[argvIdx]);
            return 1;
        }
    }

    double res = polynomial_eval(coefficients, x);

    printf("%.5g\n", res);

    free_double_array(coefficients);
    return 0;
}

