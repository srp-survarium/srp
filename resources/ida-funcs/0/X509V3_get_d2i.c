struct ASN1_VALUE_st *__cdecl X509V3_get_d2i(stack_st_X509_EXTENSION *x, void *nid, X509_extension_st **crit, int *idx)
{
  X509_extension_st *v4; // ebp
  int *v6; // edi
  int v7; // esi
  char *v8; // edi

  v4 = 0;
  if ( !x )
  {
    if ( idx )
      *idx = -1;
    if ( crit )
      *crit = (X509_extension_st *)-1;
    return 0;
  }
  v6 = idx;
  if ( !idx || (v7 = *idx + 1, v7 < 0) )
    v7 = 0;
  if ( v7 >= sk_num(&x->stack) )
  {
LABEL_24:
    if ( v6 )
      *v6 = -1;
    if ( crit )
      *crit = (X509_extension_st *)-1;
    return 0;
  }
  while ( 1 )
  {
    v8 = sk_value(&x->stack, v7);
    if ( OBJ_obj2nid(*(const asn1_object_st **)v8) == nid )
      break;
LABEL_15:
    if ( ++v7 >= sk_num(&x->stack) )
      goto LABEL_16;
  }
  if ( !idx )
  {
    if ( v4 )
    {
      if ( !crit )
        return 0;
      *crit = (X509_extension_st *)-2;
      return 0;
    }
    v4 = (X509_extension_st *)v8;
    goto LABEL_15;
  }
  *idx = v7;
  v4 = (X509_extension_st *)v8;
LABEL_16:
  if ( !v4 )
  {
    v6 = idx;
    goto LABEL_24;
  }
  if ( crit )
    *crit = X509_EXTENSION_get_critical(v4);
  return X509V3_EXT_d2i((int)v8, v4);
}
