#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void printLastKLines(string fileName, int K) {

    ifstream inFile(fileName);
    if(!inFile) {
        cout << "Cannot open file." << fileName << endl;
        return;
    }


    vector<string> lines(K);
    int idx = 0;

    while(!inFile.eof() && inFile.peek() != EOF) {
        string line;
        getline(inFile, line);
        lines[idx % K] = line;
        idx++;
    }

    int start = (idx > K) ? (idx % K) : 0;
    int count = min(idx, K);
    for(int i = 0; i < count; ++i) {
        cout << lines[(i + start) % K] << endl;
    }
}


int main() {
    
    string fileName = "test.txt";
    printLastKLines(fileName, 5);

    return 0;
}
