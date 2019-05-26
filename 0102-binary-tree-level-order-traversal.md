---
tags: ["leetcode","tree","breadth-first search"]
created: "26/05/2019, 16:39:10"
difficulty: "medium"
---

# [0102-binary-tree-level-order-traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

## Problem
<div><p>Given a binary tree, return the <i>level order</i> traversal of its nodes' values. (ie, from left to right, level by level).</p><br><br><p><br>For example:<br><br>Given binary tree <code>[3,9,20,null,null,15,7]</code>,<br><br></p><pre>    3<br>   / \<br>  9  20<br>    /  \<br>   15   7<br></pre><br><p></p><br><p><br>return its level order traversal as:<br><br></p><pre>[<br>  [3],<br>  [9,20],<br>  [15,7]<br>]<br></pre><br><p></p></div>

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
//Using two queue method
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> even,odd;
        vector<vector<int>> ans;
        if(!root) return ans;
        even.push(root);
        TreeNode* temp;
        
        
        while(!even.empty() || !odd.empty()){
            vector<int> level;
            
            if(odd.empty()){
                
                while(!even.empty()){
                    temp = even.front();
                    even.pop();
                    level.push_back(temp->val);
                    
                    if(temp->left)  odd.push(temp->left);
                    if(temp->right) odd.push(temp->right);
                }
            }else if(even.empty()){
                
                while(!odd.empty()){
                    temp = odd.front();
                    odd.pop();
                    level.push_back(temp->val);
                    
                    if(temp->left)  even.push(temp->left);
                    if(temp->right) even.push(temp->right);
                }    
            }
            ans.push_back(level);
        }
        return ans;
    }
};
​
```
