#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int d) : data(d), next(NULL) {}
};

Node* initializeList(const vector<int>& data) {

    Node* head, *temp;
    for(int i = 0; i < data.size(); ++i) {
        Node* node = new Node(data[i]);
        if(i == 0) {
            head = node;
            temp = node;
            continue;
        }

        temp->next = node;
        temp = node;
    }

    return head;
}


Node* calculateSum(Node* list1, Node* list2) {

    if(list1 == NULL && list2 == NULL) {
        return NULL;
    } else if(list1 == NULL) {
        return list2;
    } else if(list2 == NULL) {
        return list1;
    }

    Node* sum = new Node(0);
    Node* temp = sum;
    int i = 0;

    while(list1 != NULL && list2 != NULL) {
        int data = i + list1->data + list2->data;
        Node* next = new Node(i);
        temp->next = next;
        temp = next;
        temp->data = data % 10;
        i = data / 10;

        list1 = list1->next;
        list2 = list2->next;
    }

    while(list1 != NULL) {
        int data = i + list1->data;
        Node* next = new Node(i);
        temp->next = next;
        temp = next;
        temp->data = data % 10;
        i = data / 10;

        list1 = list1->next;
    }

    while(list2 != NULL) {
        int data = i + list2->data;
        Node* next = new Node(i);
        temp->next = next;
        temp = next;
        temp->data = data % 10;
        i = data / 10;

        list2 = list2->next;
    }

    Node* head = sum;
    sum = sum->next;
    head->next = NULL;
    delete head;

    return sum;
}


int main() {

/*
    vector<int> data;
    int a;
    while(cin >> a) {
        data.push_back(a);
        if(getchar() == '\n') {
            break;
        }
    }

    for(int i = 0; i < data.size(); ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
    */

    vector<int> vec1{1, 2, 3, 4};
    vector<int> vec2{5};
    Node* list1 = initializeList(vec1);
    Node* list2 = initializeList(vec2);
    Node* result = calculateSum(list1, list2);

    while(result != NULL) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
