---
tags: ["leetcode","divide and conquer"]
created: "01/06/2019, 22:43:52"
difficulty: "medium"
---

# [0241-different-ways-to-add-parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/)

## Problem
<div><p>Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are <code>+</code>, <code>-</code> and <code>*</code>.</p><br><br><p><b>Example 1:</b></p><br><br><pre><b>Input:</b> <code>"2-1-1"</code><br><b>Output:</b> <code>[0, 2]</code><br><strong>Explanation: </strong><br>((2-1)-1) = 0 <br>(2-(1-1)) = 2</pre><br><br><p><b>Example 2:</b></p><br><br><pre><b>Input: </b><code>"2*3-4*5"</code><br><b>Output:</b> <code>[-34, -14, -10, -10, 10]</code><br><strong>Explanation: <br></strong>(2*(3-(4*5))) = -34 <br>((2*3)-(4*5)) = -14 <br>((2*(3-4))*5) = -10 <br>(2*((3-4)*5)) = -10 <br>(((2*3)-4)*5) = 10<strong><br></strong></pre></div>

## Solution

c++
```c++

class Solution {
    
public:
    vector<int> res;
    vector<int> diffWaysToCompute(string input) {
        int n = input.size();
        for (int k = 0; k < input.size(); ++k)
        {
            if(input[k] == '+' || input[k]=='*' || input[k]=='-'){
                vector<int> x = solve(input,0,k-1);
                vector<int> y = solve(input,k+1,n-1);
                for(int i : x){
                    for(int j :y){
                        switch(input[k]){
                            case '+': res.push_back(i+j);
                                break;
                            case '-': res.push_back(i-j);
                                break;
                            case '*': res.push_back(i*j);
                        }
                    }
                }
                
            }
        }
        
        if(res.empty()) res.push_back(stoi(input));
        return res;
    }
​
    std::vector<int> solve(string input, int start,int end){
        std::vector<int> subset;
        if(start < 0 || end >= input.size()) return subset;
​
        for (int k = start; k <=end; ++k)
        {
            if(input[k] == '+' || input[k]=='*' || input[k]=='-'){
                std::vector<int> x = solve(input,start,k-1);
                std::vector<int> y = solve(input,k+1,end);
​
```
