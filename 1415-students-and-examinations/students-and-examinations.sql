# Write your MySQL query statement below
SELECT S.student_id, S.student_name, SS.subject_name, COUNT(E.subject_name) AS attended_exams FROM
Students S CROSS JOIN Subjects SS
LEFT JOIN Examinations E ON S.student_id = E.student_id AND SS.subject_name = E.subject_name
GROUP BY S.student_id, S.student_name, SS.subject_name
ORDER BY S.student_id, SS.subject_name;