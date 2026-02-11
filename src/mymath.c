#include<src/mymath.h>
#include<stdlib.h>

double polynomial_eval(DoubleArray array, double x) {
    double res = 0;
    for (int i = array.length - 1; i >= 0; i--) {
        res = res * x + array.numbers[i];
    }
    return res;
}


void free_double_array(DoubleArray array) {
    return free(array.numbers);
}