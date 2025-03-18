# Write your MySQL query statement below
WITH CTE AS(
    SELECT p.product_id, SUM(price*units) AS cost, SUM(units) AS unit FROM
    Prices p LEFT JOIN
    UnitsSold u ON
    u.product_id = p.product_id AND purchase_date BETWEEN start_date AND end_date
    GROUP BY p.product_id
)
SELECT product_id, COALESCE(ROUND(cost/unit, 2), 0) AS average_price FROM CTE 
GROUP BY product_id;