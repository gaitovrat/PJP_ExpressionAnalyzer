# PJP_ExpressionAnalyzer
An interpreter of arithmetic expressions. These expressions contain `+, -, *, /` operators (with common priorities and left associativity) and parentheses.
Only binary operators supported.

## Input
The first line of the input contains a number `N`. It defines the number of expressions your program should evaluate. These expressions are on next N lines. Each line contains exactly one expression.

## Output
For each expression write one line containing the result – the computed value of the expression. If there is any error in the input, write text `ERROR` instead.

## Example
* Input
```
2
2 * (3+5)
15 - 2**7
```
* Output
```
16
ERROR
```
