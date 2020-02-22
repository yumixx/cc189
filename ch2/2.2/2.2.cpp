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

Node* returnKthToLast(Node* head, int k) {

    int size = 0;
    Node* temp = head;
    while(temp != NULL) {
        size++;
        temp = temp->next;
    }

    if(k > size) {
        throw "k is larger than the size of linked list!";
    }

    temp = head;
    int n = size-k+1;
    while(n > 1) {
        temp = temp->next;
        n--;
    }

    return temp;
}

Node* kthToLast(Node* head, int k, int& i) {
    if(head == NULL) {
        return NULL;
    }

    Node* temp = kthToLast(head->next, k, i);
    i++;
    if(i == k) {
        return head;
    }
    return temp;
}

Node* returnKthToLast2(Node* head, int k) {
    int i = 0;
    return kthToLast(head, k, i);
}

Node* returnKthToLast3(Node* head, int k) {

    Node* p1 = head;
    Node* p2 = head;

    for(int i = 0; i < k; ++i) {
        if(p1 == NULL) return NULL;
        p1 = p1->next;
    }

    while(p1 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
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
    Node* kthToLast = returnKthToLast3(head, 3);

    while(kthToLast != NULL) {
        cout << kthToLast->data << " ";
        kthToLast = kthToLast->next;
    }
    cout << endl;

    return 0;
}
