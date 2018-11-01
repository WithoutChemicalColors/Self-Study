#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// merge sort
template <class T>
void _combine(vector<T> &vect, int sdx, int mdx, int edx){
    vector<T> left_vect(vect.begin()+sdx, vect.begin()+mdx+1);
    vector<T> right_vect(vect.begin()+mdx+1, vect.begin()+edx+1);

    int left_id=0, right_id=0;

    left_vect.insert(left_vect.end(), numeric_limits<T>::max());
    right_vect.insert(right_vect.end(), numeric_limits<T>::max());

    for(int i=sdx; i<=edx; i++){
        if(left_vect.at(left_id) < right_vect.at(right_id)){
            vect.at(i) = left_vect.at(left_id);
            left_id++;                                  }
        else{
            vect.at(i) = right_vect.at(right_id);
            right_id++;                                 }
    }
}

template <class T>
void merge(vector<T> &vect, int sdx, int edx){
    if(sdx < edx){
        int mdx = (sdx+edx)/2;
        merge(vect, sdx, mdx);
        merge(vect, mdx+1, edx);
        _combine(vect, sdx, mdx, edx);      }
}
