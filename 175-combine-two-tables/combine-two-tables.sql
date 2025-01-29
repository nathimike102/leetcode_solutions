# Write your MySQL query statement below
SELECT firstname, lastname, city, state FROM Person p LEFT JOIN Address a ON p.personid = a.personid;