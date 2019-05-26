---
tags: ["leetcode","string"]
created: "26/05/2019, 17:15:56"
difficulty: "medium"
---

# [0833-find-and-replace-in-string](https://leetcode.com/problems/find-and-replace-in-string/)

## Problem
<div><p>To some string <code>S</code>, we will perform some&nbsp;replacement&nbsp;operations that replace groups of letters with new ones (not necessarily the same size).</p><br><br><p>Each replacement operation has <code>3</code> parameters: a starting index <code>i</code>, a source word&nbsp;<code>x</code>&nbsp;and a target word&nbsp;<code>y</code>.&nbsp; The rule is that if <code><font face="monospace">x</font></code>&nbsp;starts at position <code>i</code>&nbsp;in the <strong>original</strong> <strong>string</strong> <strong><code>S</code></strong>, then we will replace that occurrence of&nbsp;<code>x</code>&nbsp;with&nbsp;<code>y</code>.&nbsp; If not, we do nothing.</p><br><br><p>For example, if we have&nbsp;<code>S = "abcd"</code>&nbsp;and we have some replacement operation&nbsp;<code>i = 2, x = "cd", y = "ffff"</code>, then because&nbsp;<code>"cd"</code>&nbsp;starts at position <code><font face="monospace">2</font></code>&nbsp;in the original string <code>S</code>, we will replace it with <code>"ffff"</code>.</p><br><br><p>Using another example on <code>S = "abcd"</code>, if we have both the replacement operation <code>i = 0, x = "ab", y = "eee"</code>, as well as another replacement operation&nbsp;<code>i = 2, x = "ec", y = "ffff"</code>, this second operation does nothing because in the original string&nbsp;<code>S[2] = 'c'</code>, which doesn't match&nbsp;<code>x[0] = 'e'</code>.</p><br><br><p>All these operations occur simultaneously.&nbsp; It's guaranteed that there won't be any overlap in replacement: for example,&nbsp;<code>S = "abc", indexes = [0, 1],&nbsp;sources = ["ab","bc"]</code> is not a valid test case.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]<br><strong>Output: </strong>"eeebffff"<br><strong>Explanation:</strong> "a" starts at index 0 in S, so it's replaced by "eee".<br>"cd" starts at index 2 in S, so it's replaced by "ffff".<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]<br><strong>Output: </strong>"eeecd"<br><strong>Explanation:</strong> "ab" starts at index 0 in S, so it's replaced by "eee". <br>"ec" doesn't starts at index 2 in the <strong>original</strong> S, so we do nothing.<br></pre><br><br><p>Notes:</p><br><br><ol><br>	<li><code>0 &lt;=&nbsp;indexes.length =&nbsp;sources.length =&nbsp;targets.length &lt;= 100</code></li><br>	<li><code>0&nbsp;&lt;&nbsp;indexes[i]&nbsp;&lt; S.length &lt;= 1000</code></li><br>	<li>All characters in given inputs are lowercase letters.</li><br></ol><br><br><p>&nbsp;</p><br></div>

## Solution

c++
```c++
class Solution {
    struct sortinrev{
        bool operator()(const pair<int,int> &a,const pair<int,int> &b) 
            { 
                   return (a.first > b.first); 
            }
    };
​
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<int> valid(indexes.size(),0);
        vector<pair<int,int>> p;
        
        for(int i=0;i<indexes.size();i++){
            if(S.find(sources[i],indexes[i]) == indexes[i]){
                valid[i]=1;
            }
        }
        
        for(int i=0;i<indexes.size();i++) p.push_back({indexes[i],i});
        
        sort(p.begin(),p.end(),sortinrev());
        
        for(int i=0;i<p.size();i++){
            
            if(valid[p[i].second]){
                int idx = p[i].second;
                S.replace(p[i].first,sources[idx].size(),targets[idx]);
            }
            
        }
        return S;
    }
};
​
```
