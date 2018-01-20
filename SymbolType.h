/*
 * SymbolType.h
 *
 *  Created on: 19 αιπε 2018
 *      Author: shurun
 */

#ifndef SYMBOLTYPE_H_
#define SYMBOLTYPE_H_

#include <vector>
#include <string>
using namespace std;

//represents either a function or variable type
class SymbolType {
	SymbolType();
	//SymbolType & operator=(const SymbolType&);
public:
	vector<int > argTypes; //BYTE BOOL INT
	int type; //used as returnType in functions
	bool isFunction;
	SymbolType(const SymbolType & r) {
		argTypes = r.argTypes;
		type = r.type;
		isFunction = r.isFunction;

	}
	SymbolType(vector<int> args, int returnType) : argTypes(args), type(returnType), isFunction(true) {
	};
	SymbolType(int type) : type(type), isFunction(false) {
	};
	inline bool operator== (SymbolType & r) {
		return argTypes == r.argTypes && type == r.type && isFunction == r.isFunction;
	}
	inline bool operator!= (SymbolType & r) {
		return !operator==(r);
	}

};
#endif /* SYMBOLTYPE_H_ */
