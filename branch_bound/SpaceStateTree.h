#ifndef INC_2_SPACESTATETREE_H
#define INC_2_SPACESTATETREE_H


#include "Node.h"

class SpaceStateTree {
private:
    Node *minimalLeaf;
    vector<Node *> nodes;
public:
    explicit SpaceStateTree(Node *node);

    virtual ~SpaceStateTree();

    void addNode(Node *node);

    Node *getMinimalLeaf();
};


#endif //INC_2_SPACESTATETREE_H
