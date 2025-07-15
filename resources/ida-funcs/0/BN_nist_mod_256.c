int __usercall BN_nist_mod_256@<eax>(
        int a1@<ebx>,
        bignum_st *r,
        const bignum_st *a,
        const bignum_st *field,
        bignum_ctx *ctx)
{
  unsigned int *d; // ebp
  int v7; // eax
  bignum_st *v9; // eax
  unsigned int *v10; // esi
  unsigned int *v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // ebx
  int v15; // ebp
  unsigned int *v16; // ecx
  int v17; // edx
  bignum_st *v18; // eax
  int v19; // eax
  int v20; // edi
  int v21; // eax
  int v22; // edi
  int v23; // eax
  int v24; // edi
  int v25; // edi
  int v26; // edi
  int v27; // eax
  unsigned int v28; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  unsigned int *v31; // ecx
  int v32; // eax
  _DWORD *v33; // ecx
  int v35; // [esp+Ch] [ebp-64h]
  int v36; // [esp+10h] [ebp-60h] BYREF
  int v37; // [esp+14h] [ebp-5Ch]
  int v38; // [esp+18h] [ebp-58h]
  int v39; // [esp+1Ch] [ebp-54h]
  int v40; // [esp+20h] [ebp-50h]
  int v41; // [esp+24h] [ebp-4Ch]
  int v42; // [esp+28h] [ebp-48h]
  int v43; // [esp+2Ch] [ebp-44h]
  int v44; // [esp+30h] [ebp-40h] BYREF
  int v45; // [esp+34h] [ebp-3Ch]
  int v46; // [esp+38h] [ebp-38h]
  int v47; // [esp+3Ch] [ebp-34h]
  int v48; // [esp+40h] [ebp-30h]
  int v49; // [esp+44h] [ebp-2Ch]
  int v50; // [esp+48h] [ebp-28h]
  int v51; // [esp+4Ch] [ebp-24h]
  _DWORD v52[8]; // [esp+50h] [ebp-20h] BYREF
  bignum_st *aa; // [esp+78h] [ebp+8h]
  bignum_st *ab; // [esp+78h] [ebp+8h]

  d = a->d;
  aa = (bignum_st *)a->top;
  if ( a->neg || BN_ucmp(a, &bignum_nist_p_256_sqr) >= 0 )
    return BN_nnmod(a1, r, a, &bignum_nist_p_256, ctx);
  v7 = BN_ucmp(&bignum_nist_p_256, a);
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
      if ( r->dmax < 8 )
        v9 = bn_expand2(r, 8);
      else
        v9 = r;
      if ( !v9 )
        return 0;
      v10 = r->d;
      v11 = r->d;
      v12 = 8;
      v13 = (char *)d - (char *)r->d;
      do
      {
        *v11 = *(unsigned int *)((char *)v11 + v13);
        ++v11;
        --v12;
      }
      while ( v12 );
    }
    nist_cp_bn_0(8, (int)&aa[-1].neg, (char *)&v44, (char *)d + 32);
    v14 = v49;
    v15 = v50;
    v39 = v47;
    v40 = v48;
    v52[3] = v48;
    v43 = v51;
    v52[6] = v51;
    v36 = 0;
    v37 = 0;
    v38 = 0;
    v41 = v49;
    v42 = v50;
    memset(v52, 0, 12);
    v52[4] = v49;
    v52[5] = v50;
    v52[7] = 0;
    v35 = bn_add_words(&v36, &v36, v52, 8);
    v16 = (unsigned int *)&v36;
    ab = 0;
    v17 = 8;
    do
    {
      v18 = (bignum_st *)(*v16 >> 31);
      *v16 = (unsigned int)ab | (2 * *v16);
      ++v16;
      --v17;
      ab = v18;
    }
    while ( v17 );
    v19 = bn_add_words(v10, v10, &v36, 8);
    v37 = v45;
    v39 = 0;
    v40 = 0;
    v41 = 0;
    v36 = v44;
    v38 = v46;
    v42 = v15;
    v43 = v51;
    v20 = bn_add_words(v10, v10, &v36, 8) + ((unsigned int)ab | (2 * v35)) + v19;
    v38 = v47;
    v36 = v45;
    v37 = v46;
    v39 = v14;
    v40 = v15;
    v41 = v51;
    v42 = v14;
    v43 = v44;
    v21 = bn_add_words(v10, v10, &v36, 8);
    v37 = v48;
    v36 = v47;
    v39 = 0;
    v40 = 0;
    v41 = 0;
    v38 = v14;
    v42 = v44;
    v43 = v46;
    v22 = v21 + v20 - bn_sub_words(v10, v10, &v36, 8);
    v36 = v48;
    v37 = v14;
    v38 = v15;
    v39 = v51;
    v40 = 0;
    v41 = 0;
    v42 = v45;
    v43 = v47;
    v23 = bn_sub_words(v10, v10, &v36, 8);
    v40 = v45;
    v38 = v51;
    v39 = v44;
    v36 = v14;
    v37 = v15;
    v41 = v46;
    v42 = 0;
    v43 = v48;
    v24 = v22 - v23 - bn_sub_words(v10, v10, &v36, 8);
    v39 = v45;
    v36 = v15;
    v37 = v51;
    v38 = 0;
    v40 = v46;
    v41 = v47;
    v42 = 0;
    v43 = v14;
    v25 = v24 - bn_sub_words(v10, v10, &v36, 8);
    if ( v25 <= 0 )
    {
      if ( v25 < 0 )
      {
        v26 = bn_add_words(v10, v10, nist_p_256[-v25 - 1], 8);
        v27 = ((int (__cdecl *)(_DWORD *, unsigned int *, const unsigned int *, int))((unsigned int)bn_sub_words & -v26
                                                                                    | (unsigned int)bn_add_words
                                                                                    & (v26 - 1)))(
                v52,
                v10,
                (const unsigned int *)nist_p_256,
                8);
LABEL_27:
        v28 = (unsigned int)v10 & -v26 & -v27 | (unsigned int)v52 & ~(-v26 & -v27);
        v29 = 8;
        v30 = v28 - (_DWORD)v10;
        do
        {
          *v10 = *(unsigned int *)((char *)v10 + v30);
          ++v10;
          --v29;
        }
        while ( v29 );
        v31 = r->d;
        r->top = 8;
        v32 = 8;
        v33 = v31 + 7;
        do
        {
          if ( *v33-- )
            break;
          --v32;
        }
        while ( v32 > 0 );
        r->top = v32;
        return 1;
      }
      v26 = 1;
    }
    else
    {
      v26 = bn_sub_words(v10, v10, &nist_p_224_sqr[8 * v25 + 6], 8);
    }
    v27 = bn_sub_words(v52, v10, (const unsigned int *)nist_p_256, 8);
    goto LABEL_27;
  }
  if ( r == a )
    return 1;
  return BN_copy(r, a) != 0;
}
