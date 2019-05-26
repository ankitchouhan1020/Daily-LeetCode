---
tags: ["leetcode","binary search tree"]
created: "26/05/2019, 17:16:39"
difficulty: "medium"
---

# [1038-binary-search-tree-to-greater-sum-tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)

## Problem
<div><p>Given the root of a binary <strong>search</strong> tree with distinct values, modify it so that every <code>node</code>&nbsp;has a new value equal to the sum of the values of the original tree that are greater than or equal to <code>node.val</code>.</p><br><br><p>As a reminder, a&nbsp;<em>binary search tree</em> is a tree that satisfies these constraints:</p><br><br><ul><br>	<li>The left subtree of a node contains only nodes with keys&nbsp;<strong>less than</strong>&nbsp;the node's key.</li><br>	<li>The right subtree of a node contains only nodes with keys&nbsp;<strong>greater than</strong>&nbsp;the node's key.</li><br>	<li>Both the left and right subtrees must also be binary search trees.</li><br></ul><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/05/02/tree.png" style="width: 280px; height: 191px;"></strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]</span><br><strong>Output: </strong><span id="example-output-1">[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]</span><br></pre><br><br><div><br><p>&nbsp;</p><br></div><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li>The number of nodes in the tree is between <code>1</code> and <code>100</code>.</li><br>	<li>Each node will have value between <code>0</code> and <code>100</code>.</li><br>	<li>The given tree is a binary search tree.</li><br></ol><br><br><div><br><div><br><div>&nbsp;</div><br></div><br></div><br></div>

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
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return root;
        if(root->right != NULL){
           int rvalue = toGST(root->right,0);
            root->val = rvalue + root->val; 
        }
        if(root->left != NULL){
           int lvalue = toGST(root -> left,root->val); 
        }        
        return root;
    }
    int toGST(TreeNode* root,int value){
        int x = 0,y=0;
        if(root->right != NULL){
            y = toGST(root->right,value);
        }
        if(y==0)    root->val = root->val + value;
        else root->val = root->val + y;
        if(root->left != NULL){
            x = toGST(root->left,root->val);
            return x;
        }
        return root->val;
    }
};
​
```
