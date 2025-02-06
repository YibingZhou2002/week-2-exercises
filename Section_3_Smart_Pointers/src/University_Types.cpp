// 包含必要的头文件
#include <memory>    // 智能指针的头文件
#include <iostream>  // 输入输出流的头文件
#include <string>    // 字符串类的头文件
#include <algorithm> // 算法库的头文件
#include "University_Types.h"  // 包含类的声明头文件

using namespace std;  // 使用标准命名空间

// 学生构造函数：初始化学生姓名，并分配唯一ID
Student::Student(const std::string &n) : name(n), id(max_id++) {}

// 学生析构函数：当学生对象被销毁时打印信息
Student::~Student()
{
    cout << "Student " << name << " destroyed." << endl;
}

// 获取学生ID的方法，const表示这个方法不会修改对象的状态
int Student::getId() const
{
    return id;
}

// 设置学生所属院系的方法
void Student::setDepartment(shared_ptr<Department> dept) {
    // 使用weak_ptr存储院系指针，避免循环引用问题
    department = dept;  // weak_ptr可以直接从shared_ptr构造
}

// 获取学生所属院系的方法
weak_ptr<Department> Student::getDepartment() const {
    return department;
}

// 清除学生所属院系的方法
void Student::clearDepartment() {
    department.reset();  // Clear the weak_ptr to department
}

// 初始化静态成员变量max_id
// 这个变量在所有Student对象间共享，用于生成唯一ID
int Student::max_id = 0;

// 院系构造函数：初始化院系名称
Department::Department(const std::string &n) : name(n) {}

// 院系析构函数：当院系对象被销毁时打印信息
Department::~Department()
{
    cout << "Department " << name << " destroyed." << endl;
}

// 添加学生到院系的方法
void Department::addStudent(shared_ptr<Student> student) {
    // 将学生智能指针添加到院系的学生列表中
    students.push_back(student);
}

// 注销学生的方法
void Department::deregisterStudent(shared_ptr<Student> student) {
    // Find and remove the student from the vector
    students.erase(
        remove_if(students.begin(), students.end(),
            [&student](const shared_ptr<Student>& s) {
                return s->getId() == student->getId();
            }),
        students.end()
    );
    student->clearDepartment();  // Clear the student's department reference
}

// 获取院系所有学生的方法
// 返回常量引用以避免复制，同时保护内部数据不被修改
const vector<shared_ptr<Student>>& Department::getStudents() const {
    return students;
}