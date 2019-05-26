---
tags: ["leetcode","depth-first search","union find"]
created: "26/05/2019, 17:08:53"
difficulty: "medium"
---

# [0547-friend-circles](https://leetcode.com/problems/friend-circles/)

## Problem
<div><p><br>There are <b>N</b> students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a <b>direct</b> friend of B, and B is a <b>direct</b> friend of C, then A is an <b>indirect</b> friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.<br></p><br><br><p><br>Given a <b>N*N</b> matrix <b>M</b> representing the friend relationship between students in the class. If M[i][j] = 1, then the i<sub>th</sub> and j<sub>th</sub> students are <b>direct</b> friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.<br></p><br><br><p><b>Example 1:</b><br><br></p><pre><b>Input:</b> <br>[[1,1,0],<br> [1,1,0],<br> [0,0,1]]<br><b>Output:</b> 2<br><b>Explanation:</b>The 0<sub>th</sub> and 1<sub>st</sub> students are direct friends, so they are in a friend circle. <br>The 2<sub>nd</sub> student himself is in a friend circle. So return 2.<br></pre><br><p></p><br><br><p><b>Example 2:</b><br><br></p><pre><b>Input:</b> <br>[[1,1,0],<br> [1,1,1],<br> [0,1,1]]<br><b>Output:</b> 1<br><b>Explanation:</b>The 0<sub>th</sub> and 1<sub>st</sub> students are direct friends, the 1<sub>st</sub> and 2<sub>nd</sub> students are direct friends, <br>so the 0<sub>th</sub> and 2<sub>nd</sub> students are indirect friends. All of them are in the same friend circle, so return 1.<br></pre><br><p></p><br><br><br><p><b>Note:</b><br><br></p><ol><br><li>N is in range [1,200].</li><br><li>M[i][i] = 1 for all students.</li><br><li>If M[i][j] = 1, then M[j][i] = 1.</li><br></ol><br><p></p></div>

## Solution

c++
```c++
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size() == 0) return 0;
        int row = M.size();
        int col = M[0].size();
        int counter = 0;
        vector<int> visited(row,0);
        stack<int> dfs;
        
        for(int i=0;i<row;i++){
            if(!visited[i]){
                dfs.push(i);
                counter++;
                
                while(!dfs.empty()){
                    int curr = dfs.top();
                    dfs.pop();
                    visited[curr] = 1;
                    
                    
                    for(int j=0;j<col;j++){
                        if(!visited[j] && M[curr][j])
                        {
                            dfs.push(j);
                        }
                    }
                    
                }
            }
        }
        return counter;
        
    }
};
​
```
