---
tags: ["leetcode","tree","depth-first search"]
created: "26/05/2019, 16:38:12"
difficulty: "medium"
---

# [0098-validate-binary-search-tree](https://leetcode.com/problems/validate-binary-search-tree/)

## Problem
<div><p>Given a binary tree, determine if it is a valid binary search tree (BST).</p><br><br><p>Assume a BST is defined as follows:</p><br><br><ul><br>	<li>The left subtree of a node contains only nodes with keys <strong>less than</strong> the node's key.</li><br>	<li>The right subtree of a node contains only nodes with keys <strong>greater than</strong> the node's key.</li><br>	<li>Both the left and right subtrees must also be binary search trees.</li><br></ul><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre>    2<br>   / \<br>  1   3<br><br><strong>Input:</strong>&nbsp;[2,1,3]<br><strong>Output:</strong> true<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre>    5<br>   / \<br>  1   4<br>&nbsp;    / \<br>&nbsp;   3   6<br><br><strong>Input:</strong> [5,1,4,null,null,3,6]<br><strong>Output:</strong> false<br><strong>Explanation:</strong> The root node's value is 5 but its right child's value is 4.<br></pre><br></div>

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
​
//via inorder template
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> todo;
        TreeNode* prev = NULL;
        if(root == NULL) return true;
        while(root!= NULL || !todo.empty()){
            while(root!=NULL){
                todo.push(root);
                root = root->left;
            }
            
            root = todo.top();
            todo.pop();
            if(prev != NULL && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};
​
```
