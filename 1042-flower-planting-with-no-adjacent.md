---
tags: ["leetcode","graph"]
created: "28/06/2019, 16:12:00"
difficulty: "easy"
---

# [1042-flower-planting-with-no-adjacent](https://leetcode.com/problems/flower-planting-with-no-adjacent/)

## Problem
<div><p>You have <code>N</code> gardens, labelled <code>1</code> to <code>N</code>.&nbsp; In each garden, you want to plant one of 4 types of flowers.</p><br><br><p><code>paths[i] = [x, y]</code> describes the existence of a bidirectional path from garden <code>x</code> to garden <code>y</code>.</p><br><br><p>Also, there is no garden that has more than 3 paths coming into or leaving it.</p><br><br><p>Your task is to choose a flower type for each garden such that,&nbsp;for any two gardens connected by a path, they have different types of flowers.</p><br><br><p>Return <strong>any</strong> such a choice as an array <code>answer</code>, where&nbsp;<code>answer[i]</code> is the type of flower&nbsp;planted in the <code>(i+1)</code>-th garden.&nbsp; The flower types are denoted&nbsp;<font face="monospace">1</font>, <font face="monospace">2</font>, <font face="monospace">3</font>, or <font face="monospace">4</font>.&nbsp; It is guaranteed an answer exists.</p><br><br><p>&nbsp;</p><br><br><div><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>N = <span id="example-input-1-1">3</span>, paths = <span id="example-input-1-2">[[1,2],[2,3],[3,1]]</span><br><strong>Output: </strong><span id="example-output-1">[1,2,3]</span><br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>N = <span id="example-input-2-1">4</span>, paths = <span id="example-input-2-2">[[1,2],[3,4]]</span><br><strong>Output: </strong><span id="example-output-2">[1,2,1,2]</span><br></pre><br><br><div><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong>N = <span id="example-input-3-1">4</span>, paths = <span id="example-input-3-2">[[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]</span><br><strong>Output: </strong><span id="example-output-3">[1,2,3,4]</span><br></pre><br><br><p>&nbsp;</p><br><br><p><strong><span>Note:</span></strong></p><br><br><ul><br>	<li><code><span>1 &lt;= N &lt;= 10000</span></code></li><br>	<li><code><span>0 &lt;= paths.size &lt;= 20000</span></code></li><br>	<li>No garden has 4 or more paths coming into or leaving it.</li><br>	<li>It is guaranteed an answer exists.</li><br></ul><br></div><br></div><br></div></div>

## Solution

c++
```c++
//  Suddenly it became obious
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> arr(N,0);
        vector<vector<int>> list(N,vector<int>());
        for(auto path: paths){
            int u = path[0];
            int v = path[1];
            list[u-1].push_back(v-1);
            list[v-1].push_back(u-1);
        }
        
        for(int i=0;i<N;i++){
            vector<int> used(5,0);
            for(int j: list[i]) used[arr[j]] = 1;
            for(int k=1;k<=4;k++){
                if(!used[k]){
                    arr[i] = k; break;
                }
            }
        }
        return arr;
    }
    
};
​
```
