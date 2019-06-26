---
tags: ["leetcode","tree","depth-first search"]
created: "26/06/2019, 20:27:06"
difficulty: "easy"
---

# [0872-leaf-similar-trees](https://leetcode.com/problems/leaf-similar-trees/)

## Problem
<div><p>Consider all the leaves of a binary tree.&nbsp; From&nbsp;left to right order, the values of those&nbsp;leaves form a <em>leaf value sequence.</em></p><br><br><p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png" style="width: 300px; height: 240px;"></p><br><br><p>For example, in the given tree above, the leaf value sequence is <code>(6, 7, 4, 9, 8)</code>.</p><br><br><p>Two binary trees are considered <em>leaf-similar</em>&nbsp;if their leaf value sequence is the same.</p><br><br><p>Return <code>true</code> if and only if the two given trees with head nodes <code>root1</code> and <code>root2</code> are leaf-similar.</p><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>Both of the given trees will have between <code>1</code> and <code>100</code> nodes.</li><br></ul><br></div>

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
    vector<int> one,two;
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1,1);
        dfs(root2,2);
        if(one.size() != two.size()) return false;
        for(int i=0;i<one.size();i++){
            if(one[i] != two[i]) return false;
        }
        return true;
    }
    
    void dfs(TreeNode* root,int chance){
        if(root==nullptr) return;
        if(root->left) dfs(root->left,chance);
        if(root->right) dfs(root->right,chance);
        if(!root->left && !root->right){
            if(chance == 1) one.push_back(root->val);
            else two.push_back(root->val);
        }
        return;
    }
    
};
​
```
