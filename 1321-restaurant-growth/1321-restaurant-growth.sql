/* Write your T-SQL query statement below */
WITH amount_per_visit_date AS (
    SELECT 
        visited_on, 
        SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
)
SELECT 
    visited_on, 
    SUM(amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount, 
    ROUND(AVG(amount * 1.00) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW), 2) AS average_amount
FROM amount_per_visit_date
ORDER BY visited_on
OFFSET 6 ROWS;