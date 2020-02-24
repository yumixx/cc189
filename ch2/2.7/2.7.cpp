#include <iostream>
#include <vector>
#include <stack>

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

Node* findTail(Node* head) {
    Node* temp = head;
    if(temp == NULL) return NULL;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    return temp;
}


bool isIntersection(Node* list1, Node* list2) {
    Node* tail1 = findTail(list1);
    Node* tail2 = findTail(list2);

    return tail1 == tail2;
}

Node* findTailAndSize(Node* head, int& size) {
    Node* temp = head;
    size = 0;
    if(temp == NULL) {
        return NULL;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
        size++;
    }

    size++;

    return temp;
}


bool findIntersection(Node* list1, Node* list2, Node** intersection) {

    int size1, size2;
    Node* tail1 = findTailAndSize(list1, size1);
    Node* tail2 = findTailAndSize(list2, size2);

    if(tail1 == tail2) {
        if(size1 >= size2) {
            int diff = size1-size2;
            while(diff > 0) {
                list1 = list1->next;
                diff--;
            }
        } else {
            int diff = size2-size1;
            while(diff > 0) {
                list2 = list2->next;
                diff--;
            }
        }

        while(list1 != list2) {
            list1 = list1->next;
            list2 = list2->next;
        }

        *intersection = list1;
        return true;
    } else {
        *intersection = NULL;
        return false;
    }
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

    vector<int> vec1{4,2,3};
    Node* list1 = initializeList(vec1);
    vector<int> vec2{5,6};
    Node* list2 = initializeList(vec2);
    Node* temp = list2;
    while(list2->next != NULL) {
        list2 = list2->next;
    }
    list2->next = list1;
    bool isIntersect = isIntersection(list1, temp);
    Node** intersection = new Node*(0);
    bool isIntersect2 = findIntersection(list1, temp, intersection);

/*
    while(result != NULL) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;
    */

   cout << isIntersect << endl;
   cout << isIntersect2 << endl;
   if(*intersection != NULL) {
       cout << (*intersection)->data << endl;
   }

    return 0;
}
