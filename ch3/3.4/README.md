# 题目： Queue via Stacks

# 思路：
1. 最初始的想法，用一个stackOld保存数据，然后每次pop的时候将stackOld的数据pop到stackNew中，这样此时stackNew的top就是queue的top，将其pop出，然后再将stackNew的数据推回stackOld中。但是这样其实每次都有很多无用的数据迁移。
2. 基于方法1的改进。每次push时，若stackOut中有元素，先将其推回stackIn，然后再push进stackIn。每次pop时，若stackIn中有数据，就先将stackIn中数据pop到stackOut中，以获得top数据。在这种方法下，stackIn与stackOut一定是至少有一个为空。
3. 在2中其实仍有不必要的数据迁移，可以进一步改进。在每次push时，我们不需要考虑stackOut中是否还有元素，直接push进stackIn中。当pop时，将stackOut中的数据pop出即可，如果stackOut为空，则将stackIn的数据先推入stackOut中。这种方法其实相当于将队列的元素划分为了两个部分，分别存储在stackIn和stackOut中。
