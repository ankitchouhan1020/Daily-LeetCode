---
tags: ["leetcode","string"]
created: "06/07/2019, 00:48:10"
difficulty: "medium"
---

# [0791-custom-sort-string](https://leetcode.com/problems/custom-sort-string/)

## Problem
<div><p><code>S</code> and <code>T</code> are strings composed of lowercase letters. In <code>S</code>, no letter occurs more than once.</p><br><br><p><code>S</code> was sorted in some custom order previously. We want to permute the characters of <code>T</code> so that they match the order that <code>S</code> was sorted. More specifically, if <code>x</code> occurs before <code>y</code> in <code>S</code>, then <code>x</code> should occur before <code>y</code> in the returned string.</p><br><br><p>Return any permutation of <code>T</code> (as a string) that satisfies this property.</p><br><br><pre><strong>Example :</strong><br><strong>Input:</strong> <br>S = "cba"<br>T = "abcd"<br><strong>Output:</strong> "cbad"<br><strong>Explanation:</strong> <br>"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". <br>Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li><code>S</code> has length at most <code>26</code>, and no character is repeated in <code>S</code>.</li><br>	<li><code>T</code> has length at most <code>200</code>.</li><br>	<li><code>S</code> and <code>T</code> consist of lowercase letters only.</li><br></ul><br></div>

## Solution

c++
```c++
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> m(26,0);
        for(char ch: S) m[ch-'a'] = 1;
        
        vector<int> n(26,0);
        for(char ch: T) n[ch-'a'] += 1;
        
        string ans = "";
        for(char ch : S){
            while(n[ch-'a']-- > 0) ans.push_back(ch);
        }
        
        
        for(int i=0;i<26;i++){
            if(m[i]) n[i] = 0;
        }
        
        for(int i=0;i<26;i++){
            while(n[i] > 0){
                ans.push_back(i+'a');
                n[i]-=1;
            }
        }
        return ans;
        
    }
};
​
```
