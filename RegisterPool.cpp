/*
 * RegisterPool.cpp
 *
 *  Created on: 19 ???? 2018
 *      Author: shurun
 */

#include "RegisterPool.h"
#include "utils.h"

void RegisterPool::delMap(map<string, Register*> m) {
	for (map<string, Register*>::iterator it = m.begin(); it != m.end(); it++) {
		delete (*it).second;
	}
}

RegisterPool &RegisterPool::instance() {
	static RegisterPool inst;//only instance
	return inst;
}

RegisterPool::RegisterPool() {
	for (int i = 8; i <= 25; i++) {
		string s = "$" + ToString<int>(i);
		registers.insert(pair<string, Register*>(s, new Register(s)));
		unOccupied.push_back(s);
	}
}
RegisterPool::~RegisterPool() {
	delMap(registers);
	while (!stored.empty()) {
		delMap(stored.top().first);
		stored.pop();
	}
}

Register* RegisterPool::getRegister() {
	Register* reg = registers[unOccupied.back()];
	unOccupied.pop_back();
	return reg;
}

void RegisterPool::returnRegister(Register* reg) {
	if (!reg) return;
	reg->reset();
	unOccupied.push_back(reg->getName());
}

void RegisterPool::storeAll() {
	stored.push(make_pair(registers, unOccupied));
	registers.clear();
	unOccupied.clear();
	for (int i = 8; i <= 25; i++) {
		string reg = "$" + ToString<int>(i);
		registers.insert(pair<string, Register*>(reg, new Register(reg)));
		unOccupied.push_back(reg);
		CodeBuffer::instance().emit("sub $sp, $sp, 4");
		CodeBuffer::instance().emit("sw " + reg + ", " + "($sp)");
	}
}

void RegisterPool::restoreAll() {
	delMap(registers);
	registers = stored.top().first;
	unOccupied = stored.top().second;
	stored.pop();
	for (int i = 25; i >= 8; i--) {
		string reg = "$" + ToString<int>(i);
		CodeBuffer::instance().emit("lw " + reg + ", " + "($sp)");
		CodeBuffer::instance().emit("add $sp, $sp, 4");
	}
}
