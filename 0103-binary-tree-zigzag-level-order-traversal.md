---
tags: ["leetcode","stack","tree","breadth-first search"]
created: "28/05/2019, 13:23:35"
difficulty: "medium"
---

# [0103-binary-tree-zigzag-level-order-traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

## Problem
<div><p>Given a binary tree, return the <i>zigzag level order</i> traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).</p><br><br><p><br>For example:<br><br>Given binary tree <code>[3,9,20,null,null,15,7]</code>,<br><br></p><pre>    3<br>   / \<br>  9  20<br>    /  \<br>   15   7<br></pre><br><p></p><br><p><br>return its zigzag level order traversal as:<br><br></p><pre>[<br>  [3],<br>  [20,9],<br>  [15,7]<br>]<br></pre><br><p></p></div>

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
//level order traversal with marker
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> powerset;
        TreeNode* marker = new TreeNode(INT_MIN);
        if(!root) return powerset;
        
        vector<int> subset;
        queue<TreeNode*> q;
        int even = 1;
        q.push(root);
        q.push(marker);
        
        while(!q.empty()){
            root  = q.front(); q.pop();
​
            while(root->val != INT_MIN){
                subset.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
                root = q.front(); q.pop();
            }
            q.push(root);
            
            if(!even) reverse(subset.begin(),subset.end());
            powerset.push_back(subset);
            subset = vector<int>();
            even = (even+1)%2;
            
            if(q.front()->val == INT_MIN) break;
        }
        
        return powerset;
    }
};
​
```
