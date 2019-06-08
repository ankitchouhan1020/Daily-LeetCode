---
tags: ["leetcode"]
created: "07/06/2019, 00:03:19"
difficulty: "medium"
---

# [0184-department-highest-salary](https://leetcode.com/problems/department-highest-salary/)

## Problem
<div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__3Su4"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>The <code>Employee</code> table holds all employees. Every employee has an Id, a salary, and there is also a column for the department Id.</p><br><br><pre>+----+-------+--------+--------------+<br>| Id | Name  | Salary | DepartmentId |<br>+----+-------+--------+--------------+<br>| 1  | Joe   | 70000  | 1            |<br>| 2 &nbsp;| Jim &nbsp; | 90000 &nbsp;| 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|<br>| 3  | Henry | 80000  | 2            |<br>| 4  | Sam   | 60000  | 2            |<br>| 5  | Max   | 90000  | 1            |<br>+----+-------+--------+--------------+<br></pre><br><br><p>The <code>Department</code> table holds all departments of the company.</p><br><br><pre>+----+----------+<br>| Id | Name     |<br>+----+----------+<br>| 1  | IT       |<br>| 2  | Sales    |<br>+----+----------+<br></pre><br><br><p>Write a SQL query to find employees who have the highest salary in each of the departments.&nbsp;For the above tables, your SQL query should return the following rows (order of rows does not matter).</p><br><br><pre>+------------+----------+--------+<br>| Department | Employee | Salary |<br>+------------+----------+--------+<br>| IT         | Max      | 90000  |<br>| IT &nbsp; &nbsp; &nbsp; &nbsp; | Jim &nbsp; &nbsp; &nbsp;| 90000 &nbsp;|<br>| Sales      | Henry    | 80000  |<br>+------------+----------+--------+<br></pre><br><br><p><strong>Explanation:</strong></p><br><br><p>Max and Jim both have&nbsp;the highest salary in the IT department and Henry has the highest salary in the Sales department.</p><br></div>

## Solution

mysql
```mysql
# select d.Name as Department, e.Name as Employee,e.Salary as Salary
# from Employee e
# join Department d
#     on e.DepartmentId = d.Id
# where e.Salary = ( select max(f.Salary) from Employee as f where e.DepartmentId = f.DepartmentId );
​
select d.Name as Department, e.Name as Employee,e.Salary as Salary
from Employee e,
    (select DepartmentId,max(Salary) as max from Employee group by DepartmentId) t,
    Department d
where e.DepartmentId = d.Id
    and e.Salary =  t.max
    and e.DepartmentId = t.DepartmentId;
​
```
