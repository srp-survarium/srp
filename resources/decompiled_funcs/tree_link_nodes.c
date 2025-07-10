int __usercall tree_link_nodes@<eax>(X509_POLICY_LEVEL_st *curr@<ebx>, const X509_POLICY_CACHE_st *cache@<edi>)
{
  int v2; // esi
  char *v3; // eax

  v2 = 0;
  if ( sk_num(&cache->data->stack) <= 0 )
    return 1;
  while ( 1 )
  {
    v3 = sk_value(&cache->data->stack, v2);
    if ( !tree_link_matching_nodes(curr, (const X509_POLICY_DATA_st *)v3) )
      break;
    if ( ++v2 >= sk_num(&cache->data->stack) )
      return 1;
  }
  return 0;
}
