#include <iostream>
#include <string>
#include <unordered_set>
#include <memory.h>

using namespace std;

// Using STL hash map
bool isUnique(string aString) {

  unordered_set<char> unique;
  for(char c : aString) {
    if(unique.find(c) == unique.end()) {
      unique.insert(c);
    } else {
      return false;
    }
  }

  return true;
}

// No additional data structures
bool isUnique2(string aString) {

  for(int i = 0; i < aString.length(); ++i) {
    char c = aString[i];
    for(int j = i+1; j < aString.length(); ++j) {
      if(aString[j] == c) {
        return false;
      }
    }
  }

  return true;
}

// Similar idee - hash table
bool isUnique3(string aString) {

  if(aString.length() > 256) {
    return false;
  }

  bool a[256];
  memset(a, 0, sizeof(a));
  for(char c : aString) {
    int idx = (int)c;
    if(a[idx]) {
      return false;
    } else {
      a[idx] = true;
    }
  }
  return true;
}

// Bit vector
bool isUnique4(string aString) {

  int checker = 0;
  for(int i = 0; i < aString.length(); ++i) {
    int val = aString[i]-'a';
    if(checker & (1<<val)) {
      return false;
    }
    checker |= (1<<val);
  }
  return true;
}

int main() {

  string aString;
  getline(cin, aString);

  bool unique = isUnique(aString);
  bool unique2 = isUnique2(aString);
  bool unique3 = isUnique3(aString);
  bool unique4 = isUnique4(aString);

  cout << unique << endl;
  cout << unique2 << endl;
  cout << unique3 << endl;
  cout << unique4 << endl;

  return 0;
}
