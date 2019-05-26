---
tags: ["leetcode","linked list","divide and conquer","heap"]
created: "26/05/2019, 17:27:21"
difficulty: "hard"
---

# [0023-merge-k-sorted-lists](https://leetcode.com/problems/merge-k-sorted-lists/)

## Problem
<div><p>Merge <em>k</em> sorted linked lists and return it as one sorted list. Analyze and describe its complexity.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong><br>[<br>&nbsp; 1-&gt;4-&gt;5,<br>&nbsp; 1-&gt;3-&gt;4,<br>&nbsp; 2-&gt;6<br>]<br><strong>Output:</strong> 1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6<br></pre><br></div>

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
​
// Merging like merge sort works in NlogK time.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        for(int i=0;i<lists.size()-1;i++){
            lists[i+1] = merge2Lists(lists[i],lists[i+1]);
        }        
        return lists[lists.size()-1];
    }
    
    
    ListNode* merge2Lists(ListNode* l1,ListNode* l2){
        ListNode dummy(INT_MIN);
        ListNode* tail = &dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        
        return dummy.next;
    }
};
​
//Merge 2 Lists first
​
```
