#ifndef INC_2_SPACESTATETREE_H
#define INC_2_SPACESTATETREE_H

#include <map>
#include <vector>
#include "Node.h"

class SpaceStateTree {
private:
    multimap<int, Node *> m;
public:
    explicit SpaceStateTree(Node *node);

    virtual ~SpaceStateTree();

    void addNode(Node *node);

    Node *getMinimalLeaf();
};


#endif //INC_2_SPACESTATETREE_H
