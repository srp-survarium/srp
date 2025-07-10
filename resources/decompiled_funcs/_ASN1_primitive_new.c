int __cdecl ASN1_primitive_new(struct ASN1_VALUE_st **pval, const ASN1_ITEM_st *it)
{
  _DWORD *funcs; // eax
  int (__cdecl *v3)(struct ASN1_VALUE_st **, const ASN1_ITEM_st *); // eax
  int result; // eax
  int utype; // eax
  asn1_string_st *v6; // eax

  if ( !it )
    goto LABEL_7;
  funcs = it->funcs;
  if ( funcs )
  {
    v3 = (int (__cdecl *)(struct ASN1_VALUE_st **, const ASN1_ITEM_st *))funcs[2];
    if ( v3 )
      return v3(pval, it);
  }
  if ( it->itype == 5 )
LABEL_7:
    utype = -1;
  else
    utype = it->utype;
  switch ( utype )
  {
    case -4:
      result = (int)CRYPTO_malloc(8, ".\\crypto\\asn1\\tasn_new.c", 357);
      if ( result )
      {
        *(_DWORD *)(result + 4) = 0;
        *(_DWORD *)result = -1;
        *pval = (struct ASN1_VALUE_st *)result;
        result = *pval != 0;
      }
      break;
    case 1:
      *pval = (struct ASN1_VALUE_st *)it->size;
      result = 1;
      break;
    case 5:
      *pval = (struct ASN1_VALUE_st *)1;
      result = 1;
      break;
    case 6:
      *pval = (struct ASN1_VALUE_st *)OBJ_nid2obj(0);
      result = 1;
      break;
    default:
      v6 = ASN1_STRING_type_new(utype);
      if ( it->itype == 5 && v6 )
        v6->flags |= 0x40u;
      *pval = (struct ASN1_VALUE_st *)v6;
      result = *pval != 0;
      break;
  }
  return result;
}
