---
tags: ["leetcode","string","dynamic programming"]
created: "26/05/2019, 16:35:54"
difficulty: "medium"
---

# [0091-decode-ways](https://leetcode.com/problems/decode-ways/)

## Problem
<div><p>A message containing letters from <code>A-Z</code> is being encoded to numbers using the following mapping:</p><br><br><pre>'A' -&gt; 1<br>'B' -&gt; 2<br>...<br>'Z' -&gt; 26<br></pre><br><br><p>Given a <strong>non-empty</strong> string containing only digits, determine the total number of ways to decode it.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> "12"<br><strong>Output:</strong> 2<br><strong>Explanation:</strong>&nbsp;It could be decoded as "AB" (1 2) or "L" (12).<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> "226"<br><strong>Output:</strong> 3<br><strong>Explanation:</strong>&nbsp;It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).</pre><br></div>

## Solution

c++
```c++

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        // If "0" is string then no way to decode.
        if(n == 0 || s[0]=='0') return 0;
        if(n == 1) return 1;
        
        // dp[i] represents how many way to decode string fron that index till last index.
        vector<int> dp(n);
        
        // Initialize dp[n-1] and dp[n-2] rest is easy.
        // Before zero must be clubbed with either 1 or 2. Like 10 or 20.
        // So dp[i] = 0 where zero is at i. You may think like no existance of single zero
        // Other than 1 and 2 then write 0 at dp[i] since wrong encoded string given.
        
        if(s[n-1] == '0')dp[n-1] = 0;
        else dp[n-1] = 1;
        
        // If 1 or 2 and next is zero. Than only one way.
        if((s[n-2] == '1' || s[n-2] == '2') && s[n-1] == '0') dp[n-2] = 1;
        
        // Invalid encoded string case
        else if(s[n-1] == '0' || s[n-2]=='0') dp[n-2] = 0;
        
        // valid number case. 10 -> 26 two possible way
        else if(s[n-2]=='1' || (s[n-2]=='2' && s[n-1]<='6')) dp[n-2] = 2;
        
        // 3->9 digit case
        else dp[n-2] = 1;
        
        
        for(int i=n-3; i>=0; i--){
            
            // If zero incounters leave it now.
​
```
