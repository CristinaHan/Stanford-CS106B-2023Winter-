/*
 * CS106B Section Handout Test Harness: Section 8
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Neel Kishnani for 
 * CS106B Winter 2022.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <string>
#include <iostream>
#include "testing/SimpleTest.h"
#include "node.h"
#include "utility.h"
#include "vector.h"
using namespace std;

/*
 * Function: isBST
 * ----------------
 * Checks if the tree given by root is a valid 
 * binary searcg tree.
 */
bool helper(Node* root, Node* minNode, Node* maxNode) {
    if (root == nullptr) return true;

    if (minNode != nullptr && root->data <= minNode->data) return false;
    if (maxNode != nullptr && root->data >= maxNode->data) return false;

    return helper(root->left, minNode, root) && helper(root->right, root, maxNode);
}
bool isBST(Node* root) {
    return helper(root, nullptr, nullptr);
}

PROVIDED_TEST("Simple positive tests for isBST function") {
    Node *tree = nullptr;
    EXPECT(isBST(tree));

    tree = createTreeFromVector({/* Level 1*/ 5});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, EMPTY});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ EMPTY, 6});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, 6});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, 6, /* Level 3*/ 1, 4, EMPTY, EMPTY});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, 6, /* Level 3*/ 1, 4, EMPTY, 9});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, 6, /* Level 3*/ 1, 4, EMPTY, 9, /* Level 4*/ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 8, EMPTY});
    EXPECT(isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 3, 6, /* Level 3*/ 1, 4, EMPTY, 9, /* Level 4*/ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 8, 10});
    EXPECT(isBST(tree));

    freeTree(tree);
}

PROVIDED_TEST("Simple negative tests for isBST function") {
    Node *tree = createTreeFromVector({5, 6});
    EXPECT(!isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 4, 3});
    EXPECT(!isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 4, 6, /* Level 3*/ 1, 7, EMPTY, EMPTY});
    EXPECT(!isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 4, 6, /* Level 3*/ 7, 1, EMPTY, EMPTY});
    EXPECT(!isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 4, 6, /* Level 3*/ 1, EMPTY, 8, 9});
    EXPECT(!isBST(tree));

    freeTree(tree);
    tree = createTreeFromVector({/* Level 1*/ 5, /* Level 2*/ 4, 6, /* Level 3*/ 1, EMPTY, EMPTY, 9, /* Level 4*/ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 1, 10});
    EXPECT(!isBST(tree));

    freeTree(tree);
}
