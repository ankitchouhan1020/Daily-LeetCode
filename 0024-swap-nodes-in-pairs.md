---
tags: ["leetcode","linked list"]
created: "26/05/2019, 16:21:24"
difficulty: "medium"
---

# [0024-swap-nodes-in-pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)

## Problem
<div><p>Given a&nbsp;linked list, swap every two adjacent nodes and return its head.</p><br><br><p>You may <strong>not</strong> modify the values in the list's nodes, only nodes itself may be changed.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example:</strong></p><br><br><pre>Given <code>1-&gt;2-&gt;3-&gt;4</code>, you should return the list as <code>2-&gt;1-&gt;4-&gt;3</code>.<br></pre><br></div>

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode *prev,*after;
        prev = head;
        head = head->next;
        after = head->next;
        head->next = prev;
        prev->next = swapPairs(after);
        return head;
    }
};
​
```
