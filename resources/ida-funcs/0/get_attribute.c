asn1_type_st *__usercall get_attribute@<eax>(stack_st_X509_ATTRIBUTE *sk@<ebx>, unsigned int nid)
{
  asn1_object_st *v2; // ebp
  int v3; // esi
  char *v4; // edi

  v2 = OBJ_nid2obj((int)sk, nid);
  if ( !v2 || !sk )
    return 0;
  v3 = 0;
  if ( sk_num(&sk->stack) <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = sk_value(&sk->stack, v3);
    if ( !OBJ_cmp(*(const asn1_object_st **)v4, v2) )
      break;
    if ( ++v3 >= sk_num(&sk->stack) )
      return 0;
  }
  if ( *((_DWORD *)v4 + 1) || !sk_num(*((const stack_st **)v4 + 2)) )
    return 0;
  else
    return (asn1_type_st *)sk_value(*((const stack_st **)v4 + 2), 0);
}
