# Write your MySQL query statement below
SELECT `customer_number`
FROM `Orders`
GROUP BY `customer_number`
HAVING COUNT(`order_number`) = (
    SELECT MAX(`count`) FROM (
        SELECT `customer_number`, COUNT('order_number') AS `count` 
        FROM `Orders`
        GROUP BY `customer_number`
    ) AS `temp`
);