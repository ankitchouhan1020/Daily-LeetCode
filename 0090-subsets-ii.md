---
tags: ["leetcode","array","backtracking"]
created: "26/05/2019, 16:35:45"
difficulty: "medium"
---

# [0090-subsets-ii](https://leetcode.com/problems/subsets-ii/)

## Problem
<div><p>Given a collection of integers that might contain duplicates, <strong><em>nums</em></strong>, return all possible subsets (the power set).</p><br><br><p><strong>Note:</strong> The solution set must not contain duplicate subsets.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> [1,2,2]<br><strong>Output:</strong><br>[<br>  [2],<br>  [1],<br>  [1,2,2],<br>  [2,2],<br>  [1,2],<br>  []<br>]<br></pre><br></div>

## Solution

c++
```c++
class Solution {
    private:
            vector<vector<int> > powerset;
            vector<int> subset;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0) return {};
        sort(nums.begin(),nums.end());
        backtrackNums(nums,0);
        return powerset;
    }
    
    void backtrackNums(vector<int> &nums,int s){
        powerset.push_back(subset);
        
        for(int i=s;i<nums.size();i++){
            if(i>s && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            
            backtrackNums(nums,i+1);
            
            subset.pop_back();
        }
    }
};
//Try using bit masking
​
```
