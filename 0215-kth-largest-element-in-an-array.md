---
tags: ["leetcode","divide and conquer","heap"]
created: "12/06/2019, 19:32:02"
difficulty: "medium"
---

# [0215-kth-largest-element-in-an-array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

## Problem
<div><p>Find the <strong>k</strong>th largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> <code>[3,2,1,5,6,4] </code>and k = 2<br><strong>Output:</strong> 5<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> <code>[3,2,3,1,2,4,5,5,6] </code>and k = 4<br><strong>Output:</strong> 4</pre><br><br><p><strong>Note: </strong><br><br>You may assume k is always valid, 1 ≤ k ≤ array's length.</p><br></div>

## Solution

c++
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(),nums.begin()+k-1,nums.end(),greater<int>());
        return nums[k-1];
    }
};
​
​
```
