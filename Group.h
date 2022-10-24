#include <iostream>
#include <string>
#include <list>
#include "Student.h"

#ifndef DZ3_23_GROUP_H
#define DZ3_23_GROUP_H

class Group {
public:
    Group() = default;
    explicit Group(std::list<Student> all_group) {
        std::copy(all_group.begin(), all_group.end(), all_group_.begin());
    }

    Group(Group &input);
    void getStudentsNumber(); //количество студентов в группе
    void getExcellentStudentsNumber(); //количество отличников
    void getDebtorsStudentsNumber(); //количество задолжников
    void addNewStudent(Student new_student); //добавление студента в конец списка




    ~Group() = default;

private:
    std::list<Student> all_group_;
    std::list<Student> excellent_students_; //список отличников
    std::list<Student> debtors_students_; //список задолжников
};

#endif //DZ3_23_GROUP_H
