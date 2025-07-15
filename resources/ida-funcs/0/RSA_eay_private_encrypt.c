int __cdecl RSA_eay_private_encrypt(int flen, unsigned __int8 *from, unsigned __int8 *to, rsa_st *rsa, int padding)
{
  bignum_ctx *v5; // eax
  bignum_ctx *v6; // edi
  bignum_pool_item *v7; // ebx
  int v8; // ebp
  unsigned __int8 *v9; // eax
  int v10; // eax
  bn_blinding_st *blinding; // eax
  int flags; // eax
  bignum_st *d; // eax
  const bignum_st *v14; // esi
  int v15; // eax
  int v16; // eax
  unsigned __int8 *v17; // esi
  int v19; // [esp-8h] [ebp-40h]
  bignum_pool_item *n; // [esp+Ch] [ebp-2Ch]
  bn_blinding_st *b; // [esp+10h] [ebp-28h]
  bignum_pool_item *r; // [esp+14h] [ebp-24h]
  int v23; // [esp+18h] [ebp-20h]
  int local; // [esp+1Ch] [ebp-1Ch] BYREF
  unsigned __int8 *s; // [esp+20h] [ebp-18h]
  bignum_st a; // [esp+24h] [ebp-14h] BYREF

  v23 = -1;
  local = 0;
  r = 0;
  b = 0;
  v5 = BN_CTX_new();
  v6 = v5;
  if ( !v5 )
    return -1;
  BN_CTX_start(v5);
  v7 = BN_CTX_get(v6);
  n = BN_CTX_get(v6);
  v8 = (BN_num_bits(rsa->n) + 7) / 8;
  v9 = (unsigned __int8 *)CRYPTO_malloc(v8, ".\\crypto\\rsa\\rsa_eay.c", 369);
  s = v9;
  if ( !v7 || !n || !v9 )
  {
    v19 = 372;
    goto LABEL_48;
  }
  switch ( padding )
  {
    case 1:
      v10 = RSA_padding_add_PKCS1_type_1(v9, v8, from, flen);
      break;
    case 3:
      v10 = RSA_padding_add_none(v9, v8, from, flen);
      break;
    case 5:
      v10 = RSA_padding_add_X931(v9, v8, from, flen);
      break;
    default:
      ERR_put_error((int)v7, 4u, 102, 118, ".\\crypto\\rsa\\rsa_eay.c", 389);
      goto err_108;
  }
  if ( v10 > 0 && BN_bin2bn(s, v8, v7->vals) )
  {
    if ( BN_ucmp(v7->vals, rsa->n) >= 0 )
    {
      ERR_put_error((int)v7, 4u, 102, 132, ".\\crypto\\rsa\\rsa_eay.c", 399);
      goto err_108;
    }
    if ( SLOBYTE(rsa->flags) >= 0 )
    {
      blinding = rsa_get_blinding(rsa, (int)v7, &local, v6);
      b = blinding;
      if ( !blinding )
      {
        ERR_put_error((int)v7, 4u, 102, 68, ".\\crypto\\rsa\\rsa_eay.c", 408);
        goto err_108;
      }
      if ( !local )
      {
        r = BN_CTX_get(v6);
        if ( !r )
        {
          v19 = 417;
LABEL_48:
          ERR_put_error((int)v7, 4u, 102, 65, ".\\crypto\\rsa\\rsa_eay.c", v19);
          goto err_108;
        }
        blinding = b;
      }
      if ( !rsa_blinding_convert(v7->vals, r->vals, v6, blinding) )
        goto err_108;
    }
    flags = rsa->flags;
    if ( (flags & 0x20) != 0 || rsa->p && rsa->q && rsa->dmp1 && rsa->dmq1 && rsa->iqmp )
    {
      if ( !rsa->meth->rsa_mod_exp((bignum_st *)n, (const bignum_st *)v7, rsa, v6) )
        goto err_108;
    }
    else
    {
      if ( (flags & 0x100) != 0 )
      {
        local = (int)rsa->d;
      }
      else
      {
        BN_init(&a);
        d = rsa->d;
        a.d = d->d;
        local = (int)&a;
        a.top = d->top;
        a.dmax = d->dmax;
        a.neg = d->neg;
        a.flags = a.flags & 1 | d->flags & 0xFFFFFFFE | 6;
      }
      if ( (rsa->flags & 2) != 0 && !BN_MONT_CTX_set_locked((int)v6, &rsa->_method_mod_n, 9, rsa->n, v6)
        || !rsa->meth->bn_mod_exp(
              (bignum_st *)n,
              (const bignum_st *)v7,
              (const bignum_st *)local,
              rsa->n,
              v6,
              rsa->_method_mod_n) )
      {
        goto err_108;
      }
    }
    if ( !b || BN_BLINDING_invert_ex(n->vals, r->vals, b, v6) )
    {
      if ( padding == 5 )
      {
        BN_sub(v7->vals, rsa->n, n->vals);
        v14 = (const bignum_st *)n;
        if ( BN_cmp(n->vals, v7->vals) )
          v14 = (const bignum_st *)v7;
      }
      else
      {
        v14 = (const bignum_st *)n;
      }
      v15 = BN_num_bits(v14);
      v16 = BN_bn2bin(v14, &to[v8 - (v15 + 7) / 8]);
      if ( v8 - v16 > 0 )
        memset((int)to, 0, v8 - v16);
      v23 = v8;
    }
  }
err_108:
  BN_CTX_end(v6);
  BN_CTX_free(v6);
  v17 = s;
  if ( s )
  {
    OPENSSL_cleanse(s, v8);
    CRYPTO_free(v17);
  }
  return v23;
}
