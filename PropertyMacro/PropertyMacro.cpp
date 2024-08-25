/* PropertyMacro.cpp 
* Exercising reflection implementation via property macro
 */

#include <iostream>
#include <string>
#include <map>
#include <sstream>

#define REFLECTABLE(...) \
public: \
std::map<std::string, std::string> GetProperties() const { \
std::map<std::string, std::string> props; \
__VA_ARGS__ \
return props; \
}

#define PROPERTY(type, name, label) \
{ \
std::ostringstream oss; \
oss << name; \
props[label] = oss.str(); \
}

class Person
{
    REFLECTABLE(
        PROPERTY(std::string, name, "Full Name")
        PROPERTY(int, age, "Age")
    )

public:
    Person(const std::string& name, int age): name(name), age(age)
    {
    }

private:
    std::string name;
    int age;
};


int main(int argc, char* argv[])
{
    Person p("Bob", 25);
    for (const auto& prop : p.GetProperties())
    {
        std::cout << prop.first << ": " << prop.second << std::endl;
    }
    return 0;
}
