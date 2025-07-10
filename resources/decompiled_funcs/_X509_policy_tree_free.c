void __cdecl X509_policy_tree_free(X509_POLICY_TREE_st *tree)
{
  X509_POLICY_LEVEL_st *levels; // esi
  int i; // ebx
  stack_st *p_stack; // eax
  stack_st_X509_POLICY_DATA *extra_data; // eax

  if ( tree )
  {
    sk_free(&tree->auth_policies->stack);
    sk_pop_free(&tree->user_policies->stack, (void (__cdecl *)(void *))exnode_free);
    levels = tree->levels;
    for ( i = 0; i < tree->nlevel; ++levels )
    {
      if ( levels->cert )
        X509_free(levels->cert);
      p_stack = &levels->nodes->stack;
      if ( p_stack )
        sk_pop_free(p_stack, (void (__cdecl *)(void *))policy_node_free);
      if ( levels->anyPolicy )
        policy_node_free(levels->anyPolicy);
      ++i;
    }
    extra_data = tree->extra_data;
    if ( extra_data )
      sk_pop_free(&extra_data->stack, (void (__cdecl *)(void *))policy_data_free);
    CRYPTO_free(tree->levels);
    CRYPTO_free(tree);
  }
}
