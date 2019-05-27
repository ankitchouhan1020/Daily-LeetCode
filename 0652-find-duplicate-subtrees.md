---
tags: ["leetcode","tree"]
created: "27/05/2019, 13:13:26"
difficulty: "medium"
---

# [0652-find-duplicate-subtrees](https://leetcode.com/problems/find-duplicate-subtrees/)

## Problem
<div><p>Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any <b>one</b> of them.</p><br><br><p>Two trees are duplicate if they have the same structure with same node values.</p><br><br><p><b>Example 1: </b></p><br><br><pre>        1<br>       / \<br>      2   3<br>     /   / \<br>    4   2   4<br>       /<br>      4<br></pre><br><br><p>The following are two duplicate subtrees:</p><br><br><pre>      2<br>     /<br>    4<br></pre><br><br><p>and</p><br><br><pre>    4<br></pre><br>Therefore, you need to return above trees' root in the form of a list.</div>

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
// Todo : Why inorder did't worked.
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> m;
        vector<TreeNode*> ans;
        dfs(m,ans,root);
        return ans;
    }
    
    string dfs(unordered_map<string,int> &m,vector<TreeNode*>& ans,TreeNode* root){
        if(!root) return "";
        string s =  to_string(root->val) + ','+ dfs(m,ans,root->left) +',' + dfs(m,ans,root->right);
        if(m[s]++ == 1)
            ans.push_back(root);
        return s;        
    }
};
​
```
