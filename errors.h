#ifndef ERRORS_H_
#define ERRORS_H_
#include "parser.tab.hpp"
#include <string>
#include <vector>
#include <string.h>
#include <stdexcept>
#include <iostream>
#include "utils.h"
using namespace std;
struct Error: public exception {
	Error(){};
	virtual void print(int lineno)=0;
};
struct ErrorLex: public Error{
	ErrorLex(){};
	virtual void print(int lineno){
		output::errorLex(lineno);
	}
};

struct ErrorSyn: public Error{
	ErrorSyn(){};
	virtual void print(int lineno){
		output::errorSyn(lineno);
	}
};
 struct ErrorUndef: public Error {
	 string id;
	 ErrorUndef(const string& id): id(id){};
	 virtual ~ErrorUndef() throw(){};
		virtual void print(int lineno){
			output::errorUndef(lineno, id);
		}
 };
 struct ErrorDef: public Error {
	 string id;
	 ErrorDef( const string& id): id(id){};
	 virtual ~ErrorDef() throw(){};
	 virtual void print(int lineno){
			output::errorDef(lineno, id);
		}

 };
 struct ErrorUndefFunc: public Error {
	 string id;
	 ErrorUndefFunc(const string& id):  id(id){};
	 virtual ~ErrorUndefFunc() throw(){};
		virtual void print(int lineno){
			output::errorUndefFunc(lineno, id);
		}


 };
 struct ErrorMismatch: public Error{
	 ErrorMismatch(){};
		virtual void print(int lineno){
			output::errorMismatch(lineno);
		}

 };
 struct ErrorPrototypeMismatch: public Error{
	 string id;
	 vector<int>  argTypes;
	 ErrorPrototypeMismatch( const string id, vector<int> argTypes): id(id), argTypes(argTypes){};
	 virtual ~ErrorPrototypeMismatch() throw(){};
		virtual void print(int lineno){
			vector<string> stringArgTypes;
			for(vector<int>::const_iterator it=argTypes.begin(); it!=argTypes.end(); ++it)
			{
				string s=TokenToString(*it);

				stringArgTypes.push_back(s);
			}
			output::errorPrototypeMismatch(lineno,id,stringArgTypes);
		}

 };
 struct ErrorUnexpectedBreak: public Error{
	 ErrorUnexpectedBreak(){};
		virtual void print(int lineno){
			output::errorUnexpectedBreak(lineno);
		}
 };
 struct ErrorMainMissing: public Error{
	 ErrorMainMissing(){};
		virtual void print(int lineno){
			output::errorMainMissing();
		}
 };
 struct ErrorByteTooLarge: public Error {
	 string val;
	 ErrorByteTooLarge( const string val):  val(val){};
	 virtual ~ErrorByteTooLarge() throw(){};
		virtual void print(int lineno){
			output::errorByteTooLarge(lineno, val);
		}

 };
 struct ErrorTooManyDefaults: public Error{
	 ErrorTooManyDefaults(){};
		virtual void print(int lineno){
			output::errorTooManyDefaults(lineno);
		}
 };


#endif /* ERRORS_H_ */
