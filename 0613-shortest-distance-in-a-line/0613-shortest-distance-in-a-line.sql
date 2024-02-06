# Write your MySQL query statement below
# SELECT MIN(ABS(`p1`.`x`-`p2`.`x`)) AS `shortest`
# FROM `Point` `p1`, `Point` `p2`
# WHERE `p1`.`x` != `p2`.`x`;

WITH `distances` AS (
    SELECT ABS(`x` - LEAD(`x`) OVER (ORDER BY `x` ASC)) AS `distance`
    FROM `Point`
)

SELECT MIN(`distance`) AS `shortest` FROM `distances`;