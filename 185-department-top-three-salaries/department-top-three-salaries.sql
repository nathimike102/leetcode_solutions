# Write your MySQL query statement below
WITH cte AS
(SELECT d.name AS Department, e.name Employee, e.salary AS Salary,
DENSE_RANK() OVER(PARTITION BY d.id ORDER BY e.salary DESC) AS ranks
FROM Department d JOIN Employee e ON d.id = e.departmentId)
SELECT Department, EMployee, Salary FROM cte WHERE ranks < 4;