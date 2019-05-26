---
tags: ["leetcode","tree","depth-first search"]
created: "26/05/2019, 16:39:33"
difficulty: "medium"
---

# [0114-flatten-binary-tree-to-linked-list](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

## Problem
<div><p>Given a binary tree, flatten it to a linked list in-place.</p><br><br><p>For example, given the following tree:</p><br><br><pre>    1<br>   / \<br>  2   5<br> / \   \<br>3   4   6<br></pre><br><br><p>The flattened tree should look like:</p><br><br><pre>1<br> \<br>  2<br>   \<br>    3<br>     \<br>      4<br>       \<br>        5<br>         \<br>          6<br></pre><br></div>

## Solution

c++
```c++
/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
​
//root's left is child and right is next node
class Solution {
public:
    void flatten(TreeNode* p) {
        while(p){
            if(p->left == NULL){
                p = p->right;
                continue;
            }
​
            TreeNode* tmp = p->left;
            while(tmp->right) tmp=tmp->right;
            tmp->right = p->right;
            p->right = p->left;
            p->left = NULL;
            p = p->right;
        }
    }
};
​
​
​
```
