// #include <graphviz/cgraph.h>

#include <graphviz/gvc.h>
#include <stdarg.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include "ast.h"
#include "dfs.h"

extern int is_verbose;
static int nr_spaces = 0;

const char *ot_symbol[] = {
        [OT_BIN_PLUS] = "+", [OT_MINUS] = "-",

        [OT_BIN_MUL] = "*", [OT_BIN_DIV] = "/",

        [OT_BIN_LESS] = "=<", [OT_BIN_GREATER] = ">=", [OT_BIN_EQUALS] = "==",

        [OT_ASSIGN] = ":=",

        [OT_UN_NOT] = "not"};

static struct ast_node *make_node(enum ast_node_type type) {
    struct ast_node *node = (struct ast_node *) malloc(sizeof(struct ast_node));
    if (node == NULL) {
        fprintf(stdout, "%s: MEMORY ALLOCATION ERR\n", __func__);
        exit(1);
    }
    node->type = type;
    node->is_visited = false;
    is_verbose && fprintf(stdout, "%s: ", ant_names[type]);
    return node;
}

struct ast_node *make_typeref_array(struct ast_node *node_arr) {
    struct ast_node *node = make_node(T_TYPE_REF);
    node->as_typeref.type = TR_ARR;
    node->as_typeref.sub_field = node_arr;
    return node;
}

struct ast_node *make_typeref_ident(struct ast_node *node_ident) {
    struct ast_node *node = make_node(T_TYPE_REF);
    node->as_typeref.type = TR_IDENT;
    node->as_typeref.sub_field = node_ident;
    return node;
}

struct ast_node *make_typeref(enum type_ref type) {
    struct ast_node *node = make_node(T_TYPE_REF);
    node->as_typeref.type = type;
    return node;
}

struct ast_node *make_typeref_lt(enum literal_type type) {
    struct ast_node *node = make_node(T_TYPE_REF_LT);
    node->as_typeref_lt.type = type;
    return node;
}

struct ast_node *make_ident(const char *name, struct ast_node *typeref_node) {
    struct ast_node *ident = make_node(T_IDENT);
    strncpy(ident->as_ident.name, name, MAXIMUM_IDENTIFIER_LENGTH);
    printf("make_ident: %s\n", ident->as_ident.name);
    ident->as_ident.type = typeref_node;
    is_verbose && fprintf(stdout, "[name: %s]\n", name);
    return ident;
}

struct ast_node *make_func_sign(struct ast_node *name,
                                struct ast_node *arg_list) {
    struct ast_node *fs = make_node(T_FUNC_SIGN);
    fs->as_func_sign.ident = name;
    fs->as_func_sign.arg_list = arg_list;
    return fs;
}

struct ast_node *make_func(struct ast_node *sign, struct ast_node *body) {
    struct ast_node *func = make_node(T_FUNC);
    func->as_func.func_sign = sign;
    func->as_func.body = body;
    return func;
}

struct ast_node *make_body(struct ast_node *var_list,
                           struct ast_node *statement) {
    struct ast_node *body = make_node(T_BODY);
    body->as_body.var_list = var_list;
    body->as_body.statement = statement;
    return body;
}

// struct ast_node *set_type_operand(struct ast_node *node, enum type_ref val) {
//  if (node->type == T_IDENT) node->as_ident.name = val;
//  if (node->type == T_LITERAL) node->as_literal.value = val;
// return node;
//}

struct ast_node *set_type_array(struct ast_node *node, struct ast_node *type) {
    // struct ast_node *body = make_node(T_BODY);
    struct ast_node *iter = node->as_list.current;
    // while (iter != NULL) {   //todo fill all
    //   int t = iter->as_list.current->type;
    //   if (t == T_IDENT)
    //     iter->as_ident.type = type;
    //   else if (t == T_LITERAL)
    //     iter->as_literal.type = type;
    //   iter = iter->as_list.next;
    // }
    return node;
}

struct ast_node *make_literal(const char *value, struct ast_node *lt) {
    struct ast_node *constant = make_node(T_LITERAL);
    constant->as_literal.type = lt;
    constant->as_literal.value = value;
    is_verbose && fprintf(stdout, "[op: %s]\n", value);
    return constant;
}

struct ast_node *make_expr(struct ast_node *node) {
    struct ast_node *expr = make_node(T_EXPR);
    expr->as_expr.some_node = node;
    return expr;
}

struct ast_node *make_unexpr(enum operation_type op, struct ast_node *arg) {
    struct ast_node *unexpr = make_node(T_UN_EXPR);

    unexpr->as_unexpr.op = op;
    unexpr->as_unexpr.argument = arg;
    is_verbose && fprintf(stdout, "[op: %s]\n", ot_symbol[op]);
    return unexpr;
}

struct ast_node *make_binexpr(enum operation_type op, struct ast_node *arg1,
                              struct ast_node *arg2) {
    struct ast_node *binexpr = make_node(T_BIN_EXPR);
    binexpr->as_binexpr.op = op;
    binexpr->as_binexpr.arg1 = arg1;
    binexpr->as_binexpr.arg2 = arg2;
    return binexpr;
}

struct ast_node *make_expr_call(struct ast_node *expr,
                                struct ast_node *expr_list) {
    struct ast_node *node = make_node(T_CALL_EXPR);
    node->as_call_expr.expr = expr;
    node->as_call_expr.expr_list = expr_list;
    return node;
}

struct ast_node *make_break() {
    struct ast_node *node = make_node(T_BREAK);
    return node;
}

// struct ast_node *make_expr_indexer(struct ast_node *expr,
//                                    struct ast_node *expr_list) {
//   return expr; // todo
// }

struct ast_node *make_branch(struct ast_node *test, struct ast_node *consequent,
                             struct ast_node *alternate) {
    struct ast_node *br = make_node(T_BRANCH);
    br->as_branch.test = test;
    br->as_branch.consequent = consequent;
    br->as_branch.alternate = alternate;
    return br;
}

struct ast_node *make_while(struct ast_node *test, struct ast_node *body) {
    struct ast_node *wh = make_node(T_WHILE);
    wh->as_repeat.test = test;
    wh->as_repeat.body = body;
    return wh;
}

struct ast_node *make_repeat(struct ast_node *body, struct ast_node *test) {
    struct ast_node *repeat = make_node(T_REPEAT);
    repeat->as_repeat.test = test;
    repeat->as_repeat.body = body;
    // is_verbose && fprintf(stdout, ANT_REPEAT_FMT "\n", (long unsigned int)
    // test, (long unsigned int) body);
    return repeat;
}

struct ast_node *make_expr_indexer(struct ast_node *expr,
                                   struct ast_node *expr_list) {
    struct ast_node *indx = make_node(T_INDEXER);
    indx->as_indexer.expr = expr;
    indx->as_indexer.expr_list = expr_list;
    return indx;
}

#define MAKE_LIST(type, head, next)                                            \
  \ 
  struct ast_node *list = make_node(type);                                     \
  \ 
  list->as_list.current = head;                                                \
  \ 
  list->as_list.next = next;                                                   \
  \ 
  return list;

#define INSERT_LIST(head_p, first, func)                                       \
  \ 
  if (*head_p) {                                                               \
    \ 
    struct ast_node *const oldstart =                                          \ 
        func((*head_p)->as_list.current, (*head_p)->as_list.next);             \
    \ 
    free(*head_p);                                                             \
    \ 
    (*head_p) = func(first, oldstart);                                         \
    \ 
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            \
  }                                                                            \
  else \ 
    *head_p = func(first, NULL);                                               \
  \ 
  return *head_p;

struct ast_node *insert_stat_list(struct ast_node **head_p, // maybe void?
                                  struct ast_node *first) {
    INSERT_LIST(head_p, first, make_stat_list);
}

struct ast_node *make_stat_list(struct ast_node *head, struct ast_node *next) {
    MAKE_LIST(T_STMTS_LIST, head, next);
}

struct ast_node *make_statement(struct ast_node *node) {
    struct ast_node *stat = make_node(T_STMT);
    stat->as_statement.some_node = node;
    return stat;
}

struct ast_node *make_argdef_list(struct ast_node *head,
                                  struct ast_node *next) {
    MAKE_LIST(T_ARGDEF_LIST, head, next);
}

struct ast_node *insert_argdef_list(struct ast_node **head_p,
                                    struct ast_node *first) {
    INSERT_LIST(head_p, first, make_argdef_list);
}

struct ast_node *make_array(struct ast_node *head, struct ast_node *next) {
    MAKE_LIST(T_ARRAY, head, next);
}

struct ast_node *insert_array(struct ast_node **head_p,
                              struct ast_node *first) {
    INSERT_LIST(head_p, first, make_array);
}

struct ast_node *insert_expr_list(struct ast_node **head_p,
                                  struct ast_node *first) {
    INSERT_LIST(head_p, first, make_expr_list);
}

struct ast_node *make_expr_list(struct ast_node *head, struct ast_node *next) {
    MAKE_LIST(T_EXPR_LIST, head, next);
}

struct ast_node *make_literal_list(struct ast_node *head,
                                   struct ast_node *next) {
    MAKE_LIST(T_LIT_LIST, head, next);
}

struct ast_node *insert_literal_list(struct ast_node **head_p,
                                     struct ast_node *first) {
    INSERT_LIST(head_p, first, make_literal_list);
}

struct ast_node *make_program(struct ast_node *child) {
    struct ast_node *program = make_node(T_PROGRAM);

    program->as_program.child = child;
    return program;
}

struct ast_node *insert_def_list(struct ast_node *root_func,
                                 struct ast_node *func) {
    root_func->as_program.next_func = func;
    return root_func;
}

void free_ast(struct ast_node *);

static void postprint_ast() { nr_spaces -= 2; }

static void preprint_ast(struct ast_node *node) {
    nr_spaces += 2;
    if (nr_spaces >= 0) {
        for (size_t i = 0; i < nr_spaces; ++i) {
            fprintf(stdout, " ");
        }
    }
    fprintf(stdout, "%s ", ant_names[node->type]);
    switch (node->type) {
        case T_PROGRAM: {
            fprintf(stdout, "\n");
            break;
        }
        case T_EXPR_LIST:
        case T_ARGDEF_LIST:
        case T_ARRAY:
        case T_LIT_LIST:
        case T_STMTS_LIST: {
            fprintf(stdout, "\n");
            break;
        }
        case T_REPEAT: {
            fprintf(stdout, "\n");
            break;
        }
        case T_LITERAL: {
            fprintf(stdout, "[val: %s, type: %s]\n", node->as_literal.value,
                    literal_names[node->as_literal.type->as_typeref.type]);
            break;
        }
        case T_IDENT: {
            fprintf(stdout, "[name: %s]\n", node->as_ident.name);
            // fprintf(stdout, "[type_ref: %s]\n", typeref_names[node->as_ident.type]);

            break;
        }
        case T_TYPE_REF: {
            fprintf(stdout, "[type: %s]\n", typeref_names[node->as_typeref.type]);

            break;
        }
        case T_INDEXER:
        case T_CALL_EXPR:
        case T_BREAK:
        case T_EXPR:
        case T_WHILE:
        case T_BRANCH:
        case T_STMT:
        case T_BODY:
        case T_FUNC:
        case T_FUNC_SIGN: {
            fprintf(stdout, "\n");
            break;
        }
        case T_UN_EXPR: {
            fprintf(stdout, "[type: %s]\n", ot_symbol[node->as_unexpr.op]);
            break;
        }
        case T_BIN_EXPR: {
            fprintf(stdout, "[type: %s]\n", ot_symbol[node->as_binexpr.op]);
            break;
        }
        default: {
            fprintf(stdout, "<unknown-node>\n");
            break;
        }
    }
}

static void dump_cb(struct ast_node *node) { return; }

static void free_node(struct ast_node *node) {
    is_verbose && fprintf(stdout, "FREE: %lx\n", (long unsigned int) node);
    free(node);
}

void free_ast(struct ast_node *root) { dfs_bypass(root, dump_cb, free_node); }

int print_ast(struct ast_node *root) {
    dfs_bypass(root, preprint_ast, postprint_ast);
    return 1;
}

int countConnections(Agraph_t *graph, Agnode_t *node) {
    int count = 0;
    Agedge_t *edge;

    for (edge = agfstout(graph, node); edge; edge = agnxtout(graph, edge)) {
        count++;
    }

    return count;
}

static int id_cnt;
static Agraph_t *graph; // or arnode?

#define ADD_POSTFIX(array, value)                                              \
  do {                                                                         \
    char new_value[100];                                                       \
    sprintf(new_value, "%s : [ %s ]", array, value);                           \
    strcpy(array, new_value);                                                  \
  } while (0)

struct cfg_node *root_cfg_node;

struct cfg_node *create_cfg(struct ast_node *root) {
    // dfs_bypass(root, preprocess_cfg, postprocess_cfg);
    root_cfg_node = cfg_create(root, NULL, NULL);
    return root_cfg_node;
}

void print_body(struct cfg_node *cnode, char *buff) {
    if (cnode->body) {
        switch (cnode->body->type) {
            case T_BIN_EXPR: {

                ADD_POSTFIX(buff, ot_symbol[cnode->body->as_binexpr.op]);

                break;
            }
            case T_UN_EXPR: {
                ADD_POSTFIX(buff, ot_symbol[cnode->body->as_unexpr.op]);

                break;
            }

            default:
                break;
        }
    }
}

static char *fold_string(char **arr) {
    int i, len = 0;
    for (i = 0; i < 100 && arr[i] != NULL; ++i)
        len += strlen(arr[i]);

    char *result = malloc((len + 1) * sizeof(char));
    result[0] = '\0';

    for (i = 0; i < 100 && arr[i] != NULL; ++i)
        strcat(result, arr[i]);

    printf("fold_arr = %s\n", result);
    return result;
}

static void add_string(char **arr, char *str) {
    int i = 0;
    for (; arr[i]; i++) {
    }
    arr[i] = calloc(strlen(str) + 1, sizeof(char));
    strcpy(arr[i], str);
    printf("add_string: %s\n", arr[i]);
}

static void fold_child(struct cfg_node *cnode, char **arr) {

    char *str = NULL;

    switch (cnode->node->type) {
        case T_LITERAL: {
            printf("fold_child: literal\n");

            add_string(arr, cnode->node->as_literal.value);
            break;
        }
        case T_BIN_EXPR: {
            printf("fold_child: binexpr\n");
            char open[2] = "[\0";
            char close[2] = "]\0";
            add_string(arr, open);
            fold_child(cnode->connection_array[0], arr);
            str = ot_symbol[cnode->node->as_binexpr.op];
            add_string(arr, str);
            fold_child(cnode->connection_array[1], arr);
            add_string(arr, close);
            break;
        }
        case T_IDENT: {
            str = cnode->node->as_ident.name;
            printf("fold_child: ident, %s\n", str);

            add_string(arr, str);
            break;
        }
    }
}

struct fold_data {
    struct cfg_node *cnode;
    char *label;
};

static struct fold_data fold(struct cfg_node *cnode) {
    if (cnode->node->type == T_BIN_EXPR) {
        struct cfg_node *node = malloc(sizeof(struct cfg_node));
        memset(node->connection_array, NULL, 100 * sizeof(void *));

        node->is_visited = cnode->is_visited;
        node->is_visited_asm = cnode->is_visited_asm;
        node->body = cnode->body;
        node->node = cnode->node;
        node->parents = calloc(100, sizeof(struct cfg_node *));
        node->agn_node = cnode->agn_node;
        for (int i = 0; cnode->parents[i]; i++) {
            node->parents[i] = cnode->parents[i];
        }
        for (int i = 2; cnode->connection_array[i]; i++) {
            node->connection_array[i - 2] = cnode->connection_array[i];
        }
        char **arr = arr = calloc(100, sizeof(char *));
        fold_child(cnode->connection_array[0], arr);
        char *str = ot_symbol[cnode->node->as_binexpr.op];
        add_string(arr, str);
        fold_child(cnode->connection_array[1], arr);
        char *res_str = fold_string(arr);
        struct fold_data data = {.cnode = node, .label = res_str};
        return data;
    } else if (cnode->node->type == T_BRANCH) {
        char **arr = arr = calloc(100, sizeof(char *));
        char *tmp1 = "if";
        add_string(arr, tmp1);
        struct cfg_node *cn = cfg_create(cnode->node->as_branch.test, NULL, NULL);
        fold_child(cn, arr);
        char *res_str = fold_string(arr);
        free(cn);
        return (struct fold_data) {.cnode = cnode, .label = res_str};

    } else if (cnode->node->type == T_WHILE || cnode->node->type == T_REPEAT) {
        struct cfg_node *cn = cfg_create(cnode->node->as_repeat.test, NULL, NULL);
        char **arr = arr = calloc(100, sizeof(char *));
        char *tmp1 = "while";
        add_string(arr, tmp1);
        fold_child(cn, arr);
        char *res_str = fold_string(arr);
        free(cn);
        return (struct fold_data) {.cnode = cnode, .label = res_str};

    } else if (cnode->node->type == T_FUNC) {
        return (struct fold_data) {
                .cnode = cnode,
                .label =
                cnode->node->as_func.func_sign->as_func_sign.ident->as_ident.name};

    } else if (cnode->node->type == T_CALL_EXPR) {
        char **arr = arr = calloc(100, sizeof(char *));
        char *tmp1 =
                cnode->node->as_call_expr.expr->as_expr.some_node->as_ident.name;
        printf("tmp1 = %s\n", tmp1);
        add_string(arr, tmp1);
        add_string(arr, "(");
        add_string(arr, ")");
        char *res_str = fold_string(arr);
        return (struct fold_data){.cnode = cnode, .label = res_str};

    } else
        return (struct fold_data) {.cnode = cnode, .label = NULL};
}

void dfs_print_cfg(struct cfg_node *node, struct cfg_node *prev_node) {

    if (node->is_visited)
        return;

    node->is_visited = true;
    char id[10];
    char label_buf[100];

    strcpy(label_buf, ant_names[node->node->type]);

    sprintf(id, "%d", id_cnt);

    print_body(node, label_buf);

    switch (node->node->type) {
        case T_LITERAL: {
            ADD_POSTFIX(label_buf, node->node->as_literal.value);
            ADD_POSTFIX(label_buf, literal_names[node->body->as_typeref_lt.type]);

            break;
        }
        case T_IDENT: {
            ADD_POSTFIX(label_buf, node->node->as_ident.name);
            ADD_POSTFIX(label_buf, typeref_names[node->body->as_typeref.type]);
            break;
        }
        default:
            break;
    }
    node->agn_node = agnode(graph, id, 1);
    struct fold_data fd = fold(node);
    struct cfg_node *cnode = fd.cnode;

//    struct cfg_node *cnode = node;

    char *fold_label = fd.label;
    fold_label == NULL ? agset(cnode->agn_node, "label", label_buf)
                       : agset(cnode->agn_node, "label", fd.label);
    id_cnt++;

    for (int i = 0; cnode->connection_array[i] != NULL; i++) {
        if (cnode->node->type == T_BRANCH && !cnode->connection_array[1] &&
            cnode->connection_array[2]) {
            dfs_print_cfg(cnode->connection_array[2], cnode);
            Agedge_t *e = agedge(graph, cnode->agn_node,
                                 cnode->connection_array[2]->agn_node, 0, 1);
            agset(e, "label", "your label here");
        }

        dfs_print_cfg(cnode->connection_array[i], cnode);

        Agedge_t *e = agedge(graph, cnode->agn_node,
                             cnode->connection_array[i]->agn_node, 0, 1);
        agset(e, "label", "your text here");
    }
}

int print_cfg(struct ast_node *root) {

    id_cnt = 0;

    struct ast_node *iter = root;
    for (int i = 0; iter; i++) {
        GVC_t *gvc = gvContext();
        graph = agopen("G", Agdirected, NULL);
        struct cfg_node *croot = create_cfg(iter);
        dfs_print_cfg(croot, NULL);
        printf("return\n");
        //   struct ast_node *extra = NULL;
        //   dfs_bypass_cfg(root, NULL, &extra, NULL);

        char filename[10];
        sprintf(filename, "%s%d.png", "file", i);
        printf("return 1\n");
        gvLayout(gvc, graph, "dot");
        gvRenderFilename(gvc, graph, "png", filename);
        gvFreeLayout(gvc, graph);
        agclose(graph);
        gvFreeContext(gvc);

        // instr_list_t *instr_list = malloc(sizeof(instr_list_t));
//        instr_list_t *instr_list = NULL;
//        labels_t **larr = calloc(100, sizeof(labels_t * ));
//        instr_list = dfs_cfg_asm(croot, NULL, NULL, NULL, larr, false, NULL);
//        printf("instr_list ptr = %p\n", instr_list);
//        print_instr_list(instr_list);

        iter = iter->as_program.next_func;
    }

    return 1;
}
