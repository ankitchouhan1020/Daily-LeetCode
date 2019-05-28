---
tags: ["leetcode","tree","depth-first search","breadth-first search"]
created: "28/05/2019, 13:56:25"
difficulty: "medium"
---

# [0199-binary-tree-right-side-view](https://leetcode.com/problems/binary-tree-right-side-view/)

## Problem
<div><p>Given a binary tree, imagine yourself standing on the <em>right</em> side of it, return the values of the nodes you can see ordered from top to bottom.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong>&nbsp;[1,2,3,null,5,null,4]<br><strong>Output:</strong>&nbsp;[1, 3, 4]<br><strong>Explanation:<br></strong><br>   1            &lt;---<br> /   \<br>2     3         &lt;---<br> \     \<br>  5     4       &lt;---<br></pre></div>

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
// Thinking : Traverse all and store latest val in preorder traversal
// Alternative : Traverse in mirror image of preorder // store the first val // Link GeeksforGeeks
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        map<int,int> m;
        preorder(root,m,0);
        for(auto i: m){
            ans.push_back(i.second);
        }
        return ans;
    }
    
    void preorder(TreeNode* root, map<int,int>& m,int level){
        if(!root) return;
        
        m[level] = root->val;
        preorder(root->left,m,level+1);
        preorder(root->right,m,level+1);
    }
    
};
​
```
