#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class MinStack {

private:
    vector<int> myStack;
    vector<int> minStack;

public:

    MinStack() {
        myStack = {};
        minStack = {};
    }

    void push(int value) {
        if(myStack.empty()) {
            minStack.push_back(value);
        } else if(value <= minStack.back()) {
            minStack.push_back(value);
        }

        myStack.push_back(value);
    }

    void pop() {
        if(myStack.back() == minStack.back()) {
            myStack.pop_back();
            minStack.pop_back();
        } else {
            myStack.pop_back();
        }
    }

    int min() {
        return minStack.back();
    }
};




int main() {

    MinStack* obj = new MinStack();

    obj->push(11);
    obj->push(4);
    obj->push(6);
    obj->push(1);
    int min = obj->min();
    cout << min << endl;
    obj->pop();
    min = obj->min();
    cout << min << endl;
    obj->pop();
    min = obj->min();
    cout << min << endl;
    obj->push(2);
    min = obj->min();
    cout << min << endl;


    return 0;
}

