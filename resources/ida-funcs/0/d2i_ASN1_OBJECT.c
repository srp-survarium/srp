asn1_object_st *__usercall d2i_ASN1_OBJECT@<eax>(
        int a1@<ebx>,
        asn1_object_st **a,
        const unsigned __int8 **pp,
        const unsigned __int8 *length)
{
  const unsigned __int8 **v4; // esi
  __int16 v5; // ax
  asn1_object_st *result; // eax
  int ptag; // [esp+4h] [ebp-Ch] BYREF
  int plength; // [esp+8h] [ebp-8h] BYREF
  int pclass; // [esp+Ch] [ebp-4h] BYREF

  v4 = pp;
  pp = (const unsigned __int8 **)*pp;
  if ( (ASN1_get_object((const unsigned __int8 **)&pp, (unsigned int *)&plength, &ptag, &pclass, length) & 0x80u) != 0 )
  {
    v5 = 102;
err_21:
    ERR_put_error(a1, 0xDu, 147, v5, ".\\crypto\\asn1\\a_object.c", 283);
    return 0;
  }
  if ( ptag != 6 )
  {
    v5 = 116;
    goto err_21;
  }
  result = c2i_ASN1_OBJECT(a, (const __m128i **)&pp, plength);
  if ( result )
    *v4 = (const unsigned __int8 *)pp;
  return result;
}
