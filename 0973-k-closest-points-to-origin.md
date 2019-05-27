---
tags: ["leetcode","divide and conquer","heap","sort"]
created: "27/05/2019, 11:52:36"
difficulty: "medium"
---

# [0973-k-closest-points-to-origin](https://leetcode.com/problems/k-closest-points-to-origin/)

## Problem
<div><p>We have a list of <code>points</code>&nbsp;on the plane.&nbsp; Find the <code>K</code> closest points to the origin <code>(0, 0)</code>.</p><br><br><p>(Here, the distance between two points on a plane is the Euclidean distance.)</p><br><br><p>You may return the answer in any order.&nbsp; The&nbsp;answer is guaranteed to be unique (except for the order that it is in.)</p><br><br><p>&nbsp;</p><br><br><div><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>points = <span id="example-input-1-1">[[1,3],[-2,2]]</span>, K = <span id="example-input-1-2">1</span><br><strong>Output: </strong><span id="example-output-1">[[-2,2]]</span><br><strong>Explanation: </strong><br>The distance between (1, 3) and the origin is sqrt(10).<br>The distance between (-2, 2) and the origin is sqrt(8).<br>Since sqrt(8) &lt; sqrt(10), (-2, 2) is closer to the origin.<br>We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].<br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>points = <span id="example-input-2-1">[[3,3],[5,-1],[-2,4]]</span>, K = <span id="example-input-2-2">2</span><br><strong>Output: </strong><span id="example-output-2">[[3,3],[-2,4]]</span><br>(The answer [[-2,4],[3,3]] would also be accepted.)<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= K &lt;= points.length &lt;= 10000</code></li><br>	<li><code>-10000 &lt; points[i][0] &lt; 10000</code></li><br>	<li><code>-10000 &lt; points[i][1] &lt; 10000</code></li><br></ol><br></div><br></div></div>

## Solution

c++
```c++

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        if(k==0 || points.size()==0) return ans;
        if(k==points.size()) return points;
        
        vector<int> arr;
        unordered_map<int,vector<int>> m;
        
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int key = x*x + y*y;
            if(m.count(key)==0){
                m[key] = vector<int>();
                m[key].push_back(i);
            }else{
                 m[key].push_back(i);
            }
            arr.push_back(key);
        }
        
        sort(arr.begin(),arr.end());
        
        int j = 0;
        while(k){
            auto it = m.find(arr[j]);
            vector<int>& v = it->second;
            
            for(int i=0;i<v.size();i++){
                if(k==0) break;
                ans.push_back(points[v[i]]);
                k--;
            }
            j++;
        }
        return ans;        
    }
};
​
// Another good method is to use nth_element or partial sort to do it in O(n) time.
​
```
