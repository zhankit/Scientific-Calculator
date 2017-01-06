#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

// DEFINE AN EXCEPTION TO CATCH THE NAME FOR ERROR
class var_error {
public:
        string the_name;
        var_error(string name) : the_name{ name } {};
};

// BASE CLASS FOR EXPRESSION
class Expression {
public:
        // CTOR
        Expression();

        // VIRTUAL METHODS
        virtual string prettyprint() = 0;
        virtual int evaluation() = 0;
        virtual void set(string,int) = 0;
        virtual void unset(string) = 0;

        // DTOR
        virtual ~Expression();
};

#endif

