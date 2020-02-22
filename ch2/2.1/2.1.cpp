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

void removeDuplicates(Node* head) {

    unordered_set<int> hashTable;
    
    if(head == NULL) return;

    hashTable.insert(head->data);

    Node* prev = head;
    Node* current = head->next;

    while(current != NULL) {
        if(hashTable.find(current->data) != hashTable.end()) {
            Node* temp = current;
            prev->next = current->next;
            current = prev->next;
            delete temp;
        } else {
            hashTable.insert(current->data);
            prev = prev->next;
            current = current->next;
        }
    }

}

void removeDuplicates2(Node* head) {

    if(head == NULL) return;

    Node *current = head;
    Node *prev, *comparison;
    while(current) {
        prev = current;
        comparison = current->next;
        while (comparison)
        {
            if(comparison->data == current->data) {
                Node* temp = comparison;
                prev->next = comparison->next;
                comparison = prev->next;
                delete temp;
            } else {
                comparison = comparison->next;
                prev = prev->next;
            }
        }
        current = current->next;
        
    }
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
    removeDuplicates(head);

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    Node* head2 = initializeList(data);
    removeDuplicates2(head2);

    while(head2 != NULL) {
        cout << head2->data << " ";
        head2 = head2->next;
    }
    cout << endl;

    return 0;
}
