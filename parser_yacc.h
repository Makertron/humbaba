/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_PARSER_PARSER_TAB_H_INCLUDED
# define YY_PARSER_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int parserdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_ERROR = 258,
    TOK_MODULE = 259,
    TOK_FUNCTION = 260,
    TOK_IF = 261,
    TOK_ELSE = 262,
    TOK_FOR = 263,
    TOK_LET = 264,
    TOK_ID = 265,
    TOK_STRING = 266,
    TOK_USE = 267,
    TOK_NUMBER = 268,
    TOK_TRUE = 269,
    TOK_FALSE = 270,
    TOK_UNDEF = 271,
    LE = 272,
    GE = 273,
    EQ = 274,
    NE = 275,
    AND = 276,
    OR = 277,
    LET = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 74 "src/parser.y" /* yacc.c:1909  */

  char *text;
  double number;
  class Value *value;
  class Expression *expr;
  class ModuleInstantiation *inst;
  class IfElseModuleInstantiation *ifelse;
  Assignment *arg;
  AssignmentList *args;

#line 89 "parser.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parserlval;

int parserparse (void);

#endif /* !YY_PARSER_PARSER_TAB_H_INCLUDED  */
