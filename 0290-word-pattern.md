---
tags: ["leetcode","hash table"]
created: "26/06/2019, 19:41:14"
difficulty: "easy"
---

# [0290-word-pattern](https://leetcode.com/problems/word-pattern/)

## Problem
<div><p>Given a <code>pattern</code> and a string <code>str</code>, find if <code>str</code> follows the same pattern.</p><br><br><p>Here <b>follow</b> means a full match, such that there is a bijection between a letter in <code>pattern</code> and a <b>non-empty</b> word in <code>str</code>.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> pattern = <code>"abba"</code>, str = <code>"dog cat cat dog"</code><br><strong>Output:</strong> true</pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong>pattern = <code>"abba"</code>, str = <code>"dog cat cat fish"</code><br><strong>Output:</strong> false</pre><br><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input:</strong> pattern = <code>"aaaa"</code>, str = <code>"dog cat cat dog"</code><br><strong>Output:</strong> false</pre><br><br><p><strong>Example 4:</strong></p><br><br><pre><strong>Input:</strong> pattern = <code>"abba"</code>, str = <code>"dog dog dog dog"</code><br><strong>Output:</strong> false</pre><br><br><p><b>Notes:</b><br><br>You may assume <code>pattern</code> contains only lowercase letters, and <code>str</code> contains lowercase letters that may be separated by a single space.</p><br></div>

## Solution

c++
```c++
/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        vector<string> tokens;
        string token;
        while(getline(ss, token, ' ')){
            tokens.push_back(token);
        }
        
        if(tokens.size() != pattern.size()) return false;
        unordered_map<string,string> mp;
        int i=0;int flag=0;
        
        for(string word: tokens){
            string p = to_string(pattern[i++]);
            if(mp.count(word) == 0 && mp.count(p)==0){
                mp[word] = p;
                mp[p] = word;
            }else if(mp[word]==p && mp[p]==word){
                continue;
            }else {
            flag = 1;
                break;
            }
        }
        if(flag) return false;
        return true;
    }
};
​
​
​
```
