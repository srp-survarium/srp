int __cdecl generate_key(dh_st *dh)
{
  bignum_st *priv_key; // edi
  int v2; // ebp
  bignum_st *pub_key; // ebx
  int length; // eax
  int top; // ecx
  int dmax; // edx
  int neg; // ecx
  int flags; // edx
  bignum_st *p_a; // eax
  int v10; // ebp
  bignum_ctx *ctx; // [esp+10h] [ebp-20h]
  bn_mont_ctx_st *v13; // [esp+14h] [ebp-1Ch]
  bignum_st a; // [esp+1Ch] [ebp-14h] BYREF

  priv_key = 0;
  v2 = 0;
  v13 = 0;
  pub_key = 0;
  ctx = BN_CTX_new(0);
  if ( !ctx )
    goto LABEL_18;
  priv_key = dh->priv_key;
  if ( priv_key )
    goto LABEL_5;
  priv_key = BN_new(0);
  if ( !priv_key )
  {
LABEL_18:
    ERR_put_error((int)pub_key, 5u, 103, 3, ".\\crypto\\dh\\dh_key.c", 166);
    v10 = 0;
    goto LABEL_19;
  }
  v2 = 1;
LABEL_5:
  pub_key = dh->pub_key;
  if ( !pub_key )
  {
    pub_key = BN_new(0);
    if ( !pub_key )
      goto LABEL_18;
  }
  if ( (dh->flags & 1) != 0 )
  {
    v13 = BN_MONT_CTX_set_locked((int)priv_key, &dh->method_mont_p, 26, dh->p, ctx);
    if ( !v13 )
      goto LABEL_18;
  }
  if ( v2 )
  {
    length = dh->length;
    if ( !length )
      length = BN_num_bits(dh->p) - 1;
    if ( !BN_rand((int)pub_key, priv_key, length, 0, 0) )
      goto LABEL_18;
  }
  if ( (dh->flags & 2) != 0 )
  {
    p_a = priv_key;
  }
  else
  {
    BN_init(&a);
    top = priv_key->top;
    a.d = priv_key->d;
    dmax = priv_key->dmax;
    a.top = top;
    neg = priv_key->neg;
    a.dmax = dmax;
    flags = priv_key->flags;
    a.neg = neg;
    p_a = &a;
    a.flags = a.flags & 1 | flags & 0xFFFFFFFE | 6;
  }
  if ( !dh->meth->bn_mod_exp(dh, pub_key, dh->g, p_a, dh->p, ctx, v13) )
    goto LABEL_18;
  dh->pub_key = pub_key;
  dh->priv_key = priv_key;
  v10 = 1;
LABEL_19:
  if ( pub_key && !dh->pub_key )
    BN_free(pub_key);
  if ( priv_key && !dh->priv_key )
    BN_free(priv_key);
  BN_CTX_free(ctx);
  return v10;
}
