int __usercall tree_link_unmatched@<eax>(
        X509_POLICY_LEVEL_st *curr@<ebx>,
        X509_POLICY_NODE_st *node@<ecx>,
        const X509_POLICY_CACHE_st *cache,
        X509_POLICY_TREE_st *tree)
{
  const stack_st *p_stack; // esi
  int v6; // ebp
  asn1_object_st *v8; // esi
  X509_POLICY_DATA_st *v9; // esi
  stack_st_POLICYQUALINFO *qualifier_set; // eax
  stack_st_ASN1_OBJECT *st; // [esp+Ch] [ebp-4h]

  if ( (curr[-1].flags & 0x400) != 0 || (node->data->flags & 1) == 0 )
  {
    if ( !node->nchild )
    {
      v9 = (X509_POLICY_DATA_st *)policy_data_new(0, node->data->valid_policy, node->data->flags & 0x10);
      if ( !v9 )
        return 0;
      qualifier_set = cache->anyPolicy->qualifier_set;
      v9->flags |= 4u;
      v9->qualifier_set = qualifier_set;
      if ( !level_add_node(curr, v9, node, tree) )
      {
        policy_data_free(v9);
        return 0;
      }
    }
    return 1;
  }
  st = node->data->expected_policy_set;
  p_stack = &st->stack;
  if ( node->nchild == sk_num(&st->stack) )
    return 1;
  v6 = 0;
  if ( sk_num(&st->stack) <= 0 )
    return 1;
  while ( 1 )
  {
    v8 = (asn1_object_st *)sk_value(p_stack, v6);
    if ( !level_find_node(curr, node, v8) && !tree_add_unmatched(node, curr, cache, v8, tree) )
      break;
    if ( ++v6 >= sk_num(&st->stack) )
      return 1;
    p_stack = &st->stack;
  }
  return 0;
}
