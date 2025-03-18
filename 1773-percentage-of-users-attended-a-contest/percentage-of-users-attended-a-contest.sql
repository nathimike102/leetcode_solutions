# Write your MySQL query statement below
WITH CTE AS(
    SELECT *, COUNT(R.contest_id) AS other FROM
    Users U JOIN
    Register R
    USING(user_id)
    GROUP BY contest_id
    ORDER BY other DESC, contest_id
), CTE2 AS(
    SELECT COUNT(user_id) AS total FROM Users
)
SELECT contest_id, ROUND((other*100/total), 2)  AS percentage FROM CTE, CTE2;