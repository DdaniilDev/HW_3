#include "Student.h"
#include <stdexcept>
#include <utility>

Student::Student(Student &input) {
    name_and_surname_ = input.name_and_surname_;
    student_id_ = input.student_id_;
    group_id_ = input.group_id_;
}

std::string Student::getNameAndSurname() const {
    return name_and_surname_;
}

std::string Student::getStudentID() const {
    return student_id_;
}

int Student::getGroupId() const {
    return group_id_;
}

void Student::setAllParameters(std::string name_and_surname, std::string student_id, int group_id,
                               std::vector<int> marks) {
    name_and_surname_ = std::move(name_and_surname);
    student_id_ = std::move(student_id);
    if (group_id <= 0) {
        throw std::invalid_argument(
                "Error! Check group_id: it must be > 0!"); //исключение: значение группы должно быть больше 0
    } else {
        group_id_ = group_id;
    }
    std::copy(marks.begin(), marks.end(),marks_.begin());
}

void Student::getAllInfo() const {
    std::cout << "Student name and surname: " << name_and_surname_ << std::endl;
    std::cout << "Student identificator: " << student_id_ << std::endl;
    std::cout << "Student's group identificator: " << group_id_ << std::endl;
    std::cout << "Student's marks: ";
    for (const auto &mark : marks_) {
        std::cout << mark << " ";
    }
    std::cout << std::endl;
}

void Student::checkStudentStatus() const {
    if (!isExpelled_) {
        std::cout << "Expelled" << std::endl; //не отчислен
    } else {
        std::cout << "Not expelled" << std::endl; //отчислен
    }
}

double Student::averageMark() {
    int sum = 0;
    double result = 0;
    for (int i : marks_) {
        sum += i;
    }
    result = static_cast<double>(sum) / marks_.size();
    return result;
}

std::ostream& operator<<(std::ostream& out, Student const& obj) {
    out << obj.name_and_surname_ << std::endl;
    out << obj.student_id_ << std::endl;
    out << obj.group_id_ << std::endl;
    for (const auto &i: obj.marks_) {
        out << i << " ";
    }
    return out;
}

