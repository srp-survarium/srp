int __cdecl BN_nist_mod_384(bignum_st *r, const bignum_st *a, const bignum_st *field, bignum_ctx *ctx)
{
  unsigned int *d; // ebp
  int v5; // eax
  bignum_st *v7; // eax
  unsigned int *v8; // esi
  unsigned int *v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int *v13; // ecx
  int v14; // ebx
  unsigned int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // ebx
  int v19; // eax
  int v20; // ebx
  int v21; // ebx
  int v22; // eax
  int v23; // ebx
  int v24; // ebx
  int v25; // ebx
  int v26; // ebx
  int v27; // eax
  unsigned int v28; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  unsigned int *v31; // ecx
  int v32; // eax
  _DWORD *v33; // ecx
  unsigned int v35; // [esp+Ch] [ebp-94h] BYREF
  unsigned int v36; // [esp+10h] [ebp-90h]
  unsigned int v37; // [esp+14h] [ebp-8Ch]
  unsigned int v38; // [esp+18h] [ebp-88h]
  unsigned int v39; // [esp+1Ch] [ebp-84h]
  unsigned int v40; // [esp+20h] [ebp-80h]
  unsigned int v41; // [esp+24h] [ebp-7Ch]
  unsigned int v42; // [esp+28h] [ebp-78h]
  unsigned int v43; // [esp+2Ch] [ebp-74h]
  unsigned int v44; // [esp+30h] [ebp-70h]
  unsigned int v45; // [esp+34h] [ebp-6Ch]
  unsigned int v46; // [esp+38h] [ebp-68h]
  unsigned int buf; // [esp+3Ch] [ebp-64h] BYREF
  unsigned int v48; // [esp+40h] [ebp-60h]
  unsigned int v49; // [esp+44h] [ebp-5Ch]
  unsigned int v50; // [esp+48h] [ebp-58h]
  unsigned int v51; // [esp+4Ch] [ebp-54h]
  unsigned int v52; // [esp+50h] [ebp-50h]
  unsigned int v53; // [esp+54h] [ebp-4Ch]
  unsigned int v54; // [esp+58h] [ebp-48h]
  unsigned int v55; // [esp+5Ch] [ebp-44h]
  unsigned int v56; // [esp+60h] [ebp-40h]
  unsigned int v57; // [esp+64h] [ebp-3Ch]
  unsigned int v58; // [esp+68h] [ebp-38h]
  int top; // [esp+6Ch] [ebp-34h]
  _BYTE v60[48]; // [esp+70h] [ebp-30h] BYREF

  d = a->d;
  top = a->top;
  if ( a->neg || BN_ucmp(a, &bignum_nist_p_384_sqr) >= 0 )
    return BN_nnmod(r, a, &bignum_nist_p_384, ctx);
  v5 = BN_ucmp(&bignum_nist_p_384, a);
  if ( !v5 )
  {
    BN_set_word(r, 0);
    return 1;
  }
  if ( v5 <= 0 )
  {
    if ( r == a )
    {
      v8 = d;
    }
    else
    {
      if ( r->dmax < 12 )
        v7 = bn_expand2(r, (unsigned int *)0xC);
      else
        v7 = r;
      if ( !v7 )
        return 0;
      v8 = r->d;
      v9 = r->d;
      v10 = 12;
      v11 = (char *)d - (char *)r->d;
      do
      {
        *v9 = *(unsigned int *)((char *)v9 + v11);
        ++v9;
        --v10;
      }
      while ( v10 );
    }
    nist_cp_bn_0(12, top - 12, &buf, d + 12);
    v36 = v57;
    v12 = 0;
    v35 = v56;
    v37 = v58;
    v38 = 0;
    v39 = 0;
    v40 = 0;
    v41 = 0;
    v42 = 0;
    v13 = (int *)&v35;
    v14 = 3;
    do
    {
      v15 = *v13;
      *v13 = v12 | (2 * *v13);
      v16 = v15 >> 31;
      ++v13;
      --v14;
      v12 = v16;
    }
    while ( v14 );
    *v13 = v16;
    v17 = bn_add_words(v8 + 4, v8 + 4, &v35, 8);
    v18 = bn_add_words(v8, v8, &buf, 12) + v17;
    v35 = v56;
    v38 = buf;
    v41 = v50;
    v36 = v57;
    v37 = v58;
    v44 = v53;
    v39 = v48;
    v40 = v49;
    v42 = v51;
    v43 = v52;
    v45 = v54;
    v46 = v55;
    v19 = bn_add_words(v8, v8, &v35, 12);
    v38 = v55;
    v41 = v49;
    v36 = v58;
    v44 = v52;
    v39 = buf;
    v40 = v48;
    v42 = v50;
    v43 = v51;
    v35 = 0;
    v37 = 0;
    v45 = v53;
    v46 = v54;
    v20 = bn_add_words(v8, v8, &v35, 12) + v19 + v18;
    v35 = 0;
    v36 = 0;
    v37 = 0;
    v38 = 0;
    v40 = v56;
    v39 = v55;
    v41 = v57;
    v42 = v58;
    v43 = 0;
    v44 = 0;
    v45 = 0;
    v46 = 0;
    v21 = bn_add_words(v8, v8, &v35, 12) + v20;
    v38 = v56;
    v35 = v55;
    v36 = 0;
    v37 = 0;
    v39 = v57;
    v40 = v58;
    v41 = 0;
    v42 = 0;
    v43 = 0;
    v44 = 0;
    v45 = 0;
    v46 = 0;
    v22 = bn_add_words(v8, v8, &v35, 12);
    v35 = v58;
    v38 = v49;
    v41 = v52;
    v36 = buf;
    v37 = v48;
    v44 = v55;
    v39 = v50;
    v40 = v51;
    v42 = v53;
    v43 = v54;
    v45 = v56;
    v46 = v57;
    v23 = v22 + v21 - bn_sub_words(v8, v8, &v35, 12);
    v36 = v55;
    v35 = 0;
    v37 = v56;
    v38 = v57;
    v39 = v58;
    v40 = 0;
    v41 = 0;
    v42 = 0;
    v43 = 0;
    v44 = 0;
    v45 = 0;
    v46 = 0;
    v24 = v23 - bn_sub_words(v8, v8, &v35, 12);
    v35 = 0;
    v36 = 0;
    v37 = 0;
    v38 = v58;
    v39 = v58;
    v40 = 0;
    v41 = 0;
    v42 = 0;
    v43 = 0;
    v44 = 0;
    v45 = 0;
    v46 = 0;
    v25 = v24 - bn_sub_words(v8, v8, &v35, 12);
    if ( v25 <= 0 )
    {
      if ( v25 < 0 )
      {
        v26 = bn_add_words(v8, v8, nist_p_384[-v25 - 1], 12);
        v27 = ((int (__cdecl *)(_BYTE *, unsigned int *, const unsigned int *, int))((unsigned int)bn_sub_words & -v26
                                                                                   | (unsigned int)bn_add_words
                                                                                   & (v26 - 1)))(
                v60,
                v8,
                (const unsigned int *)nist_p_384,
                12);
LABEL_27:
        v28 = (unsigned int)v8 & -v26 & -v27 | (unsigned int)v60 & ~(-v26 & -v27);
        v29 = 12;
        v30 = v28 - (_DWORD)v8;
        do
        {
          *v8 = *(unsigned int *)((char *)v8 + v30);
          ++v8;
          --v29;
        }
        while ( v29 );
        v31 = r->d;
        r->top = 12;
        v32 = 12;
        v33 = v31 + 11;
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
      v26 = bn_sub_words(v8, v8, &nist_p_256_sqr[12 * v25 + 4], 12);
    }
    v27 = bn_sub_words(v60, v8, (const unsigned int *)nist_p_384, 12);
    goto LABEL_27;
  }
  if ( r == a )
    return 1;
  return BN_copy(r, a) != 0;
}
