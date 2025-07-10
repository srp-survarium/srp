int __cdecl BN_nist_mod_192(bignum_st *r, const bignum_st *a, const bignum_st *field, bignum_ctx *ctx)
{
  unsigned int *d; // edi
  int v6; // eax
  bignum_st *v8; // eax
  unsigned int *v9; // esi
  unsigned int *v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // eax
  unsigned int v18; // ecx
  _DWORD *v19; // edx
  int v20; // eax
  unsigned int v21; // ecx
  unsigned int *v22; // ecx
  int v23; // eax
  _DWORD *v24; // ecx
  unsigned int v26; // [esp+Ch] [ebp-48h] BYREF
  int v27; // [esp+10h] [ebp-44h]
  unsigned int v28; // [esp+14h] [ebp-40h]
  int v29; // [esp+18h] [ebp-3Ch]
  unsigned int v30; // [esp+1Ch] [ebp-38h]
  int v31; // [esp+20h] [ebp-34h]
  unsigned int buf; // [esp+24h] [ebp-30h] BYREF
  int v33; // [esp+28h] [ebp-2Ch]
  unsigned int v34; // [esp+2Ch] [ebp-28h]
  int v35; // [esp+30h] [ebp-24h]
  unsigned int v36; // [esp+34h] [ebp-20h]
  int v37; // [esp+38h] [ebp-1Ch]
  _BYTE v38[24]; // [esp+3Ch] [ebp-18h] BYREF
  bignum_st *aa; // [esp+5Ch] [ebp+8h]

  d = a->d;
  aa = (bignum_st *)a->top;
  if ( a->neg || BN_ucmp(a, &bignum_nist_p_192_sqr) >= 0 )
    return BN_nnmod(r, a, &bignum_nist_p_192, ctx);
  v6 = BN_ucmp(&bignum_nist_p_192, a);
  if ( !v6 )
  {
    BN_set_word(r, 0);
    return 1;
  }
  if ( v6 <= 0 )
  {
    if ( r == a )
    {
      v9 = d;
    }
    else
    {
      if ( r->dmax < 6 )
        v8 = bn_expand2(r, (unsigned int *)6);
      else
        v8 = r;
      if ( !v8 )
        return 0;
      v9 = r->d;
      v10 = r->d;
      v11 = 6;
      v12 = (char *)d - (char *)r->d;
      do
      {
        *v10 = *(unsigned int *)((char *)v10 + v12);
        ++v10;
        --v11;
      }
      while ( v11 );
    }
    nist_cp_bn_0(6, (int)&aa[-1].neg + 2, &buf, d + 6);
    v27 = v33;
    v29 = v33;
    v26 = buf;
    v28 = buf;
    v30 = 0;
    v31 = 0;
    v13 = bn_add_words(v9, v9, &v26, 6);
    v26 = 0;
    v27 = 0;
    v28 = v34;
    v29 = v35;
    v30 = v34;
    v31 = v35;
    v14 = bn_add_words(v9, v9, &v26, 6) + v13;
    v26 = v36;
    v28 = v36;
    v30 = v36;
    v27 = v37;
    v29 = v37;
    v31 = v37;
    v15 = bn_add_words(v9, v9, &v26, 6) + v14;
    if ( v15 <= 0 )
      v16 = 1;
    else
      v16 = bn_sub_words(v9, v9, &aCryptoEcEcpSmp[24 * v15], 6);
    v17 = bn_sub_words(v38, v9, (const unsigned int *)nist_p_192, 6);
    v18 = (unsigned int)v9 & -v16 & -v17 | (unsigned int)v38 & ~(-v16 & -v17);
    v19 = v9;
    v20 = 6;
    v21 = v18 - (_DWORD)v9;
    do
    {
      *v19 = *(_DWORD *)((char *)v19 + v21);
      ++v19;
      --v20;
    }
    while ( v20 );
    v22 = r->d;
    r->top = 6;
    v23 = 6;
    v24 = v22 + 5;
    do
    {
      if ( *v24-- )
        break;
      --v23;
    }
    while ( v23 > 0 );
    r->top = v23;
    return 1;
  }
  else
  {
    if ( r == a )
      return 1;
    return BN_copy(r, a) != 0;
  }
}
