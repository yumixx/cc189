#include <iostream>
#include <stack>

using namespace std;


class MyQueue {

public:
    void push(int value) {
        stackOld_.push(value);
    }

    void pop() {
        while(!stackOld_.empty()) {
            int top = stackOld_.top();
            stackNew_.push(top);
            stackOld_.pop();
        }

        stackNew_.pop();
        while(!stackNew_.empty()) {
            int top = stackNew_.top();
            stackOld_.push(top);
            stackNew_.pop();
        }
    }

    int top() {
        while(!stackOld_.empty()) {
            int top = stackOld_.top();
            stackNew_.push(top);
            stackOld_.pop();
        }

        int queueTop = stackNew_.top();
        while(!stackNew_.empty()) {
            int top = stackNew_.top();
            stackOld_.push(top);
            stackNew_.pop();
        }

        return queueTop;
    }

    bool empty() {
        return stackOld_.empty();
    }
private:
    stack<int> stackOld_;
    stack<int> stackNew_;
};


class MyQueue1 {

public:
    void push(int value) {
        while(!stackOut_.empty()) {
            int top = stackOut_.top();
            stackIn_.push(top);
            stackOut_.pop();
        }
        stackIn_.push(value);
    }

    void pop() {
        while(!stackIn_.empty()) {
            int top = stackIn_.top();
            stackOut_.push(top);
            stackIn_.pop();
        }
        stackOut_.pop();
    }

    int top() {
        if(stackIn_.empty()) {
            return stackOut_.top();
        } else {
            while(!stackIn_.empty()) {
                int top = stackIn_.top();
                stackOut_.push(top);
                stackIn_.pop();
            }
            return stackOut_.top();
        }
    }

    
    bool empty() {
        return stackIn_.empty() && stackOut_.empty();
    }
private:
    stack<int> stackIn_;
    stack<int> stackOut_;
};


class MyQueue2 {
public:
    void push(int value) {
        stackIn_.push(value);
    }

    void pop() {
        if(stackOut_.empty()) {
            while(!stackIn_.empty()) {
                int top = stackIn_.top();
                stackOut_.push(top);
                stackIn_.pop();
            }
        }

        stackOut_.pop();
    }

    int top() {
        if(stackOut_.empty()) {
            while(!stackIn_.empty()) {
                int top = stackIn_.top();
                stackOut_.push(top);
                stackIn_.pop();
            }
        }

        return stackOut_.top();
    }

    bool empty() {
        return stackIn_.empty() && stackOut_.empty();
    }
private:
    stack<int> stackIn_;
    stack<int> stackOut_;

};


int main() {

    MyQueue myQueue;
    for(int i = 0; i < 10; ++i) {
        myQueue.push(i);
    }

    while(!myQueue.empty()) {
        cout << myQueue.top() << " ";
        myQueue.pop();
    }
    cout << endl;


    MyQueue1 myQueue1;
    for(int i = 0; i < 10; ++i) {
        myQueue1.push(i);
    }

    while(!myQueue1.empty()) {
        cout << myQueue1.top() << " ";
        myQueue1.pop();
    }
    cout << endl;


    MyQueue2 myQueue2;
    for(int i = 0; i < 10; ++i) {
        myQueue2.push(i);
    }

    while(!myQueue2.empty()) {
        cout << myQueue2.top() << " ";
        myQueue2.pop();
    }
    cout << endl;

    return 0;
}

