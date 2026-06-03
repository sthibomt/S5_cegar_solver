#pragma once

#include <memory>
#include <string>

//---------------------------------------------------------------------------------
enum class FormulaType 
{
    ATOM,
    NOT,
    AND,
    OR,
    IMPLIES,
    BOX,
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
class AtomFormula : public Formula 
{
    public:
    std::string name;

    AtomFormula(const std::string& n)
        : Formula(FormulaType::ATOM), name(n) {}
};

//---------------------------------------------------------------------------------
class UnaryFormula : public Formula 
{
    public:
    std::shared_ptr<Formula> child;

    UnaryFormula(FormulaType t,
                 std::shared_ptr<Formula> c)
        : Formula(t), child(std::move(c)) {}
};

//---------------------------------------------------------------------------------
class BinaryFormula : public Formula 
{
    public:
    std::shared_ptr<Formula> left;
    std::shared_ptr<Formula> right;

    BinaryFormula(
        FormulaType t,
        std::shared_ptr<Formula> l,
        std::shared_ptr<Formula> r)
        : Formula(t),
          left(std::move(l)),
          right(std::move(r)) {}
};

//---------------------------------------------------------------------------------
class ModalFormula : public Formula 
{
    public:
    int agent;

    std::shared_ptr<Formula> child;

    ModalFormula(
        FormulaType t,
        int a,
        std::shared_ptr<Formula> c)
        : Formula(t),
          agent(a),
          child(std::move(c)) {}
};