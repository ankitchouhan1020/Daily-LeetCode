---
tags: ["leetcode","tree","depth-first search"]
created: "27/06/2019, 01:03:02"
difficulty: "medium"
---

# [0129-sum-root-to-leaf-numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/)

## Problem
<div><p>Given a binary tree containing digits from <code>0-9</code> only, each root-to-leaf path could represent a number.</p><br><br><p>An example is the root-to-leaf path <code>1-&gt;2-&gt;3</code> which represents the number <code>123</code>.</p><br><br><p>Find the total sum of all root-to-leaf numbers.</p><br><br><p><strong>Note:</strong>&nbsp;A leaf is a node with no children.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> [1,2,3]<br>    1<br>   / \<br>  2   3<br><strong>Output:</strong> 25<br><strong>Explanation:</strong><br>The root-to-leaf path <code>1-&gt;2</code> represents the number <code>12</code>.<br>The root-to-leaf path <code>1-&gt;3</code> represents the number <code>13</code>.<br>Therefore, sum = 12 + 13 = <code>25</code>.</pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> [4,9,0,5,1]<br>    4<br>   / \<br>  9   0<br>&nbsp;/ \<br>5   1<br><strong>Output:</strong> 1026<br><strong>Explanation:</strong><br>The root-to-leaf path <code>4-&gt;9-&gt;5</code> represents the number 495.<br>The root-to-leaf path <code>4-&gt;9-&gt;1</code> represents the number 491.<br>The root-to-leaf path <code>4-&gt;0</code> represents the number 40.<br>Therefore, sum = 495 + 491 + 40 = <code>1026</code>.</pre><br></div>

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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return sumTree(root,root->val);
    }
    
    int sumTree(TreeNode* root,int rval){
        if(root==nullptr) return rval;
        if(!root->left && !root->right) return rval;
        
        int lsum,rsum;
        if(root->left && root->right)
        {
            lsum = sumTree(root->left, rval*10+root->left->val);
            rsum = sumTree(root->right, rval*10+root->right->val);
            return lsum+rsum;
        }
            
        if(!root->left){
            rsum = sumTree(root->right, rval*10+root->right->val);
            return rsum;
        }
        lsum = sumTree(root->left, rval*10+root->left->val);
        return lsum;
    }
};
​
```
