#include <iostream>
#include "stack.h"
using namespace std;

int main(){
    Stack<int> stack(5);
    stack.push(5);
    stack.push(10);
    stack.push(20);
    stack.show();
    cout<< "----------" << endl;
    cout<< "Stack of size " << stack.size() << " is made."<< endl;
    cout<< "now there are " << stack.length() << " things inside"<< endl;
    cout<< "----------" << endl;
    cout<< "pop the last number: " << stack.pop() << endl;
    cout<< "Stack of size " << stack.size() << " is made."<< endl;
    cout<< "now there are " << stack.length() << " things inside"<< endl;
    stack.show();

    return 0;
}
