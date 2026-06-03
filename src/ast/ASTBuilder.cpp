#include "ASTBuilder.h"

std::any ASTBuilder::visitFormula(
    ModalParser::FormulaContext *ctx)
{
    return visit(ctx->implication());
}

std::any ASTBuilder::visitImplication(
    ModalParser::ImplicationContext *ctx)
{
    if (ctx->IMPLIES())
    {
        auto left =
            std::any_cast<std::shared_ptr<Formula>>(
                visit(ctx->disjunction()));

        auto right =
            std::any_cast<std::shared_ptr<Formula>>(
                visit(ctx->implication()));

        return std::make_shared<BinaryFormula>(
            FormulaType::IMPLIES,
            left,
            right);
    }

    return visit(ctx->disjunction());
}

std::any ASTBuilder::visitDisjunction(
    ModalParser::DisjunctionContext *ctx)
{
    return visit(ctx->conjunction(0));
}

std::any ASTBuilder::visitConjunction(
    ModalParser::ConjunctionContext *ctx)
{
    return visit(ctx->unary(0));
}

std::any ASTBuilder::visitUnary(
    ModalParser::UnaryContext *ctx)
{
    if (ctx->atom())
    {
        return visit(ctx->atom());
    }

    if (ctx->NOT())
    {
        auto child =
            std::any_cast<std::shared_ptr<Formula>>(
                visit(ctx->unary()));

        return std::make_shared<UnaryFormula>(
            FormulaType::NOT,
            child);
    }

    return visitChildren(ctx);
}

std::any ASTBuilder::visitAtom(
    ModalParser::AtomContext *ctx)
{
    std::shared_ptr<Formula> result =
        std::make_shared<AtomFormula>(
            ctx->IDENTIFIER()->getText());

    return result;    
}