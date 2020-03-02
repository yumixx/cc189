# 题目：Sort Stack

# 思路：
在只能额外使用1个stack的情况下，我们可以用两个stack模拟插入排序的过程。假设有两个stack，stack1是原始stack，stack2是additional stack：
stack1: bottom | 7 | 10 | 5 | top
stack2: bottom | 1 | 3 | 8 | 12 | top
stack2已经是一个sorted stack，现在我们想将stack1的top插入到stack2中合适的位置，很明显应该在元素3之上。我们可以先将5取出，存起来，然后将stack2的元素不断pop出来push到stack1中，直到stack2的top小于5，然后将5push入stack2。之后再不断重复这种比较的过程，根据数值的大小进行操作。只有当stack2不为空且stack2的top大于stack1的top时，我们才需要不断进行将这些大的元素放入stack1中缓存的操作。
上述方法时间复杂度O(n²)，空间复杂度O(n)。

TODO: 假如可以额外用两个stack，我们可以进行mergeSort或者quickSort，在递归的每一层都要额外构建两个stacks。
