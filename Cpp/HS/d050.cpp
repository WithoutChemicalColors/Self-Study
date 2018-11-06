#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int input;
    while(cin>> input){
        int output;
        output = input - 15;
        if( output<0 )
            output += 24;
        cout<< output << endl;
    }
    return 0;
}
