ssl_comp_st *__cdecl ssl3_comp_find(stack_st_SSL_COMP *sk, int n)
{
  int v2; // ebx
  int v3; // esi
  ssl_comp_st *result; // eax

  if ( !n || !sk )
    return 0;
  v2 = sk_num(&sk->stack);
  v3 = 0;
  if ( v2 <= 0 )
    return 0;
  while ( 1 )
  {
    result = (ssl_comp_st *)sk_value(&sk->stack, v3);
    if ( result->id == n )
      break;
    if ( ++v3 >= v2 )
      return 0;
  }
  return result;
}
