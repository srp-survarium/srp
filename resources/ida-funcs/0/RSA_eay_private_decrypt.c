int __cdecl RSA_eay_private_decrypt(int flen, unsigned __int8 *from, unsigned __int8 *to, rsa_st *rsa, int padding)
{
  bignum_ctx *v5; // eax
  bignum_ctx *v6; // edi
  bignum_pool_item *v7; // ebx
  int v8; // ebp
  unsigned __int8 *v9; // eax
  bn_blinding_st *blinding; // eax
  int flags; // ecx
  bignum_st *d; // eax
  bignum_st *v13; // esi
  unsigned __int8 *v14; // ebx
  int v15; // eax
  int v16; // eax
  unsigned __int8 *v17; // esi
  int v19; // [esp-8h] [ebp-40h]
  int v20; // [esp+Ch] [ebp-2Ch]
  bignum_pool_item *n; // [esp+10h] [ebp-28h]
  bn_blinding_st *b; // [esp+14h] [ebp-24h]
  bignum_pool_item *r; // [esp+18h] [ebp-20h]
  int local; // [esp+1Ch] [ebp-1Ch] BYREF
  unsigned __int8 *toa; // [esp+20h] [ebp-18h]
  _DWORD v26[4]; // [esp+24h] [ebp-14h] BYREF
  unsigned int v27; // [esp+34h] [ebp-4h]

  v20 = -1;
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
  v9 = (unsigned __int8 *)CRYPTO_malloc(v8, ".\\crypto\\rsa\\rsa_eay.c", 512);
  toa = v9;
  if ( !v7 || !n || !v9 )
  {
    v19 = 515;
    goto LABEL_44;
  }
  if ( flen <= v8 )
  {
    if ( !BN_bin2bn(from, flen, v7->vals) )
      goto err_109;
    if ( BN_ucmp(v7->vals, rsa->n) >= 0 )
    {
      ERR_put_error((int)v7, 4u, 101, 132, ".\\crypto\\rsa\\rsa_eay.c", 532);
      goto err_109;
    }
    if ( SLOBYTE(rsa->flags) >= 0 )
    {
      blinding = rsa_get_blinding(rsa, (int)v7, &local, v6);
      b = blinding;
      if ( !blinding )
      {
        ERR_put_error((int)v7, 4u, 101, 68, ".\\crypto\\rsa\\rsa_eay.c", 541);
        goto err_109;
      }
      if ( !local )
      {
        r = BN_CTX_get(v6);
        if ( !r )
        {
          v19 = 550;
LABEL_44:
          ERR_put_error((int)v7, 4u, 101, 65, ".\\crypto\\rsa\\rsa_eay.c", v19);
          goto err_109;
        }
        blinding = b;
      }
      if ( !rsa_blinding_convert(v7->vals, r->vals, v6, blinding) )
        goto err_109;
    }
    flags = rsa->flags;
    if ( (flags & 0x20) != 0 || rsa->p && rsa->q && rsa->dmp1 && rsa->dmq1 && rsa->iqmp )
    {
      if ( !rsa->meth->rsa_mod_exp((bignum_st *)n, (const bignum_st *)v7, rsa, v6) )
        goto err_109;
      v13 = (bignum_st *)n;
    }
    else
    {
      d = rsa->d;
      if ( (flags & 0x100) != 0 )
      {
        local = (int)rsa->d;
      }
      else
      {
        local = (int)v26;
        v26[0] = d->d;
        v26[1] = d->top;
        v26[2] = d->dmax;
        v26[3] = d->neg;
        v27 = v27 & 1 | d->flags & 0xFFFFFFFE | 6;
      }
      if ( (flags & 2) != 0 && !BN_MONT_CTX_set_locked((int)v6, &rsa->_method_mod_n, 9, rsa->n, v6) )
        goto err_109;
      v13 = (bignum_st *)n;
      if ( !rsa->meth->bn_mod_exp(
              (bignum_st *)n,
              (const bignum_st *)v7,
              (const bignum_st *)local,
              rsa->n,
              v6,
              rsa->_method_mod_n) )
        goto err_109;
    }
    if ( !b || BN_BLINDING_invert_ex(v13, r->vals, b, v6) )
    {
      v14 = toa;
      v15 = BN_bn2bin(v13, toa);
      switch ( padding )
      {
        case 1:
          v16 = RSA_padding_check_PKCS1_type_2(to, v8, v14, v15, v8);
          goto LABEL_40;
        case 2:
          v16 = RSA_padding_check_SSLv23(to, v8, v14, v15, v8);
          goto LABEL_40;
        case 3:
          v16 = RSA_padding_check_none(to, v8, v14, v15);
          goto LABEL_40;
        case 4:
          v16 = RSA_padding_check_PKCS1_OAEP(to, v8, v14, v15, v8, 0, 0);
LABEL_40:
          v20 = v16;
          if ( v16 < 0 )
            ERR_put_error((int)v14, 4u, 101, 114, ".\\crypto\\rsa\\rsa_eay.c", 616);
          break;
        default:
          ERR_put_error((int)v14, 4u, 101, 118, ".\\crypto\\rsa\\rsa_eay.c", 612);
          break;
      }
    }
    goto err_109;
  }
  ERR_put_error((int)v7, 4u, 101, 108, ".\\crypto\\rsa\\rsa_eay.c", 523);
err_109:
  BN_CTX_end(v6);
  BN_CTX_free(v6);
  v17 = toa;
  if ( toa )
  {
    OPENSSL_cleanse(toa, v8);
    CRYPTO_free(v17);
  }
  return v20;
}
