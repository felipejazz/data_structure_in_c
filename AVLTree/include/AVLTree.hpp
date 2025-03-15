#include "NodeType.hpp"
#include "BaseObject.hpp"


#ifndef AVL_TREE_HPP
#define AVLTREE_HPP
class AVLTree {
    public:
        AVLTree() {root = NULL;};
        ~AVLTree() { destroyTree(root);};
        bool isEmpty() const;
        bool isFull() const;

    

        void retrieveObject(BaseObject& baseObject, bool& found) const { retrieveObject(root, baseObject, found);};
        void insertObject(BaseObject baseObject) { 
            bool isGrowing = false; 
            insertObject(root, baseObject, isGrowing);
        };
        void deleteObject(int baseObjectCode) { 
            bool isReducing = false;
            deleteObject(root, baseObjectCode, isReducing);
        };
        void getSuccessor(BaseObject& baseObject){ getSuccessor(root, baseObject);};
        void printPreOrder() const { printPreOrder(root);};
        void printPosOrder() const{ printPosOrder(root);};
        void printInOrder() const{ printInOrder(root);};
    private:
        NodeType* root;
        
        void destroyTree(NodeType*& tree);
        void deleteNode(NodeType*& tree, bool& isReducing);
        void retrieveObject(NodeType* tree, BaseObject& baseObject, bool& found) const;
        void insertObject(NodeType*& tree, BaseObject baseObject, bool& isGrowing);
        void deleteObject(NodeType*& tree, int baseObjectCode, bool& isReducing);

        void rotateToLeft(NodeType*& tree) const;
        void rotateToRight(NodeType*& tree) const;
        void rotateToLeftAndRight(NodeType*& tree) const;
        void rotateToRightAndLeft(NodeType*& tree) const;
        void performRotations(NodeType*& tree) const;

        void getSuccessor(NodeType* tree, BaseObject& baseObject);
        void printTree(NodeType* tree) const;
        void printPreOrder(NodeType* tree) const;
        void printPosOrder(NodeType* tree) const;
        void printInOrder(NodeType* tree) const;
};
#endif