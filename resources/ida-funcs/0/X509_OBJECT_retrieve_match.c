x509_object_st *__cdecl X509_OBJECT_retrieve_match(stack_st_X509_OBJECT *h, x509_object_st *x)
{
  int v2; // esi
  int i; // ebx
  char *v5; // esi
  unsigned int v6; // eax
  int v7; // eax

  v2 = sk_find(&h->stack, (char *)x);
  if ( v2 == -1 )
    return 0;
  if ( x->type != 1 && x->type != 2 )
    return (x509_object_st *)sk_value(&h->stack, v2);
  for ( i = v2; i < sk_num(&h->stack); ++i )
  {
    v5 = sk_value(&h->stack, i);
    if ( *(_DWORD *)v5 != x->type )
      return 0;
    if ( *(_DWORD *)v5 == 1 )
    {
      v6 = X509_subject_name_cmp(*((const x509_st **)v5 + 1), x->data.x509);
    }
    else
    {
      if ( *(_DWORD *)v5 != 2 )
        goto LABEL_13;
      v6 = X509_CRL_cmp(*((const X509_crl_st **)v5 + 1), x->data.crl);
    }
    if ( v6 )
      return 0;
LABEL_13:
    if ( x->type == 1 )
    {
      v7 = X509_cmp((unsigned int)x, *((x509_st **)v5 + 1), x->data.x509);
    }
    else
    {
      if ( x->type != 2 )
        return (x509_object_st *)v5;
      v7 = X509_CRL_match(*((const X509_crl_st **)v5 + 1), x->data.crl);
    }
    if ( !v7 )
      return (x509_object_st *)v5;
  }
  return 0;
}
