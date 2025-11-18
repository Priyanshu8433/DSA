# Write your MySQL query statement below
SELECT max(salary) as SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT max(salary) FROM Employee);