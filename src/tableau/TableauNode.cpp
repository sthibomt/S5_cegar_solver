#include "TableauNode.h"

//---------------------------------------------------------------------------------
TableauNode::TableauNode(int nodeId): id(nodeId)
{
    //
}

//---------------------------------------------------------------------------------
void TableauNode::AddWorld(int worldId)
{    
    if (FindWorld(worldId) != nullptr)// Avoid creating duplicate world identifiers.
        return;
    worlds.emplace_back(worldId);
}

//---------------------------------------------------------------------------------
TableauWorld* TableauNode::FindWorld(int worldId)
{
    for (auto& world : worlds)
    {
        if (world.id == worldId)
            return &world;
    }

    return nullptr;
}

//---------------------------------------------------------------------------------
void TableauNode::AddFormula(int worldId, const FormulaPtr& formula)
{
    TableauWorld* world = FindWorld(worldId);
    if (world == nullptr)
        return;
    world->AddFormula(formula);
}
