
// Generated from grammars/Modal.g4 by ANTLR 4.13.2

#pragma once


#include <antlr4-runtime/antlr4-runtime.h>
#include "ModalListener.h"


/**
 * This class provides an empty implementation of ModalListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ModalBaseListener : public ModalListener {
public:

  virtual void enterFormula(ModalParser::FormulaContext * /*ctx*/) override { }
  virtual void exitFormula(ModalParser::FormulaContext * /*ctx*/) override { }

  virtual void enterImplication(ModalParser::ImplicationContext * /*ctx*/) override { }
  virtual void exitImplication(ModalParser::ImplicationContext * /*ctx*/) override { }

  virtual void enterDisjunction(ModalParser::DisjunctionContext * /*ctx*/) override { }
  virtual void exitDisjunction(ModalParser::DisjunctionContext * /*ctx*/) override { }

  virtual void enterConjunction(ModalParser::ConjunctionContext * /*ctx*/) override { }
  virtual void exitConjunction(ModalParser::ConjunctionContext * /*ctx*/) override { }

  virtual void enterUnary(ModalParser::UnaryContext * /*ctx*/) override { }
  virtual void exitUnary(ModalParser::UnaryContext * /*ctx*/) override { }

  virtual void enterModal(ModalParser::ModalContext * /*ctx*/) override { }
  virtual void exitModal(ModalParser::ModalContext * /*ctx*/) override { }

  virtual void enterAgentBox(ModalParser::AgentBoxContext * /*ctx*/) override { }
  virtual void exitAgentBox(ModalParser::AgentBoxContext * /*ctx*/) override { }

  virtual void enterAgentDiamond(ModalParser::AgentDiamondContext * /*ctx*/) override { }
  virtual void exitAgentDiamond(ModalParser::AgentDiamondContext * /*ctx*/) override { }

  virtual void enterAtom(ModalParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(ModalParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

