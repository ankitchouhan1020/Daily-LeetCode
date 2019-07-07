---
tags: ["leetcode"]
created: "07/07/2019, 22:56:49"
difficulty: "medium"
---

# [1109-corporate-flight-bookings](https://leetcode.com/problems/corporate-flight-bookings/)

## Problem
<div><p>There are <code>n</code> flights, and they are labeled&nbsp;from <code>1</code> to <code>n</code>.</p><br><br><p>We have a list of flight bookings.&nbsp; The <code>i</code>-th booking&nbsp;<code>bookings[i] = [i, j, k]</code>&nbsp;means that we booked <code>k</code> seats from flights labeled <code>i</code> to <code>j</code> inclusive.</p><br><br><p>Return an array <code>answer</code> of length <code>n</code>, representing the number of seats booked on each flight in order of their label.</p><br><br><p>&nbsp;</p><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5<br><strong>Output:</strong> [10,55,45,25,25]<br></pre><br><br><p>&nbsp;</p><br><p><strong>Constraints:</strong></p><br><br><ul><br>	<li><code>1 &lt;= bookings.length &lt;= 20000</code></li><br>	<li><code>1 &lt;= bookings[i][0] &lt;= bookings[i][1] &lt;= n &lt;= 20000</code></li><br>	<li><code>1 &lt;= bookings[i][2] &lt;= 10000</code></li><br></ul><br></div>

## Solution

c++
```c++
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(auto booking: bookings){
            ans[booking[0]-1] += booking[2];
            if(booking[1] < n)
                ans[booking[1]] -= booking[2];
        }
        for(int i=1;i<n;i++) ans[i]+=ans[i-1];
        return ans;
    }
};
​
```
