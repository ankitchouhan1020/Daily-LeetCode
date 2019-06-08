---
tags: ["leetcode"]
created: "06/06/2019, 23:28:13"
difficulty: "medium"
---

# [0177-nth-highest-salary](https://leetcode.com/problems/nth-highest-salary/)

## Problem
<div><p>Write a SQL query to get the <em>n</em><sup>th</sup> highest salary from the <code>Employee</code> table.</p><br><br><pre>+----+--------+<br>| Id | Salary |<br>+----+--------+<br>| 1  | 100    |<br>| 2  | 200    |<br>| 3  | 300    |<br>+----+--------+<br></pre><br><br><p>For example, given the above Employee table, the <em>n</em><sup>th</sup> highest salary where <em>n</em> = 2 is <code>200</code>. If there is no <em>n</em><sup>th</sup> highest salary, then the query should return <code>null</code>.</p><br><br><pre>+------------------------+<br>| getNthHighestSalary(2) |<br>+------------------------+<br>| 200                    |<br>+------------------------+<br></pre><br></div>

## Solution

mysql
```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M int;
set M = N-1;
  RETURN (
      # Write your MySQL query statement below.
      select ifnull ( (
        select Distinct Salary
        from Employee 
        order by Salary DESC
        limit M,1
        ),
    null)
  );
END
​
```
