#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

bool permutation(string a, string b) {

  if(a.length() != b.length()) {
    return false;
  }

  vector<int> letterA(256, 0);
  vector<int> letterB(256, 0);

  for(char c : a) {
    int idx = (int)c;
    letterA[idx]++;
  }

  for(char c : b) {
    int idx = (int)c;
    letterB[idx]++;
  }

  for(int i = 0; i < 256; ++i) {
    if(letterA[i] != letterB[i]) {
      return false;
    }
  }

  return true;
}

bool permutation2(string a, string b) {

  if(a.length() != b.length()) {
    return false;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  return a == b;
}

bool permutation3(string a, string b) {

  if(a.length() != b.length()) {
    return false;
  }

  int letter[256];
  memset(letter, 0, sizeof(letter));

  for(char c : a) {
    int idx = (int)c;
    letter[idx]++;
  }

  for(char c : b) {
    int idx = (int)c;
    letter[idx]--;
    if(letter[idx] < 0) {
      return false;
    }
  }

  return true;

}

int main() {
  string a;
  string b;
  getline(cin, a);
  getline(cin, b);

  bool isPermutation = permutation(a, b);
  bool isPermutation2 = permutation2(a, b);
  bool isPermutation3 = permutation3(a, b);
  cout << isPermutation << endl;
  cout << isPermutation2 << endl;
  cout << isPermutation3 << endl;

  return 0;
}
