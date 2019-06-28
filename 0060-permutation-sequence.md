---
tags: ["leetcode","math","backtracking"]
created: "27/06/2019, 16:06:53"
difficulty: "medium"
---

# [0060-permutation-sequence](https://leetcode.com/problems/permutation-sequence/)

## Problem
<div><p>The set <code>[1,2,3,...,<em>n</em>]</code> contains a total of <em>n</em>! unique permutations.</p><br><br><p>By listing and labeling all of the permutations in order, we get the following sequence for <em>n</em> = 3:</p><br><br><ol><br>	<li><code>"123"</code></li><br>	<li><code>"132"</code></li><br>	<li><code>"213"</code></li><br>	<li><code>"231"</code></li><br>	<li><code>"312"</code></li><br>	<li><code>"321"</code></li><br></ol><br><br><p>Given <em>n</em> and <em>k</em>, return the <em>k</em><sup>th</sup> permutation sequence.</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>Given <em>n</em> will be between 1 and 9 inclusive.</li><br>	<li>Given&nbsp;<em>k</em>&nbsp;will be between 1 and <em>n</em>! inclusive.</li><br></ul><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> n = 3, k = 3<br><strong>Output:</strong> "213"<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> n = 4, k = 9<br><strong>Output:</strong> "2314"<br></pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact[] = {1,1,2,6,24,120,720,5040,40320,362880};
        string nums = "123456789";
        string ans = "";
        k--;
        for(int i=1;i<=n;i++){
            int idx = k/fact[n-i];
            ans += nums[idx];
            nums.erase(nums.begin()+idx);
            k -= idx*fact[n-i];
        }
        return ans;
        
    }
};
​
```
