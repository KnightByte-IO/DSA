# Write your MySQL query statement below
select 
    DATE_FORMAT(trans_date, '%Y-%m')
    AS month,
    country, 
    count(trans_date) as trans_count,
    sum(case when state = 'approved' then 1 else 0 end) as approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(CASE WHEN state='approved' THEN amount ELSE 0 END) AS approved_total_amount 
from Transactions 
group by DATE_FORMAT(trans_date, '%Y-%m'), country;