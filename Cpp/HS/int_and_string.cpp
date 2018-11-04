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
    vector<int> vect({0,1,2,3,4,5});
    show(vect);
    vect.erase(vect.begin()+1);
    show(vect);
    cout<< vect.size() << endl;

}
