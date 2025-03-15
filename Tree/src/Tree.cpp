#include "Tree.hpp"
#include <iostream>

void Tree::destroyTree(NodeType*& tree) {
    if (tree != NULL) {
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
    };
};

bool Tree::isEmpty() const{
    return root == NULL;
}

bool Tree::isFull() const {
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch (std::bad_alloc expcetion){
        return true;
    };
};

void Tree::printPreOrder(NodeType* tree) const {
    if (tree != NULL) {
        std::cout << tree->baseObject.getNome() << ", ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}

void Tree::printInOrder(NodeType* tree) const {
    if (tree != NULL) {
        printInOrder(tree->left);
        std::cout << tree->baseObject.getNome() << ", ";
        printInOrder(tree->right);
    }
}


void Tree::printPosOrder(NodeType* tree) const {
    if (tree != NULL) {
        printPosOrder(tree->left);
        printPosOrder(tree->right);
        std::cout << tree->baseObject.getNome() << ", ";
    }
}


void Tree::retrieveObject(NodeType* tree, BaseObject& baseObject, bool& found) const {

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

void Tree::insertObject(NodeType*& tree, BaseObject baseObject) {
    if (tree == NULL) {
        tree = new NodeType;
        tree->left = NULL;
        tree->right = NULL;
        tree->baseObject = baseObject;
        
        return;
    }

    if (baseObject.getCode() < tree->baseObject.getCode()) {
        insertObject(tree->left, baseObject);
        return;
    };
    if (baseObject.getCode() > tree->baseObject.getCode()) {
        insertObject(tree->right, baseObject);
        return;
    };

    throw "Element already in Tree!";

}

void Tree::deleteNode(NodeType*& tree){
    
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
    deleteObject(tree->right, data.getCode());

}
void Tree::deleteObject(NodeType*& tree, int baseObjectCode) {
    if (baseObjectCode < tree->baseObject.getCode()) {
        deleteObject(tree->left, baseObjectCode);
        return;
    }
    if (baseObjectCode > tree->baseObject.getCode()) { 
        deleteObject(tree->right, baseObjectCode);
        return;
    }
    deleteNode(tree);

}


void Tree::getSuccessor(NodeType* tree, BaseObject& baseObject){
    {
        tree = tree->right;
        while (tree->left != NULL)
        {
            tree = tree->left;
        };
        baseObject = tree->baseObject;

        
    }
}