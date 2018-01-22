#include "utils.h"
#include "parser.tab.hpp"

int EMIT(string line) {
	#ifdef DEBUG
	cout << "					; " <<line <<endl;
	#endif DEBUG
	return CodeBuffer::instance().emit(string(line));

}

void SymTable::insert(string symbolName, int offset, SymbolType symbolType) {
	try {
		getType(symbolName);
		throw SymbolAlreadyExists(symbolName);
	}
	catch (SymbolDoesNotExist &e) {
		//SymTableTuple tuple = make_pair(offset, symbolType);
		AddressDescriptor ad(symbolName, symbolType, offset);
		
		table.insert(make_pair(symbolName, ad));
		tableWithOrder.push_back(symbolName);
#ifdef DEBUG
		cout << table.size() - 1 << ": Symbol(" << symbolName << "," << offset << "," << symbolType << ")" << " Table " << getDepth() << endl;
#endif


	}
}

void SymTable::insertFunctionArguments(vector<ar> args, int offset) {
	for (int i = 0; i < args.size(); i++) {
		//TODO: can function accepts function as args?? this is not supported here
		insert(args[i]->id, --offset, args[i]->type);
		
	}
}

SymbolType SymTable::getType(string symbolName) const {
	if (table.find(symbolName) == table.end()) {

		if (_parent == NULL) {
			throw SymbolDoesNotExist();
		}

		return _parent->getType(symbolName);
	}
	else {
		SymbolType t = table.find(symbolName)->second.sym_type;
		t.isFunction;
		return table.find(symbolName)->second.sym_type;
	}
}

int SymTable::getOffset(string symbolName) const {
	if (table.find(symbolName) == table.end()) {

		if (_parent == NULL) {
			throw SymbolDoesNotExist();
		}

		return _parent->getOffset(symbolName);
	}
	else {
		int t = table.find(symbolName)->second.offset;
		//t.isFunction;
		return table.find(symbolName)->second.offset;
	}
}


void SymTable::print() {

	for (vector<string>::iterator it = tableWithOrder.begin(); it != tableWithOrder.end(); it++)
	{
		string id = *it;
		int offset = table.find(id)->second.offset;
		SymbolType type = table.find(id)->second.sym_type;
		string stringType;
		if (type.isFunction)
		{
			vector<string> stringArgTypes;
			for (int i = 0; i < type.argTypes.size(); i++)
			{
				stringArgTypes.push_back(TokenToString(type.argTypes[i]));
			}
			stringType = makeFunctionType(TokenToString(type.type), stringArgTypes);
		}
		else {
			stringType = TokenToString(type.type);
		}

		printID(id, offset, stringType);
	}
}
string TokenToString(int token) {
	switch (token)
	{
	case BOOL:
		return "BOOL";
	case BYTE:
		return "BYTE";
	case INT:
		return "INT";
	case STRING:
		return "STRING";
	case VOID:
		return "VOID";
	default:
		cout << token << endl;
		throw exception();
	}

}






