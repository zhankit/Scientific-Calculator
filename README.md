# Scientific-Calculator

### Introduction
This calculator will read int the expression in reverse Polish notation (RPN), also known as postfix notation. 

### Technique Used
catch-and-try except and polymorphisms 

### Valid Expression
1. Lone integer
2. Variables (letters only, case-sensitive but cannot be done, ABS or NEG)
3. Unary Operation (NEG or ABS)
4. Binary Operation (+,-,* or /)

### Commands
**set var num** sets the variable var to valye num. <br />
**unset var** reverts the variable var to the unassigned state<br />
**print** prettyprint the expression.<br />
**eval** evaluates the expression and print the value of it<br />

### Example
```
1 3 + 4 y - * ABS NEG done
-|((1 + 3) * (4 - y))|
eval
y has no value.
set y 4
print
-|((1 + 3) * (4 - 4))|
eval
0
set y 3
print
-|((1 + 3) * (4 - 3))|
eval
-4
unset y
print
-|((1 + 3) * (4 - y))|
eval
x has no value
```
