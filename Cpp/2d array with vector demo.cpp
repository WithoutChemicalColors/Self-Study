// <Easy Demo -- 2D array>
// int nrows = 3;
// int ncols = 3;

// <way I>
// vector<int> col; col.resize(ncols, 0);
// vector< vector<int> > array; array.resize(nrows, col);

// <way II>
// vector< vector<int> > array;
// array.resize(nrows, vector<int>(ncols));

// int index = 0;
// for(int i=0; i<nrows; i++)
//   for(int j=0; j<ncols; j++, index++)
//     array.at(i).at(j) = index;
//
// for(int i=0; i<nrows; i++){
//   for(int j=0; j<ncols; j++)
//     cout<< array.at(i).at(j) <<" ";
//   cout<<endl;
// }
