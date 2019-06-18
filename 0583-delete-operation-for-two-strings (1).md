---
tags: ["leetcode","string"]
created: "17/06/2019, 13:21:11"
difficulty: "medium"
---

# [0583-delete-operation-for-two-strings](https://leetcode.com/problems/delete-operation-for-two-strings/)

## Problem
<div><p><br>Given two words <i>word1</i> and <i>word2</i>, find the minimum number of steps required to make <i>word1</i> and <i>word2</i> the same, where in each step you can delete one character in either string.<br></p><br><br><p><b>Example 1:</b><br><br></p><pre><b>Input:</b> "sea", "eat"<br><b>Output:</b> 2<br><b>Explanation:</b> You need one step to make "sea" to "ea" and another step to make "eat" to "ea".<br></pre><br><p></p><br><br><p><b>Note:</b><br><br></p><ol><br><li>The length of given words won't exceed 500.</li><br><li>Characters in given words can only be lower-case letters.</li><br></ol><br><p></p></div>

## Solution

c++
```c++
class Solution {
public:
    int minDistance(string w1, string w2) {
        int m = w1.size();
        int n = w2.size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(w1[i-1] == w2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n+m-2*dp[m][n];
    }
};
​
```
