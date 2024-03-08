#include "dfs.h"

//#include "symbol_table.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs_bypass(struct ast_node *node, process_cb preproccess_cb,
                process_cb postprocess_cb) {
    if (node == NULL)
        return;

    node->is_visited = true;
    preproccess_cb(node);
    switch (node->type) {
        case T_PROGRAM: {
            dfs_bypass(node->as_program.next_func, preproccess_cb, postprocess_cb);
            dfs_bypass(node->as_program.child, preproccess_cb, postprocess_cb);
            break;
        }
        case T_EXPR_LIST:
        case T_ARGDEF_LIST:
        case T_ARRAY:
        case T_LIT_LIST:
        case T_STMTS_LIST: {
            struct ast_node *iter = node;
            while (iter != NULL) {
                dfs_bypass(iter->as_list.current, preproccess_cb, postprocess_cb);
                struct ast_node *temp = iter;
                iter = iter->as_list.next;
                // postprocess_cb(temp);
            }
            return;
            // break;
        }
        case T_WHILE:
        case T_REPEAT: {
            dfs_bypass(node->as_repeat.test, preproccess_cb, postprocess_cb);
            dfs_bypass(node->as_repeat.body, preproccess_cb, postprocess_cb);
            break;
        }
        case T_BRANCH: {
            dfs_bypass(node->as_branch.test, preproccess_cb,
                       postprocess_cb); // todo add node?
            dfs_bypass(node->as_branch.consequent, preproccess_cb, postprocess_cb);
            dfs_bypass(node->as_branch.alternate, preproccess_cb, postprocess_cb);
            break;
        }
        case T_BIN_EXPR: {
            dfs_bypass(node->as_binexpr.arg1, preproccess_cb, postprocess_cb);
            dfs_bypass(node->as_binexpr.arg2, preproccess_cb, postprocess_cb);

            break;
        }
        case T_UN_EXPR: {
            dfs_bypass(node->as_unexpr.argument, preproccess_cb, postprocess_cb);
            break;
        }
        case T_INDEXER: {
            dfs_bypass(node->as_indexer.expr, preproccess_cb, postprocess_cb);
            dfs_bypass(node->as_indexer.expr_list, preproccess_cb, postprocess_cb);
            break;
        }
        case T_CALL_EXPR: {
            dfs_bypass(node->as_call_expr.expr, preproccess_cb, postprocess_cb);
            dfs_bypass(node->as_call_expr.expr_list, preproccess_cb, postprocess_cb);
            break;
        }
        case T_FUNC_SIGN: {
            dfs_bypass(node->as_func_sign.ident, preproccess_cb, postprocess_cb);
            dfs_bypass(node->as_func_sign.arg_list, preproccess_cb, postprocess_cb);
            break;
        }
        case T_FUNC: {
            dfs_bypass(node->as_func.func_sign, preproccess_cb, postprocess_cb);
            dfs_bypass(node->as_func.body, preproccess_cb, postprocess_cb);
            break;
        }
        case T_IDENT: {
            dfs_bypass(node->as_ident.type, preproccess_cb, postprocess_cb);
            break;
        }
        case T_BODY: {
            dfs_bypass(node->as_body.var_list, preproccess_cb,
                       postprocess_cb); // todo rename to var_list
            dfs_bypass(node->as_body.statement, preproccess_cb, postprocess_cb);
            break;
        }

        case T_STMT: {
            dfs_bypass(node->as_statement.some_node, preproccess_cb, postprocess_cb);
            break;
        }
        case T_EXPR: {
            dfs_bypass(node->as_expr.some_node, preproccess_cb, postprocess_cb);
            break;
        }
        case T_TYPE_REF: {
            if (node->as_typeref.type == TR_IDENT || node->as_typeref.type == TR_ARR) {
                dfs_bypass(node->as_typeref.sub_field, preproccess_cb, postprocess_cb);
            }
            break;
        }
        default: {
            break;
        }
    }
    postprocess_cb(node);
    return;
}

static void insert_connect(struct cfg_node *node, struct cfg_node **arr) {
    int i = 0;
    for (; arr[i]; i++)
        ;

    arr[i] = node;
}

static void set_parent(struct cfg_node *node, struct cfg_node *parent) {
    int i = 0;
    for (; node->parents[i] && i < 100; i++)
        ;
    node->parents[i] = parent;
}

static int get_parents_num(struct cfg_node *node) {
    int i = 0;
    for (; node->parents[i] && i < 100; i++)
        ;
    return i;
}

static struct cfg_node *create_cfg_node(struct ast_node *node) {
    struct cfg_node *cnode = malloc(sizeof(struct cfg_node));
    memset(cnode->connection_array, NULL, 100 * sizeof(void *));

    cnode->is_visited = false;
    cnode->is_visited_asm = false;
    cnode->body = NULL;
    cnode->node = node;
    cnode->parents = calloc(100, sizeof(struct cfg_node *));

    return cnode;
}

struct ast_node *reverse_ast_list(struct ast_node *head) {
    if (head == NULL || head->as_list.next == NULL)
        return head;

    struct ast_node *rest = reverse_ast_list(head->as_list.next);
    head->as_list.next->as_list.next = head;
    head->as_list.next = NULL;

    return rest;
}

struct cfg_node *cfg_create(struct ast_node *node, struct cfg_node *prev_cfg,
                            struct cfg_node *next_node) {
    if (node == NULL)
        return NULL;

    // node->is_visited = true;
    struct cfg_node *cnode = NULL;
    struct cfg_node *ret_val = NULL;
    switch (node->type) {
        case T_PROGRAM: {
            ret_val = cfg_create(node->as_program.child, cnode, NULL);
            break;
        }
        case T_ARGDEF_LIST: {
            struct ast_node *iter = reverse_ast_list(node);
            struct cfg_node *last_cfg = NULL;

            while (iter != NULL) {
                ret_val = cfg_create(iter->as_list.current, NULL, ret_val);
                if (!last_cfg)
                    last_cfg = ret_val;
                iter = iter->as_list.next;
            }
            return last_cfg;

            break;
        }
        case T_EXPR_LIST:

        case T_ARRAY:
        case T_LIT_LIST:
        case T_STMTS_LIST: {

            struct ast_node *iter;
            struct cfg_node *prev_iter = prev_cfg;

            // iter = (prev_cfg->node->type == T_FUNC || prev_cfg->node->type ==
            // T_WHILE)
            //            ? reverse_ast_list(node)
            //            : node;

            iter = reverse_ast_list(node);

            struct cfg_node *parent_iter = prev_cfg;
            struct cfg_node *last_cfg = NULL;

            while (iter != NULL) {
                // if (prev_cfg->node->type != T_FUNC && prev_cfg->node->type != T_WHILE)
                //   ret_val = NULL;

                ret_val = cfg_create(iter->as_list.current, NULL, ret_val);
                if (!last_cfg)
                    last_cfg = ret_val;

                iter = iter->as_list.next;
            }

            // if (prev_cfg->node->type == T_FUNC || prev_cfg->node->type == T_WHILE)
            insert_connect(ret_val, prev_cfg->connection_array);
            set_parent(ret_val, prev_cfg);

            if (next_node) {
                if (last_cfg->node->type == T_BRANCH) {
                    // if ()
                    insert_connect(next_node,
                                   last_cfg->connection_array[0]->connection_array);
                    set_parent(next_node, last_cfg->connection_array[0]);

                    if (last_cfg->connection_array[1]) {
                        insert_connect(next_node,
                                       last_cfg->connection_array[1]->connection_array);
                        set_parent(next_node, last_cfg->connection_array[1]);

                    } else {
                        insert_connect(next_node, last_cfg->connection_array);
                        set_parent(next_node, last_cfg);
                    }
                } else {
                    insert_connect(next_node, last_cfg->connection_array);
                    set_parent(next_node, last_cfg);
                }

                // insert_connect(next_node, last_cfg->connection_array);
                // set_parent(next_node, last_cfg);
            }
            return last_cfg;
            // ret_val = last_cfg;
            break;
        }
        case T_WHILE:
        case T_REPEAT: {
            // cfg_create(node->as_repeat.test, cnode);
            cnode = create_cfg_node(node);
            cnode->body = node->as_repeat.test;

//            ret_val = cfg_create(node->as_repeat.body, cnode, next_node);
            ret_val = cfg_create(node->as_repeat.body, cnode, NULL);
            insert_connect(cnode, ret_val->connection_array);
            insert_connect(next_node, cnode->connection_array);
            set_parent(cnode, prev_cfg);

            break;
        }
        case T_BRANCH: {
            // printf("%s\n", ant_names[prev_cfg->node->type]);
            //  cfg_create(node->as_branch.test); // todo add node?
            cnode = create_cfg_node(node);
            cnode->body = node->as_branch.test;

            ret_val = cfg_create(node->as_branch.consequent, cnode, next_node);
            if (node->as_branch.alternate)
                ret_val = cfg_create(node->as_branch.alternate, cnode, next_node);
            else if (next_node) {
                cnode->connection_array[2] = next_node;
                // insert_connect(next_node, cnode->connection_array);
                // set_parent(cnode, prev_cfg);
                set_parent(next_node, cnode);
            }

            break;
        }
        case T_BIN_EXPR: {
            cnode = create_cfg_node(node);
            cnode->body = node;
            ret_val = cfg_create(node->as_binexpr.arg1, cnode, NULL);
            ret_val = cfg_create(node->as_binexpr.arg2, cnode, NULL);
            if (next_node) {
                insert_connect(next_node, cnode->connection_array);
                set_parent(next_node, cnode);
            }
            break;
        }
        case T_UN_EXPR: {
            cnode = create_cfg_node(node);
            cnode->body = node;
            ret_val = cfg_create(node->as_unexpr.argument, cnode, NULL);
            if (next_node) {
                insert_connect(next_node, cnode->connection_array);
                set_parent(next_node, cnode);
            }

            break;
        }
        case T_INDEXER: {
            // ret_val = cfg_create(node->as_indexer.expr, cnode);
            // ret_val = cfg_create(node->as_indexer.expr_list, cnode);
            break;
        }
        case T_CALL_EXPR: {
            cnode = create_cfg_node(node);
            if (next_node) {
                insert_connect(next_node, cnode->connection_array);
                set_parent(next_node, cnode);
            }
            // cfg_create(node->as_call_expr.expr, cnode, next_node);
            char *name = node->as_call_expr.expr->as_ident.name;
            // ret_val = cfg_create(node->as_call_expr.expr_list, cnode, next_node);
            break;
        }
        case T_FUNC_SIGN: {
            // cfg_create(node->as_func_sign.ident);
            ret_val = cfg_create(node->as_func_sign.arg_list, cnode, next_node);
            break;
        }
        case T_FUNC: {
            cnode = create_cfg_node(node);
            cfg_create(node->as_func.func_sign, cnode, next_node);
            ret_val = cfg_create(node->as_func.body, cnode, next_node);
            break;
        }
        case T_IDENT: {
            cnode = create_cfg_node(node);
            cnode->body = node->as_ident.type;
            ret_val = cfg_create(node->as_ident.type, cnode, next_node);
            break;
        }
        case T_LITERAL: {
            cnode = create_cfg_node(node);
            cnode->body = node->as_literal.type;
            break;
        }
        case T_BODY: {
            // cfg_create(node->as_body.var_list); // todo rename to var_list
            ret_val = cfg_create(node->as_body.statement, prev_cfg, next_node);
            break;
        }

        case T_STMT: {
            // if (node->as_statement.some_node->type == T_EXPR) {
            //   cnode = create_cfg_node(node);
            //   struct ast_node *tmp = node->as_statement.some_node;
            //   cnode->body = tmp->as_expr.some_node;
            // }

            ret_val = cfg_create(node->as_statement.some_node, prev_cfg, next_node);
            break;
        }
        case T_EXPR: {
            ret_val = cfg_create(node->as_expr.some_node, prev_cfg, next_node);
            break;
        }
        case T_TYPE_REF: {
            // if (node->as_typeref.type == TR_IDENT || node->as_typeref.type == TR_ARR)
            // {
            //   cfg_create(node->as_typeref.sub_field, cnode);
            // }
            break;
        }
        default: {
            break;
        }
    }
    if (cnode && prev_cfg) { // && prev_cfg->node->type != T_FUNC
        set_parent(cnode, prev_cfg);
        insert_connect(cnode, prev_cfg->connection_array);
    }
    return ((cnode) ? cnode : ret_val);
    // return cnode;
}


