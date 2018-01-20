#ifndef ATTRIBUTES_H_
#define ATTRIBUTES_H_

#include <string>
#include <vector>
#include <string.h>
#include <stdexcept>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <typeinfo>

#include "utils.h"
using namespace std;
using boost::shared_ptr;
//TODO: put this somewhere common to parser.ypp and this file
typedef stack<SymTable > Tables;
typedef stack<int > Offsets;
typedef stack<int > Defaults;
typedef shared_ptr< Defaults> DefaultsPtr;
typedef shared_ptr< Tables> TablesPtr;
typedef shared_ptr< Offsets> OffsetsPtr;
//typedef shared_ptr<RegisterPool> RegPoolPtr;
struct Node;
typedef shared_ptr<Node > sp;



struct Node {
	Node(){
	};
	virtual ~Node() {
	}
	Node(int token, const char * lexeme): token(token),lexeme(lexeme, strlen(lexeme)), reg(NULL){
#ifdef DEBUG
		cout <<"Token: "<<lexeme <<endl;
#endif
		};
	 int token ;
	 string lexeme;
	 //vector<int> argumentTypes;
	 vector<ar> arguments;
	 sp terminal;
	 int returnType;
	 ar argument;
	 //string value;

	 //int argumentType;
	 vector<int> expressionTypes;
	 int expressionType;
	 vector<string> expressionIds;
	 string expressionId;

	 // for HW5
	 bool boolian;
	 string value;//holds string value, unlike lexme it can change
	 string place;// 
	 string quad;// mainly for markers. so it on the screenshots from lectures
	 vector<int> nextlist; // for backpatching
	 stack<string> value_list;
	 stack<string> quad_list;
	 vector<int> falselist; // for backpatching
	 vector<int> truelist; // for backpatching
	 vector<int> breaklist; 
	 Register* reg;

};



#define YYSTYPE sp

#endif /* ATTRIBUTES_H_ */
