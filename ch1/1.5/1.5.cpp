#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool checkOneEdit(string a, string b) {
  if(abs((int)(a.length() - b.length())) > 1) {
    return false;
  }

  string shortString = a.length() < b.length() ? a : b;
  string longString = a.length() < b.length() ? b : a;

  bool foundDifference = false;
  int shortIdx = 0, longIdx = 0;
  while(shortIdx < shortString.length() && longIdx < longString.length()) {
    if(shortString[shortIdx] == longString[longIdx]) {
      shortIdx++;
    } else {
      if(foundDifference) return false;
      foundDifference = true;

      if(shortString.length() == longString.length()) {
        shortIdx++;
      }
    }
    longIdx++;
  }

  return true;

}

int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  cout << checkOneEdit(a, b) << endl;
}


