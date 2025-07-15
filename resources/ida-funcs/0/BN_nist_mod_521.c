int __usercall BN_nist_mod_521@<eax>(
        int a1@<ebx>,
        bignum_st *r,
        const bignum_st *a,
        const bignum_st *field,
        bignum_ctx *ctx)
{
  bool v6; // zf
  unsigned int *d; // edi
  int v8; // eax
  int result; // eax
  unsigned int *v10; // esi
  unsigned int *v11; // eax
  int v12; // edx
  int v13; // ecx
  unsigned int v14; // ecx
  int i; // eax
  unsigned int v16; // edx
  int v17; // eax
  _DWORD *v18; // edx
  int v19; // edi
  unsigned int *v20; // ecx
  int v21; // eax
  _DWORD *v22; // ecx
  _DWORD v24[17]; // [esp+8h] [ebp-44h] BYREF
  bignum_st *aa; // [esp+54h] [ebp+8h]

  v6 = a->neg == 0;
  d = a->d;
  aa = (bignum_st *)a->top;
  if ( !v6 || BN_ucmp(a, &bignum_nist_p_521_sqr) >= 0 )
    return BN_nnmod(a1, r, a, &bignum_nist_p_521, ctx);
  v8 = BN_ucmp(&bignum_nist_p_521, a);
  if ( !v8 )
  {
    BN_set_word(a1, r, 0);
    return 1;
  }
  if ( v8 <= 0 )
  {
    if ( r == a )
    {
      v10 = d;
    }
    else
    {
      if ( r->dmax < 17 )
        result = (int)bn_expand2(r, 17);
      else
        result = (int)r;
      if ( !result )
        return result;
      v10 = r->d;
      v11 = r->d;
      v12 = 17;
      v13 = (char *)d - (char *)r->d;
      do
      {
        *v11 = *(unsigned int *)((char *)v11 + v13);
        ++v11;
        --v12;
      }
      while ( v12 );
    }
    nist_cp_bn_0(17, (int)&aa[-1].top, (char *)v24, (char *)d + 64);
    v14 = v24[0];
    for ( i = 0; i < 16; ++i )
    {
      v16 = v14;
      v14 = v24[i + 1];
      v24[i] = __SPAIR64__(v14, v16) >> 9;
    }
    v24[i] = v14 >> 9;
    v10[i] &= 0x1FFu;
    bn_add_words(v10, v10, v24, 17);
    v17 = bn_sub_words(v24, v10, nist_p_521, 17);
    v18 = v10;
    v19 = 17;
    do
    {
      *v18 = *(_DWORD *)((char *)v18 + ((unsigned int)v10 & -v17 | (unsigned int)v24 & (v17 - 1)) - (_DWORD)v10);
      ++v18;
      --v19;
    }
    while ( v19 );
    v20 = r->d;
    v21 = 17;
    r->top = 17;
    v22 = v20 + 16;
    do
    {
      if ( *v22-- )
        break;
      --v21;
    }
    while ( v21 > 0 );
    r->top = v21;
    return 1;
  }
  if ( r == a )
    return 1;
  return BN_copy(r, a) != 0;
}
