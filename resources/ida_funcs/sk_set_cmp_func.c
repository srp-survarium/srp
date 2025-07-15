int (__cdecl *__cdecl sk_set_cmp_func(
        stack_st *sk,
        int (__cdecl *c)(const void *, const void *)))(const void *, const void *)
{
  int (__cdecl *result)(const void *, const void *); // eax

  result = sk->comp;
  sk->comp = c;
  if ( result != c )
    sk->sorted = 0;
  return result;
}
