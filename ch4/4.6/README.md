# 题目：Successor

# 思路：
想一下in-order遍历的方式，对一个Node而言，是左子树->node->右子树。如果一个Node有右子树，那么它的successor就是右子树中最深的那个左节点；而如果一个Node没有右子树，那么我们需要返回去看它的parent，如果这个node是它父节点的右孩子，那么需要继续往上查找它的父节点的父节点，直到某一个节点是它父节点的左孩子，那么这个父节点就是原本Node的successor；或者，当到达root节点也一直是在右子树，那么说明这个node是最后一个节点。
