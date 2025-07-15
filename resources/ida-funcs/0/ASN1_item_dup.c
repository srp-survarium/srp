struct ASN1_VALUE_st *__usercall ASN1_item_dup@<eax>(int a1@<ebx>, const ASN1_ITEM_st *it, struct ASN1_VALUE_st *x)
{
  struct ASN1_VALUE_st *result; // eax
  const unsigned __int8 **v4; // eax
  struct ASN1_VALUE_st *v5; // esi
  unsigned __int8 *out; // [esp+0h] [ebp-4h] BYREF

  result = x;
  out = 0;
  if ( x )
  {
    v4 = (const unsigned __int8 **)ASN1_item_i2d(x, &out, it);
    if ( out )
    {
      x = (struct ASN1_VALUE_st *)out;
      v5 = ASN1_item_d2i(0, (unsigned __int8 **)&x, v4, it);
      CRYPTO_free(out);
      return v5;
    }
    else
    {
      ERR_put_error(a1, 0xDu, 191, 65, ".\\crypto\\asn1\\a_dup.c", 104);
      return 0;
    }
  }
  return result;
}
