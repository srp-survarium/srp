asn1_type_st *__cdecl ASN1_generate_v3(char *str, v3_ext_ctx *cnf)
{
  unsigned __int8 *v2; // ebx
  asn1_type_st *result; // eax
  asn1_type_st *v4; // esi
  unsigned __int8 *v5; // edi
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
  int plength; // [esp+14h] [ebp-1C4h] BYREF
  unsigned __int8 *pp; // [esp+18h] [ebp-1C0h] BYREF
  unsigned int count; // [esp+1Ch] [ebp-1BCh]
  asn1_type_st *v21; // [esp+20h] [ebp-1B8h]
  unsigned __int8 *in; // [esp+24h] [ebp-1B4h] BYREF
  int pclass; // [esp+28h] [ebp-1B0h] BYREF
  int ptag; // [esp+2Ch] [ebp-1ACh] BYREF
  int arg; // [esp+30h] [ebp-1A8h] BYREF
  int xclass; // [esp+34h] [ebp-1A4h]
  int utype; // [esp+38h] [ebp-1A0h]
  int format; // [esp+3Ch] [ebp-19Ch]
  char *stra; // [esp+40h] [ebp-198h]
  char v30; // [esp+54h] [ebp-184h] BYREF
  int v31; // [esp+1D4h] [ebp-4h]

  v2 = 0;
  out = 0;
  v17 = 0;
  arg = -1;
  xclass = -1;
  format = 1;
  v31 = 0;
  if ( CONF_parse_list(str, 0x2Cu, 1, (int (__cdecl *)(const char *, int, void *))asn1_cb, &arg) )
    return 0;
  if ( utype == 16 || utype == 17 )
  {
    if ( !cnf )
    {
      ERR_put_error(0xDu, 178, 192, ".\\crypto\\asn1\\asn1_gen.c", 163);
      return 0;
    }
    result = asn1_multi(utype, stra, cnf);
  }
  else
  {
    result = asn1_str2type(format, utype);
  }
  v4 = result;
  if ( !result )
    return 0;
  if ( arg == -1 && !v31 )
    return result;
  v5 = (unsigned __int8 *)i2d_ASN1_TYPE(result, &out);
  count = (unsigned int)v5;
  ASN1_TYPE_free(v4);
  v21 = 0;
  pp = out;
  if ( arg == -1 )
    goto LABEL_19;
  object = ASN1_get_object((const unsigned __int8 **)&pp, &plength, &ptag, &pclass, v5);
  if ( object >= 0 )
  {
    count = (unsigned int)&v5[out - pp];
    if ( (object & 1) != 0 )
    {
      v17 = 2;
      plength = 0;
    }
    else
    {
      v17 = object & 0x20;
    }
    v5 = (unsigned __int8 *)ASN1_object_size(0, plength, arg);
LABEL_19:
    v7 = 0;
    for ( i = &arg + 5 * v31; v7 < v31; v5 = (unsigned __int8 *)ASN1_object_size(0, v13, v14) )
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
      if ( arg != -1 )
      {
        if ( !xclass && (arg == 16 || arg == 17) )
          v12 = 32;
        else
          v12 = v17;
        ASN1_put_object(&dst, v12, plength, arg, xclass);
      }
      memcpy(dst, pp, count);
      in = v2;
      v21 = d2i_ASN1_TYPE(0, (const unsigned __int8 **)&in, (int)v5);
    }
  }
  if ( out )
    CRYPTO_free(out);
  if ( v2 )
    CRYPTO_free(v2);
  return v21;
}
