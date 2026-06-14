
// Generated from grammars/Modal.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  ModalParser : public antlr4::Parser {
public:
  enum {
    BOX = 1, DIAMOND = 2, NOT = 3, AND = 4, OR = 5, IMPLIES = 6, LPAREN = 7, 
    RPAREN = 8, LBRACK = 9, RBRACK = 10, LANG = 11, RANG = 12, INT = 13, 
    IDENTIFIER = 14, WS = 15
  };

  enum {
    RuleFormula = 0, RuleImplication = 1, RuleDisjunction = 2, RuleConjunction = 3, 
    RuleUnary = 4, RuleModal = 5, RuleAgentBox = 6, RuleAgentDiamond = 7, 
    RuleAtom = 8
  };

  explicit ModalParser(antlr4::TokenStream *input);

  ModalParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ModalParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class FormulaContext;
  class ImplicationContext;
  class DisjunctionContext;
  class ConjunctionContext;
  class UnaryContext;
  class ModalContext;
  class AgentBoxContext;
  class AgentDiamondContext;
  class AtomContext; 

  class  FormulaContext : public antlr4::ParserRuleContext {
  public:
    FormulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ImplicationContext *implication();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormulaContext* formula();

  class  ImplicationContext : public antlr4::ParserRuleContext {
  public:
    ImplicationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DisjunctionContext *disjunction();
    antlr4::tree::TerminalNode *IMPLIES();
    ImplicationContext *implication();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImplicationContext* implication();

  class  DisjunctionContext : public antlr4::ParserRuleContext {
  public:
    DisjunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConjunctionContext *> conjunction();
    ConjunctionContext* conjunction(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DisjunctionContext* disjunction();

  class  ConjunctionContext : public antlr4::ParserRuleContext {
  public:
    ConjunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<UnaryContext *> unary();
    UnaryContext* unary(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConjunctionContext* conjunction();

  class  UnaryContext : public antlr4::ParserRuleContext {
  public:
    UnaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    UnaryContext *unary();
    ModalContext *modal();
    AtomContext *atom();
    antlr4::tree::TerminalNode *LPAREN();
    ImplicationContext *implication();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryContext* unary();

  class  ModalContext : public antlr4::ParserRuleContext {
  public:
    ModalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOX();
    UnaryContext *unary();
    antlr4::tree::TerminalNode *DIAMOND();
    AgentBoxContext *agentBox();
    AgentDiamondContext *agentDiamond();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModalContext* modal();

  class  AgentBoxContext : public antlr4::ParserRuleContext {
  public:
    AgentBoxContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *RBRACK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AgentBoxContext* agentBox();

  class  AgentDiamondContext : public antlr4::ParserRuleContext {
  public:
    AgentDiamondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LANG();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *RANG();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AgentDiamondContext* agentDiamond();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AtomContext* atom();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

