const X509_POLICY_NODE_st **__cdecl level_find_node(
        const X509_POLICY_LEVEL_st *level,
        const X509_POLICY_NODE_st *parent,
        const asn1_object_st *id)
{
  int v3; // edi
  const X509_POLICY_NODE_st **v4; // esi

  v3 = 0;
  if ( sk_num(&level->nodes->stack) <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = (const X509_POLICY_NODE_st **)sk_value(&level->nodes->stack, v3);
    if ( v4[1] == parent && !OBJ_cmp((const asn1_object_st *)(*v4)->parent, id) )
      break;
    if ( ++v3 >= sk_num(&level->nodes->stack) )
      return 0;
  }
  return v4;
}
