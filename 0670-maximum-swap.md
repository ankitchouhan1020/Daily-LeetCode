---
tags: ["leetcode","array","math"]
created: "25/06/2019, 23:51:04"
difficulty: "medium"
---

# [0670-maximum-swap](https://leetcode.com/problems/maximum-swap/)

## Problem
<div><p><br>Given a non-negative integer, you could swap two digits <b>at most</b> once to get the maximum valued number. Return the maximum valued number you could get.<br></p><br><br><p><b>Example 1:</b><br><br></p><pre><b>Input:</b> 2736<br><b>Output:</b> 7236<br><b>Explanation:</b> Swap the number 2 and the number 7.<br></pre><br><p></p><br><br><p><b>Example 2:</b><br><br></p><pre><b>Input:</b> 9973<br><b>Output:</b> 9973<br><b>Explanation:</b> No swap.<br></pre><br><p></p><br><br><br><p><b>Note:</b><br><br></p><ol><br><li>The given number is in the range [0, 10<sup>8</sup>]</li><br></ol><br><p></p></div>

## Solution

c++
```c++
class Solution {
public:
    int maximumSwap(int num) {
        if(num<=11) return num;
        int ans = num;
        vector<int>nums;
        while(num > 0){
            nums.push_back(num%10);
            num/=10;
        }
        reverse(nums.begin(),nums.end());
        int n = nums.size();
       
        int idx1 = -1;
        int idx2 = -1;
        for(int i=0;i<n-1;i++){
            int maxi = nums[i];
            idx2 = i;
            for(int j=n-1;j>i;j--){
                if(nums[j] > maxi){
                    idx1 = j;
                    maxi = nums[j];
                }
            }
            if(idx1!=-1) break;
        }
​
        if(idx1==-1) return ans;
        swap(nums[idx1],nums[idx2]);
        
        ans = 0;
        int mul = 1;
        for(int i = n-1;i>=0;i--){
            ans += nums[i]*mul;
            mul *= 10;
        }
        return ans;
    }
};
​
```
