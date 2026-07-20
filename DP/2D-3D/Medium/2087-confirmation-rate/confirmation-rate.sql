select 
    s.user_id, 
    round(SUM(CASE WHEN c1.action = 'confirmed' THEN 1 ELSE 0 END) / count(s.user_id), 2) as confirmation_rate
from Signups s
left join Confirmations c1
on s.user_id = c1.user_id
group by s.user_id;
