int __cdecl tree_prune(X509_POLICY_TREE_st *tree)
{
  X509_POLICY_LEVEL_st *v1; // ecx
  X509_POLICY_LEVEL_st *v2; // ebx
  stack_st *p_stack; // edi
  int i; // esi
  char *v5; // eax
  stack_st *v6; // edi
  int j; // esi
  char *v8; // eax
  X509_POLICY_NODE_st *anyPolicy; // eax

  v2 = v1;
  p_stack = &v1->nodes->stack;
  if ( (v1->flags & 0x400) != 0 )
  {
    for ( i = sk_num(&v1->nodes->stack) - 1; i >= 0; --i )
    {
      v5 = sk_value(p_stack, i);
      if ( (**(_BYTE **)v5 & 3) != 0 )
      {
        --*(_DWORD *)(*((_DWORD *)v5 + 1) + 8);
        CRYPTO_free(v5);
        sk_delete(p_stack, i);
      }
    }
  }
  do
  {
    v6 = &v2[-1].nodes->stack;
    --v2;
    for ( j = sk_num(v6) - 1; j >= 0; --j )
    {
      v8 = sk_value(v6, j);
      if ( !*((_DWORD *)v8 + 2) )
      {
        --*(_DWORD *)(*((_DWORD *)v8 + 1) + 8);
        CRYPTO_free(v8);
        sk_delete(v6, j);
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
