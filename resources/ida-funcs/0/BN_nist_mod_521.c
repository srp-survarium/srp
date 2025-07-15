int __cdecl BN_nist_mod_521(bignum_st *r, const bignum_st *a, const bignum_st *field, bignum_ctx *ctx)
{
  bool v5; // zf
  unsigned int *d; // edi
  int v7; // eax
  int result; // eax
  unsigned int *v9; // esi
  unsigned int *v10; // eax
  int v11; // edx
  int v12; // ecx
  unsigned int v13; // ecx
  int i; // eax
  unsigned int v15; // edx
  int v16; // eax
  _DWORD *v17; // edx
  int v18; // edi
  unsigned int *v19; // ecx
  int v20; // eax
  _DWORD *v21; // ecx
  unsigned int buf[17]; // [esp+8h] [ebp-44h] BYREF
  bignum_st *aa; // [esp+54h] [ebp+8h]

  v5 = a->neg == 0;
  d = a->d;
  aa = (bignum_st *)a->top;
  if ( !v5 || BN_ucmp(a, &bignum_nist_p_521_sqr) >= 0 )
    return BN_nnmod(r, a, &bignum_nist_p_521, ctx);
  v7 = BN_ucmp(&bignum_nist_p_521, a);
  if ( !v7 )
  {
    BN_set_word(r, 0);
    return 1;
  }
  if ( v7 <= 0 )
  {
    if ( r == a )
    {
      v9 = d;
    }
    else
    {
      if ( r->dmax < 17 )
        result = (int)bn_expand2(r, (unsigned int *)0x11);
      else
        result = (int)r;
      if ( !result )
        return result;
      v9 = r->d;
      v10 = r->d;
      v11 = 17;
      v12 = (char *)d - (char *)r->d;
      do
      {
        *v10 = *(unsigned int *)((char *)v10 + v12);
        ++v10;
        --v11;
      }
      while ( v11 );
    }
    nist_cp_bn_0(17, (int)&aa[-1].top, buf, d + 16);
    v13 = buf[0];
    for ( i = 0; i < 16; ++i )
    {
      v15 = v13;
      v13 = buf[i + 1];
      buf[i] = __SPAIR64__(v13, v15) >> 9;
    }
    buf[i] = v13 >> 9;
    v9[i] &= 0x1FFu;
    bn_add_words(v9, v9, buf, 17);
    v16 = bn_sub_words(buf, v9, nist_p_521, 17);
    v17 = v9;
    v18 = 17;
    do
    {
      *v17 = *(_DWORD *)((char *)v17 + ((unsigned int)v9 & -v16 | (unsigned int)buf & (v16 - 1)) - (_DWORD)v9);
      ++v17;
      --v18;
    }
    while ( v18 );
    v19 = r->d;
    v20 = 17;
    r->top = 17;
    v21 = v19 + 16;
    do
    {
      if ( *v21-- )
        break;
      --v20;
    }
    while ( v20 > 0 );
    r->top = v20;
    return 1;
  }
  if ( r == a )
    return 1;
  return BN_copy(r, a) != 0;
}
