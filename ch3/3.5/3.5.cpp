#include <iostream>
#include <stack>

using namespace std;

void insertionSort(stack<int>& s) {

    stack<int> sTemp;

    while(!s.empty()) {

        int top = s.top();
        s.pop();
        while(!sTemp.empty() && sTemp.top() > top) {
            s.push(sTemp.top());
            sTemp.pop();
        }

        sTemp.push(top);
    }

    while(!sTemp.empty()) {
        s.push(sTemp.top());
        sTemp.pop();
    }
}


int main() {

    stack<int> s;
    s.push(3);
    s.push(19);
    s.push(5);
    s.push(23);
    s.push(60);
    s.push(1);
    insertionSort(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    

    return 0;
}

