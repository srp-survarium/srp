int __usercall tree_calculate_user_set@<eax>(
        stack_st_ASN1_OBJECT *policy_oids@<ebx>,
        X509_POLICY_TREE_st *tree,
        stack_st_X509_POLICY_NODE *auth_nodes)
{
  X509_POLICY_NODE_st *anyPolicy; // ebp
  int v5; // esi
  char *v6; // eax
  asn1_object_st *v7; // edi
  X509_POLICY_NODE_st *sk; // esi
  X509_POLICY_DATA_st *v9; // eax
  X509_POLICY_TREE_st *v10; // edi
  stack_st *v11; // eax
  const stack_st *v12; // [esp+0h] [ebp-8h]
  int v13; // [esp+4h] [ebp-4h]

  if ( sk_num(v12) <= 0 )
    return 1;
  anyPolicy = tree->levels[tree->nlevel - 1].anyPolicy;
  v5 = 0;
  if ( sk_num(&policy_oids->stack) > 0 )
  {
    while ( 1 )
    {
      v6 = sk_value(&policy_oids->stack, v5);
      if ( OBJ_obj2nid((const asn1_object_st *)v6) == (void *)746 )
        break;
      if ( ++v5 >= sk_num(&policy_oids->stack) )
        goto LABEL_6;
    }
    tree->flags |= 2u;
    return 1;
  }
LABEL_6:
  v13 = 0;
  if ( sk_num(&policy_oids->stack) <= 0 )
    return 1;
  while ( 1 )
  {
    v7 = (asn1_object_st *)sk_value(&policy_oids->stack, v13);
    sk = tree_find_sk(auth_nodes, v7);
    if ( sk )
    {
      v10 = tree;
      goto LABEL_14;
    }
    if ( anyPolicy )
      break;
LABEL_17:
    if ( ++v13 >= sk_num(&policy_oids->stack) )
      return 1;
  }
  v9 = (X509_POLICY_DATA_st *)policy_data_new(0, v7, anyPolicy->data->flags & 0x10);
  if ( !v9 )
    return 0;
  v10 = tree;
  v9->qualifier_set = anyPolicy->data->qualifier_set;
  v9->flags = 12;
  sk = level_add_node(0, v9, anyPolicy->parent, tree);
LABEL_14:
  if ( !v10->user_policies )
  {
    v11 = sk_new_null();
    v10->user_policies = (stack_st_X509_POLICY_NODE *)v11;
    if ( !v11 )
      return 1;
  }
  if ( sk_push(&v10->user_policies->stack, (char *)sk) )
    goto LABEL_17;
  return 0;
}
