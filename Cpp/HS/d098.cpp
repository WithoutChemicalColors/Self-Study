#include <iostream>
#include <sstream>
using namespace std;

template <class T>
void show(T input){
    for(int i=0; i<input.size(); i++){
        cout<< input.at(i);
    }
    cout<< endl;
}

bool all_number(string buffer){
    for(string::iterator it=buffer.begin(); it!=buffer.end(); ++it){
        if( isdigit(*it) )
            continue;
        else{
            return false;
        }
    }
    return true;
}

int main(){
    string input;
    while(getline(cin, input)){
        string buffer;
        int temp, sum=0;
        input.push_back(' ');
        while( input.size()>0 ){
            buffer += input.front();
            if( input.front()==' ' ){
                buffer.pop_back();
                if( all_number(buffer) ){
                    istringstream(buffer) >> temp;
                    sum += temp;
                }
                buffer.clear();
            }
            input.erase(input.begin());
        }
        cout<< sum << endl;
    }
    return 0;
}
