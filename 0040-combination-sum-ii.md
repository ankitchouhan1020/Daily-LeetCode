---
tags: ["leetcode","array","backtracking"]
created: "26/05/2019, 16:25:57"
difficulty: "medium"
---

# [0040-combination-sum-ii](https://leetcode.com/problems/combination-sum-ii/)

## Problem
<div><p>Given a collection of candidate numbers (<code>candidates</code>) and a target number (<code>target</code>), find all unique combinations in <code>candidates</code>&nbsp;where the candidate numbers sums to <code>target</code>.</p><br><br><p>Each number in <code>candidates</code>&nbsp;may only be used <strong>once</strong> in the combination.</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>All numbers (including <code>target</code>) will be positive integers.</li><br>	<li>The solution set must not contain duplicate combinations.</li><br></ul><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> candidates =&nbsp;<code>[10,1,2,7,6,1,5]</code>, target =&nbsp;<code>8</code>,<br><strong>A solution set is:</strong><br>[<br>  [1, 7],<br>  [1, 2, 5],<br>  [2, 6],<br>  [1, 1, 6]<br>]<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> candidates =&nbsp;[2,5,2,1,2], target =&nbsp;5,<br><strong>A solution set is:</strong><br>[<br>&nbsp; [1,2,2],<br>&nbsp; [5]<br>]<br></pre><br></div>

## Solution

c++
```c++

class Solution {
    private:
    vector<vector<int>> powerset;
    vector<int> subset;
    int total;
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        total = target;
        sort(nums.begin(),nums.end());
        backtrackNum(nums,0);
        return powerset;
    }
    
    void backtrackNum(vector<int>& nums,int start){
        int tempSum = accumulateNums();
        if(tempSum == total){
            powerset.push_back(subset);
            return;
        }
        else if(tempSum > total) return;        
        
        for(int i=start;i<nums.size();i++){
            
            if(i>start && nums[i]==nums[i-1]) continue;
            subset.push_back(nums[i]);
            backtrackNum(nums,i+1);
            subset.pop_back();
            
        }
        return;
    }
    
    int accumulateNums(){
        int x = 0;
        for(int k:subset) x+=k;
        return x;
    }
};
​
```
