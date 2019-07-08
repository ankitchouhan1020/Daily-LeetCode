---
tags: ["leetcode","string"]
created: "08/07/2019, 13:32:51"
difficulty: "medium"
---

# [1016-binary-string-with-substrings-representing-1-to-n](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/)

## Problem
<div><p>Given a binary string <code>S</code> (a string consisting only of '0' and '1's) and a positive integer <code>N</code>, return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>S = <span id="example-input-1-1">"0110"</span>, N = <span id="example-input-1-2">3</span><br><strong>Output: </strong><span id="example-output-1">true</span><br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>S = <span id="example-input-2-1">"0110"</span>, N = <span id="example-input-2-2">4</span><br><strong>Output: </strong><span id="example-output-2">false</span><br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= S.length &lt;= 1000</code></li><br>	<li><code>1 &lt;= N &lt;= 10^9</code></li><br></ol><br></div>

## Solution

c++
```c++
// Run from last untill you can not find sunstring
// Optimization : loop till N/2 since before from 1 -> N/2 will exist if N -> N/2 exists.
#define M 1000
class Solution {
public:
    bool queryString(string S, int N) {
        
        while(N>0){
            bitset<M> b2(N);
            string tmp  = b2.to_string();
            int pos = tmp.find("1");
            tmp = tmp.substr(pos);
            
            if(S.find(tmp) == -1)
                return false;
            
            N--;
        }
        return true;
    }
};
​
```
