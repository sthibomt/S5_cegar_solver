
// Generated from grammars/Modal.g4 by ANTLR 4.13.2

#pragma once


#include <antlr4-runtime/antlr4-runtime.h>
#include "ModalParser.h"


/**
 * This class defines an abstract visitor for a parse tree
 * produced by ModalParser.
 */
class  ModalVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ModalParser.
   */
    virtual std::any visitFormula(ModalParser::FormulaContext *context) = 0;

    virtual std::any visitImplication(ModalParser::ImplicationContext *context) = 0;

    virtual std::any visitDisjunction(ModalParser::DisjunctionContext *context) = 0;

    virtual std::any visitConjunction(ModalParser::ConjunctionContext *context) = 0;

    virtual std::any visitUnary(ModalParser::UnaryContext *context) = 0;

    virtual std::any visitModal(ModalParser::ModalContext *context) = 0;

    virtual std::any visitAgentBox(ModalParser::AgentBoxContext *context) = 0;

    virtual std::any visitAgentDiamond(ModalParser::AgentDiamondContext *context) = 0;

    virtual std::any visitAtom(ModalParser::AtomContext *context) = 0;


};

