# 题目：Check Balanced

# 思路：
判断一棵二叉树是不是平衡二叉树，对每一个节点递归比较，首先它的两颗子树必定是平衡的，其次两颗子树的高度差不能大于1。那么我们要实现两个功能：
1. 得到一颗树的高度。
2. 递归比较，根据三个判定（左子树，右子树，高度差）
这里在计算高度时，叶子的高度为0，为方便计算我们将空子数的高度设为-1。
