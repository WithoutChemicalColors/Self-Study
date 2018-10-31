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

// quick sort -- partition
template <class T>
int _partition(vector<T> &vect, int sdx, int edx){
  int sm_ = sdx-1;
  T pivot = vect[edx];
  for(int j=sdx; j<edx; j++)
    if(vect[j] <= pivot){
      sm_++;
      swap(vect[j], vect[sm_]);
    }
  sm_++;
  swap(vect[sm_], vect[edx]);
  return sm_;
}

// quick sort -- main algorithm
template <class T>
void quick(vector<T> &vect, int sdx, int edx){
  if(sdx < edx){
    int sm_ = _partition(vect, sdx, edx);
    quick(vect, sdx, sm_-1);
    quick(vect, sm_+1, edx);                 }
}
