---
tags: ["leetcode","heap","depth-first search","breadth-first search","graph"]
created: "28/06/2019, 16:45:28"
difficulty: "medium"
---

# [0743-network-delay-time](https://leetcode.com/problems/network-delay-time/)

## Problem
<div><p>There are <code>N</code> network nodes, labelled <code>1</code> to <code>N</code>.</p><br><br><p>Given <code>times</code>, a list of travel times as <b>directed</b> edges <code>times[i] = (u, v, w)</code>, where <code>u</code> is the source node, <code>v</code> is the target node, and <code>w</code> is the time it takes for a signal to travel from source to target.</p><br><br><p>Now, we send a signal from a certain node <code>K</code>. How long will it take for all nodes to receive the signal? If it is impossible, return <code>-1</code>.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><p><img alt="" src="https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png" style="width: 200px; height: 220px;"></p><br><br><pre><strong>Input: </strong>times = <span id="example-input-1-1">[[2,1,1],[2,3,1],[3,4,1]]</span>, N = <span id="example-input-1-2">4</span>, K = <span id="example-input-1-3">2</span><br><strong>Output: </strong><span id="example-output-1">2</span><br></pre><br><br><p>&nbsp;</p><br><br><p><b>Note:</b></p><br><br><ol><br>	<li><code>N</code> will be in the range <code>[1, 100]</code>.</li><br>	<li><code>K</code> will be in the range <code>[1, N]</code>.</li><br>	<li>The length of <code>times</code> will be in the range <code>[1, 6000]</code>.</li><br>	<li>All edges <code>times[i] = (u, v, w)</code> will have <code>1 &lt;= u, v &lt;= N</code> and <code>0 &lt;= w &lt;= 100</code>.</li><br></ol><br></div>

## Solution

c++
```c++
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>> list(N,vector<pair<int,int>>());
        for(auto time: times){
            list[time[0]-1].push_back({time[1]-1,time[2]});
        }
        
        // vector<bool> vis(N,false);
        vector<int> ans(N,INT_MAX);
        queue<int> todo;
        K--;
        todo.push(K);
        ans[K] = 0;
​
        while(!todo.empty()){
            int idx = todo.front(); todo.pop();
            
            for(auto j: list[idx]){
                int v = j.first;
                int w = j.second;
                int old = ans[v];
                
                if(w + ans[idx] < old){
                    ans[v] = w + ans[idx];
                    todo.push(v);
                }
            }
        }
        auto it = max_element(ans.begin(),ans.end());
        return *it==INT_MAX ? -1 : *it;
    }
};
​
```
