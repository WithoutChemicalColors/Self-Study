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
    cout<<"�֥�[ ] �]����������ˬd"<<endl;
    cout<<"vector.at is your best friend?"<<endl;

    vector<string> words;
    words.reserve( 3 );
    words.push_back("hello"); words.push_back("words"); words.push_back("bye");
    cout<< words.at( 2 ) << endl;

    s="Example3"; sample_start( s ); cout<<"see the remark, please"<<endl;
    vector<string> a; a.reserve(65);        // ��k1: a���׬� 0 -> �w�d 65 �Ӥ�������m�A�S����l��
    vector<string> b; b.resize(65);          //  ��k2: b���׬� 0 -> �w�d 65 �Ӥ�������m�A�I�s string �� default constructor
    vector<string> c(65);                           //   ��k3: ���׬� 65
                                                                        // 2�M3 ��ؤ�k����l��
    //�ϥ� vector �n�`�N���Ĳv���D�j�P�����I
    //���������n���O���魫�t�m�G�֨̿� push_back() ���۰ʰO����t�m�A
    //��ۤv�n�O���骺�N�ۤv�n�A���� reserve()�Bresize() �� constructor �޼ơC
    //���������n����������C��軡�A�n�����Ϋإߤ@�� vector�B���U�Ӥ������Ȥ��P�A
    //���n�η|��Ȫ� resize() �� constructor �޼ơA
    //�ӬO�� reserve() �A�⪫��@�Ӥ@�� push_back() �i�h�C
    //�t�~�n�`�N���O�Areserve() �n�Ӫ��Ŷ������i�� operator[] ��ȡA���D�����O POD�C���U�`�C
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
