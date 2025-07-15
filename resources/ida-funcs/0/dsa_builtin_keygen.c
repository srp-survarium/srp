int __usercall dsa_builtin_keygen@<eax>(dsa_st *dsa@<edi>, int a2@<ebx>)
{
  bignum_ctx *v2; // ebp
  bignum_st *priv_key; // esi
  bignum_pool_item *pub_key; // ebx
  int top; // ecx
  int dmax; // edx
  int neg; // ecx
  int flags; // edx
  bignum_st *p_a; // eax
  int v11; // [esp+8h] [ebp-18h]
  bignum_st a; // [esp+Ch] [ebp-14h] BYREF

  v11 = 0;
  v2 = BN_CTX_new(a2);
  if ( !v2 )
    return 0;
  priv_key = dsa->priv_key;
  if ( priv_key || (priv_key = BN_new(a2)) != 0 )
  {
    while ( BN_rand_range(a2, priv_key, dsa->q) )
    {
      if ( priv_key->top )
      {
        pub_key = (bignum_pool_item *)dsa->pub_key;
        if ( pub_key || (pub_key = (bignum_pool_item *)BN_new(0)) != 0 )
        {
          if ( (dsa->flags & 2) != 0 )
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
          if ( BN_mod_exp((int)pub_key, pub_key, (bignum_pool_item *)dsa->g, p_a, dsa->p, v2) )
          {
            dsa->priv_key = priv_key;
            dsa->pub_key = (bignum_st *)pub_key;
            v11 = 1;
          }
          if ( pub_key && !dsa->pub_key )
            BN_free(pub_key->vals);
        }
        break;
      }
    }
    if ( priv_key )
    {
      if ( !dsa->priv_key )
        BN_free(priv_key);
    }
  }
  BN_CTX_free(v2);
  return v11;
}
