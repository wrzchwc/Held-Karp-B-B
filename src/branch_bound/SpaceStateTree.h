#ifndef INC_2_SPACESTATETREE_H
#define INC_2_SPACESTATETREE_H


#include "Node.h"

class SpaceStateTree {
private:
    shared_ptr<Node> minimalLeaf;
    vector<shared_ptr<Node>> nodes;
public:
    explicit SpaceStateTree(const shared_ptr<Node>& node);

    virtual ~SpaceStateTree();

    void addNode(const shared_ptr<Node>& node);

    shared_ptr<Node> getMinimalLeaf();
};


#endif //INC_2_SPACESTATETREE_H
