#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};


TreeNode* createTree(const vector<int>& values, int start) {
    if(values[start] == '#') return NULL;

    TreeNode* root = new TreeNode(values[start]);

    int leftIdx = 2*start+1;
    int rightIdx = 2*start+2;
    if(leftIdx >= values.size()) {
        root->left = NULL;
    } else {
        root->left = createTree(values, leftIdx);
        if(root->left != NULL) {
            root->left->parent = root;
        }
    }

    if(rightIdx >= values.size()) {
        root->right = NULL;
    } else {
        root->right = createTree(values, rightIdx);
        if(root->right != NULL) {
            root->right->parent = root;
        }
    }

    return root;
}



TreeNode* successor(TreeNode* node) {

    if(node == NULL) return NULL;

    if(node->right == NULL) {
        TreeNode* parent = node->parent;
        while(parent != NULL && parent->right == node) {
            node = parent;
            parent = node->parent;
        }
        return parent;
    } else {
        TreeNode* temp = node->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }
    
}

void levelTraverse(TreeNode* root) {

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << "Node: " << node->val << " ";
        if(node->parent != NULL) cout << "Parent: " << node->parent->val;
        cout << endl;
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
    }
}



int main() {

    vector<int> elements {1,2,3,4,5,6};
    TreeNode* tree = createTree(elements, 0);
    levelTraverse(tree);
    TreeNode* next = successor(tree->left);
    cout << next->val << endl;
    next = successor(tree->left->left);
    cout << next->val << endl;
    next = successor(tree->right->left);
    cout << next->val << endl;
    
    vector<int> elements2 {4,3,7,1,'#',5,'#','#',2,'#','#','#',6};
    TreeNode* tree2 = createTree(elements2, 0);
    levelTraverse(tree2);
    TreeNode* next2 = successor(tree2->left->left);
    cout << next2->val << endl;
    next2 = successor(tree2->right);
    if(next2 == NULL) {
        cout << "NULL" << endl;
    } else {
        cout << next2->val << endl;
    }
    

    return 0;

}
