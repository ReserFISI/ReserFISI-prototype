#ifndef STUDENTS_CONTROLLER_H
#define STUDENTS_CONTROLLER_H

#include "crow.h"

void getStudents(crow::response& res);
void createStudent(const crow::request& req, crow::response& res);
void updateStudent(const crow::request& req, crow::response& res);
void deleteStudent(const crow::request& req, crow::response& res);
void getStudentById(int id, crow::response& res);

#endif 
