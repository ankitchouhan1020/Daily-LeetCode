---
tags: ["leetcode","array","greedy"]
created: "06/07/2019, 15:42:07"
difficulty: "medium"
---

# [1053-previous-permutation-with-one-swap](https://leetcode.com/problems/previous-permutation-with-one-swap/)

## Problem
<div><p>Given an array <code>A</code> of positive integers (not necessarily distinct), return the lexicographically largest permutation that is smaller than <code>A</code>, that can be <strong>made with one swap</strong> (A <em>swap</em> exchanges the positions of two numbers <code>A[i]</code> and <code>A[j]</code>).&nbsp; If it cannot be done, then return the same array.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>[3,2,1]<br><strong>Output: </strong>[3,1,2]<br><strong>Explanation: </strong>Swapping 2 and 1.<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>[1,1,5]<br><strong>Output: </strong>[1,1,5]<br><strong>Explanation: </strong>This is already the smallest permutation.<br></pre><br><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong>[1,9,4,6,7]<br><strong>Output: </strong>[1,7,4,6,9]<br><strong>Explanation: </strong>Swapping 9 and 7.<br></pre><br><br><p><strong>Example 4:</strong></p><br><br><pre><strong>Input: </strong>[3,1,1,3]<br><strong>Output: </strong>[1,3,1,3]<br><strong>Explanation: </strong>Swapping 1 and 3.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= A.length &lt;= 10000</code></li><br>	<li><code>1 &lt;= A[i] &lt;= 10000</code></li><br></ol><br></div>

## Solution

c++
```c++

/*
If the array is already sorted the solution is the input array.
If not, move form right side of array toward left side until the point where the left element is larger than right element.
At this point the left element (let's call it candid) is one of the elements that should be swapped.
But to swap with what element?
We actually need to swap candid with the largest value on its right side that is less than candid (let's call it candid_2).
Since the elements on the right side of candid are all sorted we can find the largest smaller number than candid in O(logN) by binary search
​
*/
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        if(n < 2 || is_sorted(begin(A),end(A))) return A;
        
        int cand = n-2;
        while(cand>=0 && A[cand+1] >= A[cand]) cand--;
        
        int idx = swap_with(A, cand+1);
        swap(A[cand],A[idx]);
        return A;
    }
    
    int swap_with(vector<int> &A,int left){
        int right = A.size()-1;
        int val = A[left-1];
        int res = left;
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(A[mid] < val){
                if(A[res] < A[mid]){
                    res = mid;
                }
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return res;
    }
};
​
```
