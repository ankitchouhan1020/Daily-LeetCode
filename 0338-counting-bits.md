---
tags: ["leetcode","dynamic programming","bit manipulation"]
created: "30/05/2019, 23:14:38"
difficulty: "medium"
---

# [0338-counting-bits](https://leetcode.com/problems/counting-bits/)

## Problem
<div><p>Given a non negative integer number <b>num</b>. For every numbers <b>i</b> in the range <b>0 ≤ i ≤ num</b> calculate the number of 1's in their binary representation and return them as an array.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">2</span><br><strong>Output: </strong><span id="example-output-1">[0,1,1]</span></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">5</span><br><strong>Output: </strong><code>[0,1,1,2,1,2]</code><br></pre><br><br><p><b>Follow up:</b></p><br><br><ul><br>	<li>It is very easy to come up with a solution with run time <b>O(n*sizeof(integer))</b>. But can you do it in linear time <b>O(n)</b> /possibly in a single pass?</li><br>	<li>Space complexity should be <b>O(n)</b>.</li><br>	<li>Can you do it like a boss? Do it without using any builtin function like <b>__builtin_popcount</b> in c++ or in any other language.</li><br></ul></div>

## Solution

c++
```c++
class Solution {
    
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> ans(n+1);
        ans[0] = 0;
        ans[1] = 1;
        for(int i=2;i<=n;i++){
            if(i&(i-1)) ans[i]=1+ans[i&(i-1)];
            else ans[i] = 1;
        }
        return ans;
    }
    
// n & n-1 drops the leftmost set bit
};
​
```
