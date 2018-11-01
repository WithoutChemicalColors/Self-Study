#include <iostream>
#include <vector>
using namespace std;

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
