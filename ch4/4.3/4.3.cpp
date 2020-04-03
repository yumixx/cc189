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


void createDepthLinkedLists(TreeNode* root, int level, vector<list<TreeNode*>>& linkedLists) {
    if(root == NULL) return;

    if(linkedLists.size() == level) {
        list<TreeNode*> list;
        linkedLists.push_back(list);
    }
    linkedLists[level].push_back(root);

    createDepthLinkedLists(root->left, level+1, linkedLists);
    createDepthLinkedLists(root->right, level+1, linkedLists);
}

typedef list<TreeNode*>::iterator listIter;
vector<list<TreeNode*>> createDepthLinkedLists(TreeNode* root) {

    vector<list<TreeNode*>> linkedLists;
    list<TreeNode*> current;
    if(root != NULL) {
        current.push_back(root);
    }

    while(!current.empty()) {
        linkedLists.push_back(current);
        list<TreeNode*> nextLevel;
        for(listIter i = current.begin(); i != current.end(); ++i) {
            if((*i)->left != NULL) {
                nextLevel.push_back((*i)->left);
            }
            if((*i)->right != NULL) {
                nextLevel.push_back((*i)->right);
            }
        }
        current = nextLevel;
    }

    return linkedLists;
}


int main() {

    vector<int> elements {1,2,3,4,5,6};
    TreeNode* tree = createTree(elements, 0);
    vector<list<TreeNode*>> linkedLists;
    createDepthLinkedLists(tree, 0, linkedLists);
    for(int i = 0; i < linkedLists.size(); ++i) {
        for(TreeNode* node : linkedLists[i]) {
            cout << node->val << " ";
        }
        cout << endl;
    }
    linkedLists = createDepthLinkedLists(tree);
    for(int i = 0; i < linkedLists.size(); ++i) {
        for(TreeNode* node : linkedLists[i]) {
            cout << node->val << " ";
        }
        cout << endl;
    }



    vector<int> elements2 {1,2,5,3,'#',6,'#','#',4,'#','#','#',7};
    TreeNode* tree2 = createTree(elements2, 0);
    vector<list<TreeNode*>> linkedLists2;
    createDepthLinkedLists(tree2, 0, linkedLists2);
    for(int i = 0; i < linkedLists2.size(); ++i) {
        for(TreeNode* node : linkedLists2[i]) {
            cout << node->val << " ";
        }
        cout << endl;
    }
    linkedLists2 = createDepthLinkedLists(tree2);
    for(int i = 0; i < linkedLists2.size(); ++i) {
        for(TreeNode* node : linkedLists2[i]) {
            cout << node->val << " ";
        }
        cout << endl;
    }


    return 0;

}
