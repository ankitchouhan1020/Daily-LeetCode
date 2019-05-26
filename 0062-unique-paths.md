---
tags: ["leetcode","array","dynamic programming"]
created: "26/05/2019, 16:31:52"
difficulty: "medium"
---

# [0062-unique-paths](https://leetcode.com/problems/unique-paths/)

## Problem
<div><p>A robot is located at the top-left corner of a <em>m</em> x <em>n</em> grid (marked 'Start' in the diagram below).</p><br><br><p>The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).</p><br><br><p>How many possible unique paths are there?</p><br><br><p><img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" style="width: 400px; height: 183px;"><br><br><small>Above is a 7 x 3 grid. How many possible unique paths are there?</small></p><br><br><p><strong>Note:</strong> <em>m</em> and <em>n</em> will be at most 100.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> m = 3, n = 2<br><strong>Output:</strong> 3<br><strong>Explanation:</strong><br>From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:<br>1. Right -&gt; Right -&gt; Down<br>2. Right -&gt; Down -&gt; Right<br>3. Down -&gt; Right -&gt; Right<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> m = 7, n = 3<br><strong>Output:</strong> 28</pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n==0) return 0;
        if(m == 1 || n==1) return 1;
        vector<int> dp(n,1);
        int upper = 1;
        for(int i=1; i<m; i++){
            for(int j=n-2; j>=0; j--){
                dp[j] = dp[j]+dp[j+1];
            }
        }
        return dp[0];
    }
};
​
```
