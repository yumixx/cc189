# 题目：Delete Middle Node

# 思路：
由于只提供middle这个node的pointer，所以没有办法直接用一般的remove node的方法来操作。但是注意，node的替换其实可以直接进行data的替换，将middle->next的数值赋给middle，然后修改其next　pointer，再将middle->next这个指针删除即可。
注意有一个情况是，如果middle本身已经是尾节点，理论上我们只需直接删除该节点就好，然而事实上，直接删除middle，指向middle的那个节点的next指针并不会为空，当打印这个链表时，还是会打印出和原来链表长度一样的链表，且最后一个元素为０。
针对这种情况，我们可以做一些特殊处理，比如当middle为尾结点时，将其数据设置为一些特殊的数值，使得打印时并不会打印它（dummy node）。当然也可以直接不处理这种情况，直接返回false表明是一种错误的情况。
