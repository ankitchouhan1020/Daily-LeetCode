---
tags: ["leetcode","math","binary search","dynamic programming"]
created: "02/07/2019, 17:43:16"
difficulty: "hard"
---

# [0887-super-egg-drop](https://leetcode.com/problems/super-egg-drop/)

## Problem
<div><p>You are given <code>K</code> eggs, and you have access to a building with <code>N</code> floors from <code>1</code> to <code>N</code>.&nbsp;</p><br><br><p>Each egg is identical in function, and if an egg breaks, you cannot drop it&nbsp;again.</p><br><br><p>You know that there exists a floor <code>F</code> with <code>0 &lt;= F &lt;= N</code> such that any egg dropped at a floor higher than <code>F</code> will break, and any egg dropped at or below floor <code>F</code> will not break.</p><br><br><p>Each <em>move</em>, you may take an egg (if you have an unbroken one) and drop it from any floor <code>X</code> (with&nbsp;<code>1 &lt;= X &lt;= N</code>).&nbsp;</p><br><br><p>Your goal is to know&nbsp;<strong>with certainty</strong>&nbsp;what the value of <code>F</code> is.</p><br><br><p>What is the minimum number of moves that you need to know with certainty&nbsp;what <code>F</code> is, regardless of the initial value of <code>F</code>?</p><br><br><p>&nbsp;</p><br><br><ol><br></ol><br><br><div><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>K = <span id="example-input-1-1">1</span>, N = <span id="example-input-1-2">2</span><br><strong>Output: </strong><span id="example-output-1">2</span><br><strong>Explanation: </strong><br>Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.<br>Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.<br>If it didn't break, then we know with certainty F = 2.<br>Hence, we needed 2 moves in the worst case to know what F is with certainty.<br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>K = <span id="example-input-2-1">2</span>, N = 6<br><strong>Output: </strong><span id="example-output-2">3</span><br></pre><br><br><div><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong>K = <span id="example-input-3-1">3</span>, N = <span id="example-input-3-2">14</span><br><strong>Output: </strong><span id="example-output-3">4</span><br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= K &lt;= 100</code></li><br>	<li><code>1 &lt;= N &lt;= 10000</code></li><br></ol><br></div><br></div><br></div><br></div>

## Solution

c++
```c++
//This is only intuitive solution
//It gives TLE but I can't remember math solution in 45 min interview
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N+1,0));
        
        for(int i=1;i<=N;i++)   dp[1][i]=i;
        for(int i=2;i<=K;i++)   dp[i][1]=1;
        
        for(int i=2;i<=K;i++){
            for(int j=2;j<=N;j++){
                dp[i][j] = INT_MAX;
               for(int curr_floor=1;curr_floor<=j;curr_floor++){
                   int tmp = INT_MAX;
                   tmp = max(dp[i-1][curr_floor-1],dp[i][j-curr_floor]) + 1;
                   dp[i][j] = min(tmp,dp[i][j]);
               }
            }
        }
        return dp[K][N];
    }
};
​
```
