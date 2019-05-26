---
tags: ["leetcode","tree","depth-first search"]
created: "26/05/2019, 17:31:17"
difficulty: "hard"
---

# [0124-binary-tree-maximum-path-sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

## Problem
<div><p>Given a <strong>non-empty</strong> binary tree, find the maximum path sum.</p><br><br><p>For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain <strong>at least one node</strong> and does not need to go through the root.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> [1,2,3]<br><br>       <strong>1</strong><br>      <strong>/ \</strong><br>     <strong>2</strong>   <strong>3</strong><br><br><strong>Output:</strong> 6<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> [-10,9,20,null,null,15,7]<br><br>&nbsp;  -10<br>&nbsp; &nbsp;/ \<br>&nbsp; 9 &nbsp;<strong>20</strong><br>&nbsp; &nbsp; <strong>/ &nbsp;\</strong><br>&nbsp; &nbsp;<strong>15 &nbsp; 7</strong><br><br><strong>Output:</strong> 42<br></pre><br></div>

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
    int globalMax;
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        globalMax = INT_MIN;
        int res = maxPath(root);        
        return max(res,globalMax);
    }
    
    int maxPath(TreeNode* root){
        if(root == NULL) return 0;    
        int curr = root->val;
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        int maxSum = max({curr,curr+left,curr+right});
        globalMax = max({maxSum,curr+left+right, globalMax});
        return maxSum;
    }
};
​
```
