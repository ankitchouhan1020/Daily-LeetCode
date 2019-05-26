---
tags: ["leetcode","linked list","depth-first search"]
created: "26/05/2019, 17:04:44"
difficulty: "medium"
---

# [0430-flatten-a-multilevel-doubly-linked-list](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)

## Problem
<div><p>You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.</p><br><br><p>Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong><br> 1---2---3---4---5---6--NULL<br>         |<br>         7---8---9---10--NULL<br>             |<br>             11--12--NULL<br><br><strong>Output:</strong><br>1-2-3-7-8-11-12-9-10-4-5-6-NULL<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Explanation for the above example:</strong></p><br><br><p>Given the following multilevel doubly linked list:</p><br><br><pre><img src="https://assets.leetcode.com/uploads/2018/10/12/multilevellinkedlist.png" style="width: 640px;"></pre><br><br><p>&nbsp;</p><br><br><p>We should return the following flattened doubly linked list:</p><br><br><pre><img src="https://assets.leetcode.com/uploads/2018/10/12/multilevellinkedlistflattened.png" style="width: 1100px;"></pre><br></div>

## Solution

c++
```c++

/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
​
    Node() {}
​
    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* p = head;
        while(p){
            if(p->child){
                mergeChild(p,p->child,p->next);
                Node* tmp = p->next;
                p->next = p->child;
                p->child = NULL;
                p = tmp;
​
```
