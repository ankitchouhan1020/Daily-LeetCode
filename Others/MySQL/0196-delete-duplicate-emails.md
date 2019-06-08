---
tags: ["leetcode"]
created: "08/06/2019, 11:10:05"
difficulty: "easy"
---

# [0196-delete-duplicate-emails](https://leetcode.com/problems/delete-duplicate-emails/)

## Problem
<div><p>Write a SQL query to <strong>delete</strong> all duplicate email entries in a table named <code>Person</code>, keeping only unique emails based on its <i>smallest</i> <b>Id</b>.</p><br><br><pre>+----+------------------+<br>| Id | Email            |<br>+----+------------------+<br>| 1  | john@example.com |<br>| 2  | bob@example.com  |<br>| 3  | john@example.com |<br>+----+------------------+<br>Id is the primary key column for this table.<br></pre><br><br><p>For example, after running your query, the above <code>Person</code> table should have the following rows:</p><br><br><pre>+----+------------------+<br>| Id | Email            |<br>+----+------------------+<br>| 1  | john@example.com |<br>| 2  | bob@example.com  |<br>+----+------------------+<br></pre><br><br><p><strong>Note:</strong></p><br><br><p>Your output is the whole <code>Person</code>&nbsp;table after executing your sql. Use <code>delete</code> statement.</p><br></div>

## Solution

mysql
```mysql
delete p from Person p
    join Person q
    on p.Id > q.Id and p.Email = q.Email
​
```
