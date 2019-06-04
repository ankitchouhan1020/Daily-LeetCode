---
tags: ["leetcode","array","two pointers","stack"]
created: "04/06/2019, 11:51:07"
difficulty: "hard"
---

# [0042-trapping-rain-water](https://leetcode.com/problems/trapping-rain-water/)

## Problem
<div><p>Given <em>n</em> non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.</p><br><br><p><img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png" style="width: 412px; height: 161px;"><br><br><small>The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. <strong>Thanks Marcos</strong> for contributing this image!</small></p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> [0,1,0,2,1,0,1,3,2,1,2,1]<br><strong>Output:</strong> 6</pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<pair<int,int>> v(n);
        int maxLeft=0;
        for(int i=0;i<n;i++){
            maxLeft = max(maxLeft, height[i]);
            v[i].first = maxLeft;
        }
        int maxRight = 0;
        for(int i=n-1;i>=0;i--){
            maxRight = max(maxRight,height[i]);
            v[i].second = maxRight;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(v[i].first,v[i].second) - height[i];
        }
        return ans;
    }
};
​
​
```
