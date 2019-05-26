---
tags: ["leetcode","dynamic programming"]
created: "26/05/2019, 17:03:44"
difficulty: "medium"
---

# [0416-partition-equal-subset-sum](https://leetcode.com/problems/partition-equal-subset-sum/)

## Problem
<div><p>Given a <b>non-empty</b> array containing <b>only positive integers</b>, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.</p><br><br><p><b>Note:</b></p><br><br><ol><br>	<li>Each of the array element will not exceed 100.</li><br>	<li>The array size will not exceed 200.</li><br></ol><br><br><p>&nbsp;</p><br><br><p><b>Example 1:</b></p><br><br><pre>Input: [1, 5, 11, 5]<br><br>Output: true<br><br>Explanation: The array can be partitioned as [1, 5, 5] and [11].<br></pre><br><br><p>&nbsp;</p><br><br><p><b>Example 2:</b></p><br><br><pre>Input: [1, 2, 3, 5]<br><br>Output: false<br><br>Explanation: The array cannot be partitioned into equal sum subsets.<br></pre><br><br><p>&nbsp;</p><br></div>

## Solution

c++
```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return false;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum & 1) return false;
        sum /= 2;
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return canAchieve(nums,dp,0,sum);
    }
​
    bool canAchieve(vector<int> &nums,vector<vector<int>>&dp,int start,int target){
        if(target < 0) return false;
        if(target == 0) return true;
        if(start == nums.size()) return false;
        if(dp[start][target] != -1) return dp[start][target];
​
        for(int i=start;i<nums.size();i++){
            if(canAchieve(nums,dp,i+1,target - nums[i]) || canAchieve(nums,dp,i+1,target)) return true;
        }
        return dp[start][target] = false;
    }
};
​
​
​
```
