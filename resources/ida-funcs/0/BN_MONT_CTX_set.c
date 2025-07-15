int __usercall BN_MONT_CTX_set@<eax>(int a1@<ebx>, bn_mont_ctx_st *mont, const bignum_st *mod, bignum_ctx *ctx)
{
  bignum_pool_item *v4; // esi
  bignum_st *p_RR; // ebx
  unsigned int *d; // eax
  bignum_st *v7; // eax
  unsigned int *v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // eax
  int v12; // [esp+4h] [ebp-24h]
  unsigned int v13; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int v14; // [esp+10h] [ebp-18h]
  bignum_st a; // [esp+14h] [ebp-14h] BYREF

  v12 = 0;
  BN_CTX_start(a1, ctx);
  v4 = BN_CTX_get(a1, ctx);
  if ( v4 )
  {
    p_RR = &mont->RR;
    if ( BN_copy(&mont->N, mod) )
    {
      mont->N.neg = 0;
      BN_init(&a);
      a.d = &v13;
      a.dmax = 2;
      a.neg = 0;
      mont->ri = 32 * ((BN_num_bits(mod) + 31) / 32);
      BN_set_word((int)p_RR, p_RR, 0);
      if ( BN_set_bit(p_RR, 64) )
      {
        d = mod->d;
        v13 = *mod->d;
        a.top = v13 != 0;
        if ( mod->top <= 1 )
        {
          v14 = 0;
        }
        else
        {
          v14 = d[1];
          if ( v14 )
            a.top = 2;
        }
        if ( BN_mod_inverse((int)p_RR, v4->vals, p_RR, &a, ctx) && BN_lshift(v4->vals, v4->vals, 64) )
        {
          if ( v4->vals[0].top )
          {
            if ( !BN_sub_word((int)p_RR, v4->vals, 1u) )
              goto err_157;
          }
          else
          {
            if ( v4->vals[0].dmax < 1 )
              v7 = bn_expand2(v4->vals, 1);
            else
              v7 = (bignum_st *)v4;
            if ( !v7 )
              goto err_157;
            v8 = v4->vals[0].d;
            v4->vals[0].neg = 0;
            *v8 = -1;
            v4->vals[0].d[1] = -1;
            v4->vals[0].top = 2;
          }
          if ( BN_div(v4, 0, v4->vals, &a, ctx) )
          {
            if ( v4->vals[0].top <= 0 )
              v9 = 0;
            else
              v9 = *v4->vals[0].d;
            mont->n0[0] = v9;
            if ( v4->vals[0].top <= 1 )
              v10 = 0;
            else
              v10 = v4->vals[0].d[1];
            mont->n0[1] = v10;
            BN_set_word((int)p_RR, p_RR, 0);
            if ( BN_set_bit(p_RR, 2 * mont->ri) && BN_div(0, p_RR, p_RR, &mont->N, ctx) )
              v12 = 1;
          }
        }
      }
    }
  }
err_157:
  BN_CTX_end(ctx);
  return v12;
}
