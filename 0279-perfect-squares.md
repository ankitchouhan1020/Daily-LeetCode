---
tags: ["leetcode","math","dynamic programming","breadth-first search"]
created: "26/05/2019, 16:51:52"
difficulty: "medium"
---

# [0279-perfect-squares](https://leetcode.com/problems/perfect-squares/)

## Problem
<div><p>Given a positive integer <i>n</i>, find the least number of perfect square numbers (for example, <code>1, 4, 9, 16, ...</code>) which sum to <i>n</i>.</p><br><br><p><b>Example 1:</b></p><br><br><pre><b>Input:</b> <i>n</i> = <code>12</code><br><b>Output:</b> 3 <br><strong>Explanation: </strong><code>12 = 4 + 4 + 4.</code></pre><br><br><p><b>Example 2:</b></p><br><br><pre><b>Input:</b> <i>n</i> = <code>13</code><br><b>Output:</b> 2<br><strong>Explanation: </strong><code>13 = 4 + 9.</code></pre></div>

## Solution

c++
```c++
class Solution {
public:
    int numSquares(int n) {
        vector<int> data(n+1,INT_MAX);
        data[0] = 0;
        
        // Path to reach till numbers via minimum perfect squares
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                data[i] = min(data[i-j*j]+1,data[i]);
            }
        }
        //for(int i=0;i<n;i++) cout<<data[i]<< " ";
        return data[n];
    }
};
​
```
