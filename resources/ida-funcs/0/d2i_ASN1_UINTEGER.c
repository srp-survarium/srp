asn1_string_st *__cdecl d2i_ASN1_UINTEGER(asn1_string_st **a, asn1_string_st ***pp, int length)
{
  asn1_string_st **v3; // ebp
  asn1_string_st *v4; // esi
  asn1_string_st *result; // eax
  __int16 v6; // ax
  unsigned __int8 *v7; // edi
  unsigned int v8; // eax
  unsigned __int8 *v9; // ecx
  int plength; // [esp+8h] [ebp-Ch] BYREF
  int ptag; // [esp+Ch] [ebp-8h] BYREF
  int pclass; // [esp+10h] [ebp-4h] BYREF

  v3 = a;
  if ( !a || (v4 = *a) == 0 )
  {
    result = ASN1_STRING_type_new(2);
    v4 = result;
    if ( !result )
      return result;
    result->type = 2;
  }
  a = *pp;
  if ( (ASN1_get_object((const unsigned __int8 **)&a, &plength, &ptag, &pclass, length) & 0x80u) != 0 )
  {
    v6 = 102;
    goto err_10;
  }
  if ( ptag != 2 )
  {
    v6 = 115;
    goto err_10;
  }
  v7 = (unsigned __int8 *)CRYPTO_malloc(plength + 1, ".\\crypto\\asn1\\a_int.c", 305);
  if ( !v7 )
  {
    v6 = 65;
err_10:
    ERR_put_error(0xDu, 150, v6, ".\\crypto\\asn1\\a_int.c", 329);
    if ( v4 && (!v3 || *v3 != v4) )
      ASN1_STRING_free(v4);
    return 0;
  }
  v4->type = 2;
  v8 = plength;
  if ( plength )
  {
    v9 = (unsigned __int8 *)a;
    if ( !*(_BYTE *)a && plength != 1 )
    {
      v9 = (unsigned __int8 *)a + 1;
      v8 = plength - 1;
      a = (asn1_string_st **)((char *)a + 1);
      --plength;
    }
    memcpy(v7, v9, v8);
    a = (asn1_string_st **)((char *)a + plength);
  }
  if ( v4->data )
    CRYPTO_free(v4->data);
  v4->data = v7;
  v4->length = plength;
  if ( v3 )
    *v3 = v4;
  result = v4;
  *pp = a;
  return result;
}
