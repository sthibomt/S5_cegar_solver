
// Generated from grammars/Modal.g4 by ANTLR 4.13.2

#include "ModalListener.h"
#include "ModalVisitor.h"

#include "ModalParser.h"

using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ModalParserStaticData final {
  ModalParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ModalParserStaticData(const ModalParserStaticData&) = delete;
  ModalParserStaticData(ModalParserStaticData&&) = delete;
  ModalParserStaticData& operator=(const ModalParserStaticData&) = delete;
  ModalParserStaticData& operator=(ModalParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag modalParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<ModalParserStaticData> modalParserStaticData = nullptr;

void modalParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (modalParserStaticData != nullptr) {
    return;
  }
#else
  assert(modalParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ModalParserStaticData>(
    std::vector<std::string>{
      "formula", "implication", "disjunction", "conjunction", "unary", "modal", 
      "agentBox", "agentDiamond", "atom"
    },
    std::vector<std::string>{
      "", "'[]'", "'<>'", "'!'", "'&'", "'|'", "'->'", "'('", "')'", "'['", 
      "']'", "'<'", "'>'"
    },
    std::vector<std::string>{
      "", "BOX", "DIAMOND", "NOT", "AND", "OR", "IMPLIES", "LPAREN", "RPAREN", 
      "LBRACK", "RBRACK", "LANG", "RANG", "INT", "IDENTIFIER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,15,75,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,2,8,7,8,1,0,1,0,1,0,1,1,1,1,1,1,3,1,25,8,1,1,2,1,2,1,2,5,2,30,8,2,
  	10,2,12,2,33,9,2,1,3,1,3,1,3,5,3,38,8,3,10,3,12,3,41,9,3,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,3,4,51,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,3,5,63,8,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,0,0,9,0,2,4,
  	6,8,10,12,14,16,0,0,74,0,18,1,0,0,0,2,21,1,0,0,0,4,26,1,0,0,0,6,34,1,
  	0,0,0,8,50,1,0,0,0,10,62,1,0,0,0,12,64,1,0,0,0,14,68,1,0,0,0,16,72,1,
  	0,0,0,18,19,3,2,1,0,19,20,5,0,0,1,20,1,1,0,0,0,21,24,3,4,2,0,22,23,5,
  	6,0,0,23,25,3,2,1,0,24,22,1,0,0,0,24,25,1,0,0,0,25,3,1,0,0,0,26,31,3,
  	6,3,0,27,28,5,5,0,0,28,30,3,6,3,0,29,27,1,0,0,0,30,33,1,0,0,0,31,29,1,
  	0,0,0,31,32,1,0,0,0,32,5,1,0,0,0,33,31,1,0,0,0,34,39,3,8,4,0,35,36,5,
  	4,0,0,36,38,3,8,4,0,37,35,1,0,0,0,38,41,1,0,0,0,39,37,1,0,0,0,39,40,1,
  	0,0,0,40,7,1,0,0,0,41,39,1,0,0,0,42,43,5,3,0,0,43,51,3,8,4,0,44,51,3,
  	10,5,0,45,51,3,16,8,0,46,47,5,7,0,0,47,48,3,2,1,0,48,49,5,8,0,0,49,51,
  	1,0,0,0,50,42,1,0,0,0,50,44,1,0,0,0,50,45,1,0,0,0,50,46,1,0,0,0,51,9,
  	1,0,0,0,52,53,5,1,0,0,53,63,3,8,4,0,54,55,5,2,0,0,55,63,3,8,4,0,56,57,
  	3,12,6,0,57,58,3,8,4,0,58,63,1,0,0,0,59,60,3,14,7,0,60,61,3,8,4,0,61,
  	63,1,0,0,0,62,52,1,0,0,0,62,54,1,0,0,0,62,56,1,0,0,0,62,59,1,0,0,0,63,
  	11,1,0,0,0,64,65,5,9,0,0,65,66,5,13,0,0,66,67,5,10,0,0,67,13,1,0,0,0,
  	68,69,5,11,0,0,69,70,5,13,0,0,70,71,5,12,0,0,71,15,1,0,0,0,72,73,5,14,
  	0,0,73,17,1,0,0,0,5,24,31,39,50,62
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  modalParserStaticData = std::move(staticData);
}

}

ModalParser::ModalParser(TokenStream *input) : ModalParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ModalParser::ModalParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ModalParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *modalParserStaticData->atn, modalParserStaticData->decisionToDFA, modalParserStaticData->sharedContextCache, options);
}

ModalParser::~ModalParser() {
  delete _interpreter;
}

const atn::ATN& ModalParser::getATN() const {
  return *modalParserStaticData->atn;
}

std::string ModalParser::getGrammarFileName() const {
  return "Modal.g4";
}

const std::vector<std::string>& ModalParser::getRuleNames() const {
  return modalParserStaticData->ruleNames;
}

const dfa::Vocabulary& ModalParser::getVocabulary() const {
  return modalParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ModalParser::getSerializedATN() const {
  return modalParserStaticData->serializedATN;
}


//----------------- FormulaContext ------------------------------------------------------------------

ModalParser::FormulaContext::FormulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ModalParser::ImplicationContext* ModalParser::FormulaContext::implication() {
  return getRuleContext<ModalParser::ImplicationContext>(0);
}

tree::TerminalNode* ModalParser::FormulaContext::EOF() {
  return getToken(ModalParser::EOF, 0);
}


size_t ModalParser::FormulaContext::getRuleIndex() const {
  return ModalParser::RuleFormula;
}

void ModalParser::FormulaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormula(this);
}

void ModalParser::FormulaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormula(this);
}


std::any ModalParser::FormulaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ModalVisitor*>(visitor))
    return parserVisitor->visitFormula(this);
  else
    return visitor->visitChildren(this);
}

ModalParser::FormulaContext* ModalParser::formula() {
  FormulaContext *_localctx = _tracker.createInstance<FormulaContext>(_ctx, getState());
  enterRule(_localctx, 0, ModalParser::RuleFormula);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    implication();
    setState(19);
    match(ModalParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImplicationContext ------------------------------------------------------------------

ModalParser::ImplicationContext::ImplicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ModalParser::DisjunctionContext* ModalParser::ImplicationContext::disjunction() {
  return getRuleContext<ModalParser::DisjunctionContext>(0);
}

tree::TerminalNode* ModalParser::ImplicationContext::IMPLIES() {
  return getToken(ModalParser::IMPLIES, 0);
}

ModalParser::ImplicationContext* ModalParser::ImplicationContext::implication() {
  return getRuleContext<ModalParser::ImplicationContext>(0);
}


size_t ModalParser::ImplicationContext::getRuleIndex() const {
  return ModalParser::RuleImplication;
}

void ModalParser::ImplicationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImplication(this);
}

void ModalParser::ImplicationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImplication(this);
}


std::any ModalParser::ImplicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ModalVisitor*>(visitor))
    return parserVisitor->visitImplication(this);
  else
    return visitor->visitChildren(this);
}

ModalParser::ImplicationContext* ModalParser::implication() {
  ImplicationContext *_localctx = _tracker.createInstance<ImplicationContext>(_ctx, getState());
  enterRule(_localctx, 2, ModalParser::RuleImplication);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    disjunction();
    setState(24);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ModalParser::IMPLIES) {
      setState(22);
      match(ModalParser::IMPLIES);
      setState(23);
      implication();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DisjunctionContext ------------------------------------------------------------------

ModalParser::DisjunctionContext::DisjunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ModalParser::ConjunctionContext *> ModalParser::DisjunctionContext::conjunction() {
  return getRuleContexts<ModalParser::ConjunctionContext>();
}

ModalParser::ConjunctionContext* ModalParser::DisjunctionContext::conjunction(size_t i) {
  return getRuleContext<ModalParser::ConjunctionContext>(i);
}

std::vector<tree::TerminalNode *> ModalParser::DisjunctionContext::OR() {
  return getTokens(ModalParser::OR);
}

tree::TerminalNode* ModalParser::DisjunctionContext::OR(size_t i) {
  return getToken(ModalParser::OR, i);
}


size_t ModalParser::DisjunctionContext::getRuleIndex() const {
  return ModalParser::RuleDisjunction;
}

void ModalParser::DisjunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDisjunction(this);
}

void ModalParser::DisjunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDisjunction(this);
}


std::any ModalParser::DisjunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ModalVisitor*>(visitor))
    return parserVisitor->visitDisjunction(this);
  else
    return visitor->visitChildren(this);
}

ModalParser::DisjunctionContext* ModalParser::disjunction() {
  DisjunctionContext *_localctx = _tracker.createInstance<DisjunctionContext>(_ctx, getState());
  enterRule(_localctx, 4, ModalParser::RuleDisjunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    conjunction();
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ModalParser::OR) {
      setState(27);
      match(ModalParser::OR);
      setState(28);
      conjunction();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConjunctionContext ------------------------------------------------------------------

ModalParser::ConjunctionContext::ConjunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ModalParser::UnaryContext *> ModalParser::ConjunctionContext::unary() {
  return getRuleContexts<ModalParser::UnaryContext>();
}

ModalParser::UnaryContext* ModalParser::ConjunctionContext::unary(size_t i) {
  return getRuleContext<ModalParser::UnaryContext>(i);
}

std::vector<tree::TerminalNode *> ModalParser::ConjunctionContext::AND() {
  return getTokens(ModalParser::AND);
}

tree::TerminalNode* ModalParser::ConjunctionContext::AND(size_t i) {
  return getToken(ModalParser::AND, i);
}


size_t ModalParser::ConjunctionContext::getRuleIndex() const {
  return ModalParser::RuleConjunction;
}

void ModalParser::ConjunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConjunction(this);
}

void ModalParser::ConjunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConjunction(this);
}


std::any ModalParser::ConjunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ModalVisitor*>(visitor))
    return parserVisitor->visitConjunction(this);
  else
    return visitor->visitChildren(this);
}

ModalParser::ConjunctionContext* ModalParser::conjunction() {
  ConjunctionContext *_localctx = _tracker.createInstance<ConjunctionContext>(_ctx, getState());
  enterRule(_localctx, 6, ModalParser::RuleConjunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    unary();
    setState(39);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ModalParser::AND) {
      setState(35);
      match(ModalParser::AND);
      setState(36);
      unary();
      setState(41);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryContext ------------------------------------------------------------------

ModalParser::UnaryContext::UnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ModalParser::UnaryContext::NOT() {
  return getToken(ModalParser::NOT, 0);
}

ModalParser::UnaryContext* ModalParser::UnaryContext::unary() {
  return getRuleContext<ModalParser::UnaryContext>(0);
}

ModalParser::ModalContext* ModalParser::UnaryContext::modal() {
  return getRuleContext<ModalParser::ModalContext>(0);
}

ModalParser::AtomContext* ModalParser::UnaryContext::atom() {
  return getRuleContext<ModalParser::AtomContext>(0);
}

tree::TerminalNode* ModalParser::UnaryContext::LPAREN() {
  return getToken(ModalParser::LPAREN, 0);
}

ModalParser::ImplicationContext* ModalParser::UnaryContext::implication() {
  return getRuleContext<ModalParser::ImplicationContext>(0);
}

tree::TerminalNode* ModalParser::UnaryContext::RPAREN() {
  return getToken(ModalParser::RPAREN, 0);
}


size_t ModalParser::UnaryContext::getRuleIndex() const {
  return ModalParser::RuleUnary;
}

void ModalParser::UnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary(this);
}

void ModalParser::UnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary(this);
}


std::any ModalParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ModalVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}

ModalParser::UnaryContext* ModalParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 8, ModalParser::RuleUnary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ModalParser::NOT: {
        enterOuterAlt(_localctx, 1);
        setState(42);
        match(ModalParser::NOT);
        setState(43);
        unary();
        break;
      }

      case ModalParser::BOX:
      case ModalParser::DIAMOND:
      case ModalParser::LBRACK:
      case ModalParser::LANG: {
        enterOuterAlt(_localctx, 2);
        setState(44);
        modal();
        break;
      }

      case ModalParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(45);
        atom();
        break;
      }

      case ModalParser::LPAREN: {
        enterOuterAlt(_localctx, 4);
        setState(46);
        match(ModalParser::LPAREN);
        setState(47);
        implication();
        setState(48);
        match(ModalParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModalContext ------------------------------------------------------------------

ModalParser::ModalContext::ModalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ModalParser::ModalContext::BOX() {
  return getToken(ModalParser::BOX, 0);
}

ModalParser::UnaryContext* ModalParser::ModalContext::unary() {
  return getRuleContext<ModalParser::UnaryContext>(0);
}

tree::TerminalNode* ModalParser::ModalContext::DIAMOND() {
  return getToken(ModalParser::DIAMOND, 0);
}

ModalParser::AgentBoxContext* ModalParser::ModalContext::agentBox() {
  return getRuleContext<ModalParser::AgentBoxContext>(0);
}

ModalParser::AgentDiamondContext* ModalParser::ModalContext::agentDiamond() {
  return getRuleContext<ModalParser::AgentDiamondContext>(0);
}


size_t ModalParser::ModalContext::getRuleIndex() const {
  return ModalParser::RuleModal;
}

void ModalParser::ModalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModal(this);
}

void ModalParser::ModalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModal(this);
}


std::any ModalParser::ModalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ModalVisitor*>(visitor))
    return parserVisitor->visitModal(this);
  else
    return visitor->visitChildren(this);
}

ModalParser::ModalContext* ModalParser::modal() {
  ModalContext *_localctx = _tracker.createInstance<ModalContext>(_ctx, getState());
  enterRule(_localctx, 10, ModalParser::RuleModal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ModalParser::BOX: {
        enterOuterAlt(_localctx, 1);
        setState(52);
        match(ModalParser::BOX);
        setState(53);
        unary();
        break;
      }

      case ModalParser::DIAMOND: {
        enterOuterAlt(_localctx, 2);
        setState(54);
        match(ModalParser::DIAMOND);
        setState(55);
        unary();
        break;
      }

      case ModalParser::LBRACK: {
        enterOuterAlt(_localctx, 3);
        setState(56);
        agentBox();
        setState(57);
        unary();
        break;
      }

      case ModalParser::LANG: {
        enterOuterAlt(_localctx, 4);
        setState(59);
        agentDiamond();
        setState(60);
        unary();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AgentBoxContext ------------------------------------------------------------------

ModalParser::AgentBoxContext::AgentBoxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ModalParser::AgentBoxContext::LBRACK() {
  return getToken(ModalParser::LBRACK, 0);
}

tree::TerminalNode* ModalParser::AgentBoxContext::INT() {
  return getToken(ModalParser::INT, 0);
}

tree::TerminalNode* ModalParser::AgentBoxContext::RBRACK() {
  return getToken(ModalParser::RBRACK, 0);
}


size_t ModalParser::AgentBoxContext::getRuleIndex() const {
  return ModalParser::RuleAgentBox;
}

void ModalParser::AgentBoxContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAgentBox(this);
}

void ModalParser::AgentBoxContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAgentBox(this);
}


std::any ModalParser::AgentBoxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ModalVisitor*>(visitor))
    return parserVisitor->visitAgentBox(this);
  else
    return visitor->visitChildren(this);
}

ModalParser::AgentBoxContext* ModalParser::agentBox() {
  AgentBoxContext *_localctx = _tracker.createInstance<AgentBoxContext>(_ctx, getState());
  enterRule(_localctx, 12, ModalParser::RuleAgentBox);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(ModalParser::LBRACK);
    setState(65);
    match(ModalParser::INT);
    setState(66);
    match(ModalParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AgentDiamondContext ------------------------------------------------------------------

ModalParser::AgentDiamondContext::AgentDiamondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ModalParser::AgentDiamondContext::LANG() {
  return getToken(ModalParser::LANG, 0);
}

tree::TerminalNode* ModalParser::AgentDiamondContext::INT() {
  return getToken(ModalParser::INT, 0);
}

tree::TerminalNode* ModalParser::AgentDiamondContext::RANG() {
  return getToken(ModalParser::RANG, 0);
}


size_t ModalParser::AgentDiamondContext::getRuleIndex() const {
  return ModalParser::RuleAgentDiamond;
}

void ModalParser::AgentDiamondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAgentDiamond(this);
}

void ModalParser::AgentDiamondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAgentDiamond(this);
}


std::any ModalParser::AgentDiamondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ModalVisitor*>(visitor))
    return parserVisitor->visitAgentDiamond(this);
  else
    return visitor->visitChildren(this);
}

ModalParser::AgentDiamondContext* ModalParser::agentDiamond() {
  AgentDiamondContext *_localctx = _tracker.createInstance<AgentDiamondContext>(_ctx, getState());
  enterRule(_localctx, 14, ModalParser::RuleAgentDiamond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(ModalParser::LANG);
    setState(69);
    match(ModalParser::INT);
    setState(70);
    match(ModalParser::RANG);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

ModalParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ModalParser::AtomContext::IDENTIFIER() {
  return getToken(ModalParser::IDENTIFIER, 0);
}


size_t ModalParser::AtomContext::getRuleIndex() const {
  return ModalParser::RuleAtom;
}

void ModalParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void ModalParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ModalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}


std::any ModalParser::AtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ModalVisitor*>(visitor))
    return parserVisitor->visitAtom(this);
  else
    return visitor->visitChildren(this);
}

ModalParser::AtomContext* ModalParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 16, ModalParser::RuleAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(ModalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void ModalParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  modalParserInitialize();
#else
  ::antlr4::internal::call_once(modalParserOnceFlag, modalParserInitialize);
#endif
}
