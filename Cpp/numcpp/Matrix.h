#include <vector>

// use vector to build matrix class
template <class T>
class Matrix{
private:
  vector<T> col;                // cols
  vector< vector<T> > matrix;   // whole matrix with columns: col

public:
  Matrix(int nr, int nc);                // Constructure: Matrix
	Matrix(T *input, int nr, int nc);      // Constructure: Matrix initialize with input array
  int nrows;
  int ncols;
  void show();                           // print the matrix
  vector<T> at(int rdx);                 // 1d "at" func for Matrix<T>
  T at(int rdx, int cdx);                // 2d "at" func
  void set(int i, int j, T number);      // set value replace operator =
  Matrix<T> add(Matrix<T> natrix);       // add function
  Matrix<T> operator+(Matrix<T> natrix); // add function by operator +
  Matrix<T> matmul(Matrix<T> natrix);    // matrix multiplication
  Matrix<T> operator@(Matrix<T> natrix); // matrix multiplication
};


// Constructure of Matrix<T>
template <class T>
Matrix<T>::Matrix(int nr, int nc){
  // memorize nrows, and ncols;
  nrows = nr;
  ncols = nc;
  // create in parivate
  col.resize(ncols, 0);
  matrix.resize(nrows, col);
}

// Constructure by Initializer
template <class T>
Matrix<T>::Matrix(T *input, int nr, int nc){
  // memorize nrows, and ncols;
  nrows = nr;
  ncols = nc;
  col.resize(ncols, 0);
  matrix.resize(nrows, col); // create in parivate
	for(int i=0; i<nr; i++){
    for(int j=0; j<nc; j++){
      matrix[i][j] = *(input + i*nc + j);
    }
  }
}

// print the matrix
template <class T>
void Matrix<T>::show(){
  for(int i=0; i<nrows; i++){
    for(int j=0; j<ncols; j++)
      cout<< matrix.at(i).at(j) <<' ';
    cout<< endl;
  }
  cout<< "----------" << endl;
}

// "at" func for Matrix<T>
template <class T>
vector<T> Matrix<T>::at(int rdx){
  return matrix.at(rdx);
}

// 2d "at" function
template <class T>
T Matrix<T>::at(int rdx, int cdx){
  return matrix.at(rdx).at(cdx);
}

template <class T>
void Matrix<T>::set(int i, int j, T number){
  matrix.at(i).at(j) = number;
}

template <class T>
Matrix<T> Matrix<T>::add(Matrix<T> natrix){
  Matrix<T> ans(nrows, ncols);
  for(int i=0; i<nrows; i++)
    for(int j=0; j<ncols; j++)
      ans.set(i, j, matrix.at(i).at(j) + natrix.at(i).at(j));
  return ans;
}

template <class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> natrix){
  Matrix<T> ans(nrows, ncols);
  for(int i=0; i<nrows; i++)
    for(int j=0; j<ncols; j++)
      ans.set(i, j, matrix.at(i,k) + natrix.at(k,j) );
  return ans;
}
// matrix multiplication
template <class T>
Matrix<T> Matrix<T>::matmul(Matrix<T> natrix){
  Matrix<T> ans(nrows, ncols);
  for(int i=0; i<nrows; i++)
    for(int j=0; j<ncols; j++)
      for(int k=0; k<nrows; k++)
        ans.set(i, j, matrix.at(i,k) * matrix.at(k,j) );
}
Matrix<T> operator@(Matrix<T> natrix); // matrix multiplication
