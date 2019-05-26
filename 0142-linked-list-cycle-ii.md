---
tags: ["leetcode","linked list","two pointers"]
created: "26/05/2019, 16:45:55"
difficulty: "medium"
---

# [0142-linked-list-cycle-ii](https://leetcode.com/problems/linked-list-cycle-ii/)

## Problem
<div><p>Given a linked list, return the node where the cycle begins. If there is no cycle, return <code>null</code>.</p><br><br><p>To represent a cycle in the given linked list, we use an integer <code>pos</code> which represents the position (0-indexed)&nbsp;in the linked list where tail connects to. If <code>pos</code> is <code>-1</code>, then there is no cycle in the linked list.</p><br><br><p><b>Note:</b> Do not modify the linked list.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>head = [3,2,0,-4], pos = 1<br><strong>Output: </strong>tail connects to node index 1<br><strong>Explanation:</strong> There is a cycle in the linked list, where tail connects to the second node.<br></pre><br><br><p><img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png" style="height: 97px; width: 300px;"></p><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>head = [1,2], pos = 0<br><strong>Output: </strong>tail connects to node index 0<br><strong>Explanation:</strong> There is a cycle in the linked list, where tail connects to the first node.<br></pre><br><br><p><img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png" style="height: 74px; width: 141px;"></p><br><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong>head = [1], pos = -1<br><strong>Output: </strong>no cycle<br><strong>Explanation:</strong> There is no cycle in the linked list.<br></pre><br><br><p><img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png" style="height: 45px; width: 45px;"></p><br><br><p>&nbsp;</p><br><br><p><b>Follow up</b>:<br><br>Can you solve it without using extra space?</p><br></div>

## Solution

c++
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return head;
        ListNode* walker = head;
        ListNode* runner = head;
        int flag = 0;
        while(runner && runner->next){
            walker = walker->next;
            runner = runner->next->next;
            if(walker == runner){
                flag = 1;
                break;
            }
        }
        if(flag){
            while(head != walker){
                head = head->next;
                walker = walker->next;
            }
            return head;
        }
        return NULL;
    }
};
​
```
