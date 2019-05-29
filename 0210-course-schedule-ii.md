---
tags: ["leetcode","depth-first search","breadth-first search","graph","topological sort"]
created: "29/05/2019, 23:44:46"
difficulty: "medium"
---

# [0210-course-schedule-ii](https://leetcode.com/problems/course-schedule-ii/)

## Problem
<div><p>There are a total of <em>n</em> courses you have to take, labeled from <code>0</code> to <code>n-1</code>.</p><br><br><p>Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: <code>[0,1]</code></p><br><br><p>Given the total number of courses and a list of prerequisite <strong>pairs</strong>, return the ordering of courses you should take to finish all courses.</p><br><br><p>There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> 2, [[1,0]] <br><strong>Output: </strong><code>[0,1]</code><br><strong>Explanation:</strong>&nbsp;There are a total of 2 courses to take. To take course 1 you should have finished   <br>&nbsp;            course 0. So the correct course order is <code>[0,1] .</code></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> 4, [[1,0],[2,0],[3,1],[3,2]]<br><strong>Output: </strong><code>[0,1,2,3] or [0,2,1,3]</code><br><strong>Explanation:</strong>&nbsp;There are a total of 4 courses to take. To take course 3 you should have finished both     <br>             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. <br>&nbsp;            So one correct course order is <code>[0,1,2,3]</code>. Another correct ordering is <code>[0,2,1,3] .</code></pre><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li>The input prerequisites is a graph represented by <strong>a list of edges</strong>, not adjacency matrices. Read more about <a href="https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs" target="_blank">how a graph is represented</a>.</li><br>	<li>You may assume that there are no duplicate edges in the input prerequisites.</li><br></ol><br></div>

## Solution

c++
```c++
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> visited(n,-1);        
        vector<int> order;
        vector<vector<int>> G(n);
        for(auto node : pre){
            G[node[0]].push_back(node[1]);
        }
​
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(!noCycle(visited,order,G,i)) return vector<int>();
            }
        }
​
        return order;
    }
    
    bool noCycle(vector<int>&visited,vector<int>&order,vector<vector<int>>&G,int root){
        if(visited[root] == 0) return false;
        if(visited[root] == 1) return true;
        visited[root] = 0;
        for(int i: G[root]){
            if(!noCycle(visited,order,G,i)) return false;
        }
        visited[root] = 1;
        order.push_back(root);
        return true;
    }
};
​
    // -1 not visited, 0 visited, 1 in topological list
    // Cycle can be detected if you visited an already visited node but it is not in topological list
​
​
```
