---
tags: ["leetcode","array","greedy"]
created: "21/06/2019, 16:02:14"
difficulty: "hard"
---

# [0045-jump-game-ii](https://leetcode.com/problems/jump-game-ii/)

## Problem
<div><p>Given an array of non-negative integers, you are initially positioned at the first index of the array.</p><br><br><p>Each element in the array represents your maximum jump length at that position.</p><br><br><p>Your goal is to reach the last index in the minimum number of jumps.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> [2,3,1,1,4]<br><strong>Output:</strong> 2<br><strong>Explanation:</strong> The minimum number of jumps to reach the last index is 2.<br>    Jump 1 step from index 0 to 1, then 3 steps to the last index.</pre><br><br><p><strong>Note:</strong></p><br><br><p>You can assume that you can always reach the last index.</p><br></div>

## Solution

c++
```c++
// dp fails at last test case
// O(n) Solution
// Try to be greedy for every path from current position
// Find the path which leads to smaller gap to goal position.
​
class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        int maxReach = arr[0],ans=1;
        int limit,next = 0;
        
        while(maxReach < n-1){
            limit = maxReach;
            
            for(int i=next+1;i<=limit;i++){
                if(i+arr[i] > maxReach){
                    next = i;
                    maxReach = i+arr[i];
                }
            }
            ans++;
        }
        return ans;
    }
};
​
```
