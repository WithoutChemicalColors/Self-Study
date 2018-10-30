#include <iostream>
using namespace std;

void show1d_1(double input[], int nrows){
  // int nrows = sizeof(input)/sizeof(double);
  // --> this will show 1
  for(int i=0; i<nrows; i++)
    cout<< input[i] << " ";
  cout<< endl;
}

void show1d_2(double *input, int nrows){
  for(int i=0; i<nrows; i++)
    cout<< *(input+i) << " "; // input[i] is also OK
  cout<< endl;
}
// NOT recommand?
// void show1d_3(double (&input)[5], int nrows){
//   for(int i=0; i<nrows; i++)
//     cout<< input[i] << " "; // input[i] is also OK
//   cout<< endl;
// }

void show2d_1(double input[][5], int nrows, int ncols){
  // double input[][] will fail
  for(int i=0; i<nrows; i++){
    for(int j=0; j<ncols; j++)
      cout<< input[i][j] << " ";
    cout<< endl;
  }
}

void show2d_2(double *input, int nrows, int ncols){
  // the *input means 1D array of address.
  // there's no more 2d array here.
  // So, input[i][j] will fail
  for(int i=0; i<nrows; i++){
    for(int j=0; j<ncols; j++)
      cout<< *(input + i*ncols + j) << " ";
    cout<< endl;
  }
}

int main(){
  double array1d[] = { 1, 2, 3, 4, 5};
  double array2d[4][5] = { { 3, 1, 4,-1,  7},
                           { 2,-2,-1, 2,  1},
                           { 5, 7,14,-8, 20},
                           { 1, 3, 2, 4, -4} };

  cout<< "This is show1d_1:" << endl;
  show1d_1(array1d, 5);
  cout<< "----------" << endl;

  cout<< "This is show1d_2:" << endl;
  show1d_2(array1d, 5);
  cout<< "----------" << endl;

  // DON'T USE 'pass by reference'?
  // cout<< "This is show1d_3:" << endl;
  // show1d_3(array1d, 5);
  // cout<< "----------" << endl;
  cout<< "array2d is: " << array2d << endl;
  cout<< "*array2d is: " << *(array2d) << endl;
  cout<< "**array2d is: " << **array2d << endl;
  cout<< "array2d+1 is: " << array2d+1 << endl;
  cout<< "*(array2d+1) is: " << *(array2d+1) << endl;
  cout<< "**(array2d+1) is: " << **(array2d+1) << endl;
  cout<< "----------" << endl;

  cout<< "This is show2d_1:" << endl;
  show2d_1(array2d, 4, 5);
  cout<< "----------" << endl;

  cout<< "This is show2d_2:" << endl;
  show2d_2(*array2d, 4, 5);  // pass 1d array
  cout<< "----------" << endl;

  return 0;
}
