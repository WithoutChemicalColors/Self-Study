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
    int n;
    istringstream(num_buf) >> n;
    nums.push_back( n );
}

int main(int argc, char **argv){
    string sent;
    while(getline(cin, sent)){
        // deblank
        sent = deblank(sent);

        // deparentheses
        string num_buf;
        string inside;
        vector<int> nums;
        vector<char> signs;

        for(int i=0; i<sent.size(); i++){
            if(sent.at(i)=='('){

            } else{
                if( isdigit(sent.at(i)) )
                    num_buf += sent.at(i);
                else{
                    int num_temp; istringstream(num_buf) >> num_temp; num_buf.clear();
                    nums.push_back(num_temp);
                    signs.push_back(sent.at(i));
                }
            }// endelse
        }// endfor
        int num_temp; istringstream(num_buf) >> num_temp; num_buf.clear();
        nums.push_back(num_temp);
        // istringstream ( sent ) >> a;
        show(nums);
        show(signs);

    }
    return 0;
}
