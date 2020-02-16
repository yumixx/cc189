# 题目：String Compression

# 思路：
一个非常straightforward的思路是遍历，计数，加入string中。
但这里由于string的+操作是O(n²)，copy操作。
此外可以把长度的检查放到最开始。
同时要把i + 1 >= aString.length()的条件放到前面，因为在i == aString.length()-1的时候一定会进行一次添加操作的，而且此时i+1超范围了，不存在aString[i+1]。
