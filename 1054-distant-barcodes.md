---
tags: ["leetcode","heap","sort"]
created: "28/05/2019, 15:37:33"
difficulty: "medium"
---

# [1054-distant-barcodes](https://leetcode.com/problems/distant-barcodes/)

## Problem
<div><p>In a warehouse, there is a row of barcodes, where the <code>i</code>-th barcode is&nbsp;<code>barcodes[i]</code>.</p><br><br><p>Rearrange the barcodes so that no two adjacent barcodes are equal.&nbsp; You may return any answer, and it is guaranteed an answer exists.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">[1,1,1,2,2,2]</span><br><strong>Output: </strong><span id="example-output-1">[2,1,2,1,2,1]</span><br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-2-1">[1,1,1,1,2,2,3,3]</span><br><strong>Output: </strong><span id="example-output-2">[1,3,1,3,2,1,2,1]</span></pre><br></div><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= barcodes.length &lt;= 10000</code></li><br>	<li><code>1 &lt;= barcodes[i] &lt;= 10000</code></li><br></ol><br><br><div><br><div>&nbsp;</div><br></div></div>

## Solution

c++
```c++
// struct comp{
//     bool operator()(const pair<int,int>&a,const pair<int,int>&b){
//         return a.first > b.first;
//     }
// }
​
// Alternative : Fix the most frequent first and then order does not matter, fill all in gaps O(n) 
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size() <=2) return barcodes;
        
        unordered_map<int,int> m;
        int n = barcodes.size();
        for(int i: barcodes) m[i]++;
        
        priority_queue<pair<int,int>> pq;
        for(auto i: m){
            pq.push({i.second,i.first});
        }
        
        pair<int,int> tmp = pq.top();pq.pop();
        for(int i=0;i<n;i+=2){
            if(tmp.first == 0){
                tmp = pq.top();pq.pop();
            }
            barcodes[i] = tmp.second;
            tmp.first -= 1;
        }
        
        for(int i=1;i<n;i+=2){
            if(tmp.first == 0){
                tmp = pq.top();pq.pop();
            }
            barcodes[i] = tmp.second;
            tmp.first -= 1;
        }
        
        return barcodes;
    }
};
​
```
