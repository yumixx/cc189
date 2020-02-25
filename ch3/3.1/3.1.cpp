#include <iostream>
#include <cstring>

using namespace std;


template <typename T>
class Stack3 {

public:

    Stack3(int size = 300) : size_(size) {
        buffer_ = new T[size_*3];
        memset(num_, -1, sizeof(num_));
    }

    ~Stack3() {
        delete [] buffer_;
    }

    void push(int stackNum, T item) {
        if(num_[stackNum] >= size_-1) {
            throw "Out of range.";
        }
        int idx = stackNum*size_ + num_[stackNum] + 1;
        buffer_[idx] = item;
        ++num_[stackNum];
    }

    void pop(int stackNum) {
        --num_[stackNum];
    }

    T top(int stackNum) {
        int idx = stackNum*size_ + num_[stackNum];
        if(idx < 0) {
            throw "Invalid index.";
        }
        return buffer_[idx];
    }

    bool empty(int stackNum) {
        return num_[stackNum] == -1;
    }

    int size(int stackNum) {
        return num_[stackNum]+1;
    }
private:
    T* buffer_;
    int num_[3];
    int size_;
};


template <typename T>
struct Node
{
    T value;
    int preIdx;

    Node() : preIdx(-2) {}
};

template <typename T>
class Stack3_2{

public:

    Stack3_2(int totalSize) : totalSize_(totalSize), cur_(0) {
        buffer_ = new Node<T>[totalSize];
        memset(num_, -1, sizeof(num_));
        memset(size_, 0, sizeof(size_));
    }

    ~Stack3_2() {
        delete [] buffer_;
    }

    void push(int stackNum, T item) {
        buffer_[cur_].value = item;
        buffer_[cur_].preIdx = num_[stackNum];
        num_[stackNum] = cur_;
        while(buffer_[cur_].preIdx != -2) {
            cur_++;
        }
        size_[stackNum]++;
    }

    void pop(int stackNum) {
        if(num_[stackNum] < cur_) {
            cur_ = num_[stackNum];
        }
        int preIdx = buffer_[num_[stackNum]].preIdx;
        buffer_[num_[stackNum]].preIdx = -2;
        num_[stackNum] = preIdx;
        size_[stackNum]--;
    }

    T top(int stackNum) {
        return buffer_[num_[stackNum]].value;
    }

    bool empty(int stackNum) {
        return num_[stackNum] == -1;
    }

    int size(int stackNum) {
        return size_[stackNum];
    }

private:
    Node<T>* buffer_;
    int num_[3];
    int totalSize_;
    int cur_;
    int size_[3];
};




int main() {

    Stack3_2<int> stack3(100);
    for(int i = 0; i < 10; ++i) {
        stack3.push(0,i);
    }
    for(int i = 10; i < 18; ++i) {
        stack3.push(1,i);
    }
    for(int i = 18; i < 23; ++i) {
        stack3.push(2,i);
    }
    for(int i = 0; i < 3; ++i) {
        cout << stack3.top(i) << endl;
    }

    stack3.pop(0);
    stack3.push(1,100);
    stack3.push(2,300);
    stack3.pop(2);

    cout << stack3.top(0) << endl;
    cout << stack3.top(1) << endl;
    cout << stack3.top(2) << endl;

    return 0;
}

