#include <iostream>
#include <vector>
#include <math.h>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    }

    if(rightIdx >= values.size()) {
        root->right = NULL;
    } else {
        root->right = createTree(values, rightIdx);
    }

    return root;
}


bool isBSTRecursive(TreeNode* node, int checkVal, bool left) {

    if(node == NULL) return true;

    if((left && node->val <= checkVal) || (!left && node->val > checkVal)) {
        return isBSTRecursive(node->left, node->val, true) && isBSTRecursive(node->right, node->val, false);
    } else {
        return false;
    }
}

bool isBST(TreeNode* node) {

    if(node == NULL) return true;

    return isBSTRecursive(node->left, node->val, true) && isBSTRecursive(node->right, node->val, false);
}



int main() {

    vector<int> elements {1,2,3,4,5,6};
    TreeNode* tree = createTree(elements, 0);
    cout << isBST(tree) << endl;
    
    vector<int> elements2 {4,3,7,1,'#',5,'#','#',2,'#','#','#',6};
    TreeNode* tree2 = createTree(elements2, 0);
    cout << isBST(tree2) << endl;
    

    return 0;

}
