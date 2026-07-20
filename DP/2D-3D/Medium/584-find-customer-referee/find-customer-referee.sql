# Write your MySQL query statement below
SELECT c.name
FROM Customer c
where c.referee_id != 2 OR c.referee_id is null;