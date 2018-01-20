/*
 * Register.h
 *
 *  Created on: 19 ???? 2018
 *      Author: shurun
 */

#ifndef REGISTER_H_
#define REGISTER_H_
#include <string>
using namespace std;

/*
For each register, a register descriptor records the variable name(s)
whose current value is in that register:
-	we use only those registers that are available for local use within a basic
	block; we assume that initially, all register descriptors are empty
-	As code generation progresses,
	each register will hold the value of zero or
	more variables
*/
class Register
{
	//int value; // TODO rememer that byte variables also need to be overflowed... mabe add union int and char.
	string reg_name;
	string var_name;
public:
	Register(string name) :reg_name(name) {}
	void reset() { var_name.clear(); }
	string getVariable() { return var_name; }
	void setValue(string name) { var_name = name; }
	string getName() { return reg_name; }

};

#endif /* REGISTER_H_ */
