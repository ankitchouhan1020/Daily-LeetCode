---
tags: ["leetcode"]
created: "07/06/2019, 23:20:23"
difficulty: "hard"
---

# [0601-human-traffic-of-stadium](https://leetcode.com/problems/human-traffic-of-stadium/)

## Problem
<div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__3Su4"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>X city built a new stadium, each day many people visit it and the stats are saved as these columns: <b>id</b>, <strong>visit_</strong><b>date</b>, <b>people</b></p><br><br><p>Please write a query to display the records which have 3 or more consecutive rows and the amount of people more than 100(inclusive).</p><br>For example, the table <code>stadium</code>:<br><br><pre>+------+------------+-----------+<br>| id   | visit_date | people    |<br>+------+------------+-----------+<br>| 1    | 2017-01-01 | 10        |<br>| 2    | 2017-01-02 | 109       |<br>| 3    | 2017-01-03 | 150       |<br>| 4    | 2017-01-04 | 99        |<br>| 5    | 2017-01-05 | 145       |<br>| 6    | 2017-01-06 | 1455      |<br>| 7    | 2017-01-07 | 199       |<br>| 8    | 2017-01-08 | 188       |<br>+------+------------+-----------+<br></pre><br><br><p>For the sample data above, the output is:</p><br><br><pre>+------+------------+-----------+<br>| id   | visit_date | people    |<br>+------+------------+-----------+<br>| 5    | 2017-01-05 | 145       |<br>| 6    | 2017-01-06 | 1455      |<br>| 7    | 2017-01-07 | 199       |<br>| 8    | 2017-01-08 | 188       |<br>+------+------------+-----------+<br></pre><br><br><p><b>Note:</b><br><br>Each day only have one row record, and the dates are increasing with id increasing.</p><br></div>

## Solution

mysql
```mysql
select distinct s.id, s.visit_date, s.people
from stadium s, stadium t, stadium u
where (
        (s.id+1 = t.id and s.id+2 = u.id)
    or  (s.id+1 = t.id and s.id-1 = u.id)
    or  (s.id-1 = t.id and s.id-2 = u.id)
    )
    and (s.people > 99 and t.people >99 and u.people > 99)
order by s.id
​
# SELECT 
#     id, date, people
# FROM
#     (
#     SELECT 
#         id, date, people,
#         CASE
#         WHEN consecutive >= 3 THEN @pending := 3
#         ELSE @pending := @pending - 1
#         END AS tmp,
#         IF(@pending > 0, 1, 0) AS include
#     FROM  
#         (
#         SELECT 
#             id, date, people,
#             CASE 
#             WHEN people >= 100 THEN @count := @count + 1
#             ELSE @count := 0
#             END AS consecutive
#         FROM
#             stadium, (SELECT @count := 0) init1
#         ) tmp, (SELECT @pending := 0) init2
#     ORDER BY 1 DESC
#     ) otmp
# WHERE 
#     include = 1
# ORDER BY 1;
​
```
