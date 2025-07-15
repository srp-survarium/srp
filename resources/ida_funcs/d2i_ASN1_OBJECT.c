asn1_object_st *__cdecl d2i_ASN1_OBJECT(asn1_object_st **a, const unsigned __int8 **pp, int length)
{
  const unsigned __int8 **v3; // esi
  __int16 v4; // ax
  asn1_object_st *result; // eax
  int ptag; // [esp+4h] [ebp-Ch] BYREF
  int plength; // [esp+8h] [ebp-8h] BYREF
  int pclass; // [esp+Ch] [ebp-4h] BYREF

  v3 = pp;
  pp = (const unsigned __int8 **)*pp;
  if ( (ASN1_get_object((const unsigned __int8 **)&pp, &plength, &ptag, &pclass, length) & 0x80u) != 0 )
  {
    v4 = 102;
err_19:
    ERR_put_error(0xDu, 147, v4, ".\\crypto\\asn1\\a_object.c", 283);
    return 0;
  }
  if ( ptag != 6 )
  {
    v4 = 116;
    goto err_19;
  }
  result = c2i_ASN1_OBJECT(a, (unsigned __int8 **)&pp, plength);
  if ( result )
    *v3 = (const unsigned __int8 *)pp;
  return result;
}
