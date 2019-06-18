---
tags: ["leetcode","dynamic programming"]
created: "17/06/2019, 13:51:19"
difficulty: "medium"
---

# [0712-minimum-ascii-delete-sum-for-two-strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)

## Problem
<div><p>Given two strings <code>s1, s2</code>, find the lowest ASCII sum of deleted characters to make two strings equal.</p><br><br><p><b>Example 1:</b><br><br></p><pre><b>Input:</b> s1 = "sea", s2 = "eat"<br><b>Output:</b> 231<br><b>Explanation:</b> Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.<br>Deleting "t" from "eat" adds 116 to the sum.<br>At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.<br></pre><br><p></p><br><br><p><b>Example 2:</b><br><br></p><pre><b>Input:</b> s1 = "delete", s2 = "leet"<br><b>Output:</b> 403<br><b>Explanation:</b> Deleting "dee" from "delete" to turn the string into "let",<br>adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.<br>At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.<br>If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.<br></pre><br><p></p><br><br><p><b>Note:</b><br></p><li><code>0 &lt; s1.length, s2.length &lt;= 1000</code>.</li><br><li>All elements of each string will have an ASCII value in <code>[97, 122]</code>.</li> <br><p></p></div>

## Solution

c++
```c++
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int deleteSum = maxCommanAscii(s1,s2);
        
        int totalSum = 0;
        for(char i: s1) totalSum+=int(i);
        for(char j: s2) totalSum+=int(j);
        
        return totalSum-2*deleteSum;
    }
    
    int maxCommanAscii(string w1, string w2) {
        int m = w1.size();
        int n = w2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(w1[i-1] == w2[j-1]){
                    dp[i][j] = int(w1[i-1]) + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
​
```
