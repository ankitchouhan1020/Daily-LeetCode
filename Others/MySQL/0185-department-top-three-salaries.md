---
tags: ["leetcode"]
created: "07/06/2019, 19:26:40"
difficulty: "hard"
---

# [0185-department-top-three-salaries](https://leetcode.com/problems/department-top-three-salaries/)

## Problem
<div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__3Su4"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>The <code>Employee</code> table holds all employees. Every employee has an Id, and there is also a column for the department Id.</p><br><br><pre>+----+-------+--------+--------------+<br>| Id | Name  | Salary | DepartmentId |<br>+----+-------+--------+--------------+<br>| 1  | Joe   | 85000  | 1            |<br>| 2  | Henry | 80000  | 2            |<br>| 3  | Sam   | 60000  | 2            |<br>| 4  | Max   | 90000  | 1            |<br>| 5  | Janet | 69000  | 1            |<br>| 6  | Randy | 85000  | 1            |<br>| 7  | Will  | 70000  | 1            |<br>+----+-------+--------+--------------+<br></pre><br><br><p>The <code>Department</code> table holds all departments of the company.</p><br><br><pre>+----+----------+<br>| Id | Name     |<br>+----+----------+<br>| 1  | IT       |<br>| 2  | Sales    |<br>+----+----------+<br></pre><br><br><p>Write a SQL query to find employees who earn the top three salaries in each of the department. For the above tables, your SQL query should return the following rows (order of rows does not matter).</p><br><br><pre>+------------+----------+--------+<br>| Department | Employee | Salary |<br>+------------+----------+--------+<br>| IT         | Max      | 90000  |<br>| IT         | Randy    | 85000  |<br>| IT         | Joe      | 85000  |<br>| IT         | Will     | 70000  |<br>| Sales      | Henry    | 80000  |<br>| Sales      | Sam      | 60000  |<br>+------------+----------+--------+<br></pre><br><br><p><strong>Explanation:</strong></p><br><br><p>In IT department, Max earns the highest salary, both Randy and Joe earn the second highest salary, and Will earns the third highest salary. There are only two employees in the Sales department, Henry earns the highest salary while Sam earns the second highest salary.</p><br></div>

## Solution

mysql
```mysql
select d.Name as Department,tmp.Name as Employee,tmp.Salary
from(
    Select Id, Name, Salary, DepartmentId,@count as Rank
    from (select * from Employee order by DepartmentId ASC,Salary DESC) as e,
        (select @prevd:=-1,@prevs:=-1,@count:=0) as r
    where 3 >= greatest(
        @count := greatest(
            if(@prevd <> @prevd:=e.DepartmentId,
            1,
            if(@prevs<> e.Salary,
            @count+1,
            @count)
            )
        ,least(0,@prevs:=e.Salary))
    ,0)
    ) as tmp
join Department d
    on tmp.DepartmentId = d.Id
​
​
```
