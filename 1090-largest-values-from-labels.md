---
tags: ["leetcode","hash table","greedy"]
created: "08/07/2019, 13:29:47"
difficulty: "medium"
---

# [1090-largest-values-from-labels](https://leetcode.com/problems/largest-values-from-labels/)

## Problem
<div><p>We have a set of items: the <code>i</code>-th item has value <code>values[i]</code> and label <code>labels[i]</code>.</p><br><br><p>Then, we choose&nbsp;a subset <code>S</code> of these items, such that:</p><br><br><ul><br>	<li><code>|S| &lt;= num_wanted</code></li><br>	<li>For every label <code>L</code>, the number of items in <code>S</code> with&nbsp;label <code>L</code> is <code>&lt;= use_limit</code>.</li><br></ul><br><br><p>Return the largest possible sum of the subset <code>S</code>.</p><br><br><p>&nbsp;</p><br><br><div><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>values = <span id="example-input-1-1">[5,4,3,2,1]</span>, labels = <span id="example-input-1-2">[1,1,2,2,3]</span>, <code>num_wanted </code>= <span id="example-input-1-3">3</span>, use_limit = <span id="example-input-1-4">1</span><br><strong>Output: </strong><span id="example-output-1">9</span><br><strong>Explanation: </strong>The subset chosen is the first, third, and fifth item.<br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>values = <span id="example-input-2-1">[5,4,3,2,1]</span>, labels = <span id="example-input-2-2">[1,3,3,3,2]</span>, <code>num_wanted </code>= <span id="example-input-2-3">3</span>, use_limit = <span id="example-input-2-4">2</span><br><strong>Output: </strong><span id="example-output-2">12</span><br><strong>Explanation: </strong>The subset chosen is the first, second, and third item.<br></pre><br><br><div><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong>values = <span id="example-input-3-1">[9,8,8,7,6]</span>, labels = <span id="example-input-3-2">[0,0,0,1,1]</span>, <code>num_wanted </code>= <span id="example-input-3-3">3</span>, use_limit = <span id="example-input-3-4">1</span><br><strong>Output:</strong>&nbsp;16<br><strong>Explanation: </strong>The subset chosen is the first and fourth item.<br></pre><br><br><div><br><p><strong>Example 4:</strong></p><br><br><pre><strong>Input: </strong>values = <span id="example-input-4-1">[9,8,8,7,6]</span>, labels = <span id="example-input-4-2">[0,0,0,1,1]</span>, <code>num_wanted </code>= <span id="example-input-4-3">3</span>, use_limit = <span id="example-input-4-4">2</span><br><strong>Output: </strong><span id="example-output-4">24</span><br><strong>Explanation: </strong>The subset chosen is the first, second, and fourth item.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= values.length == labels.length &lt;= 20000</code></li><br>	<li><code>0 &lt;= values[i], labels[i]&nbsp;&lt;= 20000</code></li><br>	<li><code>1 &lt;= num_wanted, use_limit&nbsp;&lt;= values.length</code></li><br></ol><br></div><br></div><br></div><br></div></div>

## Solution

c++
```c++
// Think greedy -> I should cover as maximum values as I can until the use_limit of that level becomes 0
typedef pair<int,int> PII;
bool Compare(const PII &a, const PII &b){
        //if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
}
​
​
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int n = values.size();
        unordered_map<int,int> m;
        
        for(int i: labels){
            if(m.count(i)==0) m[i] = use_limit;
        }
        
        vector<PII> v(n);
        for(int i=0;i<n;i++){
            v[i] = {values[i],labels[i]};
        }
        sort(v.begin(),v.end(),Compare);
        
        int sum = 0;
        for(int i=0;num_wanted && i<n;i++){
            int value = v[i].first;
            int label = v[i].second;
            
            if(m[label]!=0){
                m[label]--;
                sum += value;
                num_wanted--;
            }
        }
        return sum;
    }
};
​
```
