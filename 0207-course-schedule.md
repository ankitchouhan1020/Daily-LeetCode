---
tags: ["leetcode","depth-first search","breadth-first search","graph","topological sort"]
created: "29/05/2019, 23:32:12"
difficulty: "medium"
---

# [0207-course-schedule](https://leetcode.com/problems/course-schedule/)

## Problem
<div><p>There are a total of <i>n</i> courses you have to take, labeled from <code>0</code> to <code>n-1</code>.</p><br><br><p>Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: <code>[0,1]</code></p><br><br><p>Given the total number of courses and a list of prerequisite <b>pairs</b>, is it possible for you to finish all courses?</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> 2, [[1,0]] <br><strong>Output: </strong>true<br><strong>Explanation:</strong>&nbsp;There are a total of 2 courses to take. <br>&nbsp;            To take course 1 you should have finished course 0. So it is possible.</pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> 2, [[1,0],[0,1]]<br><strong>Output: </strong>false<br><strong>Explanation:</strong>&nbsp;There are a total of 2 courses to take. <br>&nbsp;            To take course 1 you should have finished course 0, and to take course 0 you should<br>&nbsp;            also have finished course 1. So it is impossible.<br></pre><br><br><p><b>Note:</b></p><br><br><ol><br>	<li>The input prerequisites is a graph represented by <b>a list of edges</b>, not adjacency matrices. Read more about <a href="https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs" target="_blank">how a graph is represented</a>.</li><br>	<li>You may assume that there are no duplicate edges in the input prerequisites.</li><br></ol><br></div>

## Solution

c++
```c++
class Solution {
    // -1 not visited, 0 visited, 1 in topological list
    // Cycle can be detected if you visited an already visited node but it is not in topological list
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> visited(n,-1);        
        
        vector<vector<int>> G(n);
        for(auto node : pre){
            G[node[0]].push_back(node[1]);
        }
​
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(!noCycle(visited,G,i)) return false;
            }
        }
        return true;
    }
    
    bool noCycle(vector<int>&visited,vector<vector<int>>&G,int root){
        if(visited[root] == 0) return false;
        if(visited[root] == 1) return true;
        visited[root] = 0;
        for(int i: G[root]){
            if(!noCycle(visited,G,i)) return false;
        }
        visited[root] = 1;
        return true;
    }
};
​
```
