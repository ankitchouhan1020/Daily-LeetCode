---
tags: ["leetcode","dynamic programming"]
created: "26/05/2019, 16:41:48"
difficulty: "medium"
---

# [0139-word-break](https://leetcode.com/problems/word-break/)

## Problem
<div><p>Given a <strong>non-empty</strong> string <em>s</em> and a dictionary <em>wordDict</em> containing a list of <strong>non-empty</strong> words, determine if <em>s</em> can be segmented into a space-separated sequence of one or more dictionary words.</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>The same word in the dictionary may be reused multiple times in the segmentation.</li><br>	<li>You may assume the dictionary does not contain duplicate words.</li><br></ul><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> s = "leetcode", wordDict = ["leet", "code"]<br><strong>Output:</strong> true<br><strong>Explanation:</strong> Return true because <code>"leetcode"</code> can be segmented as <code>"leet code"</code>.<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> s = "applepenapple", wordDict = ["apple", "pen"]<br><strong>Output:</strong> true<br><strong>Explanation:</strong> Return true because <code>"</code>applepenapple<code>"</code> can be segmented as <code>"</code>apple pen apple<code>"</code>.<br>&nbsp;            Note that you are allowed to reuse a dictionary word.<br></pre><br><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input:</strong> s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]<br><strong>Output:</strong> false<br></pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> table(s.size(),-1);
        if(isSegmented(s,wordDict,table,0)) return true;
        return false;
    }
    
};
​

int isSegmented(string s,vector<string> & wordDict,vector<int> & table,int start){
        if(start == s.size()) return true;
        if(start > s.size()) return false;
        if(table[start] != -1) return table[start];
        int tempRes;
        for(int i=0;i<wordDict.size();i++){
            int lenS = s.size() - start;
            if(lenS >= wordDict[i].size()){
                if(s.substr(start,wordDict[i].size()) == wordDict[i]){
                    tempRes = isSegmented(s,wordDict,table,start+wordDict[i].size());
                    if(tempRes == 1){
                        return table[start] = 1;
                    }
                }
            }
            
        }
        return table[start] = 0;
    }
​
```
