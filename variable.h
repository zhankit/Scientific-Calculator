#ifndef __VAREXPRESSION_H__
#define __VAREXPRESSION_H__

#include <iostream>
#include <string>
#include <sstream>
#include "expression.h"

class varexpression : public Expression {
        // Var is the variable
        std::string var;

        // VALUE OF VAR
        int value;

        // assigned = 'N' if SET IS ON, 'N' otherwise
        char assigned;
public:
        // CTOR
        varexpression(std::string,char,int);
       
	 // METHODS
        std::string  prettyprint();
        int evaluation();
        void set(std::string,int);
        void unset(std::string);
        virtual Expression *clone(){	
        	return new varexpression(var,assigned,value);
        };

        // DTOR
        ~varexpression();
};

#endif

