unsigned int __usercall asn1_i2d_ex_primitive@<eax>(
        const ASN1_ITEM_st *it@<ebx>,
        struct ASN1_VALUE_st **pval,
        unsigned __int8 **out,
        int tag,
        char aclass)
{
  int v5; // edi
  unsigned int v6; // esi
  const ASN1_ITEM_st *v8; // [esp+0h] [ebp-18h]
  int putype; // [esp+10h] [ebp-8h] BYREF
  int v10; // [esp+14h] [ebp-4h]

  v5 = 0;
  putype = it->utype;
  v6 = asn1_ex_i2c(pval, 0, &putype, v8);
  if ( putype == 16 || putype == 17 || (v10 = 1, putype == -3) )
    v10 = 0;
  if ( v6 == -1 )
    return 0;
  if ( v6 == -2 )
  {
    v5 = 2;
    v6 = 0;
  }
  if ( tag == -1 )
    tag = putype;
  if ( out )
  {
    if ( v10 )
      ASN1_put_object(out, v5, v6, tag, aclass);
    asn1_ex_i2c(pval, *out, &putype, it);
    if ( v5 )
      ASN1_put_eoc(out);
    else
      *out += v6;
  }
  if ( v10 )
    return ASN1_object_size(v5, v6, tag);
  else
    return v6;
}
