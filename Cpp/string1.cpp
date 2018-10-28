#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
    /*
    reference : http://mropengate.blogspot.com/2015/07/cc-string-stl.html
��� = : �N�r����w���t�@�Ӧr��C
�۵���� == : �����Ӧr�ꪺ�r�����e�O�_�ۦP�C
�걵�r�� + : �����ϥ� + �B��l�Ӧ걵�r��C
�s���r�� []�Bstr.at() : �p�r���}�C���ާ@�Aat �a����ˬd�C
�r����� str.size() : �r����סC
�r�ꬰ�� str.empty() : �r��O�_����
�r����� str.length() : �r�ꪺ���סC

assign(str, start, num) : �q str ���� start �Ӧr�����X num �Ӧr���ӫ��w���t�@�r�ꪫ��C
append(str, start, num) : �q str ���� start �Ӧr�����X num �Ӧr���Ӫ��[�ܥt�@�r�ꪫ�󤧫�C
find(str, 0) : �q�޵o find() ���r�ꪫ�󤤲� 0 �Ӧr���M��O�_���ŦX str ���l�r��C
insert(start, str) : �N str ���J�޵o insert() ���r�ꪫ��� start �Ӧr������C
*/
    string s1;
    string s2("Hello World");
    string s3(s2+s2);

    // assign: ���w�r��
    s1.assign(s2, 0, 7);
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    s1.assign("Nice to Meet You", 5, 6);
    cout << "s1: " << s1 << endl;
    s1.assign( s2 );
    // append: �s���r��
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
