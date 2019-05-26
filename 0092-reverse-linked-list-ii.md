---
tags: ["leetcode","linked list"]
created: "26/05/2019, 16:36:50"
difficulty: "medium"
---

# [0092-reverse-linked-list-ii](https://leetcode.com/problems/reverse-linked-list-ii/)

## Problem
<div><p>Reverse a linked list from position <em>m</em> to <em>n</em>. Do it in one-pass.</p><br><br><p><strong>Note:&nbsp;</strong>1 ≤ <em>m</em> ≤ <em>n</em> ≤ length of list.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL, <em>m</em> = 2, <em>n</em> = 4<br><strong>Output:</strong> 1-&gt;4-&gt;3-&gt;2-&gt;5-&gt;NULL<br></pre><br></div>

## Solution

c++
```c++
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        /*
        *   If head is NULL or single node return it directly.
        *   If m==n means no need of reversing.
        */
        if(!head || head->next == NULL) return head;
        if(m==n) return head;
        
        /*
        *   prevTail holds tail of list before m. It is node which is connected to mth node.
        */
        ListNode* prevTail = NULL;
        ListNode* current = head;
        
        /*
        *   Traverse till mth node.
        */
        for(int i=1;i<m;i++,prevTail = current,current = current->next);      
        
        /*
        *   marker holds the mth node address. Its next will connect link after nth node.
        */
        ListNode* prev = current;
        ListNode* ahead = current->next;
        ListNode* marker = current;
        current->next = NULL;
        int diff = n-m;
        
        /*
        *   While loop reverse the link list from m to n
        */
        while(diff--){
            prev = current;
            current = ahead;
            ahead = ahead->next;
            current -> next = prev;
        }
        
        /*
            Connect node before m to nth node.
        *   It m = 1, prevTail will be NULL, so give head the 
        *   address of current node. Current is pointing to nth node.
        */
        if(prevTail)   prevTail->next = current;
        else head = current;
        
        /*
        *   Connect mth node with node after nth node.
        */
        marker->next = ahead;
        return head;
    }
};
​
```
