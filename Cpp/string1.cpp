#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
    /*
    reference : http://mropengate.blogspot.com/2015/07/cc-string-stl.html
賦值 = : 將字串指定給另一個字串。
相等比較 == : 比較兩個字串的字元內容是否相同。
串接字串 + : 直接使用 + 運算子來串接字串。
存取字符 []、str.at() : 如字元陣列的操作，at 帶邊界檢查。
字串長度 str.size() : 字串長度。
字串為空 str.empty() : 字串是否為空
字串長度 str.length() : 字串的長度。

assign(str, start, num) : 從 str 的第 start 個字元取出 num 個字元來指定給另一字串物件。
append(str, start, num) : 從 str 的第 start 個字元取出 num 個字元來附加至另一字串物件之後。
find(str, 0) : 從引發 find() 的字串物件中第 0 個字元尋找是否有符合 str 的子字串。
insert(start, str) : 將 str 插入引發 insert() 的字串物件第 start 個字元之後。
*/
    string s1;
    string s2("Hello World");
    string s3(s2+s2);

    // assign: 指定字串
    s1.assign(s2, 0, 7);
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    s1.assign("Nice to Meet You", 5, 6);
    cout << "s1: " << s1 << endl;
    s1.assign( s2 );
    // append: 連接字串
    s1.append(" Nice to Meet You");
    cout << "s1: " << s1 << endl;
    // find:
    cout << "The first position of the character M is at: " << s1.find("Meet") << endl;
    // insert:
    cout << "insert *** as position 20: " << s1.insert(20, "***") << endl;
    // length:
    cout << "length of s1: " << s1.length() << endl;



  //system("pause");
  return 0;
}
