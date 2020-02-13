#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cstring>

using namespace std;

bool checkMaxOneOdd(int letter[], int length) {
  // int length = sizeof(letter)/sizeof(letter[0]); 
  // Don't do that, since the array would be int * as the input parameter of function.

  int oddCount = 0;

  for(int i = 0; i < length; ++i) {
    if((letter[i] & 1) == 1) {
      oddCount++;
      if(oddCount > 1) {
        return false;
      }
    }
  }

  return true;

} 

bool isPalindromePermutation(string aString) {
  transform(aString.begin(), aString.end(), aString.begin(), ::tolower);

  int letter[26];
  memset(letter, 0, sizeof(letter));

  for(char c : aString) {
    if(c <= 'z' && c >= 'a') {
      int idx = c - 'a';
      letter[idx]++;
    }
  }

  return checkMaxOneOdd(letter, 26);

}

int main() {
  string a;
  getline(cin, a);
  cout << isPalindromePermutation(a) << endl;
}


