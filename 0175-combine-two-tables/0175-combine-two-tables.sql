# Write your MySQL query statement below
Select
person.firstname,
person.lastname,
address.city,
address.state
FROM person
Left join address
on person.personid = address.personid;