#ifndef UTILS_H_
#define UTILS_H_

#include <stack>
#include <map>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <sstream>
#include <stdexcept>
#include "bp.hpp"
#include "output.hpp"
#include "AddressDescriptor.h"
#include "SymbolType.h"
#include "RegisterPool.h"
using namespace output;
using boost::shared_ptr;
using namespace std;

#define POP_T tables->pop()
#define POP_O offsets->pop()
#define POP_D defaults->pop()
#define PUSH_T(t) tables->push(t)
#define PUSH_O(o) offsets->push(o)
#define PUSH_D(d) defaults->push(d)
#define TOP_O offsets->top()
#define TOP_T tables->top()
#define TOP_D defaults->top()
#define INSERT_VAR(name,type) (TOP_T).insert(name, TOP_O, type); TOP_O +=1
#define INSERT_FUNC(name,type) (TOP_T).insert(name, 0, type)
#define INSERT_FUNC_ARGS(args) (TOP_T).insertFunctionArguments(args, 0)
//hw5
#define PRINT_COMMENT(comment) CodeBuffer::instance().emit("\t\t# " + string(comment))
#define EMIT(line) CodeBuffer::instance().emit(string(line))
#define EMIT_DATA(line) CodeBuffer::instance().emitData(string(line))

using namespace std;
struct Argument;
typedef shared_ptr<Argument> ar;

struct Argument {
	string id;
	int type; //token
	string place;
};


template <typename T>
string ToString(T n)
{
	ostringstream ss;
	ss << n;
	return ss.str();
}
string TokenToString(int);

inline ostream & operator<<(ostream &os, SymbolType const &s) {
	if (s.isFunction) {
		string ss;
		for (vector<int>::const_iterator i = s.argTypes.begin(); i != s.argTypes.end(); ++i)
		{
			string n = ToString<int>(*i);
			ss = ss + "," + n;
		}
		return os << "(" << ss << ")->" << s.type;
	}
	else return os << s.type;
}

//typedef pair<int, SymbolType> SymTableTuple;

class SymTable {

public:
	//TODO: change to shared_ptr
	SymTable * _parent;
	map<string, AddressDescriptor> table; //(name) -> offset, type
	vector<string> tableWithOrder;
	void setParent(SymTable & parent) {
		_parent = &parent;
	}
	SymTable(const SymTable & r) {
		_parent = r._parent;
		table = r.table;
	};
	SymTable() :_parent(NULL) {

	};
	int getDepth() {
		if (_parent == NULL)
		{
			return 0;
		}
		return _parent->getDepth() + 1;
	}

	static SymTable createWithParent(SymTable & parent) {
		SymTable t = SymTable();
		t.setParent(parent);
		return t;
	}
	void insert(string symbolName, int offset, SymbolType symbolType);
	void insertFunctionArguments(vector<ar> args, int offset);

	SymbolType getType(string symbolName) const;
	int getOffset(string symbolName) const;
	int size() {
		return table.size();
	}
	void print();


	struct SymbolAlreadyExists : public exception {
		string s;
		SymbolAlreadyExists() {};
		SymbolAlreadyExists(string s) :s(s) {};
		virtual ~SymbolAlreadyExists() throw () {};
	};
	class SymbolDoesNotExist : public exception {};
};

#endif /* UTILS_H_ */
