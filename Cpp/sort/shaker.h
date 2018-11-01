#include <iostream>
#include <vector>
using namespace std;

// shaker -- shift max to the right and min to the left in the meanwhile.
template <class T>
void shaker(vector<T> &array1d){
  int i, j;
  int left_id = 0;
  int right_id = array1d.size()-1;

  while(left_id < right_id){

    // shift max to the right
    for(i=left_id; i<right_id; i++)
      if(array1d.at(i) >= array1d.at(i+1))
        swap(array1d.at(i), array1d.at(i+1));

    // shift min to the left
    for(j=right_id-1; j>left_id; j--)
      if(array1d.at(j) <= array1d.at(j-1))
        swap(array1d.at(j), array1d.at(j-1));

    left_id += 1;
    right_id -= 1;
  }
}
