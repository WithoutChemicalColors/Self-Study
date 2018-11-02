#include <iostream>
#include <functional>

double derivative(const std::function<double(double, int)> &f, double x0, double eps) {
    double eps2 = eps / 2;
    double lo = x0 - eps2;
    double hi = x0 + eps2;
    return (f(hi, 3) - f(lo, 4)) / eps;
}

double f(double x, int k) {
    // k is useless
    // just for 2 variables demonstration.
    return x * x;
}

int main() {
    double x = 1;
    std::cout << "d/dx(x ^ 2) [@ x = " << x << "] = " << derivative(f, x, 1e-5) << std::endl;
    return 0;
}
