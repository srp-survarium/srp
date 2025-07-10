int __usercall dsa_builtin_keygen@<eax>(dsa_st *dsa@<edi>)
{
  bignum_ctx *v1; // ebp
  bignum_st *priv_key; // esi
  bignum_st *pub_key; // ebx
  int top; // ecx
  int dmax; // edx
  int neg; // ecx
  int flags; // edx
  bignum_st *p_a; // eax
  int v10; // [esp+8h] [ebp-18h]
  bignum_st a; // [esp+Ch] [ebp-14h] BYREF

  v10 = 0;
  v1 = BN_CTX_new();
  if ( !v1 )
    return 0;
  priv_key = dsa->priv_key;
  if ( priv_key || (priv_key = BN_new()) != 0 )
  {
    while ( BN_rand_range(priv_key, dsa->q) )
    {
      if ( priv_key->top )
      {
        pub_key = dsa->pub_key;
        if ( pub_key || (pub_key = BN_new()) != 0 )
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
          if ( BN_mod_exp(pub_key, dsa->g, p_a, dsa->p, v1) )
          {
            dsa->priv_key = priv_key;
            dsa->pub_key = pub_key;
            v10 = 1;
          }
          if ( pub_key && !dsa->pub_key )
            BN_free(pub_key);
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
  BN_CTX_free(v1);
  return v10;
}
