int __usercall tree_add_unmatched@<eax>(
        X509_POLICY_NODE_st *node@<edi>,
        X509_POLICY_LEVEL_st *curr,
        const X509_POLICY_CACHE_st *cache,
        asn1_object_st *id,
        X509_POLICY_TREE_st *tree)
{
  asn1_object_st *valid_policy; // eax
  X509_POLICY_DATA_st *v6; // esi
  stack_st_POLICYQUALINFO *qualifier_set; // edx

  valid_policy = id;
  if ( !id )
    valid_policy = node->data->valid_policy;
  v6 = policy_data_new(0, valid_policy, node->data->flags & 0x10);
  if ( !v6 )
    return 0;
  qualifier_set = cache->anyPolicy->qualifier_set;
  v6->flags |= 4u;
  v6->qualifier_set = qualifier_set;
  if ( !level_add_node(curr, v6, node, tree) )
  {
    policy_data_free(v6);
    return 0;
  }
  return 1;
}
