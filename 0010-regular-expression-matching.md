---
tags: ["leetcode","string","dynamic programming","backtracking"]
created: "04/07/2019, 23:48:34"
difficulty: "hard"
---

# [0010-regular-expression-matching](https://leetcode.com/problems/regular-expression-matching/)

## Problem
<div><p>Given an input string (<code>s</code>) and a pattern (<code>p</code>), implement regular expression matching with support for <code>'.'</code> and <code>'*'</code>.</p><br><br><pre>'.' Matches any single character.<br>'*' Matches zero or more of the preceding element.<br></pre><br><br><p>The matching should cover the <strong>entire</strong> input string (not partial).</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li><code>s</code>&nbsp;could be empty and contains only lowercase letters <code>a-z</code>.</li><br>	<li><code>p</code> could be empty and contains only lowercase letters <code>a-z</code>, and characters like&nbsp;<code>.</code>&nbsp;or&nbsp;<code>*</code>.</li><br></ul><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong><br>s = "aa"<br>p = "a"<br><strong>Output:</strong> false<br><strong>Explanation:</strong> "a" does not match the entire string "aa".<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong><br>s = "aa"<br>p = "a*"<br><strong>Output:</strong> true<br><strong>Explanation:</strong>&nbsp;'*' means zero or more of the preceding&nbsp;element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".<br></pre><br><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input:</strong><br>s = "ab"<br>p = ".*"<br><strong>Output:</strong> true<br><strong>Explanation:</strong>&nbsp;".*" means "zero or more (*) of any character (.)".<br></pre><br><br><p><strong>Example 4:</strong></p><br><br><pre><strong>Input:</strong><br>s = "aab"<br>p = "c*a*b"<br><strong>Output:</strong> true<br><strong>Explanation:</strong>&nbsp;c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".<br></pre><br><br><p><strong>Example 5:</strong></p><br><br><pre><strong>Input:</strong><br>s = "mississippi"<br>p = "mis*is*p*."<br><strong>Output:</strong> false<br></pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    bool isMatch(string t, string p) {
        int n = t.size();
        int m = p.size();
        if(m==0) return n==0;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        dp[0][0] = rexMatcher(t,p,0,0,dp);
        return dp[0][0];
    }
    
    bool rexMatcher(string &t,string &p, int i, int j, vector<vector<int>> &dp){
        int ts = t.size();
        int ps = p.size();
        if(j == ps) return i == ts;
        
        if(i<ts && j<ps && dp[i][j] != -1) return dp[i][j];
        
        bool first_match = i<ts && (t[i]==p[j] || p[j]=='.');
        
        if(j+1 < ps && p[j+1]=='*'){
            return dp[i][j] = (
                (first_match && rexMatcher(t,p,i+1,j,dp)) || rexMatcher(t,p,i,j+2,dp)
            );
        }
        return dp[i][j] = first_match && rexMatcher(t,p,i+1,j+1,dp);
    }
};
​
```
