#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

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


int height(TreeNode* root) {
    if(root == NULL) {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int rootHeight = max(leftHeight, rightHeight)+1;

    return rootHeight;
}

bool isBalanced(TreeNode* root) {
    if(root == NULL) {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if(abs(leftHeight - rightHeight) <= 1) {
        return isBalanced(root->left) && isBalanced(root->right);
    } else {
        return false;
    }
}


int main() {

    vector<int> elements {1,2,3,4,5,6};
    TreeNode* tree = createTree(elements, 0);
    cout << height(tree) << endl;
    bool balanced = isBalanced(tree);
    cout << balanced << endl;

    vector<int> elements2 {1,2,5,3,'#',6,'#','#',4,'#','#','#',7};
    TreeNode* tree2 = createTree(elements2, 0);
    cout << height(tree) << endl;
    bool balanced2 = isBalanced(tree2);
    cout << balanced2 << endl;

    return 0;

}
