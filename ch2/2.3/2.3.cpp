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

/*void deleteMiddle(Node* middle) {

    while(middle->next != NULL) {
        middle->data = middle->next->data;
        middle = middle->next;
    }

    delete middle;
}*/
bool deleteMiddle(Node* middle) {
    if(middle == NULL || middle->next == NULL) return false;

    Node* temp = middle->next;
    middle->data = temp->data;
    middle->next = temp->next;

    delete temp;
    return true;
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
    Node* middle = head;
    for(int i = 0; i < 4; ++i) {
        middle = middle->next;
    }
    cout << middle->data << endl;
    deleteMiddle(middle);

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
