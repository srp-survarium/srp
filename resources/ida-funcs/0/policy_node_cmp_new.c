stack_st_X509_POLICY_NODE *__cdecl policy_node_cmp_new()
{
  return (stack_st_X509_POLICY_NODE *)sk_new((int (__cdecl *)(const void *, const void *))node_cmp);
}
