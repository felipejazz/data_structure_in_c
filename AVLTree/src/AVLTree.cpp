#include "AVLTree.hpp"
#include <iostream>

void AVLTree::destroyTree(NodeType*& tree) {
    if (tree != NULL) {
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
    };
};

bool AVLTree::isEmpty() const{
    return root == NULL;
}

bool AVLTree::isFull() const {
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch (std::bad_alloc expcetion){
        return true;
    };
};

void AVLTree::printPreOrder(NodeType* tree) const {
    if (tree != NULL) {
        std::cout << tree->baseObject.getNome() << ", ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}

void AVLTree::printInOrder(NodeType* tree) const {
    if (tree != NULL) {
        printInOrder(tree->left);
        std::cout << tree->baseObject.getNome() << ", ";
        printInOrder(tree->right);
    }
}


void AVLTree::printPosOrder(NodeType* tree) const {
    if (tree != NULL) {
        printPosOrder(tree->left);
        printPosOrder(tree->right);
        std::cout << tree->baseObject.getNome() << ", ";
    }
}


void AVLTree::retrieveObject(NodeType* tree, BaseObject& baseObject, bool& found) const {

    if (tree == NULL){
        found = false;
        return;
    }
    if (baseObject.getCode() < tree->baseObject.getCode()){
        retrieveObject(tree->left, baseObject, found);
        return;
    } 
    if (baseObject.getCode() > tree->baseObject.getCode()){
        retrieveObject(tree->right, baseObject, found);
        return;
    }
    
    baseObject = tree->baseObject;
    found = true; 
    return;
}

void AVLTree::insertObject(NodeType*& tree, BaseObject baseObject, bool& isGrowing) {
    if (tree == NULL) {
        tree = new NodeType;
        tree->left = NULL;
        tree->right = NULL;
        tree->baseObject = baseObject;
        isGrowing = true;
        tree->bFactor = 0;
        return;
    }

    if (baseObject.getCode() < tree->baseObject.getCode()) {
        insertObject(tree->left, baseObject, isGrowing);
        if (isGrowing) {
            tree->bFactor = tree->bFactor - 1;
        }
        performRotations(tree);
        if (isGrowing && tree->bFactor == 0) {
            isGrowing = false;
        }
        return;
    };
    if (baseObject.getCode() > tree->baseObject.getCode()) {
        insertObject(tree->right, baseObject, isGrowing);

        if (isGrowing) {
            tree->bFactor = tree->bFactor + 1;
        };
        performRotations(tree);
        
        if (isGrowing && tree->bFactor == 0) {
            isGrowing = false;
        }
        return;
    };
    throw "Element already in Tree!";

}

void AVLTree::deleteNode(NodeType*& tree, bool& isReducing){
    
    BaseObject data;

    NodeType* tempPtr = tree;
    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPtr;
        return;
    }

    if (tree->right == NULL) {
        tree = tree->left;
        delete tempPtr;
        return;
    }
    
    getSuccessor(tree, data);
    tree->baseObject = data;
    deleteObject(tree->right, data.getCode(), isReducing);
    if(isReducing) {
        tree->bFactor = tree->bFactor - 1;
    };
}
void AVLTree::deleteObject(NodeType*& tree, int baseObjectCode, bool& isReducing) {
    if (baseObjectCode < tree->baseObject.getCode()) {
        deleteObject(tree->left, baseObjectCode, isReducing);
        if (isReducing) {
            tree->bFactor = tree->bFactor + 1;
        }
        return;
    }
    if (baseObjectCode > tree->baseObject.getCode()) { 
        deleteObject(tree->right, baseObjectCode, isReducing);
        if (isReducing) { 
            tree->bFactor = tree->bFactor - 1;
        }
        return;
    }
    deleteNode(tree, isReducing);

    if (tree != NULL) {
        performRotations(tree);
        if (isReducing && tree->bFactor == 0){
            isReducing = false;
            return;
        };
        return;
    }
}

void AVLTree::rotateToLeft(NodeType*& tree) const {

    NodeType* p = tree->right;
    tree->right = p->left;
    p->left = tree;
    tree = p;
    return;
};

void AVLTree::rotateToRight(NodeType*& tree) const {
    NodeType* p = tree->left;
    tree->left = p->right;
    p->right = tree;
    tree = p;
    return;
}

void AVLTree::rotateToLeftAndRight(NodeType*& tree) const {
    NodeType* child = tree->left;
    rotateToLeft(child);
    tree->left = child;
    rotateToRight(tree);
    return;
}

void AVLTree:: rotateToRightAndLeft(NodeType*& tree) const {
    NodeType* child = tree->right;
    rotateToRight(child);
    tree->right = child;
    rotateToLeft(tree);
    return;
}



void AVLTree::performRotations(NodeType*& tree) const {
    NodeType* child;
    NodeType* grandchild;

    if (tree->bFactor == -2) {
        child = tree->left;
        switch (child->bFactor) {
            case -1: // "LL" rotation
                // Typically set parent->bFactor = child->bFactor = 0
                tree->bFactor  = 0;
                child->bFactor = 0;
                rotateToRight(tree);
                break;
    
            case 0: // "LL" rotation - child was perfectly balanced
                // Parent becomes child, child stays balanced
                tree->bFactor  = 0;
                child->bFactor = 0;
                rotateToRight(tree);
                break;
    
            case 1: // "LR" rotation
                // Evaluate grandchild->bFactor, then do left-right
                grandchild = child->right;
                switch(grandchild->bFactor) {
                    case -1:
                        tree->bFactor   = 0;
                        child->bFactor  = -1;
                        break;
                    case 0:
                        tree->bFactor   = 0;
                        child->bFactor  = 0;
                        break;
                    case 1:
                        tree->bFactor   = -1;
                        child->bFactor  = 0;
                        break;
                }
                grandchild->bFactor = 0;
                rotateToLeftAndRight(tree);
                break;
        }
        return;
    }
    else if (tree->bFactor == 2) {
        child = tree->right;
        switch (child->bFactor) {
            case 1: // "RR" rotation
                tree->bFactor  = 0;
                child->bFactor = 0;
                rotateToLeft(tree);
                break;
    
            case 0: // "RR" rotation - child was balanced
                tree->bFactor  = 0;
                child->bFactor = 0;
                rotateToLeft(tree);
                break;
    
            case -1: // "RL" rotation
                grandchild = child->left;
                switch (grandchild->bFactor) {
                    case -1:
                        tree->bFactor   = 0;
                        child->bFactor  = 1;
                        break;
                    case 0:
                        tree->bFactor   = 0;
                        child->bFactor  = 0;
                        break;
                    case 1:
                        tree->bFactor   = -1;
                        child->bFactor  = 0;
                        break;
                }
                grandchild->bFactor = 0;
                rotateToRightAndLeft(tree);
                break;
        }
        return;
    }    
}

void AVLTree::getSuccessor(NodeType* tree, BaseObject& baseObject){
    {
        tree = tree->right;
        while (tree->left != NULL)
        {
            tree = tree->left;
        };
        baseObject = tree->baseObject;

        
    }
}