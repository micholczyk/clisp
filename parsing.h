#ifndef PARSING_H_
#define PARSING_H_

#include "mpc.h"

enum { LVAL_NUM, LVAL_INT, LVAL_ERR, LVAL_SYM, LVAL_SEXPR };

typedef struct lval {
	int type;
	double num;
	char* err;
	char* sym;
	int count;
	struct lval** cell;
} lval;

/* parsing.c */
lval* lval_num(double);
lval* lval_int(long);
lval* lval_err(char*);
lval* lval_sym(char*);
lval* lval_sexpr(void);
lval* lval_read_num(mpc_ast_t*);
lval* lval_add(lval*, lval*);
lval* lval_read(mpc_ast_t*);
void lval_expr_print(lval*, char, char);
void lval_print(lval*);
void lval_println(lval*);
void lval_del(lval*);
lval* lval_eval_sexpr(lval*);
lval* lval_eval(lval*);
lval* lval_pop(lval*, int);
lval* lval_take(lval*, int);
lval* builtin_op(lval*, char*);

#endif // PARSING_H_
