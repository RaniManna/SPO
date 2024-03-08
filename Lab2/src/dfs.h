#include "ast.h"

void dfs_bypass(struct ast_node *node, process_cb preproccess_cb,
                process_cb postprocess_cb);

struct cfg_node *cfg_create(struct ast_node *node, struct cfg_node *prev_cfg,
                            struct cfg_node *next_node);

