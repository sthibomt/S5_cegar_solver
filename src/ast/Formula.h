#pragma once

#include <memory>
#include <string>

//---------------------------------------------------------------------------------
enum class FormulaType 
{
    ATOM, NOT, AND, OR, IMPLIES, BOX,
    DIAMOND
};

//---------------------------------------------------------------------------------
class Formula 
{
    public:    
    FormulaType type;
    explicit Formula(FormulaType t) : type(t) {}
    virtual ~Formula() = default; 
};

//---------------------------------------------------------------------------------
// Aliases for smart pointer
using FormulaPtr = std::shared_ptr<Formula>;

//---------------------------------------------------------------------------------
class AtomFormula : public Formula 
{
    public:
    std::string name;
    AtomFormula(const std::string& n) : Formula(FormulaType::ATOM), name(n) {}
};

//---------------------------------------------------------------------------------
class UnaryFormula : public Formula 
{
    public:
    FormulaPtr child;
    UnaryFormula(FormulaType t, FormulaPtr c) : Formula(t), child(std::move(c)) {}
};

//---------------------------------------------------------------------------------
class BinaryFormula : public Formula 
{
    public:
    FormulaPtr left;
    FormulaPtr right;
    BinaryFormula(FormulaType t, FormulaPtr l, FormulaPtr r)
        : Formula(t), left(std::move(l)), right(std::move(r)) {}
};

//---------------------------------------------------------------------------------
class ModalFormula : public Formula 
{
    public:
    int agent;
    FormulaPtr child;
    ModalFormula(FormulaType t, int a, FormulaPtr c)
        : Formula(t), agent(a), child(std::move(c)) {}
};