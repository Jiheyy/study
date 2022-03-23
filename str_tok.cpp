#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
int main() {
	string str = "java and python and cpp and ruby";
    string s[7];
    
    istringstream stt(str);
    stt >> s[0] >> str >> s[1] >> str >> s[2] >> str >> s[3];
    cout << s[0] << s[1] << s[2] << s[3] <<endl;
    // javapythoncppruby
}
