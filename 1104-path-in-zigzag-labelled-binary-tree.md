---
tags: ["leetcode"]
created: "30/06/2019, 14:17:37"
difficulty: "easy"
---

# [1104-path-in-zigzag-labelled-binary-tree](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/)

## Problem
<div><p>In an infinite binary tree where every node has two children, the nodes are labelled in row order.</p><br><br><p>In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.</p><br><br><p><img alt="" src="https://assets.leetcode.com/uploads/2019/06/24/tree.png" style="width: 300px; height: 138px;"></p><br><br><p>Given the <code>label</code> of a node in this tree, return the labels in the path from the root of the tree to the&nbsp;node with that <code>label</code>.</p><br><br><p>&nbsp;</p><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> label = 14<br><strong>Output:</strong> [1,3,4,14]<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> label = 26<br><strong>Output:</strong> [1,2,6,10,26]<br></pre><br><br><p>&nbsp;</p><br><p><strong>Constraints:</strong></p><br><br><ul><br>	<li><code>1 &lt;= label &lt;= 10^6</code></li><br></ul><br></div>

## Solution

c++
```c++
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        //find level of label
        int level = 0;
        while(1<<level <= label) level++;
        
        vector<int> result(level);  
        
        /*
        Every level is rotated wrt. its previous level.
        
        label = maxIndex+minIndex-1 find the index where this label should be associated
        in normal binary tree. We find that value 
        
        ex. for 10 we find label 13, which is on 10's original index. Now since we can
        find parent with i/2. we store child in result.
        */
        
        
        for(;level>=1;label/=2,level--){
            
            result[level-1] = label;
            int maxIndex = (1<<level) - 1;
            int minIndex = 1<<(level-1);
            
            label = maxIndex + minIndex - label;
            
        }
        return result;
    }
};
​
```
