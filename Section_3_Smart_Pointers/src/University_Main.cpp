#include <memory>
#include <iostream>
#include <string>
#include "University_Types.h"

using namespace std;

int main() {
    // 创建一个计算机科学院系，使用make_shared创建智能指针
    auto cs_dept = make_shared<Department>("Computer Science");

    // 创建一个学生对象，同样使用智能指针管理
    auto student = make_shared<Student>("John Doe");

    // 设置学生所属的院系
    student->setDepartment(cs_dept);

    // 将学生添加到院系的学生列表中
    cs_dept->addStudent(student);

    // Example of deregistering a student
    cs_dept->deregisterStudent(student);

    return 0;
}