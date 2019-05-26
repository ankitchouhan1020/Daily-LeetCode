---
tags: ["leetcode","depth-first search","graph"]
created: "26/05/2019, 17:16:06"
difficulty: "medium"
---

# [0841-keys-and-rooms](https://leetcode.com/problems/keys-and-rooms/)

## Problem
<div><p>There are <code>N</code> rooms and you start in room <code>0</code>.&nbsp; Each room has a distinct number in <code>0, 1, 2, ..., N-1</code>, and each room may have&nbsp;some keys to access the next room.&nbsp;</p><br><br><p>Formally, each room <code>i</code>&nbsp;has a list of keys <code>rooms[i]</code>, and each key <code>rooms[i][j]</code> is an integer in <code>[0, 1, ..., N-1]</code> where <code>N = rooms.length</code>.&nbsp; A key <code>rooms[i][j] = v</code>&nbsp;opens the room with number <code>v</code>.</p><br><br><p>Initially, all the rooms start locked (except for room <code>0</code>).&nbsp;</p><br><br><p>You can walk back and forth between rooms freely.</p><br><br><p>Return <code>true</code>&nbsp;if and only if you can enter&nbsp;every room.</p><br><br><ol><br></ol><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>[[1],[2],[3],[]]<br><strong>Output: </strong>true<br><strong>Explanation:  </strong><br>We start in room 0, and pick up key 1.<br>We then go to room 1, and pick up key 2.<br>We then go to room 2, and pick up key 3.<br>We then go to room 3.  Since we were able to go to every room, we return true.<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>[[1,3],[3,0,1],[2],[0]]<br><strong>Output: </strong>false<br><strong>Explanation: </strong>We can't enter the room with number 2.<br></pre><br><br><p><b>Note:</b></p><br><br><ol><br>	<li><code>1 &lt;= rooms.length &lt;=&nbsp;1000</code></li><br>	<li><code>0 &lt;= rooms[i].length &lt;= 1000</code></li><br>	<li>The number of keys in all rooms combined is at most&nbsp;<code>3000</code>.</li><br></ol><br></div>

## Solution

c++
```c++
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(),0);
        visited[0] = 1;
        return dfsVisit(rooms,visited,0);
    }
    
    bool dfsVisit(vector<vector<int>>& rooms,vector<int> &visited,int inRoom){
        for(int i=0;i<rooms[inRoom].size();i++){
            if(visited [rooms[inRoom][i]] || rooms[inRoom][i]==inRoom) continue;
            visited [rooms[inRoom][i]] = 1;
            if(dfsVisit(rooms,visited,rooms[inRoom][i])){
                return true;
            }
        }
        return isAllVisited(visited);
    }
    
    
    
    bool isAllVisited(vector<int> & visited){
        for(int x: visited)
            if(!x) return false;
        return true;
    }
};
​
```
