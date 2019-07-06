---
tags: ["leetcode","string"]
created: "06/07/2019, 15:25:10"
difficulty: "medium"
---

# [1081-smallest-subsequence-of-distinct-characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)

## Problem
<div><p>Return the lexicographically smallest subsequence of <code>text</code> that contains all the distinct characters of <code>text</code> exactly once.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">"cdadabcc"</span><br><strong>Output: </strong><span id="example-output-1">"adbc"</span><br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-2-1">"abcd"</span><br><strong>Output: </strong><span id="example-output-2">"abcd"</span><br></pre><br><br><div><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-3-1">"ecbacba"</span><br><strong>Output: </strong><span id="example-output-3">"eacb"</span><br></pre><br><br><div><br><p><strong>Example 4:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-4-1">"leetcode"</span><br><strong>Output: </strong><span id="example-output-4">"letcod"</span><br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= text.length &lt;= 1000</code></li><br>	<li><code>text</code> consists of lowercase English letters.</li><br></ol><br><br><p>&nbsp;</p><br></div><br></div><br></div></div>

## Solution

c++
```c++
class Solution {
   
public:
    string smallestSubsequence(string text) {
        if(text.empty()) return text;
        string result = "";
        vector<int> count(26,0);
        for(char ch: text){
            count[ch-'a']++;
        }
        
        vector<bool> used(26,false);
        for(char ch: text){
            if(used[ch - 'a']){
                count[ch - 'a']--;
                continue;
            }
            
            while(!result.empty() && ch < result.back() && count[result.back() - 'a']){
                used[result.back()-'a'] = false;
                result.pop_back();
            }
            
            result.push_back(ch);
            used[ch - 'a'] = true;
            count[ch - 'a']--;
        }
        return result;
    }
};
​
```
