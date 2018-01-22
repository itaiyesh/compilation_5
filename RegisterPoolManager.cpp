/*
 * RegisterPool.cpp
 *
 *  Created on: 19 ???? 2018
 *      Author: shurun
 */

#include "RegisterPoolManager.h"
#include "utils.h"




string RegisterPoolManager::getRegister() {
	string reg= top()->getRegister();
//	cout <<"RegisterPoolManager::getRegister"<<reg<<endl;
	return reg;
}

void RegisterPoolManager::freeRegister(string reg) {
	top()->freeRegister(reg);
}

void RegisterPoolManager::storeAll() {
	top()->storeAll();
}

void RegisterPoolManager::restoreAll() {
	top()->restoreAll();
}
RegisterPoolManager &RegisterPoolManager::instance() {
	static RegisterPoolManager inst;//only instance
	return inst;
}

void RegisterPoolManager::pop() {
	registerPools.pop();
}
void RegisterPoolManager::push() {
	registerPools.push(RegPoolPtr(new RegisterPool()));
}
RegPoolPtr RegisterPoolManager::top() {
	return registerPools.top();
}
