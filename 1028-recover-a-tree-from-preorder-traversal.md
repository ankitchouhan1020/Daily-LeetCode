---
tags: ["leetcode","tree","depth-first search"]
created: "04/06/2019, 11:51:03"
difficulty: "hard"
---

# [1028-recover-a-tree-from-preorder-traversal](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/)

## Problem
<div><p>We run a&nbsp;preorder&nbsp;depth first search on the <code>root</code> of a binary tree.</p><br><br><p>At each node in this traversal, we output <code>D</code> dashes (where <code>D</code> is the <em>depth</em> of this node), then we output the value of this node.&nbsp;&nbsp;<em>(If the depth of a node is <code>D</code>, the depth of its immediate child is <code>D+1</code>.&nbsp; The depth of the root node is <code>0</code>.)</em></p><br><br><p>If a node has only one child, that child is guaranteed to be the left child.</p><br><br><p>Given the output <code>S</code> of this traversal, recover the tree and return its <code>root</code>.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/04/08/recover-a-tree-from-preorder-traversal.png" style="width: 320px; height: 200px;"></strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">"1-2--3--4-5--6--7"</span><br><strong>Output: </strong><span id="example-output-1">[1,2,5,3,4,6,7]</span><br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/04/11/screen-shot-2019-04-10-at-114101-pm.png" style="width: 256px; height: 250px;"></strong></p><br><br><pre><strong>Input: </strong><span id="example-input-2-1">"1-2--3---4-5--6---7"</span><br><strong>Output: </strong><span id="example-output-2">[1,2,5,3,null,6,null,4,null,7]</span></pre><br></div><br><br><div><br><p>&nbsp;</p><br><br><div><br><p><strong>Example 3:</strong></p><br><br><p><span><img alt="" src="https://assets.leetcode.com/uploads/2019/04/11/screen-shot-2019-04-10-at-114955-pm.png" style="width: 276px; height: 250px;"></span></p><br><br><pre><strong>Input: </strong><span id="example-input-3-1">"1-401--349---90--88"</span><br><strong>Output: </strong><span id="example-output-3">[1,401,null,349,88,90]</span><br></pre><br></div><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>The number of nodes in the original tree is between <code>1</code> and <code>1000</code>.</li><br>	<li>Each node will have a value between <code>1</code> and <code>10^9</code>.</li><br></ul><br></div><br></div>

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
    int getDepth(int &idx,string s){
        int cnt = 0;
        while(idx < s.size() && s[idx]=='-'){
            idx++;
            cnt++;
        }
        return cnt;
    }
    
    int getValue(int &idx,string s){
        int value = 0;
        while(idx < s.size() && isdigit(s[idx])){
            value = value*10 + (s[idx]-'0');
            idx++;
        }
        return value;
     }
    
    TreeNode* recoverFromPreorder(string S) {
        vector<pair<int,int>> nodes;
        int idx = 0;
        
        //parse string
        while(idx < S.size()){
            int depth = getDepth(idx, S);
            int value = getValue(idx, S);
            nodes.push_back({depth,value});
        }
​
```
