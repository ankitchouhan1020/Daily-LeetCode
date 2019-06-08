---
tags: ["leetcode"]
created: "07/06/2019, 01:28:30"
difficulty: "medium"
---

# [0178-rank-scores](https://leetcode.com/problems/rank-scores/)

## Problem
<div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__3Su4"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>Write a SQL query to rank scores. If there is a tie between two scores, both should have the same ranking. Note that after a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no "holes" between ranks.</p><br><br><pre>+----+-------+<br>| Id | Score |<br>+----+-------+<br>| 1  | 3.50  |<br>| 2  | 3.65  |<br>| 3  | 4.00  |<br>| 4  | 3.85  |<br>| 5  | 4.00  |<br>| 6  | 3.65  |<br>+----+-------+<br></pre><br><br><p>For example, given the above <code>Scores</code> table, your query should generate the following report (order by highest score):</p><br><br><pre>+-------+------+<br>| Score | Rank |<br>+-------+------+<br>| 4.00  | 1    |<br>| 4.00  | 1    |<br>| 3.85  | 2    |<br>|&nbsp;3.65  | 3    |<br>| 3.65  | 3    |<br>| 3.50  | 4    |<br>+-------+------+<br></pre><br></div>

## Solution

mysql
```mysql
select 
    Score,
    @crank := cast(@crank + (@prev != (@prev:=Score)) as signed) Rank
from Scores,
    (select @crank := 0, @prev:=-1) r
order by Score DESC
​
```
