---
tags: ["leetcode","array","two pointers","sort"]
created: "26/05/2019, 16:33:55"
difficulty: "medium"
---

# [0075-sort-colors](https://leetcode.com/problems/sort-colors/)

## Problem
<div><p>Given an array with <em>n</em> objects colored red, white or blue, sort them <strong><a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a>&nbsp;</strong>so that objects of the same color are adjacent, with the colors in the order red, white and blue.</p><br><br><p>Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.</p><br><br><p><strong>Note:</strong>&nbsp;You are not suppose to use the library's sort function for this problem.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> [2,0,2,1,1,0]<br><strong>Output:</strong> [0,0,1,1,2,2]</pre><br><br><p><strong>Follow up:</strong></p><br><br><ul><br>	<li>A rather straight forward solution is a two-pass algorithm using counting sort.<br><br>	First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.</li><br>	<li>Could you come up with a&nbsp;one-pass algorithm using only constant space?</li><br></ul><br></div>

## Solution

c++
```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0,mid=0,high=nums.size()-1;
        
        while(mid <= high){
            if(nums[mid] == 1) mid++;
            else if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                low++;mid++;
            }else if(nums[mid] == 2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
​
```
