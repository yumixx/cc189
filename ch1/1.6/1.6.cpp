#include <iostream>
#include <string>
#include <vector>

using namespace std;

string stringCompression(string aString) {

  vector<char> letters;
  vector<int> counts;
  
  for(int i = 0; i < aString.length(); ++i) {
    char c = aString[i];

    if(i == 0) {
      letters.push_back(c);
      counts.push_back(1);
    } else {
      if(c == aString[i-1]) {
        counts[counts.size()-1]++;
      } else {
        letters.push_back(c);
        counts.push_back(1);
      }
    }
  }

  if(letters.size()*2 >= aString.length()) {
      return aString;
    } else {
      string newString;
      for(int i = 0; i < letters.size(); ++i) {
        char count = '0' + counts[i];
        newString = newString + letters[i] + count;
      }

      return newString;
    }
}


int countCompression(string str) {
  int compressedLength = 0;

  for(int i = 0; i < str.length(); ++i) {

    if(i + 1 >= str.length() || str[i] != str[i+1]) {
      compressedLength++;
    }
  }

  return compressedLength*2;
}


string stringCompression2(string aString) {
  
  int finalLength = countCompression(aString);
  if(finalLength >= aString.length()) {
    return aString;
  }

  string compressedString;
  int count = 0;
  for(int i = 0; i < aString.length(); ++i) {
    count++;

    if(i+1 >= aString.length() || aString[i] != aString[i+1]) {
      compressedString  = compressedString + aString[i] + (char)('0' + count);
      count = 0;
    }
  }

  return compressedString;

}


int main() {
  string basic;
  getline(cin, basic);

  string compression = stringCompression2(basic);
  cout << compression << endl;
}
