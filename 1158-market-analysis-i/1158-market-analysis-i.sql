# Write your MySQL query statement below
SELECT `user_id` AS `buyer_id`, `join_date`, COUNT(`Orders`.`order_id`) AS `orders_in_2019` 
FROM `Users`
LEFT JOIN `Orders`
ON `Users`.`user_id` = `Orders`.`buyer_id` AND YEAR(`Orders`.`order_date`) = '2019'
GROUP BY `user_id`;