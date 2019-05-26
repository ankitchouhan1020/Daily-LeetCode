---
tags: ["leetcode","backtracking"]
created: "26/05/2019, 16:30:24"
difficulty: "medium"
---

# [0047-permutations-ii](https://leetcode.com/problems/permutations-ii/)

## Problem
<div><p>Given a collection of numbers that might contain duplicates, return all possible unique permutations.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> [1,1,2]<br><strong>Output:</strong><br>[<br>  [1,1,2],<br>  [1,2,1],<br>  [2,1,1]<br>]<br></pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> powerset;
        if(nums.size() == 0) return powerset;
        sort(nums.begin(),nums.end());
        do{
            powerset.push_back(nums);
        }while(nextPermutation(nums));
        return powerset;
    }
    
    bool nextPermutation(vector<int>& nums) {
        auto it = is_sorted_until(nums.rbegin(),nums.rend());
        int toContinue = false;
        if(it != nums.rend()){
            toContinue = true;
            swap(*it,*upper_bound(nums.rbegin(),it,*it));
        }
        reverse(nums.rbegin(),it);
        return toContinue;
    }
};
​
```
