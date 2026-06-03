// Generated from /home/thabo/Projects/s5_solver/grammars/Modal.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class ModalParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		BOX=1, DIAMOND=2, NOT=3, AND=4, OR=5, IMPLIES=6, LPAREN=7, RPAREN=8, LBRACK=9, 
		RBRACK=10, LANG=11, RANG=12, INT=13, IDENTIFIER=14, WS=15;
	public static final int
		RULE_formula = 0, RULE_implication = 1, RULE_disjunction = 2, RULE_conjunction = 3, 
		RULE_unary = 4, RULE_modal = 5, RULE_agentBox = 6, RULE_agentDiamond = 7, 
		RULE_atom = 8;
	private static String[] makeRuleNames() {
		return new String[] {
			"formula", "implication", "disjunction", "conjunction", "unary", "modal", 
			"agentBox", "agentDiamond", "atom"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'[]'", "'<>'", "'!'", "'&'", "'|'", "'->'", "'('", "')'", "'['", 
			"']'", "'<'", "'>'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "BOX", "DIAMOND", "NOT", "AND", "OR", "IMPLIES", "LPAREN", "RPAREN", 
			"LBRACK", "RBRACK", "LANG", "RANG", "INT", "IDENTIFIER", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Modal.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public ModalParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FormulaContext extends ParserRuleContext {
		public ImplicationContext implication() {
			return getRuleContext(ImplicationContext.class,0);
		}
		public TerminalNode EOF() { return getToken(ModalParser.EOF, 0); }
		public FormulaContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formula; }
	}

	public final FormulaContext formula() throws RecognitionException {
		FormulaContext _localctx = new FormulaContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_formula);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(18);
			implication();
			setState(19);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ImplicationContext extends ParserRuleContext {
		public DisjunctionContext disjunction() {
			return getRuleContext(DisjunctionContext.class,0);
		}
		public TerminalNode IMPLIES() { return getToken(ModalParser.IMPLIES, 0); }
		public ImplicationContext implication() {
			return getRuleContext(ImplicationContext.class,0);
		}
		public ImplicationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_implication; }
	}

	public final ImplicationContext implication() throws RecognitionException {
		ImplicationContext _localctx = new ImplicationContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_implication);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(21);
			disjunction();
			setState(24);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IMPLIES) {
				{
				setState(22);
				match(IMPLIES);
				setState(23);
				implication();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DisjunctionContext extends ParserRuleContext {
		public List<ConjunctionContext> conjunction() {
			return getRuleContexts(ConjunctionContext.class);
		}
		public ConjunctionContext conjunction(int i) {
			return getRuleContext(ConjunctionContext.class,i);
		}
		public List<TerminalNode> OR() { return getTokens(ModalParser.OR); }
		public TerminalNode OR(int i) {
			return getToken(ModalParser.OR, i);
		}
		public DisjunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_disjunction; }
	}

	public final DisjunctionContext disjunction() throws RecognitionException {
		DisjunctionContext _localctx = new DisjunctionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_disjunction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(26);
			conjunction();
			setState(31);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==OR) {
				{
				{
				setState(27);
				match(OR);
				setState(28);
				conjunction();
				}
				}
				setState(33);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConjunctionContext extends ParserRuleContext {
		public List<UnaryContext> unary() {
			return getRuleContexts(UnaryContext.class);
		}
		public UnaryContext unary(int i) {
			return getRuleContext(UnaryContext.class,i);
		}
		public List<TerminalNode> AND() { return getTokens(ModalParser.AND); }
		public TerminalNode AND(int i) {
			return getToken(ModalParser.AND, i);
		}
		public ConjunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conjunction; }
	}

	public final ConjunctionContext conjunction() throws RecognitionException {
		ConjunctionContext _localctx = new ConjunctionContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_conjunction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(34);
			unary();
			setState(39);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==AND) {
				{
				{
				setState(35);
				match(AND);
				setState(36);
				unary();
				}
				}
				setState(41);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnaryContext extends ParserRuleContext {
		public TerminalNode NOT() { return getToken(ModalParser.NOT, 0); }
		public UnaryContext unary() {
			return getRuleContext(UnaryContext.class,0);
		}
		public ModalContext modal() {
			return getRuleContext(ModalContext.class,0);
		}
		public AtomContext atom() {
			return getRuleContext(AtomContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(ModalParser.LPAREN, 0); }
		public ImplicationContext implication() {
			return getRuleContext(ImplicationContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(ModalParser.RPAREN, 0); }
		public UnaryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary; }
	}

	public final UnaryContext unary() throws RecognitionException {
		UnaryContext _localctx = new UnaryContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_unary);
		try {
			setState(50);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NOT:
				enterOuterAlt(_localctx, 1);
				{
				setState(42);
				match(NOT);
				setState(43);
				unary();
				}
				break;
			case BOX:
			case DIAMOND:
			case LBRACK:
			case LANG:
				enterOuterAlt(_localctx, 2);
				{
				setState(44);
				modal();
				}
				break;
			case IDENTIFIER:
				enterOuterAlt(_localctx, 3);
				{
				setState(45);
				atom();
				}
				break;
			case LPAREN:
				enterOuterAlt(_localctx, 4);
				{
				setState(46);
				match(LPAREN);
				setState(47);
				implication();
				setState(48);
				match(RPAREN);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ModalContext extends ParserRuleContext {
		public TerminalNode BOX() { return getToken(ModalParser.BOX, 0); }
		public UnaryContext unary() {
			return getRuleContext(UnaryContext.class,0);
		}
		public TerminalNode DIAMOND() { return getToken(ModalParser.DIAMOND, 0); }
		public AgentBoxContext agentBox() {
			return getRuleContext(AgentBoxContext.class,0);
		}
		public AgentDiamondContext agentDiamond() {
			return getRuleContext(AgentDiamondContext.class,0);
		}
		public ModalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_modal; }
	}

	public final ModalContext modal() throws RecognitionException {
		ModalContext _localctx = new ModalContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_modal);
		try {
			setState(62);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOX:
				enterOuterAlt(_localctx, 1);
				{
				setState(52);
				match(BOX);
				setState(53);
				unary();
				}
				break;
			case DIAMOND:
				enterOuterAlt(_localctx, 2);
				{
				setState(54);
				match(DIAMOND);
				setState(55);
				unary();
				}
				break;
			case LBRACK:
				enterOuterAlt(_localctx, 3);
				{
				setState(56);
				agentBox();
				setState(57);
				unary();
				}
				break;
			case LANG:
				enterOuterAlt(_localctx, 4);
				{
				setState(59);
				agentDiamond();
				setState(60);
				unary();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AgentBoxContext extends ParserRuleContext {
		public TerminalNode LBRACK() { return getToken(ModalParser.LBRACK, 0); }
		public TerminalNode INT() { return getToken(ModalParser.INT, 0); }
		public TerminalNode RBRACK() { return getToken(ModalParser.RBRACK, 0); }
		public AgentBoxContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_agentBox; }
	}

	public final AgentBoxContext agentBox() throws RecognitionException {
		AgentBoxContext _localctx = new AgentBoxContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_agentBox);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(64);
			match(LBRACK);
			setState(65);
			match(INT);
			setState(66);
			match(RBRACK);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AgentDiamondContext extends ParserRuleContext {
		public TerminalNode LANG() { return getToken(ModalParser.LANG, 0); }
		public TerminalNode INT() { return getToken(ModalParser.INT, 0); }
		public TerminalNode RANG() { return getToken(ModalParser.RANG, 0); }
		public AgentDiamondContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_agentDiamond; }
	}

	public final AgentDiamondContext agentDiamond() throws RecognitionException {
		AgentDiamondContext _localctx = new AgentDiamondContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_agentDiamond);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			match(LANG);
			setState(69);
			match(INT);
			setState(70);
			match(RANG);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AtomContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(ModalParser.IDENTIFIER, 0); }
		public AtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_atom; }
	}

	public final AtomContext atom() throws RecognitionException {
		AtomContext _localctx = new AtomContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_atom);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(72);
			match(IDENTIFIER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u000fK\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0003\u0001\u0019\b\u0001\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0005\u0002\u001e\b\u0002\n\u0002\f\u0002!\t\u0002\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0005\u0003&\b\u0003\n\u0003\f\u0003)\t\u0003\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0003\u00043\b\u0004\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0003\u0005?\b\u0005\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\b\u0001\b\u0001\b\u0000\u0000\t\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010"+
		"\u0000\u0000J\u0000\u0012\u0001\u0000\u0000\u0000\u0002\u0015\u0001\u0000"+
		"\u0000\u0000\u0004\u001a\u0001\u0000\u0000\u0000\u0006\"\u0001\u0000\u0000"+
		"\u0000\b2\u0001\u0000\u0000\u0000\n>\u0001\u0000\u0000\u0000\f@\u0001"+
		"\u0000\u0000\u0000\u000eD\u0001\u0000\u0000\u0000\u0010H\u0001\u0000\u0000"+
		"\u0000\u0012\u0013\u0003\u0002\u0001\u0000\u0013\u0014\u0005\u0000\u0000"+
		"\u0001\u0014\u0001\u0001\u0000\u0000\u0000\u0015\u0018\u0003\u0004\u0002"+
		"\u0000\u0016\u0017\u0005\u0006\u0000\u0000\u0017\u0019\u0003\u0002\u0001"+
		"\u0000\u0018\u0016\u0001\u0000\u0000\u0000\u0018\u0019\u0001\u0000\u0000"+
		"\u0000\u0019\u0003\u0001\u0000\u0000\u0000\u001a\u001f\u0003\u0006\u0003"+
		"\u0000\u001b\u001c\u0005\u0005\u0000\u0000\u001c\u001e\u0003\u0006\u0003"+
		"\u0000\u001d\u001b\u0001\u0000\u0000\u0000\u001e!\u0001\u0000\u0000\u0000"+
		"\u001f\u001d\u0001\u0000\u0000\u0000\u001f \u0001\u0000\u0000\u0000 \u0005"+
		"\u0001\u0000\u0000\u0000!\u001f\u0001\u0000\u0000\u0000\"\'\u0003\b\u0004"+
		"\u0000#$\u0005\u0004\u0000\u0000$&\u0003\b\u0004\u0000%#\u0001\u0000\u0000"+
		"\u0000&)\u0001\u0000\u0000\u0000\'%\u0001\u0000\u0000\u0000\'(\u0001\u0000"+
		"\u0000\u0000(\u0007\u0001\u0000\u0000\u0000)\'\u0001\u0000\u0000\u0000"+
		"*+\u0005\u0003\u0000\u0000+3\u0003\b\u0004\u0000,3\u0003\n\u0005\u0000"+
		"-3\u0003\u0010\b\u0000./\u0005\u0007\u0000\u0000/0\u0003\u0002\u0001\u0000"+
		"01\u0005\b\u0000\u000013\u0001\u0000\u0000\u00002*\u0001\u0000\u0000\u0000"+
		"2,\u0001\u0000\u0000\u00002-\u0001\u0000\u0000\u00002.\u0001\u0000\u0000"+
		"\u00003\t\u0001\u0000\u0000\u000045\u0005\u0001\u0000\u00005?\u0003\b"+
		"\u0004\u000067\u0005\u0002\u0000\u00007?\u0003\b\u0004\u000089\u0003\f"+
		"\u0006\u00009:\u0003\b\u0004\u0000:?\u0001\u0000\u0000\u0000;<\u0003\u000e"+
		"\u0007\u0000<=\u0003\b\u0004\u0000=?\u0001\u0000\u0000\u0000>4\u0001\u0000"+
		"\u0000\u0000>6\u0001\u0000\u0000\u0000>8\u0001\u0000\u0000\u0000>;\u0001"+
		"\u0000\u0000\u0000?\u000b\u0001\u0000\u0000\u0000@A\u0005\t\u0000\u0000"+
		"AB\u0005\r\u0000\u0000BC\u0005\n\u0000\u0000C\r\u0001\u0000\u0000\u0000"+
		"DE\u0005\u000b\u0000\u0000EF\u0005\r\u0000\u0000FG\u0005\f\u0000\u0000"+
		"G\u000f\u0001\u0000\u0000\u0000HI\u0005\u000e\u0000\u0000I\u0011\u0001"+
		"\u0000\u0000\u0000\u0005\u0018\u001f\'2>";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}