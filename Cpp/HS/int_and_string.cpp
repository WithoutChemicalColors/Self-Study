#include <iostream>
#include <vector>
using namespace std;

template <class T>
void show(const T brain){
    for(int i=0; i<brain.size(); i++)
        cout<< brain.at(i) << ' ';
    cout<< endl << "----------" << endl;
}

int main(){
    string sent = "1234567";
    show(sent);
    for(int i=0; i<sent.size(); i++){
        sent.erase(sent.begin());
        cout<< i << " : " << sent.size() << endl;
    }

    vector<char> vect({'1','2',')'});
    show(vect);
    if( vect.back()==')')
        cout<<"YES"<<endl;

}
