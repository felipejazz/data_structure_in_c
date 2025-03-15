#include "BaseObject.hpp"
#ifndef NODE_TYPE_HPP
#define NODE_TYPE_HPP

struct NodeType {
    BaseObject baseObject;
    int bFactor;
    NodeType* left;
    NodeType* right;
};

#endif