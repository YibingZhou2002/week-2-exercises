// 包含必要的头文件
#include <memory>    // 为了使用智能指针
#include <iostream>  // 为了使用输入输出流
#include <string>    // 为了使用字符串
#include <vector>    // 为了使用动态数组

using namespace std;

// Forward declaration of Department class.
// This is needed to let the compiler know that a type called
// Department will be defined in the code when it compiles the 
// Student class, as the Department class is defined afterwards.
// You can have a pointer to a forward declared class because a 
// pointer is just an address in memory, so the compiler doens't
// need to know anything the data Department contains to work
// out the data layout for Student. 
class Department;

class Student {
    public:
    // 构造函数：创建新学生时设置其姓名
    Student(const std::string &n);
    // 析构函数：学生对象被销毁时调用
    ~Student();
    // 获取学生ID的方法
    int getId() const;
    // 设置学生所属院系，使用shared_ptr避免内存泄露
    void setDepartment(shared_ptr<Department> dept);
    // 获取学生所属院系，使用weak_ptr避免循环引用
    weak_ptr<Department> getDepartment() const;
    // 新方法：清除院系关联
    void clearDepartment();

    private:
    static int max_id;     // 静态变量，用于生成唯一学生ID
    string name;           // 学生姓名
    int id;               // 学生ID
    weak_ptr<Department> department;  // 使用weak_ptr指向所属院系，防止循环引用
};

class Department {
    public:
    // 构造函数：创建新院系时设置其名称
    Department(const std::string &n);
    // 析构函数：院系对象被销毁时调用
    ~Department();
    // 添加学生到院系
    void addStudent(shared_ptr<Student> student);
    // 获取院系所有学生列表
    const vector<shared_ptr<Student>>& getStudents() const;
    // 新方法：移除学生
    void deregisterStudent(shared_ptr<Student> student);

    private:
    string name;    // 院系名称
    vector<shared_ptr<Student>> students;  // 存储该院系的所有学生的智能指针
};