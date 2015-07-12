
#ifndef HEADER_GUARD_HPP
#define HEADER_GUARD_HPP

#import <iostream>
#import <string>
#import "MyObject.hpp"

#define COMPARE(x,y) (((x) > (y)) ? 1 : ((x) == (y)) ? 0 : -1)

typedef struct PersonalInfo {
    int age;
    std::string name;
} PersonalInfo;

enum class EmployeeType {
    HOURLY, SALARY, TEMP
};

template <typename T>
inline T const & maximum(T const & a, T const & b) {
    return a < b ? b : a;
}

namespace Zooce {
    class Employee {
    public:
        Employee(unsigned int a_id, PersonalInfo a_pInfo, EmployeeType a_type);
        ~Employee();

        // CLASS VARIABLES
        static int s_idNums = 0;

        // GETTERS
        inline int age() { return m_info->age; }
        inline std::string name() { return m_info->name; }
        inline unsigned int id() { return m_id; }
        EmployeeType type() { return m_eType; }

        void print();

    private:
        PersonalInfo * m_info;
        EmployeeType m_eType;
        unsigned int m_id;
    }

    Employee::Employee(unsigned int a_id, PersonalInfo a_pInfo, EmployeeType a_type) {
        m_id = Employee::s_idNums++;
        m_info = new PersonalInfo;
        m_info->age = a_pInfo.age;
        m_info->name = a_pInfo.name;
        m_eType = a_type;
    }

    Employee::~Employee() {
        delete m_info;
        m_info = NULL;
    }

    void Employee::print() {
        std::cout << "Name: " << m_info->name << std::endl;
        std::cout << "Age: " << m_info->age << std::endl;
        switch (m_eType) {
            case EmployeeType::HOURLY:
                std::cout << "Type: Hourly" << std::endl; break;
            case EmployeeType::SALARY:
                std::cout << "Type: Salary" << std::endl; break;
            case EmployeeType::TEMP:
                std::cout << "Type: Temp" << std::endl; break;
        }
        std::cout << "Id: " << m_id << std::endl;
    }
}

int main(int argc, char const *argv[]) {

    int age(32);
    std::string name = "Dave";
    PersonalInfo info = { age, name };
    Employee * newEmployee = new Employee(123, info, EmployeeType::HOURLY);
    newEmployee->print();
    delete newEmployee;

    return 0;
}

#endif // HEADER_GUARD_HPP
