int __cdecl BN_MONT_CTX_set(bn_mont_ctx_st *mont, const bignum_st *mod, bignum_ctx *ctx)
{
  bignum_pool_item *v3; // esi
  bignum_st *p_RR; // ebx
  unsigned int *d; // eax
  bignum_st *v6; // eax
  unsigned int *v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // eax
  int v11; // [esp+4h] [ebp-24h]
  unsigned int v12; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int v13; // [esp+10h] [ebp-18h]
  bignum_st a; // [esp+14h] [ebp-14h] BYREF

  v11 = 0;
  BN_CTX_start(ctx);
  v3 = BN_CTX_get(ctx);
  if ( v3 )
  {
    p_RR = &mont->RR;
    if ( BN_copy(&mont->N, mod) )
    {
      mont->N.neg = 0;
      BN_init(&a);
      a.d = &v12;
      a.dmax = 2;
      a.neg = 0;
      mont->ri = 32 * ((BN_num_bits(mod) + 31) / 32);
      BN_set_word(p_RR, 0);
      if ( BN_set_bit(p_RR, 64) )
      {
        d = mod->d;
        v12 = *mod->d;
        a.top = v12 != 0;
        if ( mod->top <= 1 )
        {
          v13 = 0;
        }
        else
        {
          v13 = d[1];
          if ( v13 )
            a.top = 2;
        }
        if ( BN_mod_inverse(v3->vals, p_RR, &a, ctx) && BN_lshift(v3->vals, v3->vals, 64) )
        {
          if ( v3->vals[0].top )
          {
            if ( !BN_sub_word(v3->vals, 1u) )
              goto err_155;
          }
          else
          {
            if ( v3->vals[0].dmax < 1 )
              v6 = bn_expand2(v3->vals, (unsigned int *)1);
            else
              v6 = (bignum_st *)v3;
            if ( !v6 )
              goto err_155;
            v7 = v3->vals[0].d;
            v3->vals[0].neg = 0;
            *v7 = -1;
            v3->vals[0].d[1] = -1;
            v3->vals[0].top = 2;
          }
          if ( BN_div(v3->vals, 0, v3->vals, &a, ctx) )
          {
            if ( v3->vals[0].top <= 0 )
              v8 = 0;
            else
              v8 = *v3->vals[0].d;
            mont->n0[0] = v8;
            if ( v3->vals[0].top <= 1 )
              v9 = 0;
            else
              v9 = v3->vals[0].d[1];
            mont->n0[1] = v9;
            BN_set_word(p_RR, 0);
            if ( BN_set_bit(p_RR, 2 * mont->ri) && BN_div(0, p_RR, p_RR, &mont->N, ctx) )
              v11 = 1;
          }
        }
      }
    }
  }
err_155:
  BN_CTX_end(ctx);
  return v11;
}
