int __cdecl BN_nist_mod_256(bignum_st *r, const bignum_st *a, const bignum_st *field, bignum_ctx *ctx)
{
  unsigned int *d; // ebp
  int v6; // eax
  bignum_st *v8; // eax
  unsigned int *v9; // esi
  unsigned int *v10; // eax
  int v11; // edx
  int v12; // ecx
  unsigned int v13; // ebx
  unsigned int v14; // ebp
  unsigned int *v15; // ecx
  int v16; // edx
  bignum_st *v17; // eax
  int v18; // eax
  int v19; // edi
  int v20; // eax
  int v21; // edi
  int v22; // eax
  int v23; // edi
  int v24; // edi
  int v25; // edi
  int v26; // eax
  unsigned int v27; // ecx
  int v28; // eax
  unsigned int v29; // ecx
  unsigned int *v30; // ecx
  int v31; // eax
  _DWORD *v32; // ecx
  int v34; // [esp+Ch] [ebp-64h]
  unsigned int v35; // [esp+10h] [ebp-60h] BYREF
  unsigned int v36; // [esp+14h] [ebp-5Ch]
  unsigned int v37; // [esp+18h] [ebp-58h]
  unsigned int v38; // [esp+1Ch] [ebp-54h]
  unsigned int v39; // [esp+20h] [ebp-50h]
  unsigned int v40; // [esp+24h] [ebp-4Ch]
  unsigned int v41; // [esp+28h] [ebp-48h]
  unsigned int v42; // [esp+2Ch] [ebp-44h]
  unsigned int buf; // [esp+30h] [ebp-40h] BYREF
  unsigned int v44; // [esp+34h] [ebp-3Ch]
  unsigned int v45; // [esp+38h] [ebp-38h]
  unsigned int v46; // [esp+3Ch] [ebp-34h]
  unsigned int v47; // [esp+40h] [ebp-30h]
  unsigned int v48; // [esp+44h] [ebp-2Ch]
  unsigned int v49; // [esp+48h] [ebp-28h]
  unsigned int v50; // [esp+4Ch] [ebp-24h]
  _DWORD v51[8]; // [esp+50h] [ebp-20h] BYREF
  bignum_st *aa; // [esp+78h] [ebp+8h]
  bignum_st *ab; // [esp+78h] [ebp+8h]

  d = a->d;
  aa = (bignum_st *)a->top;
  if ( a->neg || BN_ucmp(a, &bignum_nist_p_256_sqr) >= 0 )
    return BN_nnmod(r, a, &bignum_nist_p_256, ctx);
  v6 = BN_ucmp(&bignum_nist_p_256, a);
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
      if ( r->dmax < 8 )
        v8 = bn_expand2(r, (unsigned int *)8);
      else
        v8 = r;
      if ( !v8 )
        return 0;
      v9 = r->d;
      v10 = r->d;
      v11 = 8;
      v12 = (char *)d - (char *)r->d;
      do
      {
        *v10 = *(unsigned int *)((char *)v10 + v12);
        ++v10;
        --v11;
      }
      while ( v11 );
    }
    nist_cp_bn_0(8, (int)&aa[-1].neg, &buf, d + 8);
    v13 = v48;
    v14 = v49;
    v38 = v46;
    v39 = v47;
    v51[3] = v47;
    v42 = v50;
    v51[6] = v50;
    v35 = 0;
    v36 = 0;
    v37 = 0;
    v40 = v48;
    v41 = v49;
    memset(v51, 0, 12);
    v51[4] = v48;
    v51[5] = v49;
    v51[7] = 0;
    v34 = bn_add_words(&v35, &v35, v51, 8);
    v15 = &v35;
    ab = 0;
    v16 = 8;
    do
    {
      v17 = (bignum_st *)(*v15 >> 31);
      *v15 = (unsigned int)ab | (2 * *v15);
      ++v15;
      --v16;
      ab = v17;
    }
    while ( v16 );
    v18 = bn_add_words(v9, v9, &v35, 8);
    v36 = v44;
    v38 = 0;
    v39 = 0;
    v40 = 0;
    v35 = buf;
    v37 = v45;
    v41 = v14;
    v42 = v50;
    v19 = bn_add_words(v9, v9, &v35, 8) + ((unsigned int)ab | (2 * v34)) + v18;
    v37 = v46;
    v35 = v44;
    v36 = v45;
    v38 = v13;
    v39 = v14;
    v40 = v50;
    v41 = v13;
    v42 = buf;
    v20 = bn_add_words(v9, v9, &v35, 8);
    v36 = v47;
    v35 = v46;
    v38 = 0;
    v39 = 0;
    v40 = 0;
    v37 = v13;
    v41 = buf;
    v42 = v45;
    v21 = v20 + v19 - bn_sub_words(v9, v9, &v35, 8);
    v35 = v47;
    v36 = v13;
    v37 = v14;
    v38 = v50;
    v39 = 0;
    v40 = 0;
    v41 = v44;
    v42 = v46;
    v22 = bn_sub_words(v9, v9, &v35, 8);
    v39 = v44;
    v37 = v50;
    v38 = buf;
    v35 = v13;
    v36 = v14;
    v40 = v45;
    v41 = 0;
    v42 = v47;
    v23 = v21 - v22 - bn_sub_words(v9, v9, &v35, 8);
    v38 = v44;
    v35 = v14;
    v36 = v50;
    v37 = 0;
    v39 = v45;
    v40 = v46;
    v41 = 0;
    v42 = v13;
    v24 = v23 - bn_sub_words(v9, v9, &v35, 8);
    if ( v24 <= 0 )
    {
      if ( v24 < 0 )
      {
        v25 = bn_add_words(v9, v9, nist_p_256[-v24 - 1], 8);
        v26 = ((int (__cdecl *)(_DWORD *, unsigned int *, const unsigned int *, int))((unsigned int)bn_sub_words & -v25
                                                                                    | (unsigned int)bn_add_words
                                                                                    & (v25 - 1)))(
                v51,
                v9,
                (const unsigned int *)nist_p_256,
                8);
LABEL_27:
        v27 = (unsigned int)v9 & -v25 & -v26 | (unsigned int)v51 & ~(-v25 & -v26);
        v28 = 8;
        v29 = v27 - (_DWORD)v9;
        do
        {
          *v9 = *(unsigned int *)((char *)v9 + v29);
          ++v9;
          --v28;
        }
        while ( v28 );
        v30 = r->d;
        r->top = 8;
        v31 = 8;
        v32 = v30 + 7;
        do
        {
          if ( *v32-- )
            break;
          --v31;
        }
        while ( v31 > 0 );
        r->top = v31;
        return 1;
      }
      v25 = 1;
    }
    else
    {
      v25 = bn_sub_words(v9, v9, &nist_p_224_sqr[8 * v24 + 6], 8);
    }
    v26 = bn_sub_words(v51, v9, (const unsigned int *)nist_p_256, 8);
    goto LABEL_27;
  }
  if ( r == a )
    return 1;
  return BN_copy(r, a) != 0;
}
