int __cdecl a2d_ASN1_OBJECT(unsigned __int8 *out, int olen, const char *buf, unsigned int num)
{
  unsigned int v4; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // edx
  unsigned int v10; // ebx
  int v11; // edi
  int v12; // eax
  int v13; // esi
  int v14; // eax
  int v15; // ecx
  int v16; // esi
  int v17; // edi
  unsigned __int8 *v18; // ecx
  int i; // esi
  int v20; // eax
  bignum_st *a; // [esp+8h] [ebp-1Ch]
  int v22; // [esp+Ch] [ebp-18h]
  int v23; // [esp+10h] [ebp-14h]
  const char *v24; // [esp+14h] [ebp-10h]
  int v25; // [esp+18h] [ebp-Ch]
  int v26; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *v27; // [esp+20h] [ebp-4h]
  _BYTE str[24]; // [esp+24h] [ebp+0h] BYREF
  int v29; // [esp+50h] [ebp+2Ch]

  v4 = num;
  v27 = out;
  v22 = 0;
  v25 = 24;
  a = 0;
  if ( !num )
    return 0;
  if ( num == -1 )
    v4 = strlen(buf);
  v6 = *buf - 48;
  v7 = v4 - 1;
  v26 = v6;
  if ( (unsigned int)v6 > 2 )
  {
    ERR_put_error(0xDu, 100, 122, ".\\crypto\\asn1\\a_object.c", 109);
    return 0;
  }
  if ( v7 <= 0 )
  {
    ERR_put_error(0xDu, 100, 138, ".\\crypto\\asn1\\a_object.c", 115);
    return 0;
  }
  v8 = buf[1];
  v9 = v7 - 1;
  v24 = buf + 2;
  if ( v9 <= 0 )
    return v22;
  while ( 2 )
  {
    if ( v8 != 46 && v8 != 32 )
    {
      ERR_put_error(0xDu, 100, 131, ".\\crypto\\asn1\\a_object.c", 125);
LABEL_54:
      if ( a )
        BN_free(a);
      return 0;
    }
    v10 = 0;
    v11 = 0;
    do
    {
      v12 = *v24;
      v29 = --v9;
      v23 = v12;
      ++v24;
      if ( v12 == 32 || v12 == 46 )
        break;
      v13 = v12;
      if ( v12 < 48 || v12 > 57 )
      {
        ERR_put_error(0xDu, 100, 130, ".\\crypto\\asn1\\a_object.c", 139);
        goto LABEL_54;
      }
      if ( v11 )
        goto LABEL_23;
      if ( v10 >= 0x19999991 )
      {
        v11 = 1;
        if ( !a )
        {
          a = BN_new();
          if ( !a )
            goto LABEL_54;
        }
        if ( !BN_set_word(a, v10) )
          goto LABEL_54;
LABEL_23:
        if ( !BN_mul_word(a, 0xAu) || !BN_add_word(a, v13 - 48) )
          goto LABEL_54;
        v9 = v29;
        v6 = v26;
        continue;
      }
      v10 = v12 + 10 * v10 - 48;
    }
    while ( v9 > 0 );
    v14 = v22;
    if ( v22 )
      goto LABEL_35;
    if ( v6 < 2 && v10 >= 0x28 )
    {
      ERR_put_error(0xDu, 100, 147, ".\\crypto\\asn1\\a_object.c", 163);
      goto LABEL_54;
    }
    v15 = 5 * v6;
    if ( v11 )
    {
      if ( !BN_add_word(a, 8 * v15) )
        goto LABEL_54;
      v14 = 0;
      v9 = v29;
    }
    else
    {
      v10 += 8 * v15;
    }
LABEL_35:
    v16 = 0;
    if ( !v11 )
    {
      do
      {
        str[v16] = v10 & 0x7F;
        v10 >>= 7;
        ++v16;
      }
      while ( v10 );
      goto LABEL_41;
    }
    v17 = (BN_num_bits(a) + 6) / 7;
    if ( v17 > v25 )
    {
      v25 = v17 + 32;
      if ( !CRYPTO_malloc(v17 + 32, ".\\crypto\\asn1\\a_object.c", 185) )
        goto LABEL_54;
    }
    for ( ; v17; ++v16 )
    {
      --v17;
      str[v16] = BN_div_word(a, 0x80u);
    }
    v9 = v29;
    v14 = v22;
LABEL_41:
    v18 = v27;
    if ( !v27 )
    {
      v20 = v16 + v14;
      goto LABEL_49;
    }
    if ( v16 + v14 > olen )
    {
      ERR_put_error(0xDu, 100, 107, ".\\crypto\\asn1\\a_object.c", 207);
      goto LABEL_54;
    }
    for ( i = v16 - 1; i > 0; ++v14 )
      v18[v14] = str[i--] | 0x80;
    v18[v14] = str[0];
    v20 = v14 + 1;
LABEL_49:
    v22 = v20;
    if ( v9 > 0 )
    {
      v8 = v23;
      v6 = v26;
      continue;
    }
    break;
  }
  if ( a )
    BN_free(a);
  return v22;
}
