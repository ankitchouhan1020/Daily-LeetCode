---
tags: ["leetcode","dynamic programming"]
created: "12/06/2019, 22:35:20"
difficulty: "medium"
---

# [0213-house-robber-ii](https://leetcode.com/problems/house-robber-ii/)

## Problem
<div><p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are <strong>arranged in a circle.</strong> That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and&nbsp;<b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.</p><br><br><p>Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight <strong>without alerting the police</strong>.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> [2,3,2]<br><strong>Output:</strong> 3<br><strong>Explanation:</strong> You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),<br>&nbsp;            because they are adjacent houses.<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> [1,2,3,1]<br><strong>Output:</strong> 4<br><strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).<br>&nbsp;            Total amount you can rob = 1 + 3 = 4.</pre><br></div>

## Solution

c++
```c++
// Summary of solution was to know that problem can be solved by dividing the problem.
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        return max(HRII(nums,0,nums.size()-2),HRII(nums,1,nums.size()-1));
    }
    
    int HRII(vector<int>& nums,int s,int e){
        int prev1=nums[s];
        int prev2=0;
        
        for(int i=s+1;i<=e;i++){
            int temp = prev1;
            prev1 = max(prev2+nums[i],prev1);
            prev2 = temp;
        }
        
        return prev1;
    }
};
​
```
