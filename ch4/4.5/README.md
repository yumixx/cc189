# 题目：Validate BST

# 思路：
1. 中序遍历，如果是单调非递减则是BST，但是注意无法处理duplicates的分布情况。
2. 递归，如果是BST,则左子树一定都小于等于root，右子树一定都大于root（具体可以定义一下对duplicates的判定），那么我们只要不断地递归，并将数据和当前root的值比较就好。
