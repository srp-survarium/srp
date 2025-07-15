asn1_string_st *__usercall d2i_ASN1_UINTEGER@<eax>(
        int a1@<ebx>,
        asn1_string_st **a,
        asn1_string_st ***pp,
        const unsigned __int8 *length)
{
  asn1_string_st **v4; // ebp
  asn1_string_st *v5; // esi
  asn1_string_st *result; // eax
  __int16 v7; // ax
  unsigned __int8 *v8; // edi
  unsigned int v9; // eax
  const __m128i *v10; // ecx
  int plength; // [esp+8h] [ebp-Ch] BYREF
  int ptag; // [esp+Ch] [ebp-8h] BYREF
  int pclass; // [esp+10h] [ebp-4h] BYREF

  v4 = a;
  if ( !a || (v5 = *a) == 0 )
  {
    result = ASN1_STRING_type_new(2);
    v5 = result;
    if ( !result )
      return result;
    result->type = 2;
  }
  a = *pp;
  if ( (ASN1_get_object((const unsigned __int8 **)&a, (unsigned int *)&plength, &ptag, &pclass, length) & 0x80u) != 0 )
  {
    v7 = 102;
    goto err_12;
  }
  if ( ptag != 2 )
  {
    v7 = 115;
    goto err_12;
  }
  v8 = (unsigned __int8 *)CRYPTO_malloc(plength + 1, ".\\crypto\\asn1\\a_int.c", 305);
  if ( !v8 )
  {
    v7 = 65;
err_12:
    ERR_put_error(a1, 0xDu, 150, v7, ".\\crypto\\asn1\\a_int.c", 329);
    if ( v5 && (!v4 || *v4 != v5) )
      ASN1_STRING_free(v5);
    return 0;
  }
  v5->type = 2;
  v9 = plength;
  if ( plength )
  {
    v10 = (const __m128i *)a;
    if ( !*(_BYTE *)a && plength != 1 )
    {
      v10 = (const __m128i *)((char *)a + 1);
      v9 = plength - 1;
      a = (asn1_string_st **)((char *)a + 1);
      --plength;
    }
    memcpy((int)v8, v10, v9);
    a = (asn1_string_st **)((char *)a + plength);
  }
  if ( v5->data )
    CRYPTO_free(v5->data);
  v5->data = v8;
  v5->length = plength;
  if ( v4 )
    *v4 = v5;
  result = v5;
  *pp = a;
  return result;
}
