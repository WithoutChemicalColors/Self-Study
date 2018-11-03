#include <iostream>
#include <stdlib.h>
#include <vector>     // in case, not used here
#include <functional> // functional construction...
using namespace std;

// calculate the differential of function by the method: central difference
double diff(const function<double(double)> &f, double x, double eps){
    double eps2 = eps/2;
    return (f(x+eps2) - f(x-eps2)) / eps;
}

// function 0 : x^2
double square(double x){
    return x*x;
}

// functon 1 : x^3 + 2x^2 - 3x - 1
double func1(double x){
    return x*x*x + 2*x*x - 3*x - 1;
}

// Easy newton implementation
double newton(const function<double(double)> &f, double x_t0, double eps){
    return x_t0 - f(x_t0) / diff(f, x_t0, eps);
}

int main(){
    // parameters setting
    double x_t1 = 2, x_t0 = 2;
    double eps = 1e-4;
    double threshold = 1;

    // counter -- in case of an infinite loop
    int counter = 0;

    // main process for newton loop
    cout<< "iteration start" << endl;
    cout<< "----------\n";
    do{
        x_t1 = newton(func1, x_t0, 1e-4);
        threshold = (x_t1 > x_t0) ? (x_t1-x_t0) : (x_t0-x_t1);
        printf("x_t1: %.5f, x_t0: %.5f, threshold: %.5f\n", x_t1, x_t0, threshold);
        x_t0 = x_t1;
        counter++;
        if(counter >= 100) break;
    }while(threshold > 1e-4);
    cout<< "----------\n";
    cout<< "The minimam happens at: " << x_t0 << endl;
    cout<< "Its value is: " << func1(x_t0) << endl;
    return 0;
}
