# Write your MySQL query statement below
SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years FROM Employee e JOIN Project USING(employee_id) GROUP BY project_id;