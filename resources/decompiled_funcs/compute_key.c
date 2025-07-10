int __cdecl compute_key(unsigned __int8 *key, const bignum_st *pub_key, dh_st *dh)
{
  dh_st *v3; // esi
  bn_mont_ctx_st *v4; // ebx
  bignum_ctx *v6; // eax
  bignum_ctx *v7; // edi
  int v8; // [esp+Ch] [ebp-8h]
  bignum_pool_item *a; // [esp+10h] [ebp-4h]

  v3 = dh;
  v4 = 0;
  v8 = -1;
  if ( BN_num_bits(dh->p) <= 10000 )
  {
    v6 = BN_CTX_new();
    v7 = v6;
    if ( v6 )
    {
      BN_CTX_start(v6);
      a = BN_CTX_get(v7);
      if ( v3->priv_key )
      {
        if ( (v3->flags & 1) == 0 )
          goto LABEL_11;
        v4 = BN_MONT_CTX_set_locked(&v3->method_mont_p, 26, v3->p, v7);
        if ( (v3->flags & 2) == 0 )
          v3->priv_key->flags |= 4u;
        if ( v4 )
        {
LABEL_11:
          if ( !DH_check_pub_key(v3, pub_key, (int *)&dh) || dh )
          {
            ERR_put_error(5u, 102, 102, ".\\crypto\\dh\\dh_key.c", 214);
          }
          else if ( v3->meth->bn_mod_exp(v3, a->vals, pub_key, v3->priv_key, v3->p, v7, v4) )
          {
            v8 = BN_bn2bin(a->vals, key);
          }
          else
          {
            ERR_put_error(5u, 102, 3, ".\\crypto\\dh\\dh_key.c", 220);
          }
        }
      }
      else
      {
        ERR_put_error(5u, 102, 100, ".\\crypto\\dh\\dh_key.c", 195);
      }
      BN_CTX_end(v7);
      BN_CTX_free(v7);
      return v8;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    ERR_put_error(5u, 102, 103, ".\\crypto\\dh\\dh_key.c", 184);
    return -1;
  }
}
