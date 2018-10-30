#include <iostream>
#include "Matrix.h"
using namespace std;

template <class T>
Matrix<T> GE(Matrix<T> matrix);

int main(){

  cout<< "CPP GE Implementation" << endl;
  cout<< "---------------------" << endl;
  double input1[ ][2] = { { 1, 2},
                          { 3, 4}  };

  double input2[4][5] = { { 3, 1, 4,-1,  7},
                          { 2,-2,-1, 2,  1},
                          { 5, 7,14,-8, 20},
                          { 1, 3, 2, 4, -4} };

  Matrix<double> array1(*input1, 2, 2);
  Matrix<double> array2(*input2, 4, 5);
  cout<< array1.nrows << array1.ncols << endl;
  array1.show();

  cout<< "operator+" << endl;
  (array1+array1).show();

  GE(array1).show();


  return 0;
}

template <class T>
Matrix<T> GE(Matrix<T> matrix){
  int nrows = matrix.nrows;
  int ncols = matrix.ncols;
  for(int step=0; step<nrows-1; step++){
    double pivot = matrix.at(step, step);

    for(int row=step+1; row<nrows; row++){
      double ratio = matrix.at(row, step) / pivot;
      matrix.set(row, step, 0);

      for(int col=step+1; col<ncols; col++){
        matrix.set(row, col, matrix.at(row, col) - ratio*matrix.at(step, col) );
      }
    }
  }

  return matrix;
}
