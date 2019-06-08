---
tags: ["leetcode","tree","depth-first search"]
created: "05/06/2019, 10:36:53"
difficulty: "medium"
---

# [0117-populating-next-right-pointers-in-each-node-ii](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

## Problem
<div><p>Given a binary tree</p><br><br><pre>struct Node {<br>  int val;<br>  Node *left;<br>  Node *right;<br>  Node *next;<br>}<br></pre><br><br><p>Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to <code>NULL</code>.</p><br><br><p>Initially, all next pointers are set to <code>NULL</code>.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example:</strong></p><br><br><p><img alt="" src="https://assets.leetcode.com/uploads/2019/02/15/117_sample.png" style="width: 640px; height: 218px;"></p><br><br><pre><strong>Input: </strong><span>{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}</span><br><br><strong>Output: </strong><span>{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}</span><br><br><strong>Explanation: </strong>Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>You may only use constant extra space.</li><br>	<li>Recursive approach is fine, implicit stack space does not count as extra space for this problem.</li><br></ul></div>

## Solution

c++
```c++

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
​
    Node() {}
​
    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* head=NULL,*pre=NULL,*curr=root;
        
        while(curr){    //levelwise
            while(curr){ //In a level
                if(pre){
                    if(curr->left){
                        pre->next = curr->left;
                        pre = pre->next;
                    }
                    if(curr->right){
                        pre->next = curr->right;
                        pre = pre->next;
                    }                    
                }else{
                    if(curr->left && head==nullptr) head = curr->left;
                    if(curr->right && head==nullptr) head = curr->right;
                    pre = head;
                    
                    if(curr->left && curr->right){
                        pre->next = curr->right;
                        pre = pre->next;
                    }                    
                }
                curr = curr->next;
            }
            pre = NULL;
            curr = head;
            head = NULL;
        }
        return root;
    }
};
​
```
