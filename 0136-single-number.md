---
tags: ["leetcode","hash table","bit manipulation"]
created: "10/06/2019, 13:24:07"
difficulty: "easy"
---

# [0136-single-number](https://leetcode.com/problems/single-number/)

## Problem
<div><p>Given a <strong>non-empty</strong>&nbsp;array of integers, every element appears <em>twice</em> except for one. Find that single one.</p><br><br><p><strong>Note:</strong></p><br><br><p>Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> [2,2,1]<br><strong>Output:</strong> 1<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> [4,1,2,1,2]<br><strong>Output:</strong> 4<br></pre><br></div>

## Solution

c++
```c++
static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
​
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i:nums){
            ans^=i;
        }
        return ans;
    }
};
​
```
