#include "BaseObject.hpp"
#ifndef NODE_TYPE_HPP
#define NODE_TYPE_HPP

struct NodeType {
    BaseObject baseObject;
    NodeType* left;
    NodeType* right;
};

#endif