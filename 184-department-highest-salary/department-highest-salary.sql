# Write your MySQL query statement below
WITH cte AS 
(SELECT d.name AS Department, e.name Employee, e.salary AS Salary, 
MAX(salary) OVER(PARTITION BY d.id ORDER BY salary DESC) AS maxi
FROM Department d JOIN Employee e ON d.id = e.departmentId)
SELECT Department, EMployee, Salary FROM cte WHERE salary = maxi;