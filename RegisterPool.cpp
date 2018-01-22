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

vector<string> RegisterPool::getAllRegisters() {
	vector<string> allRegisters;
	for (int i = 8; i <= 25; i++) {
		string s = "$" + ToString<int>(i);
		allRegisters.push_back(s);
	}
	return allRegisters;
}
RegisterPool::RegisterPool() {
	freeRegisters = getAllRegisters();
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
//	vector<string> allRegisters = getAllRegisters();
	for (int i = 0; i < registers.size(); ++i)
	{

		EMIT("sub $sp, $sp, 4");
		EMIT("sw " + registers[i] + ", " + "($sp)");
	}

}

void RegisterPool::restoreAll() {
//	vector<string> allRegisters = getAllRegisters();

	for (int i = registers.size()-1; i >=0 ; --i)
	{
		EMIT("lw " + registers[i] + ", " + "($sp)");
		EMIT("add $sp, $sp, 4");
	}
}
