#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// 1 + ( 2 + 3 ) + 4
// 1 + ( 5 + 3 ) + 5
// ( 29 + 3 - 52 + 7 ) % ( 4 / 2 )

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

long int single_sentence(string &sent);

string deparentheses(string &sent);

void reverse_string(string &sent){
    string buffer;
    for(string::reverse_iterator rit=sent.rbegin(); rit!=sent.rend(); ++rit){
        buffer.push_back(*rit);
    }
    sent = buffer;
}


template <class T>
void shrink_first_operator(vector<T> &nums, vector<char> &signs){
    for(int i=1, j=0; i<signs.size(); i++, j++){
        if(signs.at(i)=='*'){
            nums.at(j) = nums.at(j) * nums.at(j+1);
            nums.erase(nums.begin()+j+1);
            j--;
        } else if(signs.at(i)=='/'){
            nums.at(j) = nums.at(j) / nums.at(j+1);
            nums.erase(nums.begin()+j+1);
            j--;
        } else if(signs.at(i)=='%'){
            nums.at(j) = nums.at(j) % nums.at(j+1);
            nums.erase(nums.begin()+j+1);
            j--;
        } else
            continue;
    }
}

template <class T>
void shrink_plus_minus(vector<T> &nums, vector<char> &signs){
    for(int i=1; i<signs.size(); i++){
        if(signs.at(i)=='+')
            nums.at(0) = nums.at(0) + nums.at(1);
        else
            nums.at(0) = nums.at(0) - nums.at(1);
        nums.erase(nums.begin()+1);
    }
}

void shrink(vector<long int> &nums, vector<char> &signs){
    if( (signs.back()=='*') || (signs.back()=='/') || (signs.back()=='%') ){
        long int right = nums.back(); nums.pop_back();
        long int left = nums.back();  nums.pop_back();
        long int ans;
        if(signs.back()=='*'){
            ans = left * right;
        }
        else if(signs.back()=='/'){
            ans = left / right;
        }
        else{
            ans = left % right;
        }
        // printf("%d %c %d\n", left, signs.back(), right);
        nums.push_back(ans);
        signs.pop_back();
    }// endif
}

template <class T>
void show(const T brain){
    for(int i=0; i<brain.size(); i++)
        cout<< brain.at(i);
    cout<< endl << "----------" << endl;
}


///////////////////////////////////////////////////////////////////
int main(int argc, char **argv){
    string sent;
    while(getline(cin, sent)){
        // deblanek
        sent = deblank(sent);
        // DEPARENTHESES
        sent = deparentheses(sent);
        // SINGLE SENTENCE
        cout<< "DEPARATEHESES: ";
        show(sent);

        long int ans = single_sentence(sent);
        cout<< ans << endl;
    }
    return 0;
}
///////////////////////////////////////////////////////////////////
// 1 + 2 + 3

long int single_sentence(string &sent){
    string num_buf;
    vector<long int> nums;
    vector<char> signs; signs.push_back('0');
    for(int i=0; i<sent.size(); i++){
        if(isdigit(sent[i]))
            num_buf += sent[i];
        else{
            long int temp = stol(num_buf);
            nums.push_back(temp);
            num_buf.clear();
            shrink(nums, signs); // shrink
            signs.push_back(sent[i]);
        }//endelse
    }//endfor
    long int temp = stoi(num_buf);
    nums.push_back(temp);
    num_buf.clear();
    shrink(nums, signs);
    shrink_plus_minus(nums, signs);
    // for(int i=1; i<signs.size(); i++){
    //     if(signs.at(i)=='+')
    //         nums.at(0) = nums.at(0) + nums.at(1);
    //     else
    //         nums.at(0) = nums.at(0) - nums.at(1);
    //     nums.erase(nums.begin()+1);
    // }
    return nums.front();
}

string deparentheses(string &sent){

    string buffer;
    vector<long int> nums;
    vector<char> signs; signs.push_back('0');
    for(int i=0; i<sent.size(); i++){
        buffer += sent.at(i);

        if(buffer.back() == ')'){
            string temp;
            while(buffer.back() != '('){
                temp.push_back( buffer.back() );
                buffer.pop_back();
            }
            buffer.pop_back();
            reverse_string(temp);                    //reverse temp
            temp.pop_back();
            buffer += to_string( single_sentence(temp) );
        }//endif
    }//endfor

    return buffer;
}//endfunction
