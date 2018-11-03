#ifndef MATRIX_H
#define MATRIX_H
#endif

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
