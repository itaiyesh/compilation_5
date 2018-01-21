/*
 * RegisterPool.cpp
 *
 *  Created on: 19 ???? 2018
 *      Author: shurun
 */
#include <stdexcept>

#include "RegisterPool.h"
#include "utils.h"
#include <algorithm>


RegisterPool::RegisterPool() {
	for (int i = 8; i <= 25; i++) {
		string s = "$" + ToString<int>(i);
		freeRegisters.push_back(s);
	}
}

string RegisterPool::getRegister() {
	if( freeRegisters.empty())
	{
		throw runtime_error("No more free registers");
	}
	else {
		vector<string>::iterator it = freeRegisters.begin();
		string val = *it;
		registers.push_back(val);
		freeRegisters.erase(it);
		return val;
	}
}

void RegisterPool::freeRegister(string reg) {
	if (reg.empty())
	{
		throw runtime_error("empty register name cannot be freed");
	} else {
		vector<string>::iterator it = find(registers.begin(), registers.end(),reg);
		if (it==registers.end())
		{
			throw runtime_error("can't free, "+reg +" is not a register");
		}else {
			freeRegisters.push_back(*it);
			registers.erase(it);

		}
	}
}
void RegisterPool::storeAll() {
	for (int i = 0; registers.size(); ++i)
	{

		CodeBuffer::instance().emit("sub $sp, $sp, 4");
		CodeBuffer::instance().emit("sw " + registers[i] + ", " + "($sp)");
	}
	EMIT("sub $sp, sp, 4");
	EMIT("sw $fp, ($sp)");
}
//order change
void RegisterPool::restoreAll() {
	EMIT("lw $fp, ($sp)");
	EMIT("add $sp, $sp, 4");
	for (int i = 0; registers.size(); ++i)
	{
		CodeBuffer::instance().emit("lw " + registers[i] + ", " + "($sp)");
		CodeBuffer::instance().emit("add $sp, $sp, 4");
	}
}
