# Write your MySQL query statement below
SELECT product_name, year, price FROM Sales s JOIN Product p USING(product_id);