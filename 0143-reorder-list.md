---
tags: ["leetcode","linked list"]
created: "04/06/2019, 15:07:51"
difficulty: "medium"
---

# [0143-reorder-list](https://leetcode.com/problems/reorder-list/)

## Problem
<div><p>Given a singly linked list <em>L</em>: <em>L</em><sub>0</sub>→<em>L</em><sub>1</sub>→…→<em>L</em><sub><em>n</em>-1</sub>→<em>L</em><sub>n</sub>,<br><br>reorder it to: <em>L</em><sub>0</sub>→<em>L</em><sub><em>n</em></sub>→<em>L</em><sub>1</sub>→<em>L</em><sub><em>n</em>-1</sub>→<em>L</em><sub>2</sub>→<em>L</em><sub><em>n</em>-2</sub>→…</p><br><br><p>You may <strong>not</strong> modify the values in the list's nodes, only nodes itself may be changed.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre>Given 1-&gt;2-&gt;3-&gt;4, reorder it to 1-&gt;4-&gt;2-&gt;3.</pre><br><br><p><strong>Example 2:</strong></p><br><br><pre>Given 1-&gt;2-&gt;3-&gt;4-&gt;5, reorder it to 1-&gt;5-&gt;2-&gt;4-&gt;3.<br></pre><br></div>

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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *p = head;
        ListNode *q = getMidNode(head);   
        q = reverseList(q);
        mergeList(p,q);
    } 
    
    ListNode* getMidNode(ListNode* head){
        ListNode *slow= head,*fast= head;
        while(slow && fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;        
    }
    
    ListNode* reverseList(ListNode *root){
        ListNode* prev = NULL, *next = root, *curr = root;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        // returning head of reversed list
    }
    
    void mergeList(ListNode* p, ListNode* q){
        ListNode* tmp;
        while(q){
            tmp = p->next;  // store address of next
            p->next = q;    // link to 2nd list
            q = q->next;    // increase 2nd list pointer
            p = p->next;    
            p->next = tmp;  // link to 1st list
            p = p->next;    // increase 1st list pointer
        }
    }
​
```
