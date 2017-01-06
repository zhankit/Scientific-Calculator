
#ifndef __BIEXPRESSION_H__
#define __BIEXPRESSION_H__

#include <iostream>
#include <string>
#include <sstream>
#include "expression.h"

class binexpression : public Expression {
	std::string op;
	Expression *x;
	Expression *y;

public:
	// CTOR
	binexpression(std::string c, Expression *x, Expression *y);

	// METHODS
	std::string prettyprint();
	int evaluation();
	void set(std::string,int);
	void unset(std::string);

	// DTOR
	~binexpression();
};

#endif
