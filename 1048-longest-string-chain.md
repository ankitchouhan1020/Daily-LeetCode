---
tags: ["leetcode","hash table","dynamic programming"]
created: "26/05/2019, 17:16:57"
difficulty: "medium"
---

# [1048-longest-string-chain](https://leetcode.com/problems/longest-string-chain/)

## Problem
<div><p>Given a list of words, each word consists of English lowercase letters.</p><br><br><p>Let's say <code>word1</code> is a predecessor of <code>word2</code>&nbsp;if and only if we can add exactly one letter anywhere in <code>word1</code> to make it equal to <code>word2</code>.&nbsp; For example,&nbsp;<code>"abc"</code>&nbsp;is a predecessor of <code>"abac"</code>.</p><br><br><p>A <em>word chain&nbsp;</em>is a sequence of words <code>[word_1, word_2, ..., word_k]</code>&nbsp;with <code>k &gt;= 1</code>,&nbsp;where <code>word_1</code> is a predecessor of <code>word_2</code>, <code>word_2</code> is a predecessor of <code>word_3</code>, and so on.</p><br><br><p>Return the longest possible length of a word chain with words chosen from the given list of <code>words</code>.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">["a","b","ba","bca","bda","bdca"]</span><br><strong>Output: </strong><span id="example-output-1">4<br><strong>Explanation</strong>: one of </span>the longest word chain is "a","ba","bda","bdca".<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= words.length &lt;= 1000</code></li><br>	<li><code>1 &lt;= words[i].length &lt;= 16</code></li><br>	<li><code>words[i]</code> only consists of English lowercase letters.</li><br></ol><br><br><div><br><p>&nbsp;</p><br></div></div>

## Solution

c++
```c++

class Solution {
    vector<int> freq;
public:
    int longestStrChain(vector<string>& words) {
        if(words.size() == 1) return 1;
        
        // Sort words in assending order of size
        sort(words.begin(),words.end(),[](string &a,string &b){return a.size() < b.size();});
        
        int n = words.size();
        
        // dp[i] represents longest chain from index i till n-1 index
        vector<int> dp(n,1);
        int maxChain = 1;
        
        // for n-1 index longest chain contains only words[n-1]
        // for every index from n-2 to 0, retrive the longest chain after it.
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(words[j].size() == words[i].size()+1){
                    
                    // If words[i] is predecessor of words[j] than chain will be incremented by 1
                    // Store max of all chains possible from words[i]
                    if(isPred(words[i],words[j])){
                        dp[i] = max(dp[i],dp[j]+1);
                    } 
                }
                
                // Difference of exactly one letter
                else if(words[j].size() > words[i].size()+1)
                    break;
            }
            
            // If chain from words[i] is longest than store it in maxChain
            maxChain = max(maxChain,dp[i]);
        }       
​
```
