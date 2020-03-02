#include <iostream>
#include <stack>
#include <string>
#include <list>

using namespace std;

class Animal {
public:
    Animal(string name):name_(name) {}
    virtual ~Animal(){}

    void setOrder(int order) {
        order_ = order;
    }

    int getOrder() {
        return order_;
    }

    string getType() {
        return type_;
    }

    virtual void bark();
protected:
    int order_;
    string name_;
    string type_;
};

class Dog : public Animal {

    Dog(string name) : Animal(name) {
        type_ = "Dog";
    }
    ~Dog() {}

    void bark() {
        cout << "www" << endl;
    }
};

class Cat : public Animal {

    Cat(string name) : Animal(name) {
        type_ = "Cat";
    }
    ~Cat() {}

    void bark() {
        cout << "mmm" << endl;
    }

};

class AnimalQueue {
public:
    AnimalQueue() : order_(0) {}

    void enqueue(Animal* a) {
        if(a->getType() == "Dog") {
            dogs.push_back(&a);
        } else if(a.getType() == "Cat") {
            cats.push_back((Cat)a);
        }
    }

    Animal dequeueAny() {

    }

    Dog dequeueDog() {

    }

    Cat dequeueCat() {

    }
private:
    list<Dog> dogs;
    list<Cat> cats;
    int order_;
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

