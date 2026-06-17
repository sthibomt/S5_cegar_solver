#pragma once

#include <any>
#include <memory>
#include "Formula.h"
#include "../parser/generated/ModalBaseVisitor.h"

class ASTBuilder : public ModalBaseVisitor
{
public:
    std::any visitFormula(ModalParser::FormulaContext *ctx) override;
    std::any visitImplication(ModalParser::ImplicationContext *ctx) override;
    std::any visitDisjunction(ModalParser::DisjunctionContext *ctx) override;
    std::any visitConjunction(ModalParser::ConjunctionContext *ctx) override;
    std::any visitUnary(ModalParser::UnaryContext *ctx) override;
    std::any visitModal(ModalParser::ModalContext *ctx) override; 
    std::any visitAgentBox(ModalParser::AgentBoxContext *ctx) override;
    std::any visitAgentDiamond(ModalParser::AgentDiamondContext *ctx) override;       
    std::any visitAtom(ModalParser::AtomContext *ctx) override;
};