---
tags: ["leetcode","array","two pointers","binary search"]
created: "26/05/2019, 16:55:22"
difficulty: "medium"
---

# [0287-find-the-duplicate-number](https://leetcode.com/problems/find-the-duplicate-number/)

## Problem
<div><p>Given an array <i>nums</i> containing <i>n</i> + 1 integers where each integer is between 1 and <i>n</i> (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.</p><br><br><p><b>Example 1:</b></p><br><br><pre><b>Input:</b> <code>[1,3,4,2,2]</code><br><b>Output:</b> 2<br></pre><br><br><p><b>Example 2:</b></p><br><br><pre><b>Input:</b> [3,1,3,4,2]<br><b>Output:</b> 3</pre><br><br><p><b>Note:</b></p><br><br><ol><br>	<li>You <b>must not</b> modify the array (assume the array is read only).</li><br>	<li>You must use only constant, <i>O</i>(1) extra space.</li><br>	<li>Your runtime complexity should be less than <em>O</em>(<em>n</em><sup>2</sup>).</li><br>	<li>There is only one duplicate number in the array, but it could be repeated more than once.</li><br></ol><br></div>

## Solution

c++
```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) return -1;
        int slow = nums[0];
        int fast = nums[0];
        do{
        slow = nums[slow];
        fast = nums[nums[fast]];
        }
        while(fast != slow);
        
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
​
```
