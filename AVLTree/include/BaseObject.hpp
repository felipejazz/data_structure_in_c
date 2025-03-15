#include <string>
#ifndef BASE_OBJECT_HPP
#define BASE_OBJECT_HPP


using namespace std;

class BaseObject {
    private:
        int code;
        string name;

    public:
        BaseObject();
        BaseObject(int code, string name);
        string getNome() const;
        int getCode() const;    
};

#endif
