---
tags: ["leetcode","hash table","heap"]
created: "26/05/2019, 16:59:23"
difficulty: "medium"
---

# [0347-top-k-frequent-elements](https://leetcode.com/problems/top-k-frequent-elements/)

## Problem
<div><p>Given a non-empty array of integers, return the <b><i>k</i></b> most frequent elements.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>nums = <span id="example-input-1-1">[1,1,1,2,2,3]</span>, k = <span id="example-input-1-2">2</span><br><strong>Output: </strong><span id="example-output-1">[1,2]</span><br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>nums = <span id="example-input-2-1">[1]</span>, k = <span id="example-input-2-2">1</span><br><strong>Output: </strong><span id="example-output-2">[1]</span></pre><br></div><br><br><p><b>Note: </b></p><br><br><ul><br>	<li>You may assume <i>k</i> is always valid, 1 ≤ <i>k</i> ≤ number of unique elements.</li><br>	<li>Your algorithm's time complexity <b>must be</b> better than O(<i>n</i> log <i>n</i>), where <i>n</i> is the array's size.</li><br></ul><br></div>

## Solution

c++
```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int num:nums) m[num]++;
        
        priority_queue<pair<int,int>> heap;
        
        for(auto tmp : m){
            heap.push({tmp.second,tmp.first}); // freq & val
            if(heap.size() > m.size() - k){
                ans.push_back(heap.top().second);
                heap.pop();
                if(ans.size() == k) break;
            }
        }
        // while(ans.size() < k){
        //     ans.push_back(heap.top().second);
        //     heap.pop();
        // }
        return ans;
    }
};
​
```
