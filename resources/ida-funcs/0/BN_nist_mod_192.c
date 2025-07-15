int __usercall BN_nist_mod_192@<eax>(
        int a1@<ebx>,
        bignum_st *r,
        const bignum_st *a,
        const bignum_st *field,
        bignum_ctx *ctx)
{
  unsigned int *d; // edi
  int v7; // eax
  bignum_st *v9; // eax
  unsigned int *v10; // esi
  unsigned int *v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // eax
  unsigned int v19; // ecx
  _DWORD *v20; // edx
  int v21; // eax
  unsigned int v22; // ecx
  unsigned int *v23; // ecx
  int v24; // eax
  _DWORD *v25; // ecx
  int v27; // [esp+Ch] [ebp-48h] BYREF
  int v28; // [esp+10h] [ebp-44h]
  int v29; // [esp+14h] [ebp-40h]
  int v30; // [esp+18h] [ebp-3Ch]
  int v31; // [esp+1Ch] [ebp-38h]
  int v32; // [esp+20h] [ebp-34h]
  int v33; // [esp+24h] [ebp-30h] BYREF
  int v34; // [esp+28h] [ebp-2Ch]
  int v35; // [esp+2Ch] [ebp-28h]
  int v36; // [esp+30h] [ebp-24h]
  int v37; // [esp+34h] [ebp-20h]
  int v38; // [esp+38h] [ebp-1Ch]
  _BYTE v39[24]; // [esp+3Ch] [ebp-18h] BYREF
  bignum_st *aa; // [esp+5Ch] [ebp+8h]

  d = a->d;
  aa = (bignum_st *)a->top;
  if ( a->neg || BN_ucmp(a, &bignum_nist_p_192_sqr) >= 0 )
    return BN_nnmod(a1, r, a, &bignum_nist_p_192, ctx);
  v7 = BN_ucmp(&bignum_nist_p_192, a);
  if ( !v7 )
  {
    BN_set_word(a1, r, 0);
    return 1;
  }
  if ( v7 <= 0 )
  {
    if ( r == a )
    {
      v10 = d;
    }
    else
    {
      if ( r->dmax < 6 )
        v9 = bn_expand2(r, 6);
      else
        v9 = r;
      if ( !v9 )
        return 0;
      v10 = r->d;
      v11 = r->d;
      v12 = 6;
      v13 = (char *)d - (char *)r->d;
      do
      {
        *v11 = *(unsigned int *)((char *)v11 + v13);
        ++v11;
        --v12;
      }
      while ( v12 );
    }
    nist_cp_bn_0(6, (int)&aa[-1].neg + 2, (char *)&v33, (char *)d + 24);
    v28 = v34;
    v30 = v34;
    v27 = v33;
    v29 = v33;
    v31 = 0;
    v32 = 0;
    v14 = bn_add_words(v10, v10, &v27, 6);
    v27 = 0;
    v28 = 0;
    v29 = v35;
    v30 = v36;
    v31 = v35;
    v32 = v36;
    v15 = bn_add_words(v10, v10, &v27, 6) + v14;
    v27 = v37;
    v29 = v37;
    v31 = v37;
    v28 = v38;
    v30 = v38;
    v32 = v38;
    v16 = bn_add_words(v10, v10, &v27, 6) + v15;
    if ( v16 <= 0 )
      v17 = 1;
    else
      v17 = bn_sub_words(v10, v10, &aCryptoEcEcpSmp[24 * v16], 6);
    v18 = bn_sub_words(v39, v10, (const unsigned int *)nist_p_192, 6);
    v19 = (unsigned int)v10 & -v17 & -v18 | (unsigned int)v39 & ~(-v17 & -v18);
    v20 = v10;
    v21 = 6;
    v22 = v19 - (_DWORD)v10;
    do
    {
      *v20 = *(_DWORD *)((char *)v20 + v22);
      ++v20;
      --v21;
    }
    while ( v21 );
    v23 = r->d;
    r->top = 6;
    v24 = 6;
    v25 = v23 + 5;
    do
    {
      if ( *v25-- )
        break;
      --v24;
    }
    while ( v24 > 0 );
    r->top = v24;
    return 1;
  }
  else
  {
    if ( r == a )
      return 1;
    return BN_copy(r, a) != 0;
  }
}
