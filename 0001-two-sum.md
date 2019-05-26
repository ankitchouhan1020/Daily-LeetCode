---
tags: ["leetcode","array","hash table"]
created: "26/05/2019, 16:10:06"
difficulty: "easy"
---

# [0001-two-sum](https://leetcode.com/problems/two-sum/)

## Problem
<div><p>Given an array of integers, return <strong>indices</strong> of the two numbers such that they add up to a specific target.</p><br><br><p>You may assume that each input would have <strong><em>exactly</em></strong> one solution, and you may not use the <em>same</em> element twice.</p><br><br><p><strong>Example:</strong></p><br><br><pre>Given nums = [2, 7, 11, 15], target = 9,<br><br>Because nums[<strong>0</strong>] + nums[<strong>1</strong>] = 2 + 7 = 9,<br>return [<strong>0</strong>, <strong>1</strong>].<br></pre><br><br><p>&nbsp;</p><br></div>

## Solution

c++
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(target - nums[i]) != hash.end()){
                return {hash[target -nums[i]],i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
​
```
