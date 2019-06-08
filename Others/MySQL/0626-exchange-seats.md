---
tags: ["leetcode"]
created: "07/06/2019, 13:20:53"
difficulty: "medium"
---

# [0626-exchange-seats](https://leetcode.com/problems/exchange-seats/)

## Problem
<div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__3Su4"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>Mary is a teacher in a middle school and she has a table <code>seat</code> storing students' names and their corresponding seat ids.</p><br>The column <b>id</b> is continuous increment.<br><br><p>&nbsp;</p><br>Mary wants to change seats for the adjacent students.<br><br><p>&nbsp;</p><br>Can you write a SQL query to output the result for Mary?<br><br><p>&nbsp;</p><br><br><pre>+---------+---------+<br>|    id   | student |<br>+---------+---------+<br>|    1    | Abbot   |<br>|    2    | Doris   |<br>|    3    | Emerson |<br>|    4    | Green   |<br>|    5    | Jeames  |<br>+---------+---------+<br></pre><br>For the sample input, the output is:<br><br><p>&nbsp;</p><br><br><pre>+---------+---------+<br>|    id   | student |<br>+---------+---------+<br>|    1    | Doris   |<br>|    2    | Abbot   |<br>|    3    | Green   |<br>|    4    | Emerson |<br>|    5    | Jeames  |<br>+---------+---------+<br></pre><br><br><p><b>Note:</b><br><br>If the number of students is odd, there is no need to change the last one's seat.</p><br></div>

## Solution

mysql
```mysql
-- 1st
​
select s.id,t.student
from seat s
cross join seat t
where 
    (s.id%2=1 and s.id+1=t.id)
    or (s.id%2=0 and s.id-1=t.id)
    or (s.id%2!=0 and s.id=(select max(id) from seat) and t.id=s.id)
order by s.id
​
​
-- 2nd
select 
    if(
        id%2 != 0,
        if(
            id != (select max(id) from seat),
            id+1,
            id
        ),
        id-1
    ) as id,student
from
    seat
order by id
​
```
