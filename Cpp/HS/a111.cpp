#include <iostream>
using namespace std;
int main(int argc, char **argv){
    int input;
    while(cin>> input && input!=0){
        int sum = 0;
        for(int i=1; i<=input; i++){
            sum += i*i;
        }
        cout<< sum << endl;
    }
    return 0;
}
