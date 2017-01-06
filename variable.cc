#include <iostream>
#include <string>
#include <sstream>
#include "expression.h"
#include "variable.h"

using namespace std;

// CTOR
varexpression::varexpression(string x) :var{ x }, Expression() {
	assigned = 'N'; 
}

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
	} // THROW ERROR
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
