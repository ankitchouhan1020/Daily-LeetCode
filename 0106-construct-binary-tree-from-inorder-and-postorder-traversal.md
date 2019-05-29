---
tags: ["leetcode","array","tree","depth-first search"]
created: "29/05/2019, 17:46:30"
difficulty: "medium"
---

# [0106-construct-binary-tree-from-inorder-and-postorder-traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

## Problem
<div><p>Given inorder and postorder traversal of a tree, construct the binary tree.</p><br><br><p><strong>Note:</strong><br><br>You may assume that duplicates do not exist in the tree.</p><br><br><p>For example, given</p><br><br><pre>inorder =&nbsp;[9,3,15,20,7]<br>postorder = [9,15,7,20,3]</pre><br><br><p>Return the following binary tree:</p><br><br><pre>    3<br>   / \<br>  9  20<br>    /  \<br>   15   7<br></pre><br></div>

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
// Finding in inorder can be done easily with map
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //helper function
        return makeTree(inorder,0,inorder.size()-1,postorder,postorder.size()-1);
    }
    
    TreeNode* makeTree(vector<int>& inorder,int start,int last, vector<int>& postorder,int pos){
       
        // If only one node in subtree
        if(start==last){
            TreeNode* root = new TreeNode(inorder[start]);
            return root;
        }
        
        if(start > last) return NULL;
        
        // reached till every root
        if(pos < 0) return NULL;
        
        // It stores index of root in inorder path
        int rootPos = -1;        
        
        // Since postorder[pos] may contain root in either left or right subtree
        // So we keep checking we didn't find root in our subtree
        while(pos>=0 && rootPos == -1){
​
```
