---
tags: ["leetcode","bit manipulation"]
created: "10/06/2019, 17:39:47"
difficulty: "medium"
---

# [0137-single-number-ii](https://leetcode.com/problems/single-number-ii/)

## Problem
<div><p>Given a <strong>non-empty</strong>&nbsp;array of integers, every element appears <em>three</em> times except for one, which appears exactly once. Find that single one.</p><br><br><p><strong>Note:</strong></p><br><br><p>Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> [2,2,3,2]<br><strong>Output:</strong> 3<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> [0,1,0,1,0,1,99]<br><strong>Output:</strong> 99</pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<32;i++){
            int sum = 0;
            for(int j=0;j<nums.size();j++){
                sum += (nums[j]>>i) & 1;
            }
            if(sum%3 != 0){
                ans = ans + (1 << i);
            }
        }
        return ans;
    }
};
​
```
