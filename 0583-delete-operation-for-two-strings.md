---
tags: ["leetcode","string"]
created: "26/05/2019, 17:10:35"
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
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        if(n==0 || m==0) return max(n,m);
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int LCS = comSequence(word1,word2,dp,n-1,m-1);
        return n+m-2*LCS;
    }
    
    int comSequence(string word1, string word2,vector<vector<int>>&dp,int last1,int last2){
        if(last1 < 0 || last2 < 0) return 0;
        if(dp[last1][last2] > -1) return dp[last1][last2]; 
        
        if(word1[last1] == word2[last2]){
         dp[last1][last2] = 1 + comSequence(word1,word2,dp,last1-1,last2-1);
        }else{
         dp[last1][last2]  = max(comSequence(word1,word2,dp,last1-1,last2),comSequence(word1,word2,dp,last1,last2-1));
        }
        return dp[last1][last2];      
    }
};
​
```
