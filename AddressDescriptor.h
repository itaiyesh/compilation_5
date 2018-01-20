/*
 * AddressDescriptor.h
 *
 *  Created on: 19 ???? 2018
 *      Author: shurun
 */

#ifndef ADDRESSDESCRIPTOR_H_
#define ADDRESSDESCRIPTOR_H_
#include <boost/shared_ptr.hpp>
#include "SymbolType.h"


using boost::shared_ptr;
/*
For each program variable, an address descriptor records the
location(s) where the current value of the variable can be found
-	The location may be a register, a memory address, a stack offset, or some
	set of these
-	Information can be stored in the symbol - table entry for that variable
*/


class AddressDescriptor {
public:
	string sym_name;
	SymbolType sym_type;
	int offset;
	string reg;
	string label;
	AddressDescriptor(string symName, SymbolType type, int offset) : sym_name(symName), sym_type(type), offset(offset) {}

};

//typedef shared_ptr<AddressDescriptor > AddressDescPtr;

#endif /* ADDRESSDESCRIPTOR_H_ */
