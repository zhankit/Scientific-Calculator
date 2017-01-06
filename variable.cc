#include <iostream>
#include <string>
#include <sstream>
#include "expression.h"
#include "variable.h"

using namespace std;

// DTOR
varexpression::varexpression(string x,char status,int val) :var{ x },assigned{status},value{val}, Expression() {};

// METHOD SET
void varexpression::set(string vartobesetted,int x) {
	if (var == vartobesetted) {
		value = x;
		assigned = 'Y';
	}
};

// METHOD UNSET
void varexpression::unset(string vartobesetted) {
	if (var == vartobesetted) {
		assigned = 'N';
	}
};

// METHOD EVALUATION
int varexpression::evaluation() {
	if (assigned == 'Y') {
		return value;
	} // 'Y'
	else {
		throw var_error{ var };
	} // 'N'
};

// METHOD PRETTYPRINT
string varexpression::prettyprint() {
	string result;
	if (assigned == 'N') {
		return var;
	}
	else {
		return to_string(value);
	}
}

// DTOR
varexpression::~varexpression() {}
