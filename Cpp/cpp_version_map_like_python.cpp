#include <iostream>
#include <vector>
using namespace std;

void square(int &item){
    item = item*item;
}

void mapEX(void (*f)(int &item), vector<int> &vect){
    for(vector<int>::iterator it=vect.begin(); it!=vect.end(); ++it){
        (*f)(*it); }
}

void show(const vector<int> vect){
    for(int i=0; i<vect.size(); i++)
        cout<< vect.at(i) << " ";
    cout<< endl;
}

int main(){
    vector<int> vect({1,2,3,4,5,6,7,8,9,10});
    mapEX(square, vect);
    show(vect);

    return 0;
}

// Efficiency - Function pointers are inefficient when compared with functors (discussed below). The compiler will often pass them as raw pointers and as such the compiler will struggle to inline the code.
// State - Function pointers by themselves are not particularly flexible at storing state. Although it is possible, by using a local static variable within the function, there is only ever one global state for the function itself and as such this static variable must be shared. Furthermore this static variable will not be thread-safe, unless the appropriate thread synchronisation code is added. Thus it can lead to bottlenecks or even race conditions in multithreaded programs.
// Templates - Function pointers do not play too well with templates if there are multiple signatures of the function in your code. The solution is to use function pointer casting, which leads to difficult and ungainly syntax.
// Adaptation - Function pointers have fixed parameter types and quantities. Thus they are not particularly flexible when external functions with differing parameter types could be used. Although adapting the function pointers (by wrapping the external functions with hard-coded parameters) is possible, it leads to poor flexibility and bloated code.
