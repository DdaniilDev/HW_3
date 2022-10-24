#include <iostream>
#include <string>
#include <utility>
#include <vector>

#ifndef DZ3_23_STUDENT_H
#define DZ3_23_STUDENT_H

class Student {
public:
    Student() = default; //студент без информации
    explicit Student(std::string name_and_surname) : name_and_surname_(std::move(name_and_surname)) {};

    Student(std::string name_and_surname, std::string student_id) : name_and_surname_(std::move(name_and_surname)),
                                                                    student_id_(std::move(student_id)) {};

    Student(std::string name_and_surname, std::string student_id, int group_id, std::vector<int> marks,
            bool isExpelled)
            : name_and_surname_(std::move(name_and_surname)),
              student_id_(std::move(student_id)),
              group_id_(group_id),
              isExpelled_(isExpelled) {
        marks_.resize(marks.size());
        for (size_t i = 0; i < marks_.size(); ++i) {
            marks_[i] = marks[i];
        }
    };

    Student(Student &input);

    std::string getNameAndSurname() const;

    std::string getStudentID() const;

    int getGroupId() const;

    void getAllInfo() const;

    void setAllParameters(std::string name_and_surname, std::string student_id, int group_id,
                     std::vector<int> marks);

    void checkStudentStatus() const; //проверка статуса студента: отчислен или нет

    double averageMark();

    friend std::ostream& operator<<(std::ostream& out, Student const& obj);

    ~Student() = default;

private:
    std::string name_and_surname_; //имя и фамилия студента
    std::string student_id_; //id студента, с использованием символов и цифр
    int group_id_ = 0; //номер группы
    bool isExpelled_ = false; //статус обучения: отчислен студент или нет
    std::vector<int> marks_;
};


#endif //DZ3_23_STUDENT_H
