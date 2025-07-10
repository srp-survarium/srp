BOOL __cdecl policy_node_match(
        const X509_POLICY_LEVEL_st *lvl,
        const X509_POLICY_NODE_st *node,
        const asn1_object_st *oid)
{
  const X509_POLICY_DATA_st *data; // edi
  int v4; // esi
  char *v5; // eax

  data = node->data;
  if ( (lvl->flags & 0x400) != 0 || (data->flags & 3) == 0 )
    return OBJ_cmp(data->valid_policy, oid) == 0;
  v4 = 0;
  if ( sk_num(&data->expected_policy_set->stack) <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = sk_value(&data->expected_policy_set->stack, v4);
    if ( !OBJ_cmp((const asn1_object_st *)v5, oid) )
      break;
    if ( ++v4 >= sk_num(&data->expected_policy_set->stack) )
      return 0;
  }
  return 1;
}
