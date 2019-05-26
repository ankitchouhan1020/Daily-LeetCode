---
tags: ["leetcode","hash table","two pointers","string","sliding window"]
created: "26/05/2019, 17:31:10"
difficulty: "hard"
---

# [0076-minimum-window-substring](https://leetcode.com/problems/minimum-window-substring/)

## Problem
<div><p>Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input: S</strong> = "ADOBECODEBANC", <strong>T</strong> = "ABC"<br><strong>Output:</strong> "BANC"<br></pre><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>If there is no such window in S that covers all characters in T, return the empty string <code>""</code>.</li><br>	<li>If there is such window, you are guaranteed that there will always be only one unique minimum window in S.</li><br></ul><br></div>

## Solution

c++
```c++
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(char ch:t) m[ch]++;
        
        int end=0,start=0,minLen = INT_MAX,head=0,counter=t.size();
        
        while(end < s.size()){           
            if(m[s[end]] > 0)   counter--;
            m[s[end]]--;
            end++;
            // If char is not in t then they will be negative
            // If they were in t, then they may be zero or 
            // If end contains higher frequency of them then they will be negative
            // While loop continue to remove redundent caracter
            while(counter==0){
                if(end-start < minLen){
                    minLen = end-start;
                    head = start;
                }
                m[s[start]]++;
                if(m[s[start]] > 0) counter++;
                start++;
            }
        }
        if(minLen == INT_MAX) return "";
        return s.substr(head,minLen);
    }
};
​
```
