# Write your MySQL query statement below
SELECT c.name AS Customers FROM CustomerS c LEFT JOIN Orders o on c.id = o.customerId WHERE o.id IS NULL;