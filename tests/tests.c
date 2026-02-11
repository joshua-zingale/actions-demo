#include<tests/harness.h>
#include<src/mymath.h>


int double_eq(double a, double b) {
    double abs = a > b ? a - b : b - a;
    return abs < 1e-5 ? 1 : 0;
}


TEST(Constant_Polynomial, ({
    DoubleArray coeffs = DOUBLE_ARRAY(-4);
    ASSERT(double_eq(polynomial_eval(coeffs, 1), -4));
    ASSERT(double_eq(polynomial_eval(coeffs, 0), -4));
    ASSERT(double_eq(polynomial_eval(coeffs, -1), -4));
    ASSERT(double_eq(polynomial_eval(coeffs, 67), -4));
    ASSERT(double_eq(polynomial_eval(coeffs, 25.5),-4));
    ASSERT(double_eq(polynomial_eval(coeffs, -25.5), -4));

    coeffs = DOUBLE_ARRAY(4.5);
    ASSERT(double_eq(polynomial_eval(coeffs, 1), 4.5));
    ASSERT(double_eq(polynomial_eval(coeffs, 0), 4.5));
    ASSERT(double_eq(polynomial_eval(coeffs, -1), 4.5));
    ASSERT(double_eq(polynomial_eval(coeffs, 67), 4.5));
    ASSERT(double_eq(polynomial_eval(coeffs, 25.5), 4.5));
    ASSERT(double_eq(polynomial_eval(coeffs, -25.5), 4.5));
}))

TEST(Identity_Polynomial, ({
    DoubleArray coeffs = DOUBLE_ARRAY(0.0, 1.0);
    ASSERT(double_eq(polynomial_eval(coeffs, 1), 1));
    ASSERT(double_eq(polynomial_eval(coeffs, 0), 0.0));
    ASSERT(double_eq(polynomial_eval(coeffs, -1), -1.0));
    ASSERT(double_eq(polynomial_eval(coeffs, 67), 67));
    ASSERT(double_eq(polynomial_eval(coeffs, 25.5), 25.5));
    ASSERT(double_eq(polynomial_eval(coeffs, -25.5), -25.5));
}))


TEST(Quadratic_Polynomial, ({
    DoubleArray coeffs = DOUBLE_ARRAY(1, 1, 2);
    ASSERT(double_eq(polynomial_eval(coeffs, 1), 4));
    ASSERT(double_eq(polynomial_eval(coeffs, 0), 1));
    ASSERT(double_eq(polynomial_eval(coeffs, -1), 2));
    ASSERT(double_eq(polynomial_eval(coeffs, 4.25), 41.375));
    ASSERT(double_eq(polynomial_eval(coeffs, -4.25), 32.875));
}))

