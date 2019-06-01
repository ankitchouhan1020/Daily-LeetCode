---
tags: ["leetcode","array","two pointers"]
created: "31/05/2019, 22:29:59"
difficulty: "medium"
---

# [0457-circular-array-loop](https://leetcode.com/problems/circular-array-loop/)

## Problem
<div><p>You are given a <b>circular</b> array <code>nums</code> of positive and negative integers. If a number <i>k</i> at an index is positive, then move forward <i>k</i> steps. Conversely, if it's negative (-<i>k</i>), move backward <i>k</i>&nbsp;steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.</p><br><br><p>Determine if there is a loop (or a cycle) in <code>nums</code>. A cycle must start and end at the same index and the cycle's length &gt; 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.</p><br><br><p>&nbsp;</p><br><br><p><b>Example 1:</b></p><br><br><pre><b>Input:</b> [2,-1,1,2,2]<br><b>Output:</b> true<br><b>Explanation:</b> There is a cycle, from index 0 -&gt; 2 -&gt; 3 -&gt; 0. The cycle's length is 3.<br></pre><br><br><p><b>Example 2:</b></p><br><br><pre><b>Input:</b> [-1,2]<br><b>Output:</b> false<br><b>Explanation:</b> The movement from index 1 -&gt; 1 -&gt; 1 ... is not a cycle, because the cycle's length is 1. By definition the cycle's length must be greater than 1.<br></pre><br><br><p><b>Example 3:</b></p><br><br><pre><b>Input:</b> [-2,1,-1,-2,-2]<br><b>Output:</b> false<br><b>Explanation:</b> The movement from index 1 -&gt; 2 -&gt; 1 -&gt; ... is not a cycle, because movement from index 1 -&gt; 2 is a forward movement, but movement from index 2 -&gt; 1 is a backward movement. All movements in a cycle must follow a single direction.</pre><br><br><p>&nbsp;</p><br><br><p><b>Note:</b></p><br><br><ol><br>	<li>-1000 ≤&nbsp;nums[i] ≤&nbsp;1000</li><br>	<li>nums[i] ≠&nbsp;0</li><br>	<li>1 ≤&nbsp;nums.length ≤ 5000</li><br></ol><br><br><p>&nbsp;</p><br><br><p><b>Follow up:</b></p><br><br><p>Could you solve it in <b>O(n)</b> time complexity and&nbsp;<strong>O(1)</strong> extra space complexity?</p></div>

## Solution

c++
```c++
class Solution {
public:
   bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = (((i + nums[i]) % n) + n) % n;
        }
        
        for(int i=0;i<n;i++){
            int slow = i;
            int fast = i;
            int sign = (nums[i] > 0 ? 1 : -1);
            int flag = 1,visited=0;
            while(1){
                if(sign<0 && (nums[v[fast]]>0 || nums[v[v[fast]]]>0 || nums[v[slow]]>0)){
                    flag = 0;break;
                }
                if(sign>0 && (nums[v[fast]]<0 || nums[v[v[fast]]]<0 || nums[v[slow]]<0)){
                    flag = 0;break;
                }
                if(fast == v[fast] || v[fast]==v[v[fast]] || slow == v[slow]){
                    flag = 0;break;
                }
                fast = v[v[fast]];
                slow = v[slow];
                visited++;
                if(fast == slow)    break;
                if(visited==n){
                    flag = 0;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};
​
```
