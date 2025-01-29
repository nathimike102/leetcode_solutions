# Write your MySQL query statement below
SELECT name, bonus FROM Employee e LEFT JOIN Bonus b USING(empID) WHERE bonus < 1000 OR bonus IS NULL;