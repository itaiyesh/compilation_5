#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include "attributes.h"
#include "parser.tab.hpp"
#include "errors.h"
#include "utils.h"
#include "RegisterPoolManager.h"
#include <stdlib.h>

#define STORE_ALL() RegisterPoolManager::instance().storeAll()
#define RESTORE_ALL() RegisterPoolManager::instance().restoreAll()
#define FREE_REG(reg) RegisterPoolManager::instance().freeRegister(reg)
#define GET_REG()  RegisterPoolManager::instance().getRegister()
// Using macros wherever we  access to tables/offsets, easier
#define DECLARE_VAR(type,id)  try {\
		SymbolType symType(type->terminal->token);\
		INSERT_VAR(id->lexeme,symType);\
	}\
	catch(SymTable::SymbolAlreadyExists & e){\
		throw ErrorDef(id->lexeme);\
	}

#define ASSERT_DEFINED(id) try {\
								if(TOP_T.getType(id->lexeme).isFunction){\
								throw SymTable::SymbolDoesNotExist();\
								}\
							}\
							catch(SymTable::SymbolDoesNotExist & e){\
								throw ErrorUndef(id->lexeme);\
							}

#define ASSERT_FUN_DEFINED(id) try {\
							 if( !(TOP_T.getType(id->lexeme)).isFunction)\
							 	 	 {throw ErrorUndefFunc(id->lexeme);}\
							}\
							catch(SymTable::SymbolDoesNotExist & e){\
								throw ErrorUndefFunc(id->lexeme);\
							}

void ASSERT_ANY_OF_TYPES(int type, vector<int> types) {
	bool found = false;
	for (vector<int>::iterator it = types.begin(); it != types.end(); ++it)
	{
		if (type == *it)
		{
			found = true;
		}
	}
	if (!found) {
		throw ErrorMismatch();
	}
}

void ASSERT_ASSIGNABLE(int target, int source) {
	if (target != source)
	{
		if (target == INT && source == BYTE)
		{
			//allowed
		}
		else {
			throw ErrorMismatch();
		}
	}
}
void ASSERT_ASSIGNABLE_ARGS(vector<int> targets, vector<int> sources, string lexeme) {
	if (targets.size() != sources.size())
	{
		throw ErrorPrototypeMismatch(lexeme, targets);

	}
	for (int i = 0; i<targets.size(); i++)
	{
		try {
			ASSERT_ASSIGNABLE(targets[i], sources[i]);
		}
		catch (ErrorMismatch & r)
		{
			throw ErrorPrototypeMismatch(lexeme, targets);
		}
	}
}
#define GET_TYPE(id) TOP_T.getType(id->lexeme)
vector<int> getArgumentTypes(vector<ar> args) {
	vector<int> argTypes;
	for (int i = 0; i < args.size(); i++)
	{
		argTypes.push_back(args[i]->type);
	}
	return argTypes;
}

#define ASSERT_IS_BYTE(val, str) 	if (val > 255){\
								throw ErrorByteTooLarge(str);}\
//Program->Funcs
sp p1(sp funcs, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p1 Program->Funcs" << endl;
#endif


	return sp(new Node());
}

void empty_boolean_expression(sp exp) {
	PRINT_COMMENT("unresolved boolean expression");
	//m1 code if exp is true
	string quad1 = CodeBuffer::instance().next();
	exp->reg = GET_REG();
	EMIT("li " + exp->reg + ", " + ToString<int>(1));
	vector<int> list1 = CodeBuffer::makelist(EMIT("j "));
	//m2 code if exp is false
	string quad2 = CodeBuffer::instance().next();
	EMIT("li " + exp->reg + ", " + ToString<int>(0));
	//back patching
	PRINT_COMMENT("back-patching exp->truelist with " + quad1);
	CodeBuffer::instance().bpatch(exp->truelist, quad1);
	PRINT_COMMENT("back-patching exp->falselist with " + quad2);
	CodeBuffer::instance().bpatch(exp->falselist, quad2);
	string lbl = CodeBuffer::instance().next();
	PRINT_COMMENT("back-patching list1 with " + lbl);
	CodeBuffer::instance().bpatch(list1, lbl);
}


//Funcs->e
sp p3e(TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p3e Funcs->e" << endl;
#endif DEBUG
	sp a = sp(new Node());

	return a;

}
//Funcs->FuncDecl Funcs
sp p3(sp funcDecl, sp funcs, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p3 Funcs->FuncDecl Funcs" << endl;
#endif DEBUG
	sp a = sp(new Node());

	return a;

}
//FuncDecl -> RetType ID LPAREN Formals RPAREN {MID RULE} ...
void p4M(sp retType, sp id, sp lparen, sp formals, sp rparen, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p4M FuncDecl -> RetType ID LPAREN Formals RPAREN {MID RULE} ..." << endl;
#endif DEBUG
	try {

		vector<ar> args(formals->arguments);
		SymbolType symType(getArgumentTypes(args), retType->returnType);
		INSERT_FUNC(id->lexeme, symType);
	}
	catch (SymTable::SymbolAlreadyExists & e) {
		throw ErrorDef(id->lexeme);
	}
}

//FuncDecl -> RetType ID LPAREN Formals RPAREN LBRACE Statements RBRACE
sp p4(sp retType, sp id, sp lparen, sp formals, sp rparen, sp lbrace, sp statements, sp rbrace, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p4 FuncDecl -> RetType ID LPAREN Formals RPAREN LBRACE Statements RBRACE" << endl;
#endif DEBUG

	sp a = sp(new Node());
	//hw5:
	SymbolType symType = TOP_T.getType(id->lexeme);
	PRINT_COMMENT("rule p4 FuncDecl -> RetType ID LPAREN Formals RPAREN LBRACE Statements RBRACE");
	//PRINT_COMMENT("poping arguments");
//	EMIT("add $sp, $sp, " + ToString<int>(4 * symType.argTypes.size()));
	//we need it because a void function dont got to have return;

	PRINT_COMMENT("Cleanning stack");
	EMIT("add $sp, $sp, "+ToString<int>(4*TOP_O));
	EMIT("jr $ra");
	return a;
}
//RetType -> Type
sp p5(sp type, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p5 RetType -> Type" << endl;
#endif DEBUG

	sp a = sp(new Node);
	a->returnType = type->terminal->token;

	return a;
}
//RetType -> VOID
sp p6(sp _void, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p6 RetType -> VOID" << endl;
#endif DEBUG

	sp a = sp(new Node());

	a->returnType = VOID;


	return a;
}
//Formals -> e
sp p8e(TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p8e" << endl;
#endif DEBUG

	sp a = sp(new Node());

	return a;
}
//Formals ->FormalsList
sp p8(sp formalsList, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p8" << endl;
#endif DEBUG

	sp a = sp(new Node());
	a->arguments = formalsList->arguments;


	return a;
}
//FormalsList -> FormalDecl
sp p9(sp formalDecl, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p9" << endl;
#endif DEBUG

	vector<ar> args;
	args.push_back(formalDecl->argument);
	sp a = sp(new Node());
	a->arguments = args;


	return a;
}
//FormalsList -> FormalDecl COMMA FormalsList
sp p10(sp formalDecl, sp comma, sp formalsList, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p10" << endl;
#endif DEBUG
	vector<ar> args(formalsList->arguments);
	vector<ar>::iterator it = args.begin();
	args.insert(it, formalDecl->argument);

	sp a = sp(new Node());
	a->arguments = args;



	return a;
}
//FormalDecl -> Type ID
sp p11(sp type, sp id, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p11" << endl;
#endif DEBUG




	sp a = sp(new Node());
	ar arg = ar(new Argument());
	arg->type = type->terminal->token;
	arg->id = id->lexeme;


	a->argument = ar(arg);
	



	return a;
}
//Statements -> Statement
sp p12(sp statement, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p12" << endl;
#endif
	PRINT_COMMENT("rule p12 Statements -> Statement");
	sp a = sp(new Node());
	a->nextlist = statement->nextlist;
	a->breaklist = statement->breaklist;
	return a;

}
//Statements -> Statements Statement
sp p13(sp statements, sp m,sp statement, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p13" << endl;
#endif DEBUG
	//HW5:
	PRINT_COMMENT("rule p13 Statements -> Statements Statement");
	sp a = sp(new Node());
	PRINT_COMMENT("back-patching stmts->nextlist with " + m->quad);
	CodeBuffer::instance().bpatch(statements->nextlist, m->quad);
	a->nextlist = statement->nextlist;
	a->breaklist = CodeBuffer::merge(statements->breaklist, statement->breaklist);
	return a;
}
//Statement -> LBRACE Statements RBRACE
sp p14(sp lbrace, sp statements, sp rbrace, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p14" << endl;
#endif DEBUG
	sp a = sp(new Node());
	//hw5:
	a->nextlist = statements->nextlist;
	a->breaklist = statements->breaklist;

	return a;
}
//Statement -> Type ID SC
sp p15(sp type, sp id, sp sc, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p15" << endl;
#endif DEBUG
	sp a = sp(new Node());

	DECLARE_VAR(type, id);

	//hw5:
	PRINT_COMMENT("declaring " + id->lexeme + " with no value");
	EMIT("sub $sp, $sp, 4");
	EMIT("sw 0, ($sp)");

	return a;
}
//Statement -> Type ID ASSIGN Exp SC
sp p16(sp type, sp id, sp assign, sp exp, sp sc,TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p16 Statement -> Type ID ASSIGN Exp SC" << endl;
#endif DEBUG
	SymbolType symType(type->terminal->token);
	ASSERT_ASSIGNABLE(symType.type, exp->expressionType);
	sp a = sp(new Node());
	DECLARE_VAR(type, id);
	//hw5:
	if (symType.type == BOOL && exp->reg.empty()) {
		empty_boolean_expression(exp);
	}
	PRINT_COMMENT("declaring "+id->lexeme+ " with the value in " + exp->reg);
	EMIT("sub $sp, $sp, 4");
	EMIT("sw "+ exp->reg +", ($sp)");
	FREE_REG(exp->reg);
	return a;
}
//Statement -> ID ASSIGN Exp SC
sp p17(sp id, sp assign, sp exp, sp sc, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p17" << endl;
#endif DEBUG
	ASSERT_DEFINED(id);
	SymbolType symType = GET_TYPE(id);
	ASSERT_ASSIGNABLE(symType.type, exp->expressionType);
	sp a = sp(new Node());
	//hw5:
	if (exp->reg.empty()) {
		empty_boolean_expression(exp);
	}
	int offset = TOP_T.getOffset(id->lexeme);
	PRINT_COMMENT("assigning to "+ id->lexeme + " the value in " + exp->reg);
	EMIT("sw " + exp->reg + ", " + ToString<int>(offset*-4) + "($fp)");
	FREE_REG(exp->reg);
	return a;
}
//Statement -> Call SC
sp p18(sp _call, sp sc, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p18" << endl;
#endif DEBUG
	sp a = sp(new Node());
	if(!_call->reg.empty()) FREE_REG(_call->reg);

	return a;
};
//Statement -> RETURN SC
sp p19(sp _return, sp sc, TablesPtr tables, OffsetsPtr offsets, int curr_ret_type) {
#ifdef DEBUG
	cout << "p19 Statement -> RETURN SC" << endl;
#endif DEBUG
	vector<int> types;
	types.push_back(VOID);
	ASSERT_ANY_OF_TYPES(curr_ret_type, types);
	sp a = sp(new Node());

	PRINT_COMMENT("Cleanning stack");
	EMIT("add $sp, $sp, "+ToString<int>(4*TOP_O));
	EMIT("jr $ra");

	return a;
}
//Statement RETURN Exp SC
sp p20(sp _return, sp exp, sp sc, TablesPtr tables, OffsetsPtr offsets, int curr_ret_type) {
#ifdef DEBUG
	cout << "p20" << endl;
#endif DEBUG
	ASSERT_ASSIGNABLE(curr_ret_type, exp->expressionType);
	sp a = sp(new Node());
	if (exp->reg.empty()) {
		empty_boolean_expression(exp);
	}

	EMIT("move $v0, " + exp->reg);
	PRINT_COMMENT("Cleanning stack");
	EMIT("add $sp, $sp, "+ToString<int>(4*TOP_O));
	EMIT("jr $ra");

	return a;
};
//Statement IF LPAREN Exp RPAREN Statement
sp p21(sp exp, sp m, sp statement, sp m2) {
#ifdef DEBUG
	cout << "p21" << endl;
#endif DEBUG

	sp a = sp(new Node());
	//hw5:
	//PRINT_COMMENT("rule p21 Statement IF LPAREN Exp RPAREN Statement");
	//PRINT_COMMENT("back-patching exp->truelist with " + m->quad);
	CodeBuffer::instance().bpatch(exp->truelist, m->quad);
	//PRINT_COMMENT("merging exp->falselist with stmt->nextlist");
	a->nextlist = CodeBuffer::merge(exp->falselist, statement->nextlist);
	//PRINT_COMMENT("back - patching exp->falselist with " + m2->quad);
	CodeBuffer::instance().bpatch(exp->falselist , m2->quad);
	a->breaklist = statement->breaklist;
	return a;
};

sp p21e(sp exp) {
#ifdef DEBUG
	cout << "p21e" << endl;
#endif DEBUG
	vector<int> types;
	types.push_back(BOOL);
	ASSERT_ANY_OF_TYPES(exp->expressionType, types);
	//hw5:

	return exp;

}

//Statement IF LPAREN Exp RPAREN Sttatemnt ELSE Statement
sp p22() {
#ifdef DEBUG
	cout << "p22 Statement->IF LPAREN Exp RPAREN Sttatemnt ELSE Statement" << endl;
#endif DEBUG


	sp a = sp(new Node());

	return a;
};
//Statement-> WHILE LPAREN Exp RPAREN Statmenet
// WHILE _while_open M_BOOLEAN LPAREN Exp {p21e($4);} RPAREN M_BOOLEAN Statement  
sp p23(sp m1, sp exp, sp m2, sp statement, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p23 Statement-> WHILE LPAREN Exp RPAREN Statmenet" << endl;
#endif DEBUG

	vector<int> types;
	types.push_back(BOOL);
	ASSERT_ANY_OF_TYPES(exp->expressionType, types);
	sp a = sp(new Node());

	//hw5:
	PRINT_COMMENT("rule p23 Statement-> WHILE M1 LPAREN Exp RPAREN M2 Statmenet");
	PRINT_COMMENT("back-patching stmt->nextlist with " + m1->quad);
	CodeBuffer::instance().bpatch(statement->nextlist, m1->quad);
	PRINT_COMMENT("back-patching exp->truelist with " + m2->quad);
	CodeBuffer::instance().bpatch(exp->truelist, m2->quad);
	a->nextlist = CodeBuffer::merge(exp->falselist, statement->breaklist);
	EMIT("j " + m1->quad);
	CodeBuffer::instance().bpatch(a->nextlist, CodeBuffer::instance().next());
	return a;
};
//Statement -> Statement (inner statement for IF) TODO: My addition
//statement -> if (EXP) M1 S1 N ELSE M2  S2
sp p24(sp exp, sp m1, sp s1, sp n, sp m2, sp s2) {
#ifdef DEBUG
	cout << "p24" << endl;
#endif DEBUG
	sp a = sp(new Node());
	//hw5:
	PRINT_COMMENT("rule p24 statement -> if (EXP) M1 S1 N ELSE M2  S2");
	PRINT_COMMENT("back-patching exp->truelist with " + m1->quad);
	CodeBuffer::instance().bpatch(exp->truelist, m1->quad);
	PRINT_COMMENT("back-patching exp->falselist with " + m2->quad);
	CodeBuffer::instance().bpatch(exp->falselist, m2->quad);

	a->nextlist = CodeBuffer::merge(CodeBuffer::merge(s1->nextlist, n->nextlist), s2->nextlist);
	string lbl = CodeBuffer::instance().next();
	PRINT_COMMENT("back-patching N->nextlist with " + lbl);
	CodeBuffer::instance().bpatch(n->nextlist, lbl);
	a->breaklist = CodeBuffer::merge(s1->breaklist, s2->breaklist);

	return a;
};
//Statmenet -> BREAK SC
sp p25(sp _break, sp sc, TablesPtr tables, OffsetsPtr offsets, int while_counter, int switch_case_counter) {
#ifdef DEBUG
	cout << "p25 Statmenet -> BREAK SC" << endl;
#endif DEBUG
	if (while_counter <= 0 && switch_case_counter <= 0) {
		throw ErrorUnexpectedBreak();
	}
	sp a = sp(new Node());
	a->breaklist = CodeBuffer::makelist(EMIT("j "));
	return a;
};
//Statement -> SWITCH_HEAD SWITCH_BODY SC
sp p26(sp head, sp body, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p26" << endl;
#endif DEBUG
	sp a = sp(new Node());
	string test_lbl = CodeBuffer::instance().next();
	//PRINT_COMMENT("bpatch head->nextlist with " + test_lbl);
	CodeBuffer::instance().bpatch(head->nextlist, test_lbl);
	for (int i = 0; i < body->value_list.size(); ++i) {
		if (body->defalts[i]) {
			//PRINT_COMMENT("jumping to default in " + (body->quad_list)[i]);
			EMIT("j " + (body->quad_list)[i]);
		}
		else {
			//PRINT_COMMENT("case number " + ToString<int>(i));
			EMIT("beq " + head->reg + ", " + (body->value_list)[i] + ", " + (body->quad_list)[i]);
		}
		string next_case = CodeBuffer::instance().next();
		//PRINT_COMMENT("bpatch body->not_break_lists "+ToString<int>(i)+" with " + next_case);
		CodeBuffer::instance().bpatch((body->not_break_lists)[i], next_case);
	}
	string next_lbl = CodeBuffer::instance().next();
	//PRINT_COMMENT("bpatch body->breaklist with " + next_lbl);
	CodeBuffer::instance().bpatch(body->breaklist, next_lbl);
	return a;
};

sp p26e(sp exp) {
	vector<int> types;
	types.push_back(INT);
	types.push_back(BYTE);
	ASSERT_ANY_OF_TYPES(exp->expressionType, types);
	//hw5:
	sp a = sp(new Node());
	//PRINT_COMMENT("switch number: " + ToString<int>(switch_index) + " ;jumping to test which expressions we should do");
	a->reg = exp->reg;
	a->nextlist = CodeBuffer::makelist(EMIT("j "));

	return a;
}

sp p26f(sp caselist) {
	sp a = sp(new Node());
	a->value_list = caselist->value_list;
	PRINT_COMMENT("values are:");
	for (int i = 0; i < a->value_list.size(); ++i) {
		PRINT_COMMENT(a->value_list[i]);
	}
	a->quad_list = caselist->quad_list;
	a->not_break_lists = caselist->not_break_lists;
	a->breaklist = caselist->breaklist;
	a->defalts = caselist->defalts;
	PRINT_COMMENT("defalts are:");
	for (int i = 0; i < a->defalts.size(); ++i) {
		PRINT_COMMENT(ToString<bool>(a->defalts[i]));
	}
	return a;

}
//STatement -> CaseList CaseSTatmetn
sp p27(sp caseList, sp caseStatement, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p27" << endl;
#endif DEBUG
	PRINT_COMMENT("p27 CaseList -> CaseList CaseSTatmetn");
	sp a = sp(new Node());
	a->value_list = caseList->value_list;
	a->quad_list = caseList->quad_list;
	a->not_break_lists = caseList->not_break_lists;
	a->breaklist = CodeBuffer::merge(caseList->breaklist, caseStatement->breaklist);
	a->defalts = caseList->defalts;
	a->value_list.push_back(caseStatement->value);
	PRINT_COMMENT("values are:");
	for (int i = 0; i < a->value_list.size(); ++i) {
		PRINT_COMMENT(a->value_list[i]);
	}
	a->quad_list.push_back(caseStatement->quad);
	a->not_break_lists.push_back(caseStatement->nextlist);
	a->defalts.push_back(caseStatement->defalt);
	PRINT_COMMENT("defalts are:");
	for (int i = 0; i < a->defalts.size(); ++i) {
		PRINT_COMMENT(ToString<bool>(a->defalts[i]));
	}
	return a;
};
//CaseList -> CaseStatemnt
sp p28(sp caseStatement, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p28" << endl;
#endif DEBUG
	PRINT_COMMENT("p28 CaseList -> CaseStatemnt");
	sp a = sp(new Node());
	//stack<string> value_list;
	//stack<string> quad_list;
	a->value_list.push_back(caseStatement->value);
	PRINT_COMMENT("values are:");
	for (int i = 0; i < a->value_list.size(); ++i) {
		PRINT_COMMENT(a->value_list[i]);
}
	a->quad_list.push_back(caseStatement->quad);
	PRINT_COMMENT("defalts are:");
	a->defalts.push_back(caseStatement->defalt);
	for (int i = 0; i < a->defalts.size(); ++i) {
		PRINT_COMMENT(ToString<bool>(a->defalts[i]));
	}
	a->breaklist = caseStatement->breaklist;
	a->not_break_lists.push_back(caseStatement->nextlist);
	return a;
};
//CaseStatmetn -> CaseDec Statements
sp p29(sp caseDec, sp m, sp statements, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p29" << endl;
#endif DEBUG
	PRINT_COMMENT("p29 CaseStatmetn -> CaseDec M Statements");
	sp a = sp(new Node());
	a->breaklist = statements->breaklist;
	a->value = caseDec->value;
	//PRINT_COMMENT("p29 value is: " + a->value);
	a->defalt = caseDec->defalt;
	//PRINT_COMMENT("p29 defalt is: " + ToString<bool>(a->defalt));
	a->quad = m->quad;
	a->nextlist = statements->nextlist;
	a->nextlist.push_back(EMIT("j "));
	return a;
};
//CaseStatemtn -> CaseDec
sp p30(sp caseDec, sp m, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p30" << endl;
#endif DEBUG
	PRINT_COMMENT("p30 CaseStatemtn -> CaseDec");
	sp a = sp(new Node());
	a->value = caseDec->value;
	//PRINT_COMMENT("p30 value is: "+ a->value);
	a->defalt = caseDec->defalt;
	//PRINT_COMMENT("p30 defalt is: " + ToString<bool>(a->defalt));
	a->quad = m->quad;
	a->nextlist = CodeBuffer::makelist(EMIT("j "));
	return a;
};
//CaseDec -> CASE NUM COLON
sp p31(sp _case, sp num, sp colon, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p31" << endl;
#endif DEBUG
	PRINT_COMMENT("p31 CaseDec -> CASE " + num->lexeme + " COLON");
	sp a = sp(new Node());
	a->value = num->lexeme;
	//PRINT_COMMENT("p31 value is: " + a->value);
	a->defalt = false;
	//PRINT_COMMENT("p31 defalt is: " + ToString<bool>(a->defalt));
	return a;
};
//CaseDec -> CASE NUM B COLON
sp p32(sp _case, sp num, sp b, sp colon, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p32" << endl;
#endif DEBUG
	PRINT_COMMENT("p32 CaseDec -> CASE " + num->lexeme + " B COLON");
	sp a = sp(new Node());
	a->value = num->lexeme;
	//PRINT_COMMENT("p32 value is: " + a->value);
	a->defalt = false;
	//PRINT_COMMENT("p32 defalt is: " + ToString<bool>(a->defalt));
	return a;
};
//CaseDec -> DEFAULT COLON
sp p33(sp _default, sp colon, TablesPtr tables, OffsetsPtr offsets, DefaultsPtr defaults) {
#ifdef DEBUG
	cout << "p33 CaseDec -> DEFAULT COLON" << TOP_D << endl;
#endif DEBUG
	PRINT_COMMENT("p33 CaseDec -> DEFAULT COLON");
	if (++TOP_D > 1) {
		throw ErrorTooManyDefaults();
	}
	sp a = sp(new Node());
	a->defalt = true;
	a->value = "has_no_value";
	//PRINT_COMMENT("p33 value is: " + a->value);
	//PRINT_COMMENT("p33 defalt is: " + ToString<bool>(a->defalt));
	return a;
};
//Call -> ID LPAREN ExpList RPAREN
sp p34(sp id, sp lparen, sp expList, sp rparen, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p34" << endl;
#endif DEBUG

	ASSERT_FUN_DEFINED(id);

	SymbolType expectedType = TOP_T.getType(id->lexeme);
	vector<int> expectedArgTypes = expectedType.argTypes;
	vector<int> argTypes = expList->expressionTypes;

	ASSERT_ASSIGNABLE_ARGS(expectedArgTypes, argTypes, id->lexeme);


	//TODO: Call's type is determined just by its return type
	sp a = sp(new Node());
	a->returnType = expectedType.type;

	//HW5:
	PRINT_COMMENT("rule p34 Call " + id->lexeme + "(expList)");
	//for printing:
	if (id->lexeme == "printi" || id->lexeme == "print") {
		//for printi
		//expList can be either a 1. number: printi(5) 2. varible: printi(x) 3. function: printi(foo())
		//it can also be any combintion: printi(5+x*foo())
		//we can canonalize it by desiding that in any case the field expList.place will hold the adress of the value;
		//
		// for print("some_string") there can be only one way. the string has to have a label.
		// the label has to be saved in explist->reg.\

		int syscall_num = (id->lexeme == "printi") ? 1 : 4 ;
		EMIT("li $v0, " + (ToString<int>(syscall_num))); //system call for printing integer;
		EMIT("move $a0, " + expList->reg);
		EMIT("syscall");
		//if(id->lexeme == "printi") 
		FREE_REG(expList->reg);
		expList->reg="";
		return a;
	}
	//store registers
	PRINT_COMMENT("Storing registers");
	STORE_ALL();
	//store previous return address
	EMIT("sub $sp, $sp, 4");
	EMIT("sw $ra, ($sp)");
	//store arguments
	vector<ex> expressions= expList->expressionList;
	PRINT_COMMENT("Storing "+ToString<int>(expressions.size())+" arguments");
	for (int i = 0; i< expressions.size(); i++)
	{
		EMIT("sub $sp, $sp, 4");
		EMIT("sw "+expressions[i]->reg+", ($sp)");
	}

	//new register pool
	RegisterPoolManager::instance().push();

	EMIT("jal " + id->lexeme);

	//pop register pool
	RegisterPoolManager::instance().pop();

	//pop args
	PRINT_COMMENT("Poping arguments");
	EMIT("add $sp, $sp, "+ToString<int>(expressions.size()*4));

	//restore return address
	EMIT("lw $ra, ($sp)");
	EMIT("add $sp, $sp, 4");

	//restore registers
	PRINT_COMMENT("Restoring registers");
	RESTORE_ALL();

	a->reg = GET_REG();
	EMIT("move " + a->reg+ " $v0");
	return a;
};
//Call -> ID LPAREN RPAREN
sp p35(sp id, sp lparen, sp rparen, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p35" << endl;
#endif DEBUG
	ASSERT_FUN_DEFINED(id);

	SymbolType expectedType = TOP_T.getType(id->lexeme);
	vector<int> expectedArgTypes = expectedType.argTypes;
	//TODO: May need to insert VOID here
	vector<int> argTypes;
	ASSERT_ASSIGNABLE_ARGS(expectedArgTypes, argTypes, id->lexeme);

	//	//TODO: Call's type is determined just by its return type

	sp a = sp(new Node());
	a->returnType = expectedType.type;


	//store registers
	STORE_ALL();
	//store previous return address
	EMIT("sub $sp, $sp, 4");
	EMIT("sw $ra, ($sp)");
	//store arguments
	//Dont have any

	RegisterPoolManager::instance().push();

	EMIT("jal " + id->lexeme);

	RegisterPoolManager::instance().pop();

	//pop args
	//dont have any

	//restore return address
	EMIT("lw $ra, ($sp)");
	EMIT("add $sp, $sp, 4");

	//restore registers
	RESTORE_ALL();


	a->reg = GET_REG();
	EMIT("move " + a->reg + " $v0");
	return a;
};
//ExpList -> Exp
sp p36(sp exp, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p36" << endl;
#endif DEBUG
	vector<int> expressionTypes;
	expressionTypes.push_back(exp->expressionType);
	if (exp->reg.empty()) {
		empty_boolean_expression(exp);
	}

	//This is where exp becomes an argument
	vector<ex> expressionList;
	ex _ex = ex(new Expression());
	_ex->reg = exp->reg;
	expressionList.push_back(_ex);

	sp a = sp(new Node());
	a->expressionTypes = expressionTypes;
	a->expressionList =expressionList;
	a->reg = exp->reg;


	return a;
};
//ExpList -> Exp COMMA ExpList
sp p37(sp exp, sp comma, sp expList, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p37" << endl;
#endif DEBUG

	vector<int> expTypes(expList->expressionTypes);
	vector<int>::iterator it1 = expTypes.begin();
	expTypes.insert(it1, exp->expressionType);
	sp a = sp(new Node());
	a->expressionTypes = expTypes;

	//This is where exp becomes an argument
	vector<ex> expressionList;
	ex _ex = ex(new Expression());
	_ex->reg = exp->reg;
	expressionList.push_back(_ex);

	expressionList.insert(expressionList.end(), expList->expressionList.begin(), expList->expressionList.end());
	a->expressionList=expressionList;

	return a;
};
//Type -> INT
sp p38(sp _int, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p38" << endl;
#endif DEBUG

	sp a = sp(new Node());
	a->terminal = _int;


	return a;
};
//Type -> BYTE
sp p39(sp _byte, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p39" << endl;
#endif DEBUG

	sp a = sp(new Node());
	a->terminal = _byte;


	return a;
};
//Type -> BOOL
sp p40(sp _bool, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p40" << endl;
#endif DEBUG

	sp a = sp(new Node());
	a->terminal = _bool;




	return a;
};
//Exp -> LPAREN Exp RPAREN
sp p41(sp lparen, sp exp, sp rparen, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p41" << endl;
#endif DEBUG

	sp a = sp(new Node());
	a->expressionType = exp->expressionType;
	a->expressionId = exp->expressionId;
	a->reg = exp->reg;
	//hw5:
	PRINT_COMMENT("rule p41 Exp -> LPAREN Exp RPAREN");
	a->truelist = exp->truelist;
	a->falselist = exp->falselist;


	return a;
};
//Exp -> Exp BINOP Exp
sp p42(sp exp1, sp binop, sp exp2, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p42" << endl;
#endif DEBUG

	vector<int> types;
	types.push_back(INT);
	types.push_back(BYTE);
	int type1 = exp1->expressionType;
	int type2 = exp2->expressionType;
	ASSERT_ANY_OF_TYPES(type1, types);
	ASSERT_ANY_OF_TYPES(type2, types);
	//TODO: Empty EXP IS VOID???
	//TODO: 10 - "greater than"?
	int resultType;
	if (type1 == INT || type2 == INT) {
		resultType = INT;
	}
	else
	{
		resultType = BYTE;
	}
	sp a = sp(new Node());
	a->expressionType = resultType;
	a->reg = exp1->reg;
	string emit;
	if (binop->lexeme == "+") {
		emit = "add " + exp1->reg + ", " + exp1->reg + ", " + exp2->reg;
	}
	else if (binop->lexeme == "-"){
		emit = "sub " + exp1->reg + ", " + exp1->reg + ", " + exp2->reg;
	}
	else if (binop->lexeme == "*") {
		emit = "mul " + exp1->reg + ", " + exp1->reg + ", " + exp2->reg;
	}
	else {
		EMIT("beq " + exp2->reg + ", zero, div_by_zero");
		emit = "div " + exp1->reg + ", " + exp1->reg + ", " + exp2->reg;
	}
	EMIT(emit);
	FREE_REG(exp2->reg);
	return a;
};
//Exp -> ID
sp p43(sp id, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p43" << endl;
#endif DEBUG

	ASSERT_DEFINED(id);
	//TODO: If ID is function???
	SymbolType symbolType = GET_TYPE(id);
	int type = symbolType.type;


	sp a = sp(new Node());
	a->expressionType = type;
	a->reg = GET_REG();
	int offset = TOP_T.getOffset(id->lexeme);
	EMIT("lw " + a->reg + ", " + ToString<int>(offset*-4) + "($fp)");

	return a;
};
//Exp -> Call
sp p44(sp _call, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p44" << endl;
#endif DEBUG

	sp a = sp(new Node());
	a->expressionType = _call->returnType;
	a->reg = _call->reg;



	return a;
};
//Exp -> NUM
sp p45(sp num, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p45" << endl;
#endif DEBUG

	sp a = sp(new Node());
	a->expressionType = INT;
	a->reg = GET_REG();
	EMIT("li " + a->reg + ", " + num->lexeme);
	return a;
};
//Exp -> NUM B
sp p46(sp num, sp b, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p46" << endl;
#endif DEBUG

	sp a = sp(new Node());
	a->expressionType = BYTE;
	a->value = num->lexeme;
	ASSERT_IS_BYTE(atoi(num->lexeme.c_str()), num->lexeme);
	a->reg = GET_REG();
	EMIT("li " + a->reg+ ", " + num->lexeme);

	return a;
};
//Exp -> STRING
static int str_index = 0;
sp p47(sp _string, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p47" << endl;
#endif DEBUG

	sp a = sp(new Node());
	a->expressionType = STRING;
	//hw5:
	PRINT_COMMENT("rule p47 Exp -> STRING");
	EMIT_DATA("str_" + ToString<int>(str_index) + ": .asciiz " +_string->lexeme);
	a->reg = GET_REG();
	EMIT("la " + a->reg + ", str_" + ToString<int>(str_index++));

	return a;
};
//Exp -> TRUE
sp p48(sp _true, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p48" << endl;
#endif DEBUG

	sp a = sp(new Node());
	a->expressionType = BOOL;
	//hw5:
	a->truelist = CodeBuffer::makelist(EMIT("j "));
	a->reg = GET_REG();
	EMIT("li " + a->reg + ", 1");
	a->boolian = true;
	return a;
};
//Exp -> FALSE
sp p49(sp _false, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p49" << endl;
#endif DEBUG

	sp a = sp(new Node());
	a->expressionType = BOOL;
	a->falselist = CodeBuffer::makelist(EMIT("j "));
	a->boolian = false;
	a->reg = GET_REG();
	EMIT("li " + a->reg + ", 0");
	return a;
};
//Exp -> NOT Exp
sp p50(sp _not, sp exp, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p50" << endl;
#endif DEBUG

	vector<int> types;
	types.push_back(BOOL);
	int type = exp->expressionType;
	ASSERT_ANY_OF_TYPES(type, types);

	sp a = sp(new Node());
	a->expressionType = BOOL;
	PRINT_COMMENT("rule p50 Exp -> NOT Exp");
	//hw5:
	a->truelist = exp->falselist;
	a->falselist = exp->truelist;


	return a;
};
//Exp -> Exp AND Exp
sp p51(sp exp1, sp _and, sp m, sp exp2, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p51" << endl;
#endif DEBUG

	vector<int> types;
	types.push_back(BOOL);
	int type1 = exp1->expressionType;
	int type2 = exp2->expressionType;
	ASSERT_ANY_OF_TYPES(type1, types);
	ASSERT_ANY_OF_TYPES(type2, types);

	sp a = sp(new Node());
	a->expressionType = BOOL;
	//hw5:
	PRINT_COMMENT("back-patching exp1->truelist with " + m->quad);
	CodeBuffer::instance().bpatch(exp1->truelist, m->quad);
	a->truelist = exp2->truelist;
	a->falselist = CodeBuffer::merge(exp1->falselist, exp2->falselist);
	return a;
};
//Exp -> Exp OR Exp
sp p52(sp exp1, sp _or,sp m, sp exp2, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p52" << endl;
#endif DEBUG

	vector<int> types;
	types.push_back(BOOL);
	int type1 = exp1->expressionType;
	int type2 = exp2->expressionType;
	ASSERT_ANY_OF_TYPES(type1, types);
	ASSERT_ANY_OF_TYPES(type2, types);

	sp a = sp(new Node());
	a->expressionType = BOOL;

	//hw5:
	PRINT_COMMENT("back-patching exp1->falselist with " + m->quad);
	CodeBuffer::instance().bpatch(exp1->falselist, m->quad);
	a->truelist = CodeBuffer::merge(exp1->truelist, exp2->truelist);
	a->falselist = exp2->falselist;

	return a;
};
//Exp -> Exp RELOP Exp
sp p53(sp exp1, sp relop, sp exp2, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p53" << endl;
#endif DEBUG

	vector<int> types;
	//TODO: ANY OTHER num type to consider?
	types.push_back(INT);
	types.push_back(BYTE);
	int type1 = exp1->expressionType;
	int type2 = exp2->expressionType;
	ASSERT_ANY_OF_TYPES(type1, types);
	ASSERT_ANY_OF_TYPES(type2, types);

	sp a = sp(new Node());
	a->expressionType = BOOL;
	//hw5:
	string e_str;
	string rel = relop->lexeme;
	string reg1 = exp1->reg;
	string reg2 = exp2->reg;
	if (rel == "==") e_str = "beq " + reg1 + ", " + reg2 + ", ";
	if (rel == "!=") e_str = "bne " + reg1 + ", " + reg2 + ", ";
	if (rel == "<") e_str = "blt " + reg1 + ", " + reg2 + ", ";
	if (rel == ">") e_str = "bgt " + reg1 + ", " + reg2 + ", ";
	if (rel == "<=") e_str = "ble " + reg1 + ", " + reg2 + ", ";
	if (rel == ">=") e_str = "bge " + reg1 + ", " + reg2 + ", ";
	a->truelist = CodeBuffer::makelist(EMIT(e_str));
	a->falselist = CodeBuffer::makelist(EMIT("j "));
	FREE_REG(exp1->reg);
	FREE_REG(exp2->reg);
	//TODO: need to return value;
	return a;
};

sp p54() {
	PRINT_COMMENT("rule p54 M->quad...");
	sp a = sp(new Node());
	a->quad = CodeBuffer::instance().next();
	return a;
}

sp p55() {
	PRINT_COMMENT("rule p55 N_BOOLEAM");
	sp a = sp(new Node());
	a->nextlist = CodeBuffer::makelist(EMIT("j "));

	return a;
}


#endif /* PRODUCTION_H_ */
