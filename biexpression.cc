#include "expression.h"
#include "biexpression.h"
#include <iostream>
#include <string>
using namespace std;

// CTOR
binexpression::binexpression(string c, Expression *x, Expression *y) :Expression(), op(c), x(x), y(y) {}

// METHOD SET 
void binexpression::set(string valuetobesetted,int val) {
	x->set(valuetobesetted, val);
	y->set(valuetobesetted, val);
};

// METHOD UNSET
void binexpression::unset(string valuetobesetted) {
	x->unset(valuetobesetted);
	y->unset(valuetobesetted);
};

// METHOD EVALUATION
int binexpression::evaluation() {
	int result;

	if (op == "-") {
		result = x->evaluation() - y->evaluation();
	} // '-'
	else if (op == "+") {
		result = x->evaluation() + y->evaluation();
	} // '+'
	else if (op == "*") {
		result = x->evaluation() * y->evaluation();
	} // '*'
	else {
		result = x->evaluation() / y->evaluation();
	} // '/'
	return result;
}

// METHOD PRETTYPRINT
string binexpression::prettyprint() {
	string exp = "(" + x->prettyprint() + " " + op + " " + y->prettyprint() + ")";
	return exp;
}

// DTOR
binexpression::~binexpression() {
	delete x;
	delete y;
}


