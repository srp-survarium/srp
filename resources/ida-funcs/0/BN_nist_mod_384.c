int __usercall BN_nist_mod_384@<eax>(
        int a1@<ebx>,
        bignum_st *r,
        const bignum_st *a,
        const bignum_st *field,
        bignum_ctx *ctx)
{
  unsigned int *d; // ebp
  int v6; // eax
  bignum_st *v8; // eax
  unsigned int *v9; // esi
  unsigned int *v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int *v14; // ecx
  int v15; // ebx
  unsigned int v16; // eax
  int v17; // eax
  int v18; // ebx
  int v19; // ebx
  int v20; // eax
  int v21; // ebx
  int v22; // ebx
  int v23; // eax
  int v24; // ebx
  int v25; // ebx
  int v26; // ebx
  int v27; // ebx
  int v28; // eax
  unsigned int v29; // ecx
  int v30; // eax
  unsigned int v31; // ecx
  unsigned int *v32; // ecx
  int v33; // eax
  _DWORD *v34; // ecx
  int v36; // [esp+Ch] [ebp-94h] BYREF
  int v37; // [esp+10h] [ebp-90h]
  int v38; // [esp+14h] [ebp-8Ch]
  int v39; // [esp+18h] [ebp-88h]
  int v40; // [esp+1Ch] [ebp-84h]
  int v41; // [esp+20h] [ebp-80h]
  int v42; // [esp+24h] [ebp-7Ch]
  int v43; // [esp+28h] [ebp-78h]
  int v44; // [esp+2Ch] [ebp-74h]
  int v45; // [esp+30h] [ebp-70h]
  int v46; // [esp+34h] [ebp-6Ch]
  int v47; // [esp+38h] [ebp-68h]
  int v48; // [esp+3Ch] [ebp-64h] BYREF
  int v49; // [esp+40h] [ebp-60h]
  int v50; // [esp+44h] [ebp-5Ch]
  int v51; // [esp+48h] [ebp-58h]
  int v52; // [esp+4Ch] [ebp-54h]
  int v53; // [esp+50h] [ebp-50h]
  int v54; // [esp+54h] [ebp-4Ch]
  int v55; // [esp+58h] [ebp-48h]
  int v56; // [esp+5Ch] [ebp-44h]
  int v57; // [esp+60h] [ebp-40h]
  int v58; // [esp+64h] [ebp-3Ch]
  int v59; // [esp+68h] [ebp-38h]
  int top; // [esp+6Ch] [ebp-34h]
  _BYTE v61[48]; // [esp+70h] [ebp-30h] BYREF

  d = a->d;
  top = a->top;
  if ( a->neg || BN_ucmp(a, &bignum_nist_p_384_sqr) >= 0 )
    return BN_nnmod(a1, r, a, &bignum_nist_p_384, ctx);
  v6 = BN_ucmp(&bignum_nist_p_384, a);
  if ( !v6 )
  {
    BN_set_word(a1, r, 0);
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
      if ( r->dmax < 12 )
        v8 = bn_expand2(r, 12);
      else
        v8 = r;
      if ( !v8 )
        return 0;
      v9 = r->d;
      v10 = r->d;
      v11 = 12;
      v12 = (char *)d - (char *)r->d;
      do
      {
        *v10 = *(unsigned int *)((char *)v10 + v12);
        ++v10;
        --v11;
      }
      while ( v11 );
    }
    nist_cp_bn_0(12, top - 12, (char *)&v48, (char *)d + 48);
    v37 = v58;
    v13 = 0;
    v36 = v57;
    v38 = v59;
    v39 = 0;
    v40 = 0;
    v41 = 0;
    v42 = 0;
    v43 = 0;
    v14 = &v36;
    v15 = 3;
    do
    {
      v16 = *v14;
      *v14 = v13 | (2 * *v14);
      v17 = v16 >> 31;
      ++v14;
      --v15;
      v13 = v17;
    }
    while ( v15 );
    *v14 = v17;
    v18 = bn_add_words(v9 + 4, v9 + 4, &v36, 8);
    v19 = bn_add_words(v9, v9, &v48, 12) + v18;
    v36 = v57;
    v39 = v48;
    v42 = v51;
    v37 = v58;
    v38 = v59;
    v45 = v54;
    v40 = v49;
    v41 = v50;
    v43 = v52;
    v44 = v53;
    v46 = v55;
    v47 = v56;
    v20 = bn_add_words(v9, v9, &v36, 12);
    v39 = v56;
    v42 = v50;
    v37 = v59;
    v45 = v53;
    v40 = v48;
    v41 = v49;
    v43 = v51;
    v44 = v52;
    v36 = 0;
    v38 = 0;
    v46 = v54;
    v47 = v55;
    v21 = bn_add_words(v9, v9, &v36, 12) + v20 + v19;
    v36 = 0;
    v37 = 0;
    v38 = 0;
    v39 = 0;
    v41 = v57;
    v40 = v56;
    v42 = v58;
    v43 = v59;
    v44 = 0;
    v45 = 0;
    v46 = 0;
    v47 = 0;
    v22 = bn_add_words(v9, v9, &v36, 12) + v21;
    v39 = v57;
    v36 = v56;
    v37 = 0;
    v38 = 0;
    v40 = v58;
    v41 = v59;
    v42 = 0;
    v43 = 0;
    v44 = 0;
    v45 = 0;
    v46 = 0;
    v47 = 0;
    v23 = bn_add_words(v9, v9, &v36, 12);
    v36 = v59;
    v39 = v50;
    v42 = v53;
    v37 = v48;
    v38 = v49;
    v45 = v56;
    v40 = v51;
    v41 = v52;
    v43 = v54;
    v44 = v55;
    v46 = v57;
    v47 = v58;
    v24 = v23 + v22 - bn_sub_words(v9, v9, &v36, 12);
    v37 = v56;
    v36 = 0;
    v38 = v57;
    v39 = v58;
    v40 = v59;
    v41 = 0;
    v42 = 0;
    v43 = 0;
    v44 = 0;
    v45 = 0;
    v46 = 0;
    v47 = 0;
    v25 = v24 - bn_sub_words(v9, v9, &v36, 12);
    v36 = 0;
    v37 = 0;
    v38 = 0;
    v39 = v59;
    v40 = v59;
    v41 = 0;
    v42 = 0;
    v43 = 0;
    v44 = 0;
    v45 = 0;
    v46 = 0;
    v47 = 0;
    v26 = v25 - bn_sub_words(v9, v9, &v36, 12);
    if ( v26 <= 0 )
    {
      if ( v26 < 0 )
      {
        v27 = bn_add_words(v9, v9, nist_p_384[-v26 - 1], 12);
        v28 = ((int (__cdecl *)(_BYTE *, unsigned int *, const unsigned int *, int))((unsigned int)bn_sub_words & -v27
                                                                                   | (unsigned int)bn_add_words
                                                                                   & (v27 - 1)))(
                v61,
                v9,
                (const unsigned int *)nist_p_384,
                12);
LABEL_27:
        v29 = (unsigned int)v9 & -v27 & -v28 | (unsigned int)v61 & ~(-v27 & -v28);
        v30 = 12;
        v31 = v29 - (_DWORD)v9;
        do
        {
          *v9 = *(unsigned int *)((char *)v9 + v31);
          ++v9;
          --v30;
        }
        while ( v30 );
        v32 = r->d;
        r->top = 12;
        v33 = 12;
        v34 = v32 + 11;
        do
        {
          if ( *v34-- )
            break;
          --v33;
        }
        while ( v33 > 0 );
        r->top = v33;
        return 1;
      }
      v27 = 1;
    }
    else
    {
      v27 = bn_sub_words(v9, v9, &nist_p_256_sqr[12 * v26 + 4], 12);
    }
    v28 = bn_sub_words(v61, v9, (const unsigned int *)nist_p_384, 12);
    goto LABEL_27;
  }
  if ( r == a )
    return 1;
  return BN_copy(r, a) != 0;
}
