int __cdecl X509_policy_check(
        X509_POLICY_TREE_st **ptree,
        int *pexplicit_policy,
        stack_st_X509 *certs,
        stack_st_ASN1_OBJECT *policy_oids)
{
  int result; // eax
  X509_POLICY_TREE_st *v5; // esi
  int v6; // eax
  int v7; // edi
  stack_st_X509_POLICY_NODE *v8; // ebp
  stack_st_X509_POLICY_NODE *v9; // eax
  bool v10; // cc
  X509_POLICY_TREE_st *ptreea; // [esp+10h] [ebp-8h] BYREF
  stack_st_X509_POLICY_NODE *pnodes; // [esp+14h] [ebp-4h] BYREF

  *ptree = 0;
  ptreea = 0;
  pnodes = 0;
  *pexplicit_policy = 0;
  switch ( tree_init(&ptreea, certs) )
  {
    case -1:
      return -1;
    case 0:
      return 0;
    case 1:
      v5 = ptreea;
      if ( ptreea )
        goto LABEL_6;
      return 1;
    case 2:
      return 1;
    case 5:
      *pexplicit_policy = 1;
      goto LABEL_5;
    case 6:
      *pexplicit_policy = 1;
      return -2;
    default:
LABEL_5:
      v5 = ptreea;
      if ( !ptreea )
        goto error_0;
LABEL_6:
      v6 = tree_evaluate(v5);
      if ( v6 <= 0 )
        goto error_0;
      if ( v6 == 2 )
      {
        X509_policy_tree_free(v5);
        return *pexplicit_policy != 0 ? -2 : 1;
      }
      else
      {
        v7 = tree_calculate_authority_set(v5, &pnodes);
        if ( v7 && (v8 = pnodes, tree_calculate_user_set(policy_oids, v5, pnodes)) )
        {
          if ( v7 == 2 )
            sk_free(&v8->stack);
          if ( v5 )
            *ptree = v5;
          if ( !*pexplicit_policy )
            return 1;
          v9 = X509_policy_tree_get0_user_policies(v5);
          v10 = sk_num(&v9->stack) <= 0;
          result = -2;
          if ( !v10 )
            return 1;
        }
        else
        {
error_0:
          X509_policy_tree_free(v5);
          return 0;
        }
      }
      return result;
  }
}
