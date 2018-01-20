%{
#include "attributes.h"
#include "parser.tab.hpp"
#include "errors.h"
using namespace std;

#define _(TOKEN) {yylval=sp(new Node(TOKEN, yytext)); return TOKEN;}
%}

%option yylineno
%option noyywrap

CR 	(\x0D)
LF	(\x0A)
SPACE	(\x20)
TAB	(\x09)

%%

"void" _(VOID)
"int" _(INT)
"byte" _(BYTE)
"b" _(B)
"bool" _(BOOL)
"and" _(AND)
"or" _(OR)
"not" _(NOT)
"true" _(TRUE)
"false" _(FALSE)
"return" _(RETURN)
"if" _(IF)
"else" _(ELSE)
"while" _(WHILE)
"switch" _(SWITCH)
"case" _(CASE)
"break" _(BREAK)
"default" _(DEFAULT)
":" _(COLON)
";" _(SC)
"," _(COMMA)
"(" _(LPAREN)
")" _(RPAREN)
"{" _(LBRACE)
"}" _(RBRACE)
"=" _(ASSIGN)
==|!=|<|>|<=|>= _(RELOP)
\+|- _(PLUS_MINUS)
\*|\/ _(MUL_DIV)


[a-zA-Z][a-zA-Z0-9]* _(ID)
0|[1-9][0-9]* _(NUM)
\"([^\n\r\"\\]|\\[rnt"\\])+\" _(STRING)

{CR}|{LF}|{TAB}|{SPACE} /*new lines,tabs,space, ignore*/

"//"[^\r\n]*[\r|\n|\r\n]? /*comments, ignore*/

. {throw ErrorLex();}

%%

