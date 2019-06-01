---
tags: ["leetcode","linked list","two pointers"]
created: "31/05/2019, 22:29:54"
difficulty: "easy"
---

# [0234-palindrome-linked-list](https://leetcode.com/problems/palindrome-linked-list/)

## Problem
<div><p>Given a singly linked list, determine if it is a palindrome.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> 1-&gt;2<br><strong>Output:</strong> false</pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> 1-&gt;2-&gt;2-&gt;1<br><strong>Output:</strong> true</pre><br><br><p><b>Follow up:</b><br><br>Could you do it in O(n) time and O(1) space?</p><br></div>

## Solution

c++
```c++

// Find the starting of reverse via two pointer technique
// Reverse the staring from that point
// Compare values from head of linked list and reversed linked list
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        if(head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = slow;
        
        while(fast){
            if(fast->next == NULL) break;
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != NULL){
            slow = slow->next;
        }
        fast = head;
        prev->next = NULL; 
        slow = reverseList(slow);
        
        while(fast && slow){
            if(fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        
        if(fast || slow) return false;
        return true;        
    }
    
    ListNode* reverseList(ListNode* root){
        if(root == NULL) return root;
        ListNode* prev=NULL;
​
```
