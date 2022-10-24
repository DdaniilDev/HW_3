#include <stdexcept>
#include <utility>
#include "Group.h"

Group::Group(Group &input) {
    std::copy(input.all_group_.begin(), input.all_group_.end(), all_group_.begin());
}

void Group::getStudentsNumber() {
    std::cout << "There are " << all_group_.size() << "students in this group" << std::endl;
}

void Group::addNewStudent(Student new_student) {
    all_group_.push_back(new_student);
}
