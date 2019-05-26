---
tags: ["leetcode","array"]
created: "26/05/2019, 16:22:39"
difficulty: "medium"
---

# [0031-next-permutation](https://leetcode.com/problems/next-permutation/)

## Problem
<div><p>Implement <strong>next permutation</strong>, which rearranges numbers into the lexicographically next greater permutation of numbers.</p><br><br><p>If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).</p><br><br><p>The replacement must be <strong><a href="http://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a></strong> and use only constant&nbsp;extra memory.</p><br><br><p>Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.</p><br><br><p><code>1,2,3</code> → <code>1,3,2</code><br><br><code>3,2,1</code> → <code>1,2,3</code><br><br><code>1,1,5</code> → <code>1,5,1</code></p><br></div>

## Solution

c++
```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return;
        auto it = is_sorted_until(nums.rbegin(),nums.rend());
        
        if(it != nums.rend()){
            swap(*it,*upper_bound(nums.rbegin(),it,*it));
        }
        reverse(nums.rbegin(),it);
        return ;
    }
};
​
/*
find value from last which does not follow assending order.
swap this value to upper bound before it. Means just greater value than it.
reverse list after this iterator
*/
​
```
