/*
 * RegisterPool.h
 *
 *  Created on: 19 ???? 2018
 *      Author: shurun
 */

#ifndef REGISTERPOOLMANAGER_H_
#define REGISTERPOOLMANAGER_H_
#include <boost/shared_ptr.hpp>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include "RegisterPool.h"

using namespace std;
using boost::shared_ptr;

class RegisterPoolManager {
	stack<RegPoolPtr> registerPools;

public:
	void pop();
	void push();
	RegPoolPtr top();
	static RegisterPoolManager &instance();

	string getRegister();
	void freeRegister(string reg);
	void storeAll();
	void restoreAll();

};
#endif /* REGISTERPOOLMANAGER_H_ */
