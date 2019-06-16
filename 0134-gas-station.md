---
tags: ["leetcode","greedy"]
created: "15/06/2019, 18:45:35"
difficulty: "medium"
---

# [0134-gas-station](https://leetcode.com/problems/gas-station/)

## Problem
<div><p>There are <em>N</em> gas stations along a circular route, where the amount of gas at station <em>i</em> is <code>gas[i]</code>.</p><br><br><p>You have a car with an unlimited gas tank and it costs <code>cost[i]</code> of gas to travel from station <em>i</em> to its next station (<em>i</em>+1). You begin the journey with an empty tank at one of the gas stations.</p><br><br><p>Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>If there exists a&nbsp;solution, it is guaranteed to be unique.</li><br>	<li>Both input arrays are non-empty and have the same length.</li><br>	<li>Each element in the input arrays is a non-negative integer.</li><br></ul><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> <br>gas  = [1,2,3,4,5]<br>cost = [3,4,5,1,2]<br><br><strong>Output:</strong> 3<br><br><strong>Explanation:<br></strong>Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4<br>Travel to station 4. Your tank = 4 - 1 + 5 = 8<br>Travel to station 0. Your tank = 8 - 2 + 1 = 7<br>Travel to station 1. Your tank = 7 - 3 + 2 = 6<br>Travel to station 2. Your tank = 6 - 4 + 3 = 5<br>Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.<br>Therefore, return 3 as the starting index.<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> <br>gas  = [2,3,4]<br>cost = [3,4,3]<br><br><strong>Output:</strong> -1<br><br><strong>Explanation:<br></strong>You can't start at station 0 or 1, as there is not enough gas to travel to the next station.<br>Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4<br>Travel to station 0. Your tank = 4 - 3 + 2 = 3<br>Travel to station 1. Your tank = 3 - 3 + 3 = 3<br>You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.<br>Therefore, you can't travel around the circuit once no matter where you start.<br></pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total(0),idx(0),tank(0);
        for(int i=0;i<n;i++){
            tank += gas[i]-cost[i];
            
            /*
                If at any time tank < 0 means we if we start with idx and no previous gas,
                we cannot complete the route.
                Only way is to start with a new idx and to try to get some previous gas.
            */
            
            if(tank < 0){
                total+=tank;
                tank=0;
                idx=i+1;
            }
        }
        total += tank;
        return total<0 ? -1 : idx%n;
    }
};
​
```
