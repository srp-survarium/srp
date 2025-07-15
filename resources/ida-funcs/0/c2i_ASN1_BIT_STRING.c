asn1_string_st *__usercall c2i_ASN1_BIT_STRING@<eax>(int a1@<ebx>, asn1_string_st **a, const __m128i **pp, int len)
{
  asn1_string_st *v5; // esi
  __int16 v6; // ax
  int v7; // edx
  const __m128i *v8; // ebp
  unsigned int v9; // edi
  void *v10; // eax
  asn1_string_st *result; // eax
  unsigned __int8 *data; // eax
  char v13; // [esp+1Ch] [ebp+Ch]

  v5 = 0;
  if ( len < 1 )
  {
    v6 = 152;
err_87:
    ERR_put_error(a1, 0xDu, 189, v6, ".\\crypto\\asn1\\a_bitstr.c", 168);
    if ( v5 && (!a || *a != v5) )
      ASN1_STRING_free(v5);
    return 0;
  }
  if ( !a || (v5 = *a) == 0 )
  {
    v5 = ASN1_STRING_type_new(a1, 3);
    if ( !v5 )
      return 0;
  }
  v13 = (*pp)->m128i_i8[0];
  v7 = len;
  v8 = (const __m128i *)&(*pp)->m128i_i8[1];
  v9 = len - 1;
  v5->flags = v5->flags & 0xFFFFFFF8 | v13 & 7 | 8;
  if ( v7 <= 1 )
  {
    a1 = 0;
  }
  else
  {
    v10 = CRYPTO_malloc(v9, ".\\crypto\\asn1\\a_bitstr.c", 147);
    a1 = (int)v10;
    if ( !v10 )
    {
      v6 = 65;
      goto err_87;
    }
    memcpy((int)v10, v8, v9);
    *(_BYTE *)(a1 + v9 - 1) &= -1 << v13;
    v8 = (const __m128i *)((char *)v8 + v9);
  }
  data = v5->data;
  v5->length = v9;
  if ( data )
    CRYPTO_free(data);
  v5->data = (unsigned __int8 *)a1;
  v5->type = 3;
  if ( a )
    *a = v5;
  result = v5;
  *pp = v8;
  return result;
}
