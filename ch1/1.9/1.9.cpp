#include <iostream>
#include <string>

using namespace std;

bool isString(string s1, string s2) {
    if(s1.find(s2) != string::npos) {
        return true;
    } else {
        return false;
    }
}

bool isRotation(string s1, string s2) {

    if(s1.length() != s2.length() || s1.length() <= 0) {
        return false;
    }

    string s = s1 + s1;
    
    return isString(s, s2);
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << isRotation(s1, s2) << endl;

    return 0;
}
