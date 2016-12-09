
#ifndef HEADER_GUARD_HPP
#define HEADER_GUARD_HPP

#import <iostream>
#import <string>
#import "MyObject.hpp"

/**
    These are our macros!!!
    They are so freaking cool dude :)
*/
#define COMPARE(x,y) (((x) > (y)) ? 1 : ((x) == (y)) ? 0 : -1)
#define CHECK(string) \
    std::cout << string;

template <typename T>
inline T const & maximum(T const & a, T const & b) {
    return a < b ? b : a;
}

namespace Zooce {

    typedef struct PersonalInfo {
        int age;
        std::string name;
    } PersonalInfo;

    enum class EmployeeType {
        HOURLY, SALARY, TEMP
    };

    class Employee {
    public:
        Employee(unsigned int aId, PersonalInfo aPInfo, EmployeeType aType);
        ~Employee();

        // CLASS VARIABLES
        static int sIdNums = 0;

        // GETTERS
        inline int age() { return mInfo->age; }
        inline std::string name() { return mInfo->name; }
        inline unsigned int id() { return mId; }
        EmployeeType type() { return mEType; }

        void print();

    private:
        PersonalInfo * mInfo;
        EmployeeType mEType;
        unsigned int mId;
    };

    class Boss : public Employee {
    public:
        Boss();
        ~Boss();

        void print(const std::string& msg) const;

        bool awesome() const;
    };

    // Implementation

    Employee::Employee(unsigned int aId, PersonalInfo aPInfo, EmployeeType aType) {
        mId = Employee::sIdNums++;
        mInfo = new PersonalInfo;
        mInfo->age = aPInfo.age;
        mInfo->name = aPInfo.name;
        mEType = aType;
    }

    Employee::~Employee() {
        delete mInfo;
        mInfo = NULL;
    }

    void Employee::print() {
        std::cout << "Name: " << mInfo->name << std::endl;
        std::cout << "Age: " << mInfo->age << std::endl;
        switch (mEType) {
            case EmployeeType::HOURLY:
                std::cout << "Type: Hourly" << std::endl; break;
            case EmployeeType::SALARY:
                std::cout << "Type: Salary" << std::endl; break;
            case EmployeeType::TEMP:
                std::cout << "Type: Temp" << std::endl; break;
        }
        std::cout << "Id: " << mId << std::endl;
    }
}

int main(int argc, char const *argv[]) {

    int age(32);
    std::string name = "Zooce";
    PersonalInfo info = { age, name };
    Employee* newEmployee = new Employee(123, info, EmployeeType::HOURLY);
    newEmployee->print();
    delete newEmployee;

    return 0;
}

#endif // HEADER_GUARD_HPP
