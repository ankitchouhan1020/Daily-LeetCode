---
tags: ["leetcode","array","two pointers"]
created: "28/06/2019, 20:34:23"
difficulty: "easy"
---

# [0088-merge-sorted-array](https://leetcode.com/problems/merge-sorted-array/)

## Problem
<div><p>Given two sorted integer arrays <em>nums1</em> and <em>nums2</em>, merge <em>nums2</em> into <em>nums1</em> as one sorted array.</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>The number of elements initialized in <em>nums1</em> and <em>nums2</em> are <em>m</em> and <em>n</em> respectively.</li><br>	<li>You may assume that <em>nums1</em> has enough space (size that is greater or equal to <em>m</em> + <em>n</em>) to hold additional elements from <em>nums2</em>.</li><br></ul><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong><br>nums1 = [1,2,3,0,0,0], m = 3<br>nums2 = [2,5,6],       n = 3<br><br><strong>Output:</strong>&nbsp;[1,2,2,3,5,6]<br></pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // copy nums2 at the end of nums1's mth int
        copy(nums2.begin(),nums2.end(),nums1.begin()+m);
        // merge two sorted arrat inplace just like in merge sort
        inplace_merge(nums1.begin(),nums1.begin()+m,nums1.end());
    }
};
​
```
