
// Generated from grammars/Modal.g4 by ANTLR 4.13.2


#include "ModalLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ModalLexerStaticData final {
  ModalLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ModalLexerStaticData(const ModalLexerStaticData&) = delete;
  ModalLexerStaticData(ModalLexerStaticData&&) = delete;
  ModalLexerStaticData& operator=(const ModalLexerStaticData&) = delete;
  ModalLexerStaticData& operator=(ModalLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag modallexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<ModalLexerStaticData> modallexerLexerStaticData = nullptr;

void modallexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (modallexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(modallexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ModalLexerStaticData>(
    std::vector<std::string>{
      "BOX", "DIAMOND", "NOT", "AND", "OR", "IMPLIES", "LPAREN", "RPAREN", 
      "LBRACK", "RBRACK", "LANG", "RANG", "INT", "IDENTIFIER", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,15,77,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,1,0,1,0,1,0,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,6,
  	1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,4,12,60,8,12,11,
  	12,12,12,61,1,13,1,13,5,13,66,8,13,10,13,12,13,69,9,13,1,14,4,14,72,8,
  	14,11,14,12,14,73,1,14,1,14,0,0,15,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,
  	17,9,19,10,21,11,23,12,25,13,27,14,29,15,1,0,4,1,0,48,57,2,0,65,90,97,
  	122,4,0,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,79,0,1,1,0,0,0,
  	0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,
  	0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,
  	0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,1,31,1,0,0,0,3,34,1,0,0,0,5,37,
  	1,0,0,0,7,39,1,0,0,0,9,41,1,0,0,0,11,43,1,0,0,0,13,46,1,0,0,0,15,48,1,
  	0,0,0,17,50,1,0,0,0,19,52,1,0,0,0,21,54,1,0,0,0,23,56,1,0,0,0,25,59,1,
  	0,0,0,27,63,1,0,0,0,29,71,1,0,0,0,31,32,5,91,0,0,32,33,5,93,0,0,33,2,
  	1,0,0,0,34,35,5,60,0,0,35,36,5,62,0,0,36,4,1,0,0,0,37,38,5,33,0,0,38,
  	6,1,0,0,0,39,40,5,38,0,0,40,8,1,0,0,0,41,42,5,124,0,0,42,10,1,0,0,0,43,
  	44,5,45,0,0,44,45,5,62,0,0,45,12,1,0,0,0,46,47,5,40,0,0,47,14,1,0,0,0,
  	48,49,5,41,0,0,49,16,1,0,0,0,50,51,5,91,0,0,51,18,1,0,0,0,52,53,5,93,
  	0,0,53,20,1,0,0,0,54,55,5,60,0,0,55,22,1,0,0,0,56,57,5,62,0,0,57,24,1,
  	0,0,0,58,60,7,0,0,0,59,58,1,0,0,0,60,61,1,0,0,0,61,59,1,0,0,0,61,62,1,
  	0,0,0,62,26,1,0,0,0,63,67,7,1,0,0,64,66,7,2,0,0,65,64,1,0,0,0,66,69,1,
  	0,0,0,67,65,1,0,0,0,67,68,1,0,0,0,68,28,1,0,0,0,69,67,1,0,0,0,70,72,7,
  	3,0,0,71,70,1,0,0,0,72,73,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,75,1,
  	0,0,0,75,76,6,14,0,0,76,30,1,0,0,0,4,0,61,67,73,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  modallexerLexerStaticData = std::move(staticData);
}

}

ModalLexer::ModalLexer(CharStream *input) : Lexer(input) {
  ModalLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *modallexerLexerStaticData->atn, modallexerLexerStaticData->decisionToDFA, modallexerLexerStaticData->sharedContextCache);
}

ModalLexer::~ModalLexer() {
  delete _interpreter;
}

std::string ModalLexer::getGrammarFileName() const {
  return "Modal.g4";
}

const std::vector<std::string>& ModalLexer::getRuleNames() const {
  return modallexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ModalLexer::getChannelNames() const {
  return modallexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ModalLexer::getModeNames() const {
  return modallexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ModalLexer::getVocabulary() const {
  return modallexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ModalLexer::getSerializedATN() const {
  return modallexerLexerStaticData->serializedATN;
}

const atn::ATN& ModalLexer::getATN() const {
  return *modallexerLexerStaticData->atn;
}




void ModalLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  modallexerLexerInitialize();
#else
  ::antlr4::internal::call_once(modallexerLexerOnceFlag, modallexerLexerInitialize);
#endif
}
