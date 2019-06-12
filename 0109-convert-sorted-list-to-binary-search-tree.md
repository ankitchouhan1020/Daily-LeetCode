---
tags: ["leetcode","linked list","depth-first search"]
created: "12/06/2019, 20:53:47"
difficulty: "medium"
---

# [0109-convert-sorted-list-to-binary-search-tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

## Problem
<div><p>Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.</p><br><br><p>For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of <em>every</em> node never differ by more than 1.</p><br><br><p><strong>Example:</strong></p><br><br><pre>Given the sorted linked list: [-10,-3,0,5,9],<br><br>One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:<br><br>      0<br>     / \<br>   -3   9<br>   /   /<br> -10  5<br></pre><br></div>

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        ListNode* mid = findMid(head);
        TreeNode* root = new TreeNode(mid->val);
        if(mid == head)
            root->left = nullptr;
        else
            root->left = sortedListToBST(head);
        if(mid->next == nullptr)
            root->right = nullptr;
        else
            root->right = sortedListToBST(mid->next);
        return root;
    } 
​
    ListNode* findMid(ListNode* head){
        ListNode *fast=head,*slow=head,*prev=nullptr;
        while(fast && fast->next && fast->next->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev)    prev->next=nullptr;
        return slow;
    }
};
​
```
