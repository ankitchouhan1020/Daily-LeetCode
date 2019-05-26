---
tags: ["leetcode","hash table","stack","tree"]
created: "26/05/2019, 16:37:26"
difficulty: "medium"
---

# [0094-binary-tree-inorder-traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

## Problem
<div><p>Given a binary tree, return the <em>inorder</em> traversal of its nodes' values.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> [1,null,2,3]<br>   1<br>    \<br>     2<br>    /<br>   3<br><br><strong>Output:</strong> [1,3,2]</pre><br><br><p><strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?</p><br></div>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> todo;
        
        if(root == NULL) return result;
        while(root!= NULL || !todo.empty()){
            while(root!=NULL){
                todo.push(root);
                root = root->left;
            }
            
            root = todo.top();
            todo.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};
​
```
