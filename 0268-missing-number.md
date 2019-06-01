---
tags: ["leetcode","array","math","bit manipulation"]
created: "31/05/2019, 22:30:07"
difficulty: "easy"
---

# [0268-missing-number](https://leetcode.com/problems/missing-number/)

## Problem
<div><p>Given an array containing <i>n</i> distinct numbers taken from <code>0, 1, 2, ..., n</code>, find the one that is missing from the array.</p><br><br><p><b>Example 1:</b></p><br><br><pre><b>Input:</b> [3,0,1]<br><b>Output:</b> 2<br></pre><br><br><p><b>Example 2:</b></p><br><br><pre><b>Input:</b> [9,6,4,2,3,5,7,0,1]<br><b>Output:</b> 8<br></pre><br><br><p><b>Note</b>:<br><br>Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?</p></div>

## Solution

c++
```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        return (n*(n+1))/2 - accumulate(nums.begin(),nums.end(),0);
    }
};
// XOR with all numbers from zero to n
​
​
```
