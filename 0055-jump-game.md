---
tags: ["leetcode","array","greedy"]
created: "26/05/2019, 16:30:52"
difficulty: "medium"
---

# [0055-jump-game](https://leetcode.com/problems/jump-game/)

## Problem
<div><p>Given an array of non-negative integers, you are initially positioned at the first index of the array.</p><br><br><p>Each element in the array represents your maximum jump length at that position.</p><br><br><p>Determine if you are able to reach the last index.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> [2,3,1,1,4]<br><strong>Output:</strong> true<br><strong>Explanation:</strong> Jump 1 step from index 0 to 1, then 3 steps to the last index.<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> [3,2,1,0,4]<br><strong>Output:</strong> false<br><strong>Explanation:</strong> You will always arrive at index 3 no matter what. Its maximum<br>&nbsp;            jump length is 0, which makes it impossible to reach the last index.<br></pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int targetIndex= n-1;
        
        for(int i=n-2;i>=0;i--){
            // If it is possible to jump from current index(i) to targetIndex
            // than we only need to reach till current index
            if(nums[i] >= targetIndex-i) targetIndex = i;            
        }
        return targetIndex == 0;
    }
};
​
```
