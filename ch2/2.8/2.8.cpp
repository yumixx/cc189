#include <iostream>
#include <vector>
#include <unordered_set>

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


Node* loopDetection(Node* head) {

    if(head == NULL) return NULL;
    
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            break;
        }
    }

    slow = head;
    while(fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}


Node* loopDetection2(Node* head) {

    if(head == NULL) return NULL;

    unordered_set<Node*> hashTable;
    while(head != NULL) {
        if(hashTable.find(head) == hashTable.end()) {
            hashTable.insert(head);
            head = head->next;
        } else {
            break;
        }
    }

    return head;
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

    vector<int> vec1{4,2,3,5,7};
    Node* list1 = initializeList(vec1);
    int k = 2;
    Node* temp = list1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list1->next->next;
    
    Node* loop1 = loopDetection(list1);
    Node* loop2 = loopDetection2(list1);

    cout << loop1->data << endl;
    cout << loop2->data << endl;

    return 0;
}
