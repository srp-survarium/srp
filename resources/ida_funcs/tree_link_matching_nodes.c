BOOL __cdecl tree_link_matching_nodes(X509_POLICY_LEVEL_st *curr, const X509_POLICY_DATA_st *data)
{
  X509_POLICY_LEVEL_st *v2; // esi
  int v3; // ebx
  X509_POLICY_NODE_st *v4; // edi
  X509_POLICY_NODE_st *anyPolicy; // esi
  int v7; // [esp+10h] [ebp-4h]

  v2 = curr - 1;
  v3 = 0;
  v7 = 0;
  if ( sk_num(&curr[-1].nodes->stack) > 0 )
  {
    do
    {
      v4 = (X509_POLICY_NODE_st *)sk_value(&v2->nodes->stack, v3);
      if ( policy_node_match(v2, v4, data->valid_policy) )
      {
        if ( !level_add_node(curr, data, v4, 0) )
          return 0;
        v7 = 1;
      }
      ++v3;
    }
    while ( v3 < sk_num(&v2->nodes->stack) );
    if ( v7 )
      return 1;
  }
  anyPolicy = v2->anyPolicy;
  return !anyPolicy || level_add_node(curr, data, anyPolicy, 0);
}
