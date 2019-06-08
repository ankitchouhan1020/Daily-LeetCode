---
tags: ["leetcode"]
created: "08/06/2019, 11:10:24"
difficulty: "easy"
---

# [0183-customers-who-never-order](https://leetcode.com/problems/customers-who-never-order/)

## Problem
<div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__3Su4"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>Suppose that a website contains two tables, the <code>Customers</code> table and the <code>Orders</code> table. Write a SQL query to find all customers who never order anything.</p><br><br><p>Table: <code>Customers</code>.</p><br><br><pre>+----+-------+<br>| Id | Name  |<br>+----+-------+<br>| 1  | Joe   |<br>| 2  | Henry |<br>| 3  | Sam   |<br>| 4  | Max   |<br>+----+-------+<br></pre><br><br><p>Table: <code>Orders</code>.</p><br><br><pre>+----+------------+<br>| Id | CustomerId |<br>+----+------------+<br>| 1  | 3          |<br>| 2  | 1          |<br>+----+------------+<br></pre><br><br><p>Using the above tables as example, return the following:</p><br><br><pre>+-----------+<br>| Customers |<br>+-----------+<br>| Henry     |<br>| Max       |<br>+-----------+<br></pre><br></div>

## Solution

mysql
```mysql
select c.Name as Customers
from Customers c
where c.Id not in (select distinct CustomerId from Orders)
​
```
