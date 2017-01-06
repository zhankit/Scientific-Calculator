#include "unaexpression.h"
#include "expression.h"
#include <iostream>
#include <string>
using namespace std;

// CTOR
unaexpression::unaexpression(string s, Expression * x) :Expression(), x(x), Unary{s} {};

// METHOD SET
void unaexpression::set(string valuetobesetted,int val) {
	x->set(valuetobesetted, val);
};

// METHOD UNSET
void unaexpression::unset(string valuetobesetted) {
	x->unset(valuetobesetted);
};

// METHOD PRINT
string unaexpression::prettyprint() {
	string exp;
	if (Unary == "ABS") {
		exp = "|" + x->prettyprint() + "|";
	} // ABS
	else if (Unary == "NEG") {

		exp = "-" + x->prettyprint();
	} // NEG
	return exp;
}

// METHOD EVALUATION
int unaexpression::evaluation() {
	int result;
	if (Unary == "ABS") {
		// if it is pos then do nothing
		if (x->evaluation() > 0) {
			result = x->evaluation();
			// if it is neg then times -1
		}
		else {
			result = -1 * x->evaluation();
		}
	} // ABS
	else if (Unary == "NEG") {
		// NEG always times -1
		result = -1 * x->evaluation();
	} // NEG
	return result;

}

// DTOR
unaexpression::~unaexpression(){
	delete x;
}
