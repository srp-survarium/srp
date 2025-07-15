int __usercall asn1_item_flags_i2d@<eax>(
        int flags@<ebx>,
        struct ASN1_VALUE_st *val,
        unsigned __int8 **out,
        const ASN1_ITEM_st *it)
{
  const ASN1_ITEM_st *v4; // ebp
  int result; // eax
  int v6; // esi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // [esp+4h] [ebp-4h] BYREF

  v4 = it;
  if ( !out || *out )
    return (int)ASN1_item_ex_i2d(&val, out, it, -1, flags);
  result = (int)ASN1_item_ex_i2d(&val, 0, it, -1, flags);
  v6 = result;
  if ( result > 0 )
  {
    v7 = (unsigned __int8 *)CRYPTO_malloc(result, ".\\crypto\\asn1\\tasn_enc.c", 113);
    v8 = v7;
    if ( v7 )
    {
      v9 = v7;
      ASN1_item_ex_i2d(&val, &v9, v4, -1, flags);
      *out = v8;
      return v6;
    }
    else
    {
      return -1;
    }
  }
  return result;
}
