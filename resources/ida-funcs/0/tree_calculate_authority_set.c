int __cdecl tree_calculate_authority_set(X509_POLICY_TREE_st *tree, stack_st_X509_POLICY_NODE **pnodes)
{
  char *anyPolicy; // esi
  stack_st_X509_POLICY_NODE *auth_policies; // eax
  stack_st **p_auth_policies; // ebx
  stack_st_X509_POLICY_NODE *v5; // eax
  stack_st_X509_POLICY_NODE **v7; // ebp
  stack_st_X509_POLICY_NODE **p_nodes; // edi
  const stack_st *v9; // eax
  int v10; // ebx
  char *v11; // esi
  stack_st_X509_POLICY_NODE *v12; // eax
  int v13; // [esp+10h] [ebp-Ch]
  stack_st_X509_POLICY_NODE **v14; // [esp+14h] [ebp-8h]
  stack_st_X509_POLICY_NODE *v15; // [esp+18h] [ebp-4h]

  anyPolicy = (char *)tree->levels[tree->nlevel - 1].anyPolicy;
  if ( anyPolicy )
  {
    auth_policies = tree->auth_policies;
    p_auth_policies = (stack_st **)&tree->auth_policies;
    v14 = &tree->auth_policies;
    if ( auth_policies )
    {
      if ( sk_find(&auth_policies->stack, anyPolicy) != -1 )
      {
LABEL_8:
        v7 = pnodes;
        goto LABEL_10;
      }
    }
    else
    {
      v5 = policy_node_cmp_new();
      *p_auth_policies = &v5->stack;
      if ( !v5 )
        return 0;
    }
    if ( !sk_push(*p_auth_policies, anyPolicy) )
      return 0;
    goto LABEL_8;
  }
  v7 = &tree->auth_policies;
  v14 = &tree->auth_policies;
LABEL_10:
  v13 = 1;
  if ( tree->nlevel > 1 )
  {
    p_nodes = &tree->levels->nodes;
    do
    {
      v15 = p_nodes[1];
      if ( !v15 )
        break;
      v9 = (const stack_st *)p_nodes[4];
      p_nodes += 4;
      v10 = 0;
      if ( sk_num(v9) > 0 )
      {
        do
        {
          v11 = sk_value(&(*p_nodes)->stack, v10);
          if ( *((stack_st_X509_POLICY_NODE **)v11 + 1) == v15 )
          {
            if ( !*v7 )
            {
              v12 = policy_node_cmp_new();
              *v7 = v12;
              if ( !v12 )
                return 0;
LABEL_19:
              if ( !sk_push(&(*v7)->stack, v11) )
                return 0;
              goto LABEL_20;
            }
            if ( sk_find(&(*v7)->stack, v11) == -1 )
              goto LABEL_19;
          }
LABEL_20:
          ++v10;
        }
        while ( v10 < sk_num(&(*p_nodes)->stack) );
      }
      ++v13;
    }
    while ( v13 < tree->nlevel );
  }
  if ( v7 == pnodes )
    return 2;
  *pnodes = *v14;
  return 1;
}
