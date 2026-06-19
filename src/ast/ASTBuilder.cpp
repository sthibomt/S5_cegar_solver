#include "ASTBuilder.h"

//---------------------------------------------------------------------------------
std::any ASTBuilder::visitFormula(ModalParser::FormulaContext *ctx)    
{
    return visit(ctx->implication());
}

//---------------------------------------------------------------------------------
std::any ASTBuilder::visitImplication(ModalParser::ImplicationContext *ctx)
{
    if (ctx->IMPLIES())
    {
        auto left = std::any_cast<std::shared_ptr<Formula>>(visit(ctx->disjunction()));
        auto right = std::any_cast<std::shared_ptr<Formula>>(visit(ctx->implication()));
        std::shared_ptr<Formula> result = std::make_shared<BinaryFormula>(FormulaType::IMPLIES, left, right);
        return result;
    }
    return visit(ctx->disjunction());
}

//---------------------------------------------------------------------------------
std::any ASTBuilder::visitDisjunction(ModalParser::DisjunctionContext *ctx)
{
    auto result = std::any_cast<std::shared_ptr<Formula>>(visit(ctx->conjunction(0)));

    for (size_t i = 1; i < ctx->conjunction().size(); i++)
    {
        auto rhs = std::any_cast<std::shared_ptr<Formula>>(visit(ctx->conjunction(i)));
        result = std::make_shared<BinaryFormula>(FormulaType::OR,result,rhs);
    }
    return result;
}

//---------------------------------------------------------------------------------
std::any ASTBuilder::visitConjunction(ModalParser::ConjunctionContext *ctx)
{
    auto result = std::any_cast<std::shared_ptr<Formula>>(visit(ctx->unary(0)));

    for (size_t i = 1; i < ctx->unary().size(); ++i)
    {
        auto rhs = std::any_cast<std::shared_ptr<Formula>>(visit(ctx->unary(i)));
        result = std::make_shared<BinaryFormula>(FormulaType::AND, result, rhs);              
    }
    return result;
}

//---------------------------------------------------------------------------------
std::any ASTBuilder::visitUnary(ModalParser::UnaryContext *ctx)
{
    if (ctx->atom())
    {
        return visit(ctx->atom());
    }

    if (ctx->modal())
    {
        return visit(ctx->modal());
    }

    if (ctx->NOT())
    {
        auto child = std::any_cast<std::shared_ptr<Formula>>(visit(ctx->unary()));  
        return std::make_shared<UnaryFormula>(FormulaType::NOT, child);
    }

    if (ctx->implication())
    {
        return visit(ctx->implication());
    }

    return visitChildren(ctx);
}

//---------------------------------------------------------------------------------
std::any ASTBuilder::visitModal(ModalParser::ModalContext *ctx)
{
    if (ctx->BOX())
    {
        auto child = std::any_cast<std::shared_ptr<Formula>>(visit(ctx->unary()));
        std::shared_ptr<Formula> result = std::make_shared<ModalFormula>(FormulaType::BOX, -1, child);
        return result;
    }

    if (ctx->DIAMOND())
    {
        auto child = std::any_cast<std::shared_ptr<Formula>>(visit(ctx->unary()));
        std::shared_ptr<Formula> result = std::make_shared<ModalFormula>(FormulaType::DIAMOND, -1, child);
        return result;
    }

    if (ctx->agentBox())
    {
        int agent = std::stoi(ctx->agentBox()->INT()->getText());
        auto child = std::any_cast<std::shared_ptr<Formula>>(visit(ctx->unary()));
        std::shared_ptr<Formula> result = std::make_shared<ModalFormula>(FormulaType::BOX, agent, child);
        return result;
    }

    if (ctx->agentDiamond())
    {
        int agent = std::stoi(ctx->agentDiamond()->INT()->getText());
        auto child = std::any_cast<std::shared_ptr<Formula>>(visit(ctx->unary()));
        std::shared_ptr<Formula> result = std::make_shared<ModalFormula>(FormulaType::DIAMOND, agent, child);
        return result;
    }

    return visitChildren(ctx);
}

//---------------------------------------------------------------------------------
std::any ASTBuilder::visitAtom(ModalParser::AtomContext *ctx)
{
    std::shared_ptr<Formula> result = std::make_shared<AtomFormula>(ctx->IDENTIFIER()->getText());
    return result;    
}
