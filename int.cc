#include "int.h"
#include "expression.h"
#include <iostream>
#include <string>
using namespace std;

// CTOR
loneint::loneint(int x): Expression(), value(x){};

// METHOD SET
void loneint::set(string,int) {
};

// METHOD SET
void loneint::unset(string) {
};

// METHOD PRETTYPRINT
string loneint::prettyprint () {
	return to_string(value);
}

// METHOD EVALUATION
int loneint::evaluation() {
	return value;
}


// DTOR
loneint::~loneint() {}
