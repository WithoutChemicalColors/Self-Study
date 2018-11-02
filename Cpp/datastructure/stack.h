#include <iostream>
#include <stdexcept>

using namespace std;


template <class T>
class Stack{
private:
    int _top_id = -1;
    int _size;
    T *container;
public:
    Stack(const int &size);
    ~Stack(){ delete [] container;};
    int size(){ return _size; };
    int length(){ return _top_id+1; };
    void push(T item);
    void show();
    T pop();

};

template <class T>
Stack<T>::Stack(const int &size){
    _size = size;
    container = new T [_size];
}

template <class T>
T Stack<T>::pop(){
    if(_top_id == -1){
        throw invalid_argument("Nothing Inside");
    }
    _top_id--;
    return container[_top_id+1];
}

template <class T>
void Stack<T>::push(T item){
    if(_top_id == _size)
        cout<< "overflow" << endl;
    else{
        _top_id++;
        container[_top_id] = item;
    }
}

template <class T>
void Stack<T>::show(){
    for(int i=0; i<=_top_id; i++)   {
        cout<< container[i] << " "; }
    cout<< endl;
}
