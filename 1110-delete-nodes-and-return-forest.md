---
tags: ["leetcode"]
created: "07/07/2019, 22:56:56"
difficulty: "medium"
---

# [1110-delete-nodes-and-return-forest](https://leetcode.com/problems/delete-nodes-and-return-forest/)

## Problem
<div><p>Given the <code>root</code>&nbsp;of a binary tree, each node in the tree has a distinct value.</p><br><br><p>After deleting&nbsp;all nodes with a value in <code>to_delete</code>, we are left with a forest (a&nbsp;disjoint union of trees).</p><br><br><p>Return the roots of the trees in the remaining forest.&nbsp; You may return the result in any order.</p><br><br><p>&nbsp;</p><br><p><strong>Example 1:</strong></p><br><br><p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/07/01/screen-shot-2019-07-01-at-53836-pm.png" style="width: 237px; height: 150px;"></strong></p><br><br><pre><strong>Input:</strong> root = [1,2,3,4,5,6,7], to_delete = [3,5]<br><strong>Output:</strong> [[1,2,null,4],[6],[7]]<br></pre><br><br><p>&nbsp;</p><br><p><strong>Constraints:</strong></p><br><br><ul><br>	<li>The number of nodes in the given tree is at most <code>1000</code>.</li><br>	<li>Each node has a distinct value between <code>1</code> and <code>1000</code>.</li><br>	<li><code>to_delete.length &lt;= 1000</code></li><br>	<li><code>to_delete</code> contains distinct values between <code>1</code> and <code>1000</code>.</li><br></ul><br></div>

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
    vector<TreeNode*> powerset;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> m;
        for(int i: to_delete){
            m.insert(i);
        }
        bool isRoot = (m.count(root->val)+1)%2;
        deleteNodes(root,m,isRoot);
        return powerset;
    }
    void deleteNodes(TreeNode* root, unordered_set<int>&m,bool isRoot) {
        if(root == nullptr) return;
        
        if(isRoot){
            powerset.push_back(root);
        }
        if(m.count(root->val)==0)   isRoot = true;
        
        if(root->left){
            if(m.count(root->left->val)){
                deleteNodes(root->left,m,false);
                root->left = nullptr;
            }
            deleteNodes(root->left,m,!isRoot);
        }
        if(root->right){
            if(m.count(root->right->val)){
                deleteNodes(root->right,m,false);
                root->right = nullptr;
            }
            deleteNodes(root->right,m,!isRoot);
        }
    }
};
​
```
