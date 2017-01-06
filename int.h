#ifndef __INT_H__
#define __INT_H__

#include <iostream>
#include <string>
#include <sstream>
#include "expression.h"

class loneint : public Expression {
	int value;
public:

	// CTOR
	loneint(int);

	// METHODS
	std::string prettyprint();
	int evaluation();
	void set(std::string,int);
	void unset(std::string);

	// DTOR
	~loneint();

};


#endif
