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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    VAR = 259,
    ARRAY = 260,
    OF = 261,
    INTEGER = 262,
    REAL = 263,
    FUNCTION = 264,
    PROCEDURE = 265,
    BEGIN = 266,
    END = 267,
    ASSIGNOP = 268,
    IF = 269,
    THEN = 270,
    ELSE = 271,
    WHILE = 272,
    FOR = 273,
    DO = 274,
    TO = 275,
    RELOP = 276,
    ADDOP = 277,
    MULOP = 278,
    NOT = 279,
    DOTDOT = 280,
    ID = 281,
    INUM = 282,
    RNUM = 283
  };
#endif
/* Tokens.  */
#define PROGRAM 258
#define VAR 259
#define ARRAY 260
#define OF 261
#define INTEGER 262
#define REAL 263
#define FUNCTION 264
#define PROCEDURE 265
#define BEGIN 266
#define END 267
#define ASSIGNOP 268
#define IF 269
#define THEN 270
#define ELSE 271
#define WHILE 272
#define FOR 273
#define DO 274
#define TO 275
#define RELOP 276
#define ADDOP 277
#define MULOP 278
#define NOT 279
#define DOTDOT 280
#define ID 281
#define INUM 282
#define RNUM 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 12 "wumbo.y" /* yacc.c:1909  */

	sym_stack_t *stkval;
	char *sval;
	int ival;
	float fval;

#line 117 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
