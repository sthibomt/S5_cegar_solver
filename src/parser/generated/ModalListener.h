
// Generated from grammars/Modal.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ModalParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ModalParser.
 */
class  ModalListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFormula(ModalParser::FormulaContext *ctx) = 0;
  virtual void exitFormula(ModalParser::FormulaContext *ctx) = 0;

  virtual void enterImplication(ModalParser::ImplicationContext *ctx) = 0;
  virtual void exitImplication(ModalParser::ImplicationContext *ctx) = 0;

  virtual void enterDisjunction(ModalParser::DisjunctionContext *ctx) = 0;
  virtual void exitDisjunction(ModalParser::DisjunctionContext *ctx) = 0;

  virtual void enterConjunction(ModalParser::ConjunctionContext *ctx) = 0;
  virtual void exitConjunction(ModalParser::ConjunctionContext *ctx) = 0;

  virtual void enterUnary(ModalParser::UnaryContext *ctx) = 0;
  virtual void exitUnary(ModalParser::UnaryContext *ctx) = 0;

  virtual void enterModal(ModalParser::ModalContext *ctx) = 0;
  virtual void exitModal(ModalParser::ModalContext *ctx) = 0;

  virtual void enterAgentBox(ModalParser::AgentBoxContext *ctx) = 0;
  virtual void exitAgentBox(ModalParser::AgentBoxContext *ctx) = 0;

  virtual void enterAgentDiamond(ModalParser::AgentDiamondContext *ctx) = 0;
  virtual void exitAgentDiamond(ModalParser::AgentDiamondContext *ctx) = 0;

  virtual void enterAtom(ModalParser::AtomContext *ctx) = 0;
  virtual void exitAtom(ModalParser::AtomContext *ctx) = 0;


};

