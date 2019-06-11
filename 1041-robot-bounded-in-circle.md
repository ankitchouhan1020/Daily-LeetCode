---
tags: ["leetcode","math"]
created: "11/06/2019, 15:13:28"
difficulty: "easy"
---

# [1041-robot-bounded-in-circle](https://leetcode.com/problems/robot-bounded-in-circle/)

## Problem
<div><p>On an infinite plane, a&nbsp;robot initially stands at <code>(0, 0)</code> and faces north.&nbsp;&nbsp;The robot can receive one of three instructions:</p><br><br><ul><br>	<li><code>"G"</code>: go straight 1 unit;</li><br>	<li><code>"L"</code>: turn 90 degrees to the left;</li><br>	<li><code>"R"</code>: turn 90 degress to the right.</li><br></ul><br><br><p>The robot performs the <code>instructions</code> given in order, and repeats them forever.</p><br><br><p>Return <code>true</code> if and only if there exists a circle in the plane such that the robot never leaves the circle.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>"GGLLGG"<br><strong>Output: </strong>true<br><strong>Explanation: </strong><br>The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).<br>When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>"GG"<br><strong>Output: </strong>false<br><strong>Explanation: </strong><br>The robot moves north indefinitely.<br></pre><br><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong>"GL"<br><strong>Output: </strong>true<br><strong>Explanation: </strong><br>The robot moves from (0, 0) -&gt; (0, 1) -&gt; (-1, 1) -&gt; (-1, 0) -&gt; (0, 0) -&gt; ...<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= instructions.length &lt;= 100</code></li><br>	<li><code>instructions[i]</code> is in <code>{'G', 'L', 'R'}</code></li><br></ol><br></div>

## Solution

c++
```c++
class Solution {
public:
    bool isRobotBounded(string s) {
        if(s.empty()) return true;
        pair<int,int> dir[] = {{1,0},{0,1},{-1,0},{0,-1}};
        int i=1;
        int x=0,y=0;
        
        for(char ch: s){
            if(ch == 'L'){
                i = (i+1)%4;
            }else if(ch == 'R'){
                i = (((i-1)%4)+4)%4;
            }
            else{
                x+=dir[i].first;
                y+=dir[i].second;
            }
           
        }
        //either robot should be on its initial pos or anywhere it is its direction should not be same
        //If it has same direction then it will keep moving in similar direction
        //Else if will any way complete a circle
        if(x==0 && y==0 || i!=1) return true;
        return false;
    }
};
​
```
