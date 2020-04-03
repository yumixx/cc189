# 题目：Route Between Nodes

# 思路：
用bfs来解，要在搜索过程中标记这个node被visit的状态。
这里我为了能够检测到环的情况，将adj == end的情况放在了检测其visit的状态前面。
