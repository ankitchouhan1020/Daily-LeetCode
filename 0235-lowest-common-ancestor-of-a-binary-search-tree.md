---
tags: ["leetcode","tree"]
created: "04/06/2019, 11:51:36"
difficulty: "easy"
---

# [0235-lowest-common-ancestor-of-a-binary-search-tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

## Problem
<div><p>Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.</p><br><br><p>According to the <a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank">definition of LCA on Wikipedia</a>: “The lowest common ancestor is defined between two nodes p and q&nbsp;as the lowest node in T that has both p and q&nbsp;as descendants (where we allow <b>a node to be a descendant of itself</b>).”</p><br><br><p>Given binary search tree:&nbsp; root =&nbsp;[6,2,8,0,4,7,9,null,null,3,5]</p><br><img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png" style="width: 200px; height: 190px;"><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8<br><strong>Output:</strong> 6<br><strong>Explanation: </strong>The LCA of nodes <code>2</code> and <code>8</code> is <code>6</code>.<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4<br><strong>Output:</strong> 2<br><strong>Explanation: </strong>The LCA of nodes <code>2</code> and <code>4</code> is <code>2</code>, since a node can be a descendant of itself according to the LCA definition.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>All of the nodes' values will be unique.</li><br>	<li>p and q are different and both values will&nbsp;exist in the BST.</li><br></ul><br></div>

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
    TreeNode* ans;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        lca(root,p,q);
        return ans;
    }
    
    int lca(TreeNode* root, TreeNode* p, TreeNode* q){
        int found = 0;
        if(root == nullptr) return 0;
        if(root == p && root == q){
            ans = root;
            return 2;
        }
        if(root == p || root == q)
            found ++;
        found += lca(root->left,p,q);
        found += lca(root->right,p,q);
        if(found >= 2)
            if(ans == nullptr)
                ans = root;
        return found;
    }
};
​
```
