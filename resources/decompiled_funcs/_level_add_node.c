X509_POLICY_NODE_st *__cdecl level_add_node(
        X509_POLICY_LEVEL_st *level,
        X509_POLICY_DATA_st *data,
        X509_POLICY_NODE_st *parent,
        X509_POLICY_TREE_st *tree)
{
  X509_POLICY_NODE_st *result; // eax
  X509_POLICY_NODE_st *v5; // edi
  stack_st_X509_POLICY_NODE *nodes; // esi
  stack_st_X509_POLICY_DATA *extra_data; // eax

  result = (X509_POLICY_NODE_st *)CRYPTO_malloc(12, ".\\crypto\\x509v3\\pcy_node.c", 118);
  v5 = result;
  if ( result )
  {
    result->data = data;
    result->parent = parent;
    result->nchild = 0;
    if ( level )
    {
      if ( OBJ_obj2nid(data->valid_policy) == 746 )
      {
        if ( level->anyPolicy )
        {
node_error:
          CRYPTO_free(v5);
          return 0;
        }
        level->anyPolicy = v5;
      }
      else
      {
        if ( !level->nodes )
          level->nodes = (stack_st_X509_POLICY_NODE *)sk_new((int (__cdecl *)(const void *, const void *))node_cmp);
        nodes = level->nodes;
        if ( !nodes || !sk_push(&nodes->stack, (char *)v5) )
          goto node_error;
      }
    }
    if ( tree )
    {
      if ( !tree->extra_data )
        tree->extra_data = (stack_st_X509_POLICY_DATA *)sk_new_null();
      extra_data = tree->extra_data;
      if ( !extra_data || !sk_push(&extra_data->stack, (char *)data) )
        goto node_error;
    }
    if ( parent )
      ++parent->nchild;
    return v5;
  }
  return result;
}
