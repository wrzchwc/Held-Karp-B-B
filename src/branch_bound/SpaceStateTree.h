#ifndef INC_2_SPACESTATETREE_H
#define INC_2_SPACESTATETREE_H

#include <map>
#include <set>
#include <vector>
#include "Node.h"

class SpaceStateTree {
private:
    multimap<int, Node *> nodes;
public:
    explicit SpaceStateTree(Node* node);

    virtual ~SpaceStateTree();

    void addNode(Node *node);

    void removeNode(Node *node);

    Node *getMinimalLeaf();

};


#endif //INC_2_SPACESTATETREE_H
