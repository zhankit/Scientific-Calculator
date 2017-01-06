#include "expression.h"
#include "int.h"
#include "biexpression.h"
#include "unaexpression.h"
#include "variable.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// VECTOR OF STACK
vector <Expression*> stack;

// TRACK THE CAPACITY OF THE STACK
int capacity = 0;


int main() {
	string s;

	// Read and construct expression object
	while (cin >> s) {
		istringstream ss(s);
		int n;

		if (ss >> n) {
			loneint * v = new loneint(n);
			stack.push_back(v);
			capacity++;
		} // LONEINT
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
		} // BINARY EXPRESSION
		else if (s == "done") {
			break;
		} // Exception
		else {
			varexpression * v = new varexpression(s,'N',0);
			stack.push_back(v);
			capacity++;
		} // Variable 
	}

	// Print the expression after all is done
	cout << stack.at(0)->prettyprint() << endl;

	// Command interpreter
	while (cin >> s) {
		if (s == "eval") {
			try{	cout << stack.at(0)->evaluation() << endl;}
			catch (var_error &b) {
                		cout << b.the_name << " has no value." << endl;
        		}
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
		else if (s == "copy") {
			Expression *thecopy = stack.at(0)->clone();
			try{
				cout << thecopy->prettyprint() << endl;
                        	thecopy->set("x",1);
				cout << thecopy->prettyprint() << endl;
				cout << thecopy->evaluation() << endl;
			}catch (var_error &b) {
                                
				cout << b.the_name << " has no value." << endl;
                        }
			delete thecopy;
		} // copy
	}

	// DEALLOCATE THE MEMORY
	delete stack.at(capacity-1);
        stack.pop_back();
        stack.clear();


}
