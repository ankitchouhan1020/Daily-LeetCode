---
tags: ["leetcode","linked list","math"]
created: "26/05/2019, 16:11:15"
difficulty: "medium"
---

# [0002-add-two-numbers](https://leetcode.com/problems/add-two-numbers/)

## Problem
<div><p>You are given two <b>non-empty</b> linked lists representing two non-negative integers. The digits are stored in <b>reverse order</b> and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.</p><br><br><p>You may assume the two numbers do not contain any leading zero, except the number 0 itself.</p><br><br><p><b>Example:</b></p><br><br><pre><b>Input:</b> (2 -&gt; 4 -&gt; 3) + (5 -&gt; 6 -&gt; 4)<br><b>Output:</b> 7 -&gt; 0 -&gt; 8<br><b>Explanation:</b> 342 + 465 = 807.<br></pre><br></div>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        ListNode* p = l1;
        ListNode* q = l2;
        int carry = 0;
        
        while(p!=NULL || q != NULL){
            int sum = 0;
            sum += (p==NULL) ? 0: p->val;
            sum += (q==NULL) ? 0: q->val;
            sum+=carry;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(p) p=p->next;
            if(q) q=q->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
        }
        return dummy.next;
    }
};
​
```
