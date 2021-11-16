#ifndef INC_2_SPACESTATETREE_H
#define INC_2_SPACESTATETREE_H

#include <map>
#include <set>
#include <vector>
#include "Node.h"

class SpaceStateTree {
private:
    multimap<int, shared_ptr<Node>> nodes;
public:
    explicit SpaceStateTree(const shared_ptr<Node>& node);

    virtual ~SpaceStateTree();

    void addNode(const shared_ptr<Node>& node);

    void removeNode(const shared_ptr<Node>& node);

    shared_ptr<Node> getMinimalLeaf();

};


#endif //INC_2_SPACESTATETREE_H
