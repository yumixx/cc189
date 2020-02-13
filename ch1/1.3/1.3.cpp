#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

void replaceSpaces(char* input, int trueLength) {

  if(input == NULL) return;
  int length = strlen(input);
  if(length == 0) return;

  int spaceCount = 0;
  for(int i = 0; i < trueLength; ++i) {
    if(input[i] == ' ') spaceCount++;
  }

  int index = spaceCount*2 + trueLength;

  input[index] = '\0';
  index--;
  for(int i = trueLength-1; i >= 0; i--) {
    if(input[i] == ' ') {
      input[index] = '0';
      input[index-1] = '2';
      input[index-2] = '%';
      index -= 3;
    } else {
      input[index] = input[i];
      index--;
    }
  }
}

int main() {
  char input[256];
  cin.getline(input, 256);
  cout << input << endl;
  int trueLength;
  cin >> trueLength;
  cout << trueLength << endl;
  replaceSpaces(input, trueLength);
  cout << input << endl;

  return 0;

}
