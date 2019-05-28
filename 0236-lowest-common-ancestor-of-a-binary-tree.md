---
tags: ["leetcode","tree"]
created: "28/05/2019, 12:34:42"
difficulty: "medium"
---

# [0236-lowest-common-ancestor-of-a-binary-tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

## Problem
<div><p>Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.</p><br><br><p>According to the <a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank">definition of LCA on Wikipedia</a>: “The lowest common ancestor is defined between two nodes p&nbsp;and q&nbsp;as the lowest node in T that has both p&nbsp;and q&nbsp;as descendants (where we allow <b>a node to be a descendant of itself</b>).”</p><br><br><p>Given the following binary tree:&nbsp; root =&nbsp;[3,5,1,6,2,0,8,null,null,7,4]</p><br><img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png" style="width: 200px; height: 190px;"><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1<br><strong>Output:</strong> 3<br><strong>Explanation: </strong>The LCA of nodes <code>5</code> and <code>1</code> is <code>3.</code><br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4<br><strong>Output:</strong> 5<br><strong>Explanation: </strong>The LCA of nodes <code>5</code> and <code>4</code> is <code>5</code>, since a node can be a descendant of itself according to the LCA definition.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>All of the nodes' values will be unique.</li><br>	<li>p and q are different and both values will&nbsp;exist in the binary tree.</li><br></ul><br></div>

## Solution

c++
```c++

​
        return ans;
    }
    
    bool isLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        // end of journey and we got nothing
        if(!root) return false;
        
        // we reached a house which containis criminals p or q
        int found = 0;
        if(root == p || root==q){
            found++;
        }
        
        // for another criminal go to left of that house and right of that.
        // May be neighbors are the one who are keeping them safe
        bool leftRes = isLCA(root->left,p,q);
        bool rightRes  = isLCA(root->right,p,q);
    
        // if one have p and other have q then we have found them.
        if(leftRes && rightRes){
            ans = root;
            return true;
        }
        
        // Else one of then having p or q
        if(leftRes || rightRes) found++;
        
        // If somehow we got both then
        if(found == 2){
            ans  = root;
            return true;
        }
        
        // Something is even in our hand
        if(found == 1) return true;
        
        //hopeless
        return false;
    }
};
​
```
