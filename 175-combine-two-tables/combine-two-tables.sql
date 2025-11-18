# Write your MySQL query statement below
SELECT P.firstName, P.lastName, A.State, A.City
From Person P LEFT JOIN Address A
ON P.personId = A.personId;