#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include "attributes.h"
#include "parser.tab.hpp"
#include "errors.h"
#include "utils.h"
#include <stdlib.h>

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
	PRINT_COMMENT("poping arguments");
//	EMIT("add $sp, $sp, " + ToString<int>(4 * symType.argTypes.size()));
//	EMIT("jr $ra");
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
	
	//hw5
	a->place=id->place;


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
	PRINT_COMMENT("back-patching stmt->nextlist with " + m->quad);
	CodeBuffer::instance().bpatch(statements->nextlist, m->quad);
	a->nextlist = statement->nextlist;
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
sp p16(sp type, sp id, sp assign, sp exp, sp sc, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p16 Statement -> Type ID ASSIGN Exp SC" << endl;
#endif DEBUG
	SymbolType symType(type->terminal->token);
	ASSERT_ASSIGNABLE(symType.type, exp->expressionType);
	sp a = sp(new Node());
	DECLARE_VAR(type, id);
	//hw5:
	PRINT_COMMENT("declaring "+id->lexeme+ " with the value in " + exp->reg->getName());
	EMIT("sub $sp, $sp, 4");
	EMIT("sw "+ exp->reg->getName() +", ($sp)");
	RegisterPool::instance().returnRegister(exp->reg);
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
	int offset = TOP_T.getOffset(id->lexeme);
	PRINT_COMMENT("assigning to "+ id->lexeme + " the value in " + exp->reg->getName());
	EMIT("sw " + exp->reg->getName() + ", " + ToString<int>(offset*-4) + "($fp)");
	RegisterPool::instance().returnRegister(exp->reg);
	return a;
}
//Statement -> Call SC
sp p18(sp _call, sp sc, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p18" << endl;
#endif DEBUG
	sp a = sp(new Node());
	RegisterPool::instance().returnRegister(_call->reg);

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

	EMIT("move $v0, " + exp->reg->getName());
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
	PRINT_COMMENT("rule p21 Statement IF LPAREN Exp RPAREN Statement");
	PRINT_COMMENT("back-patching exp->truelist with " + m->quad);
	CodeBuffer::instance().bpatch(exp->truelist, m->quad);
	PRINT_COMMENT("merging exp->falselist with stmt->nextlist");
	a->nextlist = CodeBuffer::merge(exp->falselist, statement->nextlist);
	PRINT_COMMENT("back - patching exp->falselist with " + m2->quad);
	CodeBuffer::instance().bpatch(exp->falselist , m2->quad);
	return a;
};

sp p21e(sp exp) {
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
	a->nextlist = exp->falselist;
	EMIT("j " + m1->quad);
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

	return a;
};
//Statement -> SWITCH LPAREN Exp RPRAREN LBRACE CaseList RBREACE SC
sp p26(sp _switch, sp lparen, sp exp, sp rparen, sp lbrace, sp caseList, sp rbrace, sp sc, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p26" << endl;
#endif DEBUG
	sp a = sp(new Node());


	return a;
};

void p26e(sp exp) {
	vector<int> types;
	types.push_back(INT);
	types.push_back(BYTE);
	ASSERT_ANY_OF_TYPES(exp->expressionType, types);
}
//STatement -> CaseList CaseSTatmetn
sp p27(sp caseList, sp caseStatement, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p27" << endl;
#endif DEBUG
	sp a = sp(new Node());

	return a;
};
//CaseList -> CaseStatemnt
sp p28(sp caseStatement, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p28" << endl;
#endif DEBUG
	sp a = sp(new Node());

	return a;
};
//CaseStatmetn -> CaseDec Statements
sp p29(sp caseDec, sp statements, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p29" << endl;
#endif DEBUG
	sp a = sp(new Node());

	return a;
};
//CaseStatemtn -> CaseDec
sp p30(sp caseDec, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p30" << endl;
#endif DEBUG
	sp a = sp(new Node());

	return a;
};
//CaseDec -> CASE NUM COLON
sp p31(sp _case, sp num, sp colon, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p31" << endl;
#endif DEBUG
	sp a = sp(new Node());

	return a;
};
//CaseDec -> CASE NUM B COLON
sp p32(sp _case, sp num, sp b, sp colon, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p32" << endl;
#endif DEBUG
	sp a = sp(new Node());

	return a;
};
//CaseDec -> DEFAULT COLON
sp p33(sp _default, sp colon, TablesPtr tables, OffsetsPtr offsets, DefaultsPtr defaults) {
#ifdef DEBUG
	cout << "p33 CaseDec -> DEFAULT COLON" << TOP_D << endl;
#endif DEBUG
	if (++TOP_D > 1) {
		throw ErrorTooManyDefaults();
	}
	sp a = sp(new Node());

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
	PRINT_COMMENT("Call " + id->lexeme + "(expList)");
	//for printing:
	if (id->lexeme == "printi" || id->lexeme == "print") {
		//for printi
		//expList can be either a 1. number: printi(5) 2. varible: printi(x) 3. function: printi(foo())
		//it can also be any combintion: printi(5+x*foo())
		//we can canonalize it by desiding that in any case the field expList.place will hold the adress of the value;
		//
		// for print("some_string") there can be only one way. the string has to have a label.
		// the label has to be saved in explist->place.\

		int syscall_num = (id->lexeme == "printi") ? 1 : 4 ;
		EMIT("li $v0, " + (ToString<int>(syscall_num))); //system call for printing integer;
		EMIT("move $a0, " + ((expList->reg)? expList->reg->getName(): ""));
		EMIT("syscall");
		RegisterPool::instance().returnRegister(expList->reg);
		expList->reg = NULL;
		return a;
	}
	RegisterPool::instance().storeAll();
	//previous return address
	EMIT("sub $sp, sp, 4");
	EMIT("sw $ra, ($sp)");
	//arguments
	vector<ar> args= expList->arguments;
	for (int i = 0; i< args.size(); i++)
	{
		EMIT("sub $sp, sp, 4");
		EMIT("sw "+args[i]->place+", ($sp)");
	}

	EMIT("jal " + id->lexeme);
	//somehow we need to push the argument to the stack.
	//we need the code to be right after id->lexeme;
	RegisterPool::instance().restoreAll();
	a->reg = RegisterPool::instance().getRegister();
	EMIT("move " + a->reg->getName() + " $v0");
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
	RegisterPool::instance().storeAll();
	EMIT("jal " + id->lexeme);
	RegisterPool::instance().restoreAll();
	a->reg = RegisterPool::instance().getRegister();
	EMIT("move " + a->reg->getName() + " $v0");
	return a;
};
//ExpList -> Exp
sp p36(sp exp, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p36" << endl;
#endif DEBUG
	vector<int> expressionTypes;
	expressionTypes.push_back(exp->expressionType);

	sp a = sp(new Node());
	a->expressionTypes = expressionTypes;
	a->reg = exp->reg;


	return a;
};
//ExpList -> Exp COMMA ExpList
sp p37(sp exp, sp comma, sp expList, TablesPtr tables, OffsetsPtr offsets) {
#ifdef DEBUG
	cout << "p37" << endl;
#endif DEBUG
	vector<int> expTypes(expList->expressionTypes);
	//vector<string> expIds(expList->expressionIds);
	vector<int>::iterator it1 = expTypes.begin();
	//vector<string>::iterator it2 = expIds.begin();
	expTypes.insert(it1, exp->expressionType);
	//expIds.insert(it2, exp->expressionId);
	sp a = sp(new Node());
	a->expressionTypes = expTypes;
	//a->expressionIds = expIds;


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
		emit = "add " + exp1->reg->getName() + ", " + exp1->reg->getName() + ", " + exp2->reg->getName();
	}
	else if (binop->lexeme == "-"){
		emit = "sub " + exp1->reg->getName() + ", " + exp1->reg->getName() + ", " + exp2->reg->getName();
	}
	else if (binop->lexeme == "*") {
		emit = "mul " + exp1->reg->getName() + ", " + exp1->reg->getName() + ", " + exp2->reg->getName();
	}
	else {
		EMIT("beq " + exp2->reg->getName() + ", zero, div_by_zero");
		emit = "div " + exp1->reg->getName() + ", " + exp1->reg->getName() + ", " + exp2->reg->getName();
	}
	EMIT(emit);
	RegisterPool::instance().returnRegister(exp2->reg);
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
	a->reg = RegisterPool::instance().getRegister();
	int offset = TOP_T.getOffset(id->lexeme);
	EMIT("lw " + a->reg->getName() + ", " + ToString<int>(offset*-4) + "($fp)");

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
	a->reg = RegisterPool::instance().getRegister();
	EMIT("li " + a->reg->getName() + ", " + num->lexeme);
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
	a->reg = RegisterPool::instance().getRegister();
	EMIT("li " + a->reg->getName() + ", " + num->lexeme);

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
	EMIT_DATA("label_" + ToString<int>(str_index) + ": .asciiz " +_string->lexeme);
	a->reg = RegisterPool::instance().getRegister();
	EMIT("la " + a->reg->getName() + ", label_" + ToString<int>(str_index++));

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
	PRINT_COMMENT("rule p48 Exp -> TRUE");
	a->truelist = CodeBuffer::makelist(EMIT("j "));
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
	PRINT_COMMENT("rule p49 Exp -> FALSE");
	a->falselist = CodeBuffer::makelist(EMIT("j "));
	a->boolian = false;

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
	PRINT_COMMENT("rule p51 Exp -> Exp AND Exp");
	PRINT_COMMENT("back-patching exp1->truelist with " + m->quad);
	CodeBuffer::instance().bpatch(exp1->truelist, m->quad);
	a->truelist = exp2->truelist;
	PRINT_COMMENT("merging exp1->falselist with exp2->falselist");
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
	PRINT_COMMENT("rule p52 Exp -> Exp OR Exp");
	PRINT_COMMENT("back-patching exp1->falselist with " + m->quad);
	CodeBuffer::instance().bpatch(exp1->falselist, m->quad);
	PRINT_COMMENT("merging exp1->truelist with exp2->truelist");
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
	PRINT_COMMENT("rule p54 Exp -> Exp RELOP Exp");
	string e_str;
	string rel = relop->lexeme;
	string reg1 = exp1->reg->getName();
	string reg2 = exp2->reg->getName();
	if (rel == "==") e_str = "beq " + reg1 + ", " + reg2 + ", ";
	if (rel == "!=") e_str = "bne " + reg1 + ", " + reg2 + ", ";
	if (rel == "<") e_str = "blt " + reg1 + ", " + reg2 + ", ";
	if (rel == ">") e_str = "bgt " + reg1 + ", " + reg2 + ", ";
	if (rel == "<=") e_str = "ble " + reg1 + ", " + reg2 + ", ";
	if (rel == ">=") e_str = "bge " + reg1 + ", " + reg2 + ", ";
	a->truelist = CodeBuffer::makelist(EMIT(e_str));
	a->falselist = CodeBuffer::makelist(EMIT("j "));
	RegisterPool::instance().returnRegister(exp1->reg);
	RegisterPool::instance().returnRegister(exp2->reg);

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
