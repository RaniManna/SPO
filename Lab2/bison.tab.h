/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "bison.y"

  #include <stdbool.h>
  #include "src/ast.h"

#line 54 "bison.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENT = 258,                   /* IDENT  */
    BOOL = 259,                    /* BOOL  */
    CHR = 260,                     /* CHR  */
    HEX = 261,                     /* HEX  */
    BITS = 262,                    /* BITS  */
    DEC = 263,                     /* DEC  */
    STR = 264,                     /* STR  */
    ASSIGN = 265,                  /* ASSIGN  */
    NOT = 266,                     /* NOT  */
    MINUS = 267,                   /* MINUS  */
    BIN_PLUS = 268,                /* BIN_PLUS  */
    BIN_MUL = 269,                 /* BIN_MUL  */
    BIN_DIV = 270,                 /* BIN_DIV  */
    BIN_LESS = 271,                /* BIN_LESS  */
    BIN_GREATER = 272,             /* BIN_GREATER  */
    BIN_EQUALS = 273,              /* BIN_EQUALS  */
    OP = 274,                      /* OP  */
    CP = 275,                      /* CP  */
    SBO = 276,                     /* SBO  */
    SBC = 277,                     /* SBC  */
    WHILE = 278,                   /* WHILE  */
    REPEAT = 279,                  /* REPEAT  */
    UNTIL = 280,                   /* UNTIL  */
    DO = 281,                      /* DO  */
    BREAK = 282,                   /* BREAK  */
    EOEXPR = 283,                  /* EOEXPR  */
    COMMA = 284,                   /* COMMA  */
    COLON = 285,                   /* COLON  */
    VAR = 286,                     /* VAR  */
    BEGINNING = 287,               /* BEGINNING  */
    END = 288,                     /* END  */
    METHOD = 289,                  /* METHOD  */
    IF = 290,                      /* IF  */
    BOOLEAN = 291,                 /* BOOLEAN  */
    BYTE = 292,                    /* BYTE  */
    INT = 293,                     /* INT  */
    UINT = 294,                    /* UINT  */
    LONG = 295,                    /* LONG  */
    ULONG = 296,                   /* ULONG  */
    CHAR = 297,                    /* CHAR  */
    STRING = 298,                  /* STRING  */
    ARRAY = 299,                   /* ARRAY  */
    OF = 300,                      /* OF  */
    THEN = 301,                    /* THEN  */
    ELSE = 302,                    /* ELSE  */
    ERROR = 303                    /* ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "bison.y"

  struct ast_node* node;
  char*        value;
 // char*        name;
  //bool        bl;
  //char        cr;
  enum operation_type op;

#line 128 "bison.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
