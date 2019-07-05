---
tags: ["leetcode","two pointers"]
created: "06/07/2019, 00:46:41"
difficulty: "medium"
---

# [0904-fruit-into-baskets](https://leetcode.com/problems/fruit-into-baskets/)

## Problem
<div><p>In a row of trees, the <code>i</code>-th tree&nbsp;produces&nbsp;fruit with type&nbsp;<code>tree[i]</code>.</p><br><br><p>You <strong>start at any tree&nbsp;of your choice</strong>, then repeatedly perform the following steps:</p><br><br><ol><br>	<li>Add one piece of fruit from this tree to your baskets.&nbsp; If you cannot, stop.</li><br>	<li>Move to the next tree to the right of the current tree.&nbsp; If there is no tree to the right, stop.</li><br></ol><br><br><p>Note that you do not have any choice after the initial choice of starting tree:&nbsp;you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.</p><br><br><p>You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.</p><br><br><p>What is the total amount of fruit you can collect with this procedure?</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">[1,2,1]</span><br><strong>Output: </strong><span id="example-output-1">3</span><br><strong><span>Explanation: </span></strong><span>We can collect [1,2,1].</span><br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-2-1">[0,1,2,2]</span><br><strong>Output: </strong><span id="example-output-2">3<br></span><strong><span>Explanation: </span></strong><span>We can collect [1,2,2].<br>If we started at the first tree, we would only collect [0, 1].</span><br></pre><br><br><div><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-3-1">[1,2,3,2,2]</span><br><strong>Output: </strong><span id="example-output-3">4<br></span><strong><span>Explanation: </span></strong><span>We can collect [2,3,2,2].</span><br><span>If we started at the first tree, we would only collect [1, 2].</span><br></pre><br><br><div><br><p><strong>Example 4:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-4-1">[3,3,3,1,2,1,1,2,3,3,4]</span><br><strong>Output: </strong>5<span id="example-output-4"><br></span><strong><span>Explanation: </span></strong><span>We can collect [1,2,1,1,2].</span><br><span>If we started at the first tree or the eighth tree, we would only collect 4 fruits.</span><br></pre><br><br><p>&nbsp;</p><br></div><br></div><br></div><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= tree.length &lt;= 40000</code></li><br>	<li><code>0 &lt;= tree[i] &lt; tree.length</code></li><br></ol><br></div>

## Solution

c++
```c++
//Longest Subarray of two values 
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        if(n==0) return 0;
        int i = 0,maxLen = 0;
        int first = -1,second = -1;
        int one = -1,two = -1;
        while(i<n){
            if(first==-1){
                first=tree[i];
                one = i;
            }
            else if(tree[i] == first) i++;
            else if(second == -1){
                second = tree[i];
                two = i;
            }
            else if(tree[i]==second) i++;
            else{
                if(i-one > maxLen) maxLen = i-one;
                i = two;
                first = -1;
                second = -1;
            }
        }
        if(second != -1 || first != -1){
            maxLen = max(maxLen, i-one);
        }
        return maxLen;
    }
};
​
```
