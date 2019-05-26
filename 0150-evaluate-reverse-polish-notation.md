---
tags: ["leetcode","stack"]
created: "26/05/2019, 16:47:00"
difficulty: "medium"
---

# [0150-evaluate-reverse-polish-notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

## Problem
<div><p>Evaluate the value of an arithmetic expression in <a href="http://en.wikipedia.org/wiki/Reverse_Polish_notation" target="_blank">Reverse Polish Notation</a>.</p><br><br><p>Valid operators are <code>+</code>, <code>-</code>, <code>*</code>, <code>/</code>. Each operand may be an integer or another expression.</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>Division between two integers should truncate toward zero.</li><br>	<li>The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't&nbsp;be any&nbsp;divide&nbsp;by zero operation.</li><br></ul><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> ["2", "1", "+", "3", "*"]<br><strong>Output:</strong> 9<br><strong>Explanation:</strong> ((2 + 1) * 3) = 9<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> ["4", "13", "5", "/", "+"]<br><strong>Output:</strong> 6<br><strong>Explanation:</strong> (4 + (13 / 5)) = 6<br></pre><br><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input:</strong> ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]<br><strong>Output:</strong> 22<br><strong>Explanation:</strong> <br>  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5<br>= ((10 * (6 / (12 * -11))) + 17) + 5<br>= ((10 * (6 / -132)) + 17) + 5<br>= ((10 * 0) + 17) + 5<br>= (0 + 17) + 5<br>= 17 + 5<br>= 22<br></pre><br></div>

## Solution

c++
```c++
// Solve prefix expression
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> todo;
        for(string x:tokens){
            char ch = x[0];
            if(x.size()==1 && (ch == '+' || ch == '-' || ch == '*' || ch == '/')){
                int op2 = todo.top();
                todo.pop();
                int op1 = todo.top();
                todo.pop();
                if(ch=='+') todo.push(op1+op2);
                else if(ch=='-') todo.push(op1-op2);
                else if(ch=='*') todo.push(op1*op2);
                else todo.push(op1/op2);
            }
            else{
                todo.push(stoi(x));
            }            
        }
        return todo.top();
    }
};
​
```
