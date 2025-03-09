#include "NodeType.hpp"
#include "BaseObject.hpp"


#ifndef TREE_HPP
#define TREE_HPP
class Tree {
    public:
        Tree() {root = NULL;};
        ~Tree() { destroyTree(root);};
        bool isEmpty() const;
        bool isFull() const;

    

        void retrieveObject(BaseObject& baseObject, bool& found) const { retrieveObject(root, baseObject, found);};
        void insertObject(BaseObject baseObject) { insertObject(root, baseObject);};
        void deleteObject(int baseObjectCode) { deleteObject(root, baseObjectCode);};
        void getSuccessor(BaseObject& baseObject){ getSuccessor(root, baseObject);};
        void printPreOrder() const { printPreOrder(root);};
        void printPosOrder() const{ printPosOrder(root);};
        void printInOrder() const{ printInOrder(root);};
    private:
        NodeType* root;
        
        void destroyTree(NodeType*& tree);
        void deleteNode(NodeType*& tree);
        void retrieveObject(NodeType* tree, BaseObject& baseObject, bool& found) const;
        void insertObject(NodeType*& tree, BaseObject baseObject);
        void deleteObject(NodeType*& tree, int baseObjectCode);
        void getSuccessor(NodeType* tree, BaseObject& baseObject);
        void printTree(NodeType* tree) const;
        void printPreOrder(NodeType* tree) const;
        void printPosOrder(NodeType* tree) const;
        void printInOrder(NodeType* tree) const;
};
#endif