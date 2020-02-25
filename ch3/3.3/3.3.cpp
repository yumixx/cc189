#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <memory>

using namespace std;

class SetOfStacks {

public:
    typedef shared_ptr<stack<int>> stackPtr;

    SetOfStacks(int threshold): threshold_(threshold), 
        size_(0), stackIdx_(0) {
        
        stackPtr aStack = make_shared<stack<int>>();
        stacks_.push_back(aStack);
    }

    ~SetOfStacks() {}

    void push(int value) {

        size_++;
        if(size_ > threshold_) {
            stackPtr aStack = make_shared<stack<int>>();
            aStack->push(value);
            stacks_.push_back(aStack);
            size_ = 1;
            stackIdx_++;
        } else {
            stacks_[stackIdx_]->push(value);
        }
    }

    void pop() {
        stacks_[stackIdx_]->pop();
        if(stacks_[stackIdx_]->empty()) {
            stacks_.pop_back();
            stackIdx_--;
            size_ = threshold_;
        }
    }

    int top() {
        return stacks_[stackIdx_]->top();
    }

private:
    vector<stackPtr> stacks_;
    int threshold_;
    int size_;
    int stackIdx_;
};



class SetOfStacks2 {

public:
    typedef shared_ptr<stack<int>> stackPtr;

    SetOfStacks2(int threshold): threshold_(threshold), stackIdx_(0) {
        
        stackPtr aStack = make_shared<stack<int>>();
        stacks_.push_back(aStack);
    }

    ~SetOfStacks2() {}

    void push(int value) {

        if(stacks_.back()->size() == threshold_) {
            stackPtr aStack = make_shared<stack<int>>();
            aStack->push(value);
            stacks_.push_back(aStack);
            stackIdx_++;
        } else {
            stacks_[stackIdx_]->push(value);
        }
    }

    void pop() {

        while(stacks_[stackIdx_]->empty()) {
            stackIdx_--;
        }

        stacks_[stackIdx_]->pop();
        while(stackIdx_ != -1 && stacks_[stackIdx_]->empty()) {
            stacks_.pop_back();
            stackIdx_--;
        }
    }

    int top() {
        int idx = stackIdx_;
        while(stacks_[idx]->empty()) {
            idx--;
        }
        return stacks_[idx]->top();
    }

    void popAt(int index) {
        stacks_[index]->pop();
    }

    int sizeStacks() {
        return stacks_.size();
    }

private:
    vector<stackPtr> stacks_;
    int threshold_;
    int stackIdx_;
};



int main() {

    SetOfStacks stacks(3);
    for(int i = 0; i < 19; ++i) {
        stacks.push(i);
    }

    for(int i = 0; i < 19; ++i) {
        cout << stacks.top() << " ";
        stacks.pop();
    }
    cout << endl;


    SetOfStacks2 stacks2(3);
    for(int i = 0; i < 13; ++i) {
        stacks2.push(i);
    }

    stacks2.popAt(2);
    stacks2.popAt(3);
    stacks2.pop();
    stacks2.popAt(2);
    stacks2.popAt(2);
    stacks2.push(19);

    while(stacks2.sizeStacks() > 0) {
        int top = stacks2.top();
        stacks2.pop();
        cout << top << " ";
    }
    cout << endl;


    return 0;
}

