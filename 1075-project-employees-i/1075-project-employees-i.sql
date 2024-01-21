# Write your MySQL query statement below
SELECT `temp`.`project_id`, ROUND(AVG(`experience_years`), 2) AS `average_years`
FROM (
    SELECT `project_id`, `Project`.`employee_id`, `Employee`.`experience_years`
    FROM `Project`
    LEFT JOIN `Employee`
    ON `Project`.`employee_id` = `Employee`.`employee_id`
) AS `temp`
GROUP BY `temp`.`project_id`;

