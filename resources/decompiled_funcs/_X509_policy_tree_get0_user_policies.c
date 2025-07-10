stack_st_X509_POLICY_NODE *__cdecl X509_policy_tree_get0_user_policies(stack_st_X509_POLICY_NODE *tree)
{
  stack_st_X509_POLICY_NODE *result; // eax

  result = tree;
  if ( tree )
  {
    if ( (tree[1].stack.num & 2) != 0 )
      return (stack_st_X509_POLICY_NODE *)tree->stack.num_alloc;
    else
      return (stack_st_X509_POLICY_NODE *)tree->stack.comp;
  }
  return result;
}
