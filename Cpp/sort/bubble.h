#include <iostream>
#include <vector>
using namespace std;

// bubble -- shift max to the right
template <class T>
void bubble(vector<T> &array1d){
  T buffer;
  for(int i=0; i<array1d.size(); i++){
    for(int j=0; j<array1d.size()-1; j++){
      if( array1d.at(j) >= array1d.at(j+1) ){
        buffer = array1d.at(j);
        array1d.at(j) = array1d.at(j+1);
        array1d.at(j+1) = buffer;           }}}
}
