#include "BaseObject.hpp"
#include <string>

using namespace std;

BaseObject::BaseObject() {
    this->name = "";
    this->code = -1;
}

BaseObject::BaseObject(int code, string name) {
    this->name = name;
    this->code = code;
}

string BaseObject::getNome() const {
    return name;
};

int BaseObject::getCode() const {
    return code;
};

