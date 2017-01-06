#ifndef __UNAEXPRESSION__H_
#define __UNAEXPRESSION__H_

#include <iostream>
#include <string>
#include <sstream>
#include "expression.h"

class unaexpression : public Expression {
	std::string Unary;
	Expression * x;
	int value;

public:

	// CTOR
	unaexpression(std::string, Expression * x);

	// METHODS
	std::string prettyprint();
	int evaluation();
	void set(std::string,int);
	void unset(std::string);

	// DTOR
	~unaexpression();

};


#endif
