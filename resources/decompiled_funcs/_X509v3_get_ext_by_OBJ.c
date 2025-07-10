int __cdecl X509v3_get_ext_by_OBJ(const stack_st_X509_ATTRIBUTE *sk, asn1_object_st *obj, int lastpos)
{
  int v4; // esi
  int v5; // edi
  char *v6; // eax

  if ( !sk )
    return -1;
  v4 = lastpos + 1;
  if ( lastpos + 1 < 0 )
    v4 = 0;
  v5 = sk_num(&sk->stack);
  if ( v4 >= v5 )
    return -1;
  while ( 1 )
  {
    v6 = sk_value(&sk->stack, v4);
    if ( !OBJ_cmp(*(const asn1_object_st **)v6, obj) )
      break;
    if ( ++v4 >= v5 )
      return -1;
  }
  return v4;
}
