unsigned __int8 *__cdecl ASN1_item_dup(const ASN1_ITEM_st *it, unsigned __int8 *x)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v3; // eax
  struct ASN1_VALUE_st *v4; // esi
  unsigned __int8 *out; // [esp+0h] [ebp-4h] BYREF

  result = x;
  out = 0;
  if ( x )
  {
    v3 = (unsigned __int8 *)ASN1_item_i2d((struct ASN1_VALUE_st *)x, &out, it);
    if ( out )
    {
      x = out;
      v4 = ASN1_item_d2i(0, &x, v3, it);
      CRYPTO_free(out);
      return (unsigned __int8 *)v4;
    }
    else
    {
      ERR_put_error(0xDu, 191, 65, ".\\crypto\\asn1\\a_dup.c", 104);
      return 0;
    }
  }
  return result;
}
