int __cdecl BN_nist_mod_224(bignum_st *r, const bignum_st *a, const bignum_st *field, bignum_ctx *ctx)
{
  unsigned int *d; // ebx
  int v6; // eax
  bignum_st *v8; // eax
  unsigned int *v9; // esi
  unsigned int *v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  unsigned int v14; // ebx
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  int v19; // eax
  unsigned int v20; // ecx
  int v21; // eax
  unsigned int v22; // ecx
  unsigned int *v23; // ecx
  int v24; // eax
  _DWORD *v25; // ecx
  unsigned int v27; // [esp+Ch] [ebp-54h] BYREF
  unsigned int v28; // [esp+10h] [ebp-50h]
  unsigned int v29; // [esp+14h] [ebp-4Ch]
  unsigned int v30; // [esp+18h] [ebp-48h]
  unsigned int v31; // [esp+1Ch] [ebp-44h]
  unsigned int v32; // [esp+20h] [ebp-40h]
  unsigned int v33; // [esp+24h] [ebp-3Ch]
  unsigned int buf; // [esp+28h] [ebp-38h] BYREF
  unsigned int v35; // [esp+2Ch] [ebp-34h]
  unsigned int v36; // [esp+30h] [ebp-30h]
  unsigned int v37; // [esp+34h] [ebp-2Ch]
  unsigned int v38; // [esp+38h] [ebp-28h]
  unsigned int v39; // [esp+3Ch] [ebp-24h]
  unsigned int v40; // [esp+40h] [ebp-20h]
  _BYTE v41[28]; // [esp+44h] [ebp-1Ch] BYREF
  bignum_st *aa; // [esp+68h] [ebp+8h]

  d = a->d;
  aa = (bignum_st *)a->top;
  if ( a->neg || BN_ucmp(a, &bignum_nist_p_224_sqr) >= 0 )
    return BN_nnmod(r, a, &bignum_nist_p_224, ctx);
  v6 = BN_ucmp(&bignum_nist_p_224, a);
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
      if ( r->dmax < 7 )
        v8 = bn_expand2(r, (unsigned int *)7);
      else
        v8 = r;
      if ( !v8 )
        return 0;
      v9 = r->d;
      v10 = r->d;
      v11 = 7;
      v12 = (char *)d - (char *)r->d;
      do
      {
        *v10 = *(unsigned int *)((char *)v10 + v12);
        ++v10;
        --v11;
      }
      while ( v11 );
    }
    nist_cp_bn_0(7, (int)&aa[-1].neg + 1, &buf, d + 7);
    v31 = v35;
    v30 = buf;
    v27 = 0;
    v28 = 0;
    v29 = 0;
    v32 = v36;
    v33 = v37;
    v13 = bn_add_words(v9, v9, &v27, 7);
    v14 = v38;
    v27 = 0;
    v28 = 0;
    v29 = 0;
    v30 = v38;
    v31 = v39;
    v32 = v40;
    v33 = 0;
    v15 = bn_add_words(v9, v9, &v27, 7) + v13;
    v27 = buf;
    v30 = v37;
    v28 = v35;
    v29 = v36;
    v31 = v14;
    v32 = v39;
    v33 = v40;
    v16 = v15 - bn_sub_words(v9, v9, &v27, 7);
    v27 = v14;
    v28 = v39;
    v29 = v40;
    v30 = 0;
    v31 = 0;
    v32 = 0;
    v33 = 0;
    v17 = v16 - bn_sub_words(v9, v9, &v27, 7);
    if ( v17 <= 0 )
    {
      if ( v17 < 0 )
      {
        v18 = bn_add_words(v9, v9, nist_p_224[-v17 - 1], 7);
        v19 = ((int (__cdecl *)(_BYTE *, unsigned int *, const unsigned int *, int))((unsigned int)bn_sub_words & -v18
                                                                                   | (unsigned int)bn_add_words
                                                                                   & (v18 - 1)))(
                v41,
                v9,
                (const unsigned int *)nist_p_224,
                7);
LABEL_25:
        v20 = (unsigned int)v9 & -v18 & -v19 | (unsigned int)v41 & ~(-v18 & -v19);
        v21 = 7;
        v22 = v20 - (_DWORD)v9;
        do
        {
          *v9 = *(unsigned int *)((char *)v9 + v22);
          ++v9;
          --v21;
        }
        while ( v21 );
        v23 = r->d;
        r->top = 7;
        v24 = 7;
        v25 = v23 + 6;
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
      v18 = 1;
    }
    else
    {
      v18 = bn_sub_words(v9, v9, &nist_p_192_sqr[7 * v17 + 5], 7);
    }
    v19 = bn_sub_words(v41, v9, (const unsigned int *)nist_p_224, 7);
    goto LABEL_25;
  }
  if ( r == a )
    return 1;
  return BN_copy(r, a) != 0;
}
