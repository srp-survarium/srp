int __cdecl tree_prune(X509_POLICY_TREE_st *tree)
{
  X509_POLICY_LEVEL_st *curr; // ecx
  X509_POLICY_LEVEL_st *v2; // ebx
  stack_st_X509_POLICY_NODE *nodes; // edi
  int i; // esi
  char *v5; // eax
  stack_st *p_stack; // edi
  int j; // esi
  char *v8; // eax
  X509_POLICY_NODE_st *anyPolicy; // eax

  v2 = curr;
  nodes = curr->nodes;
  if ( (curr->flags & 0x400) != 0 )
  {
    for ( i = sk_num(&curr->nodes->stack) - 1; i >= 0; --i )
    {
      v5 = sk_value(&nodes->stack, i);
      if ( (**(_BYTE **)v5 & 3) != 0 )
      {
        --*(_DWORD *)(*((_DWORD *)v5 + 1) + 8);
        CRYPTO_free(v5);
        sk_delete(&nodes->stack, i);
      }
    }
  }
  do
  {
    p_stack = &v2[-1].nodes->stack;
    --v2;
    for ( j = sk_num(p_stack) - 1; j >= 0; --j )
    {
      v8 = sk_value(p_stack, j);
      if ( !*((_DWORD *)v8 + 2) )
      {
        --*(_DWORD *)(*((_DWORD *)v8 + 1) + 8);
        CRYPTO_free(v8);
        sk_delete(p_stack, j);
      }
    }
    anyPolicy = v2->anyPolicy;
    if ( anyPolicy && !anyPolicy->nchild )
    {
      if ( anyPolicy->parent )
        --anyPolicy->parent->nchild;
      CRYPTO_free(v2->anyPolicy);
      v2->anyPolicy = 0;
    }
  }
  while ( v2 != tree->levels );
  return 2 - (v2->anyPolicy != 0);
}
