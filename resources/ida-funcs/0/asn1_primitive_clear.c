void __usercall asn1_primitive_clear(struct ASN1_VALUE_st **pval@<edx>, const ASN1_ITEM_st *it)
{
  _DWORD *funcs; // ecx
  void (__cdecl *v3)(struct ASN1_VALUE_st **, const ASN1_ITEM_st *); // ecx

  if ( it )
  {
    funcs = it->funcs;
    if ( funcs )
    {
      v3 = (void (__cdecl *)(struct ASN1_VALUE_st **, const ASN1_ITEM_st *))funcs[4];
      if ( v3 )
      {
        v3(pval, it);
        return;
      }
    }
    else if ( it->itype != 5 && it->utype == 1 )
    {
      *pval = (struct ASN1_VALUE_st *)it->size;
      return;
    }
  }
  *pval = 0;
}
