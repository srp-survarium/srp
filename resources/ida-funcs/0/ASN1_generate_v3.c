asn1_type_st *__cdecl ASN1_generate_v3(char *str, v3_ext_ctx *cnf)
{
  unsigned __int8 *v2; // ebx
  asn1_type_st *result; // eax
  asn1_type_st *v4; // esi
  const unsigned __int8 *v5; // edi
  char object; // al
  int v7; // ebp
  int *i; // esi
  unsigned __int8 *v9; // eax
  int v10; // ebp
  int *v11; // esi
  int v12; // edx
  int v13; // [esp-10h] [ebp-1E8h]
  int v14; // [esp-Ch] [ebp-1E4h]
  unsigned __int8 *dst; // [esp+8h] [ebp-1D0h] BYREF
  unsigned __int8 *out; // [esp+Ch] [ebp-1CCh] BYREF
  int v17; // [esp+10h] [ebp-1C8h]
  int length; // [esp+14h] [ebp-1C4h] BYREF
  unsigned __int8 *src; // [esp+18h] [ebp-1C0h] BYREF
  unsigned int count; // [esp+1Ch] [ebp-1BCh]
  asn1_type_st *v21; // [esp+20h] [ebp-1B8h]
  unsigned __int8 *v22; // [esp+24h] [ebp-1B4h] BYREF
  int v23; // [esp+28h] [ebp-1B0h] BYREF
  int v24; // [esp+2Ch] [ebp-1ACh] BYREF
  int tag; // [esp+30h] [ebp-1A8h] BYREF
  int v26; // [esp+34h] [ebp-1A4h]
  int utype; // [esp+38h] [ebp-1A0h]
  int v28; // [esp+3Ch] [ebp-19Ch]
  char *section; // [esp+40h] [ebp-198h]
  char v30; // [esp+54h] [ebp-184h] BYREF
  int v31; // [esp+1D4h] [ebp-4h]

  v2 = 0;
  out = 0;
  v17 = 0;
  tag = -1;
  v26 = -1;
  v28 = 1;
  v31 = 0;
  if ( CONF_parse_list(0, str, 0x2Cu, 1, (int (__cdecl *)(const char *, int, void *))asn1_cb, &tag) )
    return 0;
  if ( utype == 16 || utype == 17 )
  {
    if ( !cnf )
    {
      ERR_put_error(0, 0xDu, 178, 192, ".\\crypto\\asn1\\asn1_gen.c", 163);
      return 0;
    }
    result = asn1_multi(utype, section, cnf);
  }
  else
  {
    result = asn1_str2type((__m128i *)section, 0, v28, utype);
  }
  v4 = result;
  if ( !result )
    return 0;
  if ( tag == -1 && !v31 )
    return result;
  v5 = (const unsigned __int8 *)i2d_ASN1_TYPE(result, &out);
  count = (unsigned int)v5;
  ASN1_TYPE_free(v4);
  v21 = 0;
  src = out;
  if ( tag == -1 )
    goto LABEL_19;
  object = ASN1_get_object(0, (const unsigned __int8 **)&src, (unsigned int *)&length, &v24, &v23, v5);
  if ( object >= 0 )
  {
    count = (unsigned int)&v5[out - src];
    if ( (object & 1) != 0 )
    {
      v17 = 2;
      length = 0;
    }
    else
    {
      v17 = object & 0x20;
    }
    v5 = (const unsigned __int8 *)ASN1_object_size(0, length, tag);
LABEL_19:
    v7 = 0;
    for ( i = &tag + 5 * v31; v7 < v31; v5 = (const unsigned __int8 *)ASN1_object_size(0, v13, v14) )
    {
      v14 = *i;
      v13 = (int)&v5[i[3]];
      i[4] = v13;
      ++v7;
      i -= 5;
    }
    v9 = (unsigned __int8 *)CRYPTO_malloc((int)v5, ".\\crypto\\asn1\\asn1_gen.c", 229);
    v2 = v9;
    if ( v9 )
    {
      v10 = 0;
      dst = v9;
      if ( v31 > 0 )
      {
        v11 = (int *)&v30;
        do
        {
          ASN1_put_object(&dst, *(v11 - 2), *v11, *(v11 - 4), *(v11 - 3));
          if ( *(v11 - 1) )
            *dst++ = 0;
          ++v10;
          v11 += 5;
        }
        while ( v10 < v31 );
      }
      if ( tag != -1 )
      {
        if ( !v26 && (tag == 16 || tag == 17) )
          v12 = 32;
        else
          v12 = v17;
        ASN1_put_object(&dst, v12, length, tag, v26);
      }
      memcpy((int)dst, (const __m128i *)src, count);
      v22 = v2;
      v21 = d2i_ASN1_TYPE(0, &v22, v5);
    }
  }
  if ( out )
    CRYPTO_free(out);
  if ( v2 )
    CRYPTO_free(v2);
  return v21;
}
