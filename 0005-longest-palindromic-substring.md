---
tags: ["leetcode","string","dynamic programming"]
created: "11/06/2019, 12:09:08"
difficulty: "medium"
---

# [0005-longest-palindromic-substring](https://leetcode.com/problems/longest-palindromic-substring/)

## Problem
<div><p>Given a string <strong>s</strong>, find the longest palindromic substring in <strong>s</strong>. You may assume that the maximum length of <strong>s</strong> is 1000.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> "babad"<br><strong>Output:</strong> "bab"<br><strong>Note:</strong> "aba" is also a valid answer.<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> "cbbd"<br><strong>Output:</strong> "bb"<br></pre><br></div>

## Solution

c++
```c++
// Tried and failed with TopDown Once
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1 || n==0) return s;
        int start=0,maxLen=0;
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<3 || dp[i+1][j-1])){
                   dp[i][j] = true;
                   if(j-i+1 > maxLen){
                       maxLen = j-i+1;
                       start = i;
                   }
                }
            }
        }
        
        return s.substr(start,maxLen);
    }
};
​
```
