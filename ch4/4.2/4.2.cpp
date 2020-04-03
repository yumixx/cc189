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


TreeNode* createMinimalTree(const vector<int>& elements) {
    
    if(elements.empty()) return NULL;

    int middleIdx = elements.size()/2;
    int middle = elements[middleIdx];
    TreeNode* root = new TreeNode(middle);

    vector<int> leftElements(elements.begin(),elements.begin()+middleIdx);
    vector<int> rightElements(elements.begin()+middleIdx+1, elements.end());

    TreeNode* left = createMinimalTree(leftElements);
    TreeNode* right = createMinimalTree(rightElements);

    root->left = left;
    root->right = right;

    return root;
}


void levelTraversal(TreeNode* tree) {

    queue<TreeNode*> q;
    q.push(tree);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << endl;
        if(node->left != NULL) {
            q.push(node->left);
        }
        if(node->right != NULL) {
            q.push(node->right);
        }
    }
}


int main() {

    vector<int> elements {1,2,3,4,5,6};
    TreeNode* tree = createMinimalTree(elements);
    levelTraversal(tree);

    return 0;

}
