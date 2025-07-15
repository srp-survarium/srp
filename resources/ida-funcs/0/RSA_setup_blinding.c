bignum_ctx *__cdecl RSA_setup_blinding(rsa_st *rsa, bignum_ctx *in_ctx)
{
  bignum_ctx *v2; // esi
  bn_blinding_st *v3; // ebp
  bignum_ctx *result; // eax
  bignum_pool_item *e; // ebx
  bignum_st *d; // eax
  void *v7; // esp
  bignum_st *v8; // eax
  bignum_st *n; // ecx
  bn_blinding_st *param; // eax
  crypto_threadid_st *v11; // eax
  bignum_st m; // [esp+18h] [ebp-14h] BYREF

  v2 = in_ctx;
  v3 = 0;
  if ( in_ctx || (result = BN_CTX_new(), (v2 = result) != 0) )
  {
    BN_CTX_start(v2);
    e = BN_CTX_get(v2);
    if ( e )
    {
      e = (bignum_pool_item *)rsa->e;
      if ( e || (e = (bignum_pool_item *)rsa_get_public_exp(v2, rsa->d, rsa->p, rsa->q)) != 0 )
      {
        if ( !RAND_status((int)rsa) )
        {
          d = rsa->d;
          if ( d )
          {
            if ( d->d )
            {
              v7 = alloca(8);
              RAND_add((int)rsa, rsa->d->d, 4 * rsa->d->dmax, 0.0);
            }
          }
        }
        if ( (rsa->flags & 0x100) != 0 )
        {
          n = rsa->n;
        }
        else
        {
          v8 = rsa->n;
          m.d = v8->d;
          m.top = v8->top;
          m.dmax = v8->dmax;
          m.neg = v8->neg;
          n = &m;
          m.flags = m.flags & 1 | v8->flags & 0xFFFFFFFE | 6;
        }
        param = BN_BLINDING_create_param(0, e->vals, n, v2, rsa->meth->bn_mod_exp, rsa->_method_mod_n);
        v3 = param;
        if ( param )
        {
          v11 = BN_BLINDING_thread_id(param);
          CRYPTO_THREADID_current(v11);
        }
        else
        {
          ERR_put_error((int)e, 4u, 136, 3, ".\\crypto\\rsa\\rsa_lib.c", 426);
        }
      }
      else
      {
        ERR_put_error(0, 4u, 136, 140, ".\\crypto\\rsa\\rsa_lib.c", 398);
      }
    }
    else
    {
      ERR_put_error(0, 4u, 136, 65, ".\\crypto\\rsa\\rsa_lib.c", 389);
    }
    BN_CTX_end(v2);
    if ( !in_ctx )
      BN_CTX_free(v2);
    if ( !rsa->e )
      BN_free(e->vals);
    return (bignum_ctx *)v3;
  }
  return result;
}
