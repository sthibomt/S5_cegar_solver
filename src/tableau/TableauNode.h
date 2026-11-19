#pragma once

#include <memory>
#include <vector>
#include "TableauWorld.h"

//---------------------------------------------------------------------------------
class TableauNode;

using NodePtr = std::shared_ptr<TableauNode>;

//------------------------------------------------------------
class TableauNode
{
public:    
    int id;  
    bool closed = false;
    
    TableauNode* parent = nullptr;  
    std::vector<NodePtr> children;   
    std::vector<TableauWorld> worlds;

    explicit TableauNode(int nodeId);    
    void AddWorld(int worldId); // Add a possible world to this branch.    
    TableauWorld* FindWorld(int worldId);// Find a world using its identifier.    
    void AddFormula(int worldId, const FormulaPtr& formula);// Add a formula to a particular world.
};