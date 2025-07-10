int __usercall tree_link_any@<eax>(
        X509_POLICY_LEVEL_st *curr@<ecx>,
        const X509_POLICY_CACHE_st *cache@<edi>,
        X509_POLICY_TREE_st *tree)
{
  int v4; // esi
  char *v5; // eax
  X509_POLICY_NODE_st *anyPolicy; // eax

  v4 = 0;
  if ( sk_num(&curr[-1].nodes->stack) <= 0 )
  {
LABEL_4:
    anyPolicy = curr[-1].anyPolicy;
    if ( !anyPolicy || level_add_node(curr, cache->anyPolicy, anyPolicy, 0) )
      return 1;
  }
  else
  {
    while ( 1 )
    {
      v5 = sk_value(&curr[-1].nodes->stack, v4);
      if ( !tree_link_unmatched(curr, (X509_POLICY_NODE_st *)v5, cache, tree) )
        break;
      if ( ++v4 >= sk_num(&curr[-1].nodes->stack) )
        goto LABEL_4;
    }
  }
  return 0;
}
