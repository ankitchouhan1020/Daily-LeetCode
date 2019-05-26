---
tags: ["leetcode","array","dynamic programming"]
created: "26/05/2019, 16:47:58"
difficulty: "medium"
---

# [0152-maximum-product-subarray](https://leetcode.com/problems/maximum-product-subarray/)

## Problem
<div><p>Given an integer array&nbsp;<code>nums</code>, find the contiguous subarray within an array (containing at least one number) which has the largest product.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> [2,3,-2,4]<br><strong>Output:</strong> <code>6</code><br><strong>Explanation:</strong>&nbsp;[2,3] has the largest product 6.<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> [-2,0,-1]<br><strong>Output:</strong> 0<br><strong>Explanation:</strong>&nbsp;The result cannot be 2, because [-2,-1] is not a subarray.</pre><br></div>

## Solution

c++
```c++

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int maxSoFar = nums[0];
        int maxCurr = nums[0],minCurr = nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] < 0)
                swap(maxCurr,minCurr);
            maxCurr = max(nums[i],maxCurr*nums[i]);
            minCurr = min(nums[i],minCurr*nums[i]);
            if(maxCurr > maxSoFar) maxSoFar = maxCurr;
        }
        return maxSoFar;
    }
};
​
​
​
​
​
​
//class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         vector<int> record(nums.size());
//         vector<int> zeros(nums.size());
//         int counter = 0;
//         int zero = 0;
//         int maxProduct = 1;
        
//         /*Storing result of maxProduct of index i to index j*/
//         vector<vector<int>> memo(nums.size(),vector<int>(nums.size(),INT_MIN));
//         for(int i=0;i<nums.size();i++) memo[i][i] = nums[i];
        
​
```
