/* Reflection.cpp
 * Exercising reflection system impl
 */
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class Property {
public:
    // virtual ~Property();
    virtual std::string GetName() const        = 0;
    virtual std::string GetLabel() const       = 0;
    virtual std::string GetStringValue() const = 0;
};

template <typename T>
class PropertyImpl : public Property {
public:
    PropertyImpl(const std::string& name, const std::string& label, T* value)
        : name(name), label(label), value(value) {}

    std::string GetName() const override {
        return name;
    }

    std::string GetLabel() const override {
        return label;
    }

    std::string GetStringValue() const override {
        std::ostringstream oss;
        oss << *value;
        return oss.str();
    }

private:
    std::string name;
    std::string label;
    T*          value;
};

class Reflectable {
public:
    void AddProperty(Property* prop) {
        props[prop->GetName()] = prop;
    }

    std::map<std::string, Property*> GetProperties() const {
        return props;
    }

private:
    std::map<std::string, Property*> props;
};

class Person : public Reflectable {
public:
    Person(const std::string& name, int age) : name(name), age(age) {
        AddProperty(new PropertyImpl<std::string>("name", "Full Name", &this->name));
        AddProperty(new PropertyImpl<int>("age", "Age", &this->age));
    }

private:
    std::string name;
    int         age;
};

int main() {
    Person p("Dmitrii", 40);

    for (const auto& prop : p.GetProperties()) {
        std::cout << prop.second->GetLabel() << ": " << prop.second->GetStringValue()
                  << std::endl;
    }

    return 0;
}
