---
tags: ["leetcode","hash table","two pointers","string","sliding window"]
created: "26/05/2019, 16:13:16"
difficulty: "medium"
---

# [0003-longest-substring-without-repeating-characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Problem
<div><p>Given a string, find the length of the <b>longest substring</b> without repeating characters.</p><br><br><div><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">"abcabcbb"</span><br><strong>Output: </strong><span id="example-output-1">3 <br><strong>Explanation:</strong></span> The answer is <code>"abc"</code>, with the length of 3. <br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-2-1">"bbbbb"</span><br><strong>Output: </strong><span id="example-output-2">1<br></span><span id="example-output-1"><strong>Explanation: </strong>T</span>he answer is <code>"b"</code>, with the length of 1.<br></pre><br><br><div><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-3-1">"pwwkew"</span><br><strong>Output: </strong><span id="example-output-3">3<br></span><span id="example-output-1"><strong>Explanation: </strong></span>The answer is <code>"wke"</code>, with the length of 3. <br>             Note that the answer must be a <b>substring</b>, <code>"pwke"</code> is a <i>subsequence</i> and not a substring.<br></pre><br></div><br></div><br></div><br></div>

## Solution

c++
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        unordered_map<char,int> hash;
        // Sliding window Concept
        int i=0,j=1;
        int maxsofar = 1;
        hash[s[0]] = 0;
        
        while(j < s.size()){
            if(i == j){
                hash[s[j]] = j;
                j++;
            }
            else if(hash.find(s[j]) == hash.end()){
                hash[s[j]] = j; j++;
            }else{
                int temp = i;
                i = hash[s[j]] + 1;
                while(temp < i) hash.erase(hash.find(s[temp++]));
            }
            if(maxsofar < j-i) maxsofar = j-i;
            
        }
       return maxsofar; 
    }
};
​
```
