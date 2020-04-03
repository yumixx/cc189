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

bool nodeInTree(TreeNode* root, TreeNode* node) {

    if(root == NULL) return false;

    if(root == node) return true;

    return nodeInTree(root->left, node) || nodeInTree(root->right, node);
}

TreeNode* firstCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(root == p) {
        return p;
    }
    if(root == q) {
        return q;
    }

    if(nodeInTree(root->left, p)) {
        if(nodeInTree(root->right, q)) {
            return root;
        } else if(nodeInTree(root->left, q)) {
            return firstCommonAncestor(root->left, p, q);
        } else {
            return NULL;
        }
    } else if(nodeInTree(root->right, p)) {
        if(nodeInTree(root->left, q)) {
            return root;
        } else if(nodeInTree(root->right, q)) {
            return firstCommonAncestor(root->right, p, q);
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

int main() {

    vector<int> elements = {4,3,7,1,9,5,'#','#',2,'#','#','#',6};
    TreeNode* tree = createTree(elements, 0);
    TreeNode* p = tree->left->left;
    TreeNode* q = tree->right->left;
    TreeNode* ancestor = firstCommonAncestor(tree, p, q);

    cout << ancestor->val << endl;

    return 0;
}
