---
tags: ["leetcode","array","tree","depth-first search"]
created: "04/06/2019, 11:51:33"
difficulty: "medium"
---

# [0105-construct-binary-tree-from-preorder-and-inorder-traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

## Problem
<div><p>Given preorder and inorder traversal of a tree, construct the binary tree.</p><br><br><p><strong>Note:</strong><br><br>You may assume that duplicates do not exist in the tree.</p><br><br><p>For example, given</p><br><br><pre>preorder =&nbsp;[3,9,20,15,7]<br>inorder = [9,3,15,20,7]</pre><br><br><p>Return the following binary tree:</p><br><br><pre>    3<br>   / \<br>  9  20<br>    /  \<br>   15   7</pre><br></div>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.empty() || preorder.empty()) return nullptr;
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        return construct(preorder,inorder,m,0,inorder.size()-1,0);
    }
    
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &m,int start,int end,int node){
        if(start == end){
            return (new TreeNode(inorder[start]));
        }
        if(node==preorder.size()) return nullptr;
        
        int rootPos = m[preorder[node]];
        if(rootPos<start || rootPos>end){
            return construct(preorder,inorder,m,start,end,node+1);
        }
        
        TreeNode* root = new TreeNode(preorder[node]);
        root->left = construct(preorder,inorder,m,start,rootPos-1,node+1);
        root->right = construct(preorder,inorder,m,rootPos+1,end,node+1);      
        return root;
    }
};
​
```
