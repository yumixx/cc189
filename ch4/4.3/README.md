# 题目：List of Depths

# 思路：
一个很关键的点就是确定层级。这样如果用层次遍历的方法，或者说更普遍的bfs，就需要做一些改进。
1. 递归的方法。对一个节点，如果其在level这层，那么它的左孩子和右孩子就在level+1层。可以维护一个全局变量，保存各层的List,根据这个节点对应的level存入对应的层，或者新建一个层存入这个全局变量。
2. bfs的方法。先有当前层得到所有下一层的元素，存入，然后再遍历下一层元素，得到下下层。
以上两种方法都是O(N)的时间复杂度。对第一种方法来说，需要O(logN)的recursive calls,对每一个都要增加一个新的level到vector中。对第二种方法来说，因为是迭代的方法，所以不需要这些额外的空间。
然而，两种方法都要return O(N)的数据，而额外需要的O(logN)空间相对于O(N)来说很小。所以其实两种方法是equally space efficient.
