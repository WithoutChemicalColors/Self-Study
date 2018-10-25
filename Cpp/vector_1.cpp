#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;
void sample_start( string &name );

//<reference>
// 1. http://pingyeh.blogspot.com/2011/09/stl-vector.html#efficiency

int main(){
    string  s = "Example1";

    sample_start( s );

    vector<int> v1;
    v1.push_back( 10 ); // put something inside. But this isn't  recommended.
    v1.push_back( 20 );

    // Create iterator to read out the element inside the vector v1.
    for( vector<int>::iterator it = v1.begin(); it != v1.end(); ++it ){
            cout<<*it << endl;
            // the "it" looks like a pointer. -> *it to get the value.
            // if you don't want to change the element inside the vector v1. Try const_iterator to replace iterator.
    }

    s = "Example2"; sample_start( s );
    cout<<"少用[ ] 因為不做邊界檢查"<<endl;
    cout<<"vector.at is your best friend?"<<endl;

    vector<string> words;
    words.reserve( 3 );
    words.push_back("hello"); words.push_back("words"); words.push_back("bye");
    cout<< words.at( 2 ) << endl;

    s="Example3"; sample_start( s ); cout<<"see the remark, please"<<endl;
    vector<string> a; a.reserve(65);        // 方法1: a長度為 0 -> 預留 65 個元素的位置，沒有初始化
    vector<string> b; b.resize(65);          //  方法2: b長度為 0 -> 預留 65 個元素的位置，呼叫 string 的 default constructor
    vector<string> c(65);                           //   方法3: 長度為 65
                                                                        // 2和3 兩種方法有初始化
    //使用 vector 要注意的效率問題大致有兩點
    //不做不必要的記憶體重配置：少依賴 push_back() 的自動記憶體配置，
    //能自己要記憶體的就自己要，善用 reserve()、resize() 或 constructor 引數。
    //不做不必要的物件拷貝。比方說，要延長或建立一個 vector、但各個元素的值不同，
    //不要用會填值的 resize() 或 constructor 引數，
    //而是用 reserve() 再把物件一個一個 push_back() 進去。
    //另外要注意的是，reserve() 要來的空間切不可用 operator[] 填值，除非元素是 POD。見下節。
    s="This is the end of examples"; sample_start( s );

  //system("pause");
  return 0;
}

void sample_start( string &name ){
    cout<< endl << name << endl;
    for( int i=0; i<100; i++ ){
        cout<<"-";
    }
    cout<<endl;
}
