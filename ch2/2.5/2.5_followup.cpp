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


int listLength(Node* list) {

    int length = 0;
    while(list!=NULL) {
        length++;
        list = list->next;
    }

    return length;
}

Node* padList(Node* list, int length) {

    if(length == 0) return list;

    Node* head = new Node(0);
    Node* temp = head;
    while(length > 1) {
        Node* next = new Node(0);
        temp->next = next;
        temp = temp->next; 
        length--;
    }
    temp->next = list;

    return head;
}

Node* addLists(Node* list1, Node* list2, int& carry) {

    if(list1 == NULL && list2 == NULL) {
        carry = 0;
        return NULL;
    }

    Node* sum = addLists(list1->next, list2->next, carry);
    Node* head = new Node(0);
    head->next = sum;
    int data = list1->data + list2->data + carry;
    head->data = data % 10;
    carry = data / 10;

    return head;
}

Node* calculateSum(Node* list1, Node* list2) {

    int lengthList1 = listLength(list1);
    int lengthList2 = listLength(list2);

    if(lengthList1 > lengthList2) {
        list2 = padList(list2, lengthList1-lengthList2);
    } else if(lengthList1 < lengthList2) {
        list1 = padList(list1, lengthList2-lengthList1);
    }

    int carry = 0;
    Node* sum = addLists(list1, list2, carry);
    if(carry != 0) {
        Node* head = new Node(carry);
        head->next = sum;
        sum = head;
    }

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
    vector<int> vec2{4, 2, 8, 1, 6};
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
