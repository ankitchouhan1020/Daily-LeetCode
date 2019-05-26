---
tags: ["leetcode","binary search","tree"]
created: "26/05/2019, 16:49:35"
difficulty: "medium"
---

# [0230-kth-smallest-element-in-a-bst](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

## Problem
<div><p>Given a binary search tree, write a function <code>kthSmallest</code> to find the <b>k</b>th smallest element in it.</p><br><br><p><b>Note: </b><br><br>You may assume k is always valid, 1 ≤ k ≤ BST's total elements.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> root = [3,1,4,null,2], k = 1<br>   3<br>  / \<br> 1   4<br>  \<br>&nbsp;  2<br><strong>Output:</strong> 1</pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> root = [5,3,6,2,4,null,null,1], k = 3<br>       5<br>      / \<br>     3   6<br>    / \<br>   2   4<br>  /<br> 1<br><strong>Output:</strong> 3<br></pre><br><br><p><b>Follow up:</b><br><br>What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?</p><br></div>

## Solution

c++
```c++
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> todo;
        
        while(root!= NULL || !todo.empty()){
            while(root!=NULL){
                todo.push(root);
                root = root->left;
            }
            
            root = todo.top();
            todo.pop();
            if(--k == 0) return root->val;
            root = root->right;
        }
        return 0; 
    }
};
​
```
