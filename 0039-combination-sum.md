---
tags: ["leetcode","array","backtracking"]
created: "26/05/2019, 16:24:23"
difficulty: "medium"
---

# [0039-combination-sum](https://leetcode.com/problems/combination-sum/)

## Problem
<div><p>Given a <strong>set</strong> of candidate numbers (<code>candidates</code>) <strong>(without duplicates)</strong> and a target number (<code>target</code>), find all unique combinations in <code>candidates</code>&nbsp;where the candidate numbers sums to <code>target</code>.</p><br><br><p>The <strong>same</strong> repeated number may be chosen from <code>candidates</code>&nbsp;unlimited number of times.</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>All numbers (including <code>target</code>) will be positive integers.</li><br>	<li>The solution set must not contain duplicate combinations.</li><br></ul><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> candidates = <code>[2,3,6,7], </code>target = <code>7</code>,<br><strong>A solution set is:</strong><br>[<br>  [7],<br>  [2,2,3]<br>]<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> candidates = [2,3,5]<code>, </code>target = 8,<br><strong>A solution set is:</strong><br>[<br>&nbsp; [2,2,2,2],<br>&nbsp; [2,3,3],<br>&nbsp; [3,5]<br>]<br></pre><br></div>

## Solution

c++
```c++

//Template for backtracing problem
class Solution {
    private:
    vector<vector<int>> powerset;
    vector<int> subset;
    int total;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        total = target;
        backtrackNum(nums,0);
        return powerset;
    }
    
    void backtrackNum(vector<int>& nums,int start){
        int tempSum = accumulateNums();
        if(tempSum == total){
            powerset.push_back(subset);
            return ;
        }
        else if(tempSum > total) return;
        
        
        for(int i=start;i<nums.size();i++){
            
            subset.push_back(nums[i]);
            backtrackNum(nums,i);
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
