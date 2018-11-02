#include <iostream>
#include <string>
#include <vector>

#include "shaker.h"
#include "bubble.h"
#include "quick.h"
#include "merge.h"

#include <limits>

using namespace std;

// initializer
template <class T>
void initialize(vector<T> &v, int size, const T *array){
  for(int i=0; i<size; i++)
    v.at(i) = array[i];
}

// show
template <class T>
void show(vector<T> &array1d){
  // for(vector<int>::iterator it=array1d.begin(); it!=array1d.end(); ++it)
  //   cout<< *it << " ";
  // cout<< endl;
  for(int i=0; i<array1d.size(); i++)
    cout<< array1d.at(i) << " ";
  cout<< "\n----------\n";
}


int main(){
  int a[] = {12, 1, 5, 7, 9, 3, 10, 2, 6, 8, 0, 4, 11};
  vector<int> vect; vect.resize(13,0);

  // original vector
  initialize( vect, 13, a);
  cout<< "original vector:\n";
  show(vect);

  // bubble sort
  cout<< "sort: bubble\n";
  bubble(vect); show(vect);

  // shaker sort
  initialize( vect, 13, a);
  cout<< "sort: shaker\n";
  shaker(vect); show(vect);

  // quick sort
  initialize( vect, 13, a);
  cout<< "sort: quick\n";
  quick(vect, 0, vect.size()-1); show(vect);

  // merge sort
  initialize(vect, 13, a);
  cout<< "sort: merge\n";
  merge(vect, 0, vect.size()-1); show(vect);

  return 0;
}
