/*
 * RegisterPool.h
 *
 *  Created on: 19 ???? 2018
 *      Author: shurun
 */

#ifndef REGISTERPOOL_H_
#define REGISTERPOOL_H_
#include <boost/shared_ptr.hpp>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <set>

using namespace std;
using boost::shared_ptr;
/*
For each register, a register descriptor records the variable name(s)
whose current value is in that register:
-	we use only those registers that are available for local use within a basic
block; we assume that initially, all register descriptors are empty
-	As code generation progresses,
each register will hold the value of zero or
more variables
*/


class RegisterPool
{
	vector<string> registers; //used registers
	vector<string> freeRegisters;
	vector<string> getAllRegisters();
public:
	RegisterPool();
	string getRegister();
	void freeRegister(string reg);
	void storeAll();
	void restoreAll();
};
typedef shared_ptr<RegisterPool> RegPoolPtr;

#endif /* REGISTERPOOL_H_ */
