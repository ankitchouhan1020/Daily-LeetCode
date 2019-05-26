---
tags: ["leetcode","linked list","two pointers"]
created: "26/05/2019, 16:20:48"
difficulty: "medium"
---

# [0019-remove-nth-node-from-end-of-list](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

## Problem
<div><p>Given a linked list, remove the <em>n</em>-th node from the end of list and return its head.</p><br><br><p><strong>Example:</strong></p><br><br><pre>Given linked list: <strong>1-&gt;2-&gt;3-&gt;4-&gt;5</strong>, and <strong><em>n</em> = 2</strong>.<br><br>After removing the second node from the end, the linked list becomes <strong>1-&gt;2-&gt;3-&gt;5</strong>.<br></pre><br><br><p><strong>Note:</strong></p><br><br><p>Given <em>n</em> will always be valid.</p><br><br><p><strong>Follow up:</strong></p><br><br><p>Could you do this in one pass?</p><br></div>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        for(int i=1;i<=n+1;i++){
            fast = fast->next;
        }
        
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};
​
```
