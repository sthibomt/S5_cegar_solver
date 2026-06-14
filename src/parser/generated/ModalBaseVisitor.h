
// Generated from grammars/Modal.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ModalVisitor.h"


/**
 * This class provides an empty implementation of ModalVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ModalBaseVisitor : public ModalVisitor {
public:

  virtual std::any visitFormula(ModalParser::FormulaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImplication(ModalParser::ImplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDisjunction(ModalParser::DisjunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConjunction(ModalParser::ConjunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary(ModalParser::UnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModal(ModalParser::ModalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAgentBox(ModalParser::AgentBoxContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAgentDiamond(ModalParser::AgentDiamondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom(ModalParser::AtomContext *ctx) override {
    return visitChildren(ctx);
  }


};

