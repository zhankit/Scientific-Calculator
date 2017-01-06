#include "expression.h"
#include "int.h"
#include "biexpression.h"
#include "unaexpression.h"
#include "variable.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// STACK VECTOR
vector <Expression*> stack;

// TRACK THE CAPACITY OF THE STACk
int capacity = 0;


int main() {
	string s;

	// Read and construct expression object
	while (cin >> s) {
		istringstream ss(s);
		int n;

		if (ss >> n) {
			loneint * v = new loneint(n);
			stack.push_back (v);
			capacity++;
		} // LONE INT
		else if (s == "NEG" || s == "ABS") {
			unaexpression * u = new unaexpression(s, stack.at(capacity-1));
			stack.pop_back();
			stack.push_back(u);
		} // NEG & ABS
		else if (s == "+" || s == "-" || s == "*" || s == "/") {
			binexpression * b = new binexpression(s, stack.at(capacity - 2), stack.at(capacity - 1));
			stack.pop_back();
			stack.pop_back();
			stack.push_back(b);
			capacity--;
		} // BINARYEXPRESSION
		else if (s == "done") {
			break;
		} // DONE ENCOUNTERED
		else {
			varexpression * v = new varexpression(s);
			stack.push_back(v);
			capacity++;
		} // VARIABLE
	}

	// Print the expression after all is done
	cout << stack.at(0)->prettyprint() << endl;

	// Command interpreter
	while (cin >> s) {
		if (s == "eval") {
			try {
				cout << stack.at(0)->evaluation() << endl;
			} // TRY EVALUATION
			catch (var_error &b) {
				cout << b.the_name << " has no value." << endl;
			} // CATCH THE ERROR

		} // EVAL
		else if (s == "set") {
			string vartobeset;
			int valuetobeset;
			cin >> vartobeset;
			cin >> valuetobeset;
			stack.at(0)->set(vartobeset, valuetobeset);
		} // SET
		else if (s == "unset") {
			string vartobeunset;
			cin >> vartobeunset;
			stack.at(0)->unset(vartobeunset);
		} // UNSET 
		else if (s == "print") {
			cout << stack.at(0)->prettyprint() << endl;
		} // PRINT
	}
	
	// DEALLOCATE THE STACK
	delete stack.at(capacity-1);
	stack.pop_back();
	stack.clear();

}
