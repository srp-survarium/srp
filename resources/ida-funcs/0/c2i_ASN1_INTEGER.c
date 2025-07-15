asn1_string_st *__cdecl c2i_ASN1_INTEGER(asn1_string_st **a, const __m128i **pp, unsigned int len)
{
  asn1_string_st **v3; // esi
  asn1_string_st *v4; // ebp
  asn1_string_st *result; // eax
  const __m128i *v6; // ebx
  unsigned int v7; // edi
  unsigned __int8 *v8; // eax
  char *v9; // eax
  unsigned int v10; // esi
  unsigned __int8 *v11; // ecx
  int v12; // esi
  unsigned __int8 *v13; // ecx
  char *i; // eax
  unsigned __int8 *v15; // [esp+8h] [ebp-8h]
  unsigned __int8 *v16; // [esp+Ch] [ebp-4h]

  v3 = a;
  if ( !a || (v4 = *a) == 0 )
  {
    result = ASN1_STRING_type_new(2);
    v4 = result;
    if ( !result )
      return result;
    result->type = 2;
  }
  v6 = *pp;
  v7 = len;
  v16 = &(*pp)->m128i_u8[len];
  v8 = (unsigned __int8 *)CRYPTO_malloc(len + 1, ".\\crypto\\asn1\\a_int.c", 199);
  v15 = v8;
  if ( !v8 )
  {
    ERR_put_error((int)v6, 0xDu, 194, 65, ".\\crypto\\asn1\\a_int.c", 259);
    if ( v4 && (!a || *a != v4) )
      ASN1_STRING_free(v4);
    return 0;
  }
  if ( len )
  {
    if ( v6->m128i_i8[0] >= 0 )
    {
      v4->type = 2;
      if ( !v6->m128i_i8[0] && len != 1 )
      {
        v6 = (const __m128i *)((char *)v6 + 1);
        v7 = len - 1;
      }
      memcpy((int)v8, v6, v7);
      goto LABEL_23;
    }
    v4->type = 258;
    if ( v6->m128i_i8[0] == -1 && len != 1 )
    {
      v6 = (const __m128i *)((char *)v6 + 1);
      v7 = len - 1;
    }
    v9 = &v6->m128i_i8[v7 - 1];
    v10 = v7;
    v11 = &v15[v7 - 1];
    if ( *v9 )
    {
LABEL_20:
      if ( v10 )
      {
        *v11 = -*v9;
        v12 = v10 - 1;
        v13 = v11 - 1;
        for ( i = v9 - 1; v12 > 0; --i )
        {
          *v13 = ~*i;
          --v12;
          --v13;
        }
        goto LABEL_22;
      }
    }
    else
    {
      while ( v10 )
      {
        *v11 = 0;
        --v9;
        --v11;
        --v10;
        if ( *v9 )
          goto LABEL_20;
      }
    }
    *v15 = 1;
    v15[v7++] = 0;
LABEL_22:
    v3 = a;
    goto LABEL_23;
  }
  v4->type = 2;
LABEL_23:
  if ( v4->data )
    CRYPTO_free(v4->data);
  v4->data = v15;
  v4->length = v7;
  if ( v3 )
    *v3 = v4;
  result = v4;
  *pp = (const __m128i *)v16;
  return result;
}
