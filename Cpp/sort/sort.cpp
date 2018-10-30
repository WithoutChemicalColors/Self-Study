#include <iostream>
#include <string>
#include <vector>

using namespace std;

// initializer
template <class T>
void initialize(vector<T> &v, int size, const T *array);

// bubble -- shift max to the right
template <class T>
void bubble(vector<T> &array1d);

// shaker -- shift max to the right and min to the left in the meanwhile.
template <class T>
void shaker(vector<T> &array1d);

// show
template <class T>
void show(vector<T> &array1d);

int main(){
  int a[] = {1, 5, 7, 9, 3, 2, 6, 8, 0, 4};
  vector<int> vect({1, 5, 7, 9, 3, 2, 6, 8, 0, 4});
  cout<< "original vector: ";
  show(vect);
  cout<< "sort: bubble\n";
  bubble(vect); show(vect);

  initialize( vect, 10, a);
  cout<< "sort: shaker\n";
  shaker(vect);
  show(vect);

  return 0;
}

template <class T>
void initialize(vector<T> &v, int size, const T *array){
  for(int i=0; i<size; i++)
    v.at(i) = array[i];
}

template <class T>
void show(vector<T> &array1d){
  // for(vector<int>::iterator it=array1d.begin(); it!=array1d.end(); ++it)
  //   cout<< *it << " ";
  // cout<< endl;
  for(int i=0; i<array1d.size(); i++)
    cout<< array1d.at(i) << " ";
  cout<< "\n----------\n";
}

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
