---
tags: ["leetcode","heap","sliding window"]
created: "05/06/2019, 11:17:17"
difficulty: "hard"
---

# [0239-sliding-window-maximum](https://leetcode.com/problems/sliding-window-maximum/)

## Problem
<div><p>Given an array <em>nums</em>, there is a sliding window of size <em>k</em> which is moving from the very left of the array to the very right. You can only see the <em>k</em> numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> <em>nums</em> = <code>[1,3,-1,-3,5,3,6,7]</code>, and <em>k</em> = 3<br><strong>Output: </strong><code>[3,3,5,5,6,7] <br><strong>Explanation: <br></strong></code><br>Window position                Max<br>---------------               -----<br>[1  3  -1] -3  5  3  6  7       <strong>3</strong><br> 1 [3  -1  -3] 5  3  6  7       <strong>3</strong><br> 1  3 [-1  -3  5] 3  6  7      <strong> 5</strong><br> 1  3  -1 [-3  5  3] 6  7       <strong>5</strong><br> 1  3  -1  -3 [5  3  6] 7       <strong>6</strong><br> 1  3  -1  -3  5 [3  6  7]      <strong>7</strong><br></pre><br><br><p><strong>Note: </strong><br><br>You may assume <em>k</em> is always valid, 1 ≤ k ≤ input array's size for non-empty array.</p><br><br><p><strong>Follow up:</strong><br><br>Could you solve it in linear time?</p></div>

## Solution

c++
```c++

// Use a deque ,
// remove indices that are not in window, remove less value before any i.
// Since it itself is going to handle max case
// Priority_queue won't help
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        
        for(int i=0;i<k-1;i++){
            while(!q.empty() && nums[q.back()]<nums[i]){
                q.pop_back();
            }
                
            q.push_back(i);           
        }
        
        for(int i=k-1;i<nums.size();i++){
            while(!q.empty() && q.front() < i-(k-1))
                q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            
            q.push_back(i);
            if(i>=k-1)  res.push_back(nums[q.front()]);          
        }
        return res;
    }
};
​
```
