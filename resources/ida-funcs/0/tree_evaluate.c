int __usercall tree_evaluate@<eax>(X509_POLICY_TREE_st *tree@<esi>)
{
  int v1; // ebp
  X509_POLICY_LEVEL_st *v2; // ebx
  const X509_POLICY_CACHE_st *v3; // edi
  int result; // eax

  v1 = 1;
  v2 = tree->levels + 1;
  if ( tree->nlevel <= 1 )
    return 1;
  while ( 1 )
  {
    v3 = policy_cache_set(v2->cert);
    if ( !tree_link_nodes(v2, v3) || (v2->flags & 0x200) == 0 && !tree_link_any(v2, v3, tree) )
      break;
    result = tree_prune(tree);
    if ( result != 1 )
      return result;
    ++v1;
    ++v2;
    if ( v1 >= tree->nlevel )
      return 1;
  }
  return 0;
}
