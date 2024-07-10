# Write your MySQL query statement below
Select 
    Project.project_id, 
    Round(Avg(Employee.experience_years), 2) as average_years
from
    Project left join Employee
on 
    Project.employee_id = Employee.employee_id 
group by 
    Project.project_id;