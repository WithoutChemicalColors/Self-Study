#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
// deblank
string deblank(const string &sent){
    string buffer;
    for(int i=0; i<sent.size(); i++){
        if(sent[i]==' ')
            continue;
        else
            buffer += sent[i];
    }
    return buffer;
}
template <class T>
// show
void show(const T brain){
    for(int i=0; i<brain.size(); i++)
        cout<< brain.at(i)<< ' ';
    cout<< endl;
}
// store numbers
template <class T>
void storenums(string &sent, vector<T> &nums){
    string num_buf;
    while( isdigit(sent.front()) ){
        num_buf += sent.front();
        sent.erase(sent.begin());
    }
    if( num_buf.size()>0 ){
        int n;
        istringstream(num_buf) >> n;
        nums.push_back( n );
    }
}

template <class T>
void storesigns(string &sent, vector<T> &signs){
    if( sent.size() != 0 ){
        signs.push_back(sent.front());
        sent.erase(sent.begin());
    }
}

template <class T>
void operator_first(vector<T> &nums, vector<char> &signs);

template <class T>
void operator_last(vector<T> &nums, vector<char> &signs);

// 1 + 2 + 3 + 4 + 5
// ( 1 ) - ( ( 5 * 2 ) - ( 99 ) ) / ( 20 )
//
int main(int argc, char **argv){
    string sent;
    while(getline(cin, sent)){
        // prepare containers
        vector<int> nums;
        vector<char> signs;
        // deblank
        sent = deblank(sent);
        while(sent.size()!=0){
            storenums(sent, nums);   // sotre nums
            storesigns(sent, signs); // sotre signs

            // deparentheses --> numbers
            if( signs.back()==')' ){
                vector<int> nums_in;
                vector<char> signs_in;
                signs.pop_back();
                while( signs.back()!='(' ){
                    nums_in.insert(nums_in.begin(), nums.back());
                    nums.pop_back();
                    signs_in.insert(signs_in.begin(), signs.back());
                    signs.pop_back();
                }
                nums_in.insert(nums_in.begin(), nums.back());
                nums.pop_back();
                signs.pop_back();
                operator_first(nums_in, signs_in);
                operator_last(nums_in, signs_in);
                nums.push_back(nums_in.at(0));
            }
        }
        // single sentence
        operator_first(nums, signs);
        operator_last(nums, signs);
        cout<< nums.front() << endl;
    }
    return 0;
}

template <class T>
void operator_first(vector<T> &nums, vector<char> &signs){

    for(int i=0; i<signs.size(); i++){
        switch( signs.at(i) ){
            case '*':
                nums.at(i) = nums.at(i) * nums.at(i+1);
                nums.erase( nums.begin()+i+1 );
                signs.erase( signs.begin()+i );
                i--;
                break;
            case '/':
                nums.at(i) = nums.at(i) / nums.at(i+1);
                nums.erase( nums.begin()+i+1 );
                signs.erase( signs.begin()+i );
                i--;
                break;
            case '%':
                nums.at(i) = nums.at(i) % nums.at(i+1);
                nums.erase( nums.begin()+i+1 );
                signs.erase( signs.begin()+i );
                i--;
                break;
            }
    }
}

template <class T>
void operator_last(vector<T> &nums, vector<char> &signs){
    for(int i=0; i<signs.size(); i++){
        if( signs.at(i)=='+' )
            nums.at(0) = nums.at(0) + nums.at(1);
        else
            nums.at(0) = nums.at(0) - nums.at(1);
        nums.erase(nums.begin()+1);
    }
}
