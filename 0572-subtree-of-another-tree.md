---
tags: ["leetcode","tree"]
created: "04/06/2019, 11:51:29"
difficulty: "easy"
---

# [0572-subtree-of-another-tree](https://leetcode.com/problems/subtree-of-another-tree/)

## Problem
<div><p><br>Given two non-empty binary trees <b>s</b> and <b>t</b>, check whether tree <b>t</b> has exactly the same structure and node values with a subtree of <b>s</b>. A subtree of <b>s</b> is a tree consists of a node in <b>s</b> and all of this node's descendants. The tree <b>s</b> could also be considered as a subtree of itself.<br></p><br><br><p><b>Example 1:</b><br><br><br>Given tree s:<br></p><pre>     3<br>    / \<br>   4   5<br>  / \<br> 1   2<br></pre><br>Given tree t:<br><pre>   4 <br>  / \<br> 1   2<br></pre><br>Return <b>true</b>, because t has the same structure and node values with a subtree of s.<br><p></p><br><br><p><b>Example 2:</b><br><br><br>Given tree s:<br></p><pre>     3<br>    / \<br>   4   5<br>  / \<br> 1   2<br>    /<br>   0<br></pre><br>Given tree t:<br><pre>   4<br>  / \<br> 1   2<br></pre><br>Return <b>false</b>.<br><p></p></div>

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        vector<TreeNode*> v;
        traverseTree(s,v,t->val);
        
        for(auto root: v){
            if(matchTree(root,t)) return true;
        }
        return false;
    }
    
    bool matchTree(TreeNode* a, TreeNode*b){
        if(!a && !b) return true;
        if((a && !b) || (b && !a) || (a->val != b->val))    return false;
        return matchTree(a->left,b->left) && matchTree(a->right,b->right);
    }
    
    void traverseTree(TreeNode* s, vector<TreeNode*>&v,int rval){
        if(s == nullptr) return;
        if(s->val == rval){
            v.push_back(s);
        }
        traverseTree(s->left,v,rval);
        traverseTree(s->right,v,rval);
        return;        
    }
};
​
```
