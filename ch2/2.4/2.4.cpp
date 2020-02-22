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


Node* partition(Node* head, int x) {

    Node *less = new Node(0);
    Node *greater = new Node(0);
    Node *lessHead = less;
    Node *greaterHead = greater;

    Node* node = head;
    while(node != NULL) {
        Node* temp = new Node(node->data);
        if(node->data < x) {
            less->next = temp;
            less = less->next;
        } else {
            greater->next = temp;
            greater = greater->next;
        }
        node = node->next;
    }

    less->next = greaterHead->next;
    delete greaterHead;

    return lessHead->next;
}


Node* partition2(Node* node, int x) {

    Node* head = node;
    Node* tail = node;

    while(node != NULL) {
        Node* next = node->next;
        if(node->data < x) {
            node->next = head;
            head = node;
        } else {
            tail->next = node;
            tail = node;
        }
        node = next;
    }
    tail->next = NULL;

    return head;

}


int main() {

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

    Node* head = initializeList(data);
    Node* result = partition2(head, 5);

    while(result != NULL) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
