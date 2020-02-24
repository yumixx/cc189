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


Node* reverseList(Node* node) {

    if(node == NULL || node->next == NULL) {
        return node;
    }

    Node* newNode = reverseList(node->next);

    node->next->next = node;
    node->next = NULL;
    return newNode;

}

Node* reverseAndClone(Node* node) {

    Node* newNode = NULL;
    while(node != NULL) {
        Node* temp = new Node(node->data);
        temp->next = newNode;
        newNode = node;
        node = node->next;

    }

    return newNode;
}


bool isPalindrome(Node* node) {

    Node* reversedNode = reverseAndClone(node);
    while(reversedNode != NULL && node != NULL) {
        if(reversedNode->data != node->data) {
            return false;
        }
        reversedNode = reversedNode->next;
        node = node->next;
    }

    return true;
}

bool isPalindrome2(Node* node) {

    stack<int> stack;

    Node* temp = node;
    while(temp != NULL) {
        stack.push(temp->data);
        temp = temp->next;
    }

    temp = node;
    while(temp != NULL) {
        int data = stack.top();
        if(temp->data != data) {
            return false;
        }
        stack.pop();
        temp = temp->next;
    }

    return true;
}


struct Result {

    Node* res;
    bool result;

    Result(Node* node, bool r) : res(node), result(r) {}
};

int lengthList(Node* head) {
    int length = 0;
    Node* node = head;
    while(node != NULL) {
        length++;
        node = node->next;
    }

    return length;
}


Result isParlindromeRecursion(Node* node, int length) {

    if(node == NULL || length <= 0) { // Even number of LinkedList
        return Result(node, true);
    } else if(length == 1) { // Odd number of LinkedList
        return Result(node->next, true);
    }

    Result result = isParlindromeRecursion(node->next, length-2);

    if(!result.result || result.res == NULL) {
        return result;
    }

    result.result = result.res->data == node->data ? true : false;
    result.res = result.res->next;

    return result;
    
}

bool isParlindrome3(Node* node) {

    int length = lengthList(node);

    Result result = isParlindromeRecursion(node, length);

    return result.result;
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

    vector<int> vec1{1,2,3,2,1};
    Node* list1 = initializeList(vec1);
    bool result = isPalindrome(list1);
    bool result2 = isPalindrome2(list1);
    bool result3 = isParlindrome3(list1);

/*
    while(result != NULL) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;
    */

   cout << result << endl;
   cout << result2 << endl;
   cout << result3 << endl;

    return 0;
}
