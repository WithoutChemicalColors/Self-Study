#include <iostream>
#include <vector>
using namespace std;

// use vector to build matrix class
template <class T>
class Matrix{
private:
  vector<T> col;                // cols
  vector< vector<T> > matrix;   // whole matrix with columns: col
  int nrows, ncols;

public:
  Matrix(int nr, int nc);                // Constructure: Matrix
	Matrix(T *input, int nr, int nc); // Constructure: Matrix initialize with input array
  void show();                           // print the matrix
  vector<T> at(int rdx);                 // "at" func for Matrix<T>
  void set(int i, int j, T number);      // set value replace operator =
  Matrix<T> add(Matrix<T> natrix);
};
/////////////////////////////////////////////////////////////////
int main(){
  printf("%s\n", "hello world");
  double input[4][5] = { { 3, 1, 4,-1,  7},
                         { 2,-2,-1, 2,  1},
                         { 5, 7,14,-8, 20},
                         { 1, 3, 2, 4, -4} };

  Matrix<double> array(*input, 4, 5);
  array.show();

  array.set(1,2,100);
  array.show();

  (array.add(array)).show();

  return 0;
}
/////////////////////////////////////////////////////////////////////////
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
  nrows = nr;
  ncols = nc; // memorize nrows, and ncols;
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
