asn1_string_st *__cdecl c2i_ASN1_BIT_STRING(asn1_string_st **a, unsigned __int8 **pp, int len)
{
  asn1_string_st *v4; // esi
  __int16 v5; // ax
  int v6; // edx
  unsigned __int8 *v7; // ebp
  unsigned int v8; // edi
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // ebx
  asn1_string_st *result; // eax
  unsigned __int8 *data; // eax
  unsigned __int8 i; // [esp+1Ch] [ebp+Ch]

  v4 = 0;
  if ( len < 1 )
  {
    v5 = 152;
err_85:
    ERR_put_error(0xDu, 189, v5, ".\\crypto\\asn1\\a_bitstr.c", 168);
    if ( v4 && (!a || *a != v4) )
      ASN1_STRING_free(v4);
    return 0;
  }
  if ( !a || (v4 = *a) == 0 )
  {
    v4 = ASN1_STRING_type_new(3);
    if ( !v4 )
      return 0;
  }
  i = **pp;
  v6 = len;
  v7 = *pp + 1;
  v8 = len - 1;
  v4->flags = v4->flags & 0xFFFFFFF8 | i & 7 | 8;
  if ( v6 <= 1 )
  {
    v10 = 0;
  }
  else
  {
    v9 = (unsigned __int8 *)CRYPTO_malloc(v8, ".\\crypto\\asn1\\a_bitstr.c", 147);
    v10 = v9;
    if ( !v9 )
    {
      v5 = 65;
      goto err_85;
    }
    memcpy(v9, v7, v8);
    v10[v8 - 1] &= -1 << i;
    v7 += v8;
  }
  data = v4->data;
  v4->length = v8;
  if ( data )
    CRYPTO_free(data);
  v4->data = v10;
  v4->type = 3;
  if ( a )
    *a = v4;
  result = v4;
  *pp = v7;
  return result;
}
