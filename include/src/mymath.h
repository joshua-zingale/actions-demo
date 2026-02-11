#define DOUBLE_ARRAY(...) (DoubleArray){\
    .length = sizeof((double []){__VA_ARGS__}) / sizeof(double), \
    .numbers = (double[]){__VA_ARGS__}\
}

typedef struct {
    int length;
    double *numbers;
} DoubleArray;


void free_double_array(DoubleArray);

double polynomial_eval(DoubleArray coefficients, double x);