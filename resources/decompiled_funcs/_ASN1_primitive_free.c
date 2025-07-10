void __cdecl ASN1_primitive_free(struct ASN1_VALUE_st **pval, const ASN1_ITEM_st *it)
{
  const void *funcs; // eax
  void (*v3)(void); // eax
  int utype; // eax
  struct ASN1_VALUE_st **v5; // esi

  if ( !it )
  {
    utype = *(_DWORD *)*pval;
    v5 = (struct ASN1_VALUE_st **)((char *)*pval + 4);
    goto LABEL_9;
  }
  funcs = it->funcs;
  if ( funcs )
  {
    v3 = (void (*)(void))*((_DWORD *)funcs + 3);
    if ( v3 )
    {
      v3();
      return;
    }
  }
  v5 = pval;
  if ( it->itype == 5 )
  {
    utype = -1;
    goto LABEL_9;
  }
  utype = it->utype;
  if ( utype != 1 )
  {
LABEL_9:
    if ( !*v5 )
      return;
  }
  switch ( utype )
  {
    case -4:
      ASN1_primitive_free(v5, 0);
      CRYPTO_free(*v5);
      *v5 = 0;
      break;
    case 1:
      if ( it )
        *v5 = (struct ASN1_VALUE_st *)it->size;
      else
        *v5 = (struct ASN1_VALUE_st *)-1;
      break;
    case 5:
      goto $LN8_43;
    case 6:
      ASN1_OBJECT_free((asn1_object_st *)*v5);
      *v5 = 0;
      break;
    default:
      ASN1_STRING_free((asn1_string_st *)*v5);
      *v5 = 0;
$LN8_43:
      *v5 = 0;
      break;
  }
}
