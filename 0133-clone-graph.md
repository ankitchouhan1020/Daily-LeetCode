---
tags: ["leetcode","depth-first search","breadth-first search","graph"]
created: "29/05/2019, 21:34:47"
difficulty: "medium"
---

# [0133-clone-graph](https://leetcode.com/problems/clone-graph/)

## Problem
<div><p>Given&nbsp;a reference of a node in a&nbsp;<strong><a href="https://en.wikipedia.org/wiki/Connectivity_(graph_theory)#Connected_graph" target="_blank">connected</a></strong>&nbsp;undirected graph, return a <a href="https://en.wikipedia.org/wiki/Object_copying#Deep_copy" target="_blank"><strong>deep copy</strong></a> (clone) of the graph. Each node in the graph contains a val (<code>int</code>) and a list (<code>List[Node]</code>) of its neighbors.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example:</strong></p><br><br><p><img alt="" src="https://assets.leetcode.com/uploads/2019/02/19/113_sample.png" style="width: 200px; height: 149px;"></p><br><br><pre><strong>Input:<br></strong>{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}<br><br><strong>Explanation:</strong><br>Node 1's value is 1, and it has two neighbors: Node 2 and 4.<br>Node 2's value is 2, and it has two neighbors: Node 1 and 3.<br>Node 3's value is 3, and it has two neighbors: Node 2 and 4.<br>Node 4's value is 4, and it has two neighbors: Node 1 and 3.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li>The number of nodes will be between 1 and 100.</li><br>	<li>The undirected&nbsp;graph is a <a href="https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)#Simple_graph" target="_blank">simple graph</a>,&nbsp;which means no repeated edges and no self-loops in the graph.</li><br>	<li>Since the graph is undirected, if node <em>p</em>&nbsp;has node <em>q</em>&nbsp;as&nbsp;neighbor, then node <em>q</em>&nbsp;must have node <em>p</em>&nbsp;as neighbor too.</li><br>	<li>You must return the <strong>copy of the given node</strong> as a reference to the cloned graph.</li><br></ol><br></div>

## Solution

c++
```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
​
    Node() {}
​
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution{
    unordered_map<Node*,Node*> m;
public:
    Node* cloneGraph(Node* node) {
        Node* root = new Node(node->val);
        m[node] = root;
        
        for(auto n: node->neighbors){
            if(m.count(n) == 0)
                root->neighbors.push_back(cloneGraph(n));
            else
                root->neighbors.push_back(m[n]);
        }
        
        return root;
    }
};
​
```
