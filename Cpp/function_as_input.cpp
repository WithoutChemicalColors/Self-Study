#include <iostream>
using namespace std;

double add(double left, double right) {
    return left + right;
}

double binary_op(double left, double right, double (*f)(double, double)) {
    return (*f)(left, right);
}

int main(){
    double a = 5.0;
    double b = 10.0;
    cout << "Add: " << binary_op(a, b, add) << endl;

    return 0;
}
