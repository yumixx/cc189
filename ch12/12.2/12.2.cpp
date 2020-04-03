#include <iostream>

using namespace std;

void reverse(char* str) {
    char* end = str;
    if(str) {
        while(*end) {
            end++;
        }
        end--;
    }

    char temp;
    while(str < end) {
        temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}


int main() {
    
    char str[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    reverse(str);
    for(int i = 0; i < 7; ++i) {
        cout << str[i] << ", ";
    }
    cout << endl;


    return 0;
}
