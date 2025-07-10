int __cdecl ecdh_compute_key(
        unsigned __int8 *out,
        unsigned int outlen,
        bignum_st *pub_key,
        ssl_st *ecdh,
        void *(__cdecl *KDF)(const void *, unsigned int, void *, unsigned int *))
{
  bignum_ctx *v6; // eax
  bignum_ctx *v7; // ebp
  bignum_pool_item *v8; // edi
  bignum_pool_item *v9; // eax
  const env_md_st *v10; // esi
  const ec_group_st *v11; // esi
  ec_point_st *v12; // ebx
  const ssl_st *v13; // eax
  unsigned int v14; // esi
  unsigned int v15; // edi
  unsigned int v16; // edi
  unsigned __int8 *dst; // [esp+0h] [ebp-18h]
  unsigned int v18; // [esp+8h] [ebp-10h]
  bignum_st *y; // [esp+Ch] [ebp-Ch]
  bignum_st *p_scalar; // [esp+10h] [ebp-8h]
  bignum_st *a; // [esp+14h] [ebp-4h]

  v18 = -1;
  dst = 0;
  if ( outlen > 0x7FFFFFFF )
  {
    ERR_put_error(0x2Bu, 100, 65, ".\\crypto\\ecdh\\ech_ossl.c", 123);
    return -1;
  }
  v6 = BN_CTX_new();
  v7 = v6;
  if ( v6 )
  {
    BN_CTX_start(v6);
    v8 = BN_CTX_get(v7);
    a = (bignum_st *)v8;
    v9 = BN_CTX_get(v7);
    v10 = (const env_md_st *)ecdh;
    y = (bignum_st *)v9;
    p_scalar = (bignum_st *)EC_KEY_get0_private_key(ecdh);
    if ( !p_scalar )
    {
      ERR_put_error(0x2Bu, 100, 100, ".\\crypto\\ecdh\\ech_ossl.c", 135);
LABEL_30:
      BN_CTX_end(v7);
      BN_CTX_free(v7);
      if ( dst )
        CRYPTO_free(dst);
      return v18;
    }
    v11 = (const ec_group_st *)EVP_CIPHER_block_size(v10);
    v12 = EC_POINT_new(v11);
    if ( !v12 )
    {
      ERR_put_error(0x2Bu, 100, 65, ".\\crypto\\ecdh\\ech_ossl.c", 142);
      goto err_208;
    }
    if ( !EC_POINT_mul(v11, v12, 0, pub_key, (const ec_point_st *)p_scalar, v7) )
    {
      ERR_put_error(0x2Bu, 100, 101, ".\\crypto\\ecdh\\ech_ossl.c", 148);
      goto err_208;
    }
    v13 = (const ssl_st *)EVP_CIPHER_CTX_cipher((const ssl_st *)v11);
    if ( EVP_CIPHER_CTX_cipher(v13) == 406 )
    {
      if ( !EC_POINT_get_affine_coordinates_GFp(v11, v12, v8->vals, y, v7) )
      {
        ERR_put_error(0x2Bu, 100, 101, ".\\crypto\\ecdh\\ech_ossl.c", 156);
        goto err_208;
      }
    }
    else if ( !EC_POINT_get_affine_coordinates_GF2m(v11, v12, v8->vals, y, v7) )
    {
      ERR_put_error(0x2Bu, 100, 101, ".\\crypto\\ecdh\\ech_ossl.c", 164);
err_208:
      if ( v12 )
        EC_POINT_free(v12);
      goto LABEL_30;
    }
    v14 = (EC_GROUP_get_degree(v11) + 7) / 8;
    v15 = (BN_num_bits(v8->vals) + 7) / 8;
    if ( v15 <= v14 )
    {
      dst = (unsigned __int8 *)CRYPTO_malloc(v14, ".\\crypto\\ecdh\\ech_ossl.c", 176);
      if ( dst )
      {
        memset((int)dst, 0, v14 - v15);
        if ( v15 == BN_bn2bin(a, &dst[v14 - v15]) )
        {
          if ( KDF )
          {
            if ( (int)KDF(dst, v14, out, &outlen) )
              v18 = outlen;
            else
              ERR_put_error(0x2Bu, 100, 102, ".\\crypto\\ecdh\\ech_ossl.c", 193);
          }
          else
          {
            v16 = outlen;
            if ( outlen > v14 )
            {
              v16 = v14;
              outlen = v14;
            }
            memcpy(out, dst, v16);
            v18 = v16;
          }
        }
        else
        {
          ERR_put_error(0x2Bu, 100, 3, ".\\crypto\\ecdh\\ech_ossl.c", 185);
        }
      }
      else
      {
        ERR_put_error(0x2Bu, 100, 65, ".\\crypto\\ecdh\\ech_ossl.c", 178);
      }
    }
    else
    {
      ERR_put_error(0x2Bu, 100, 68, ".\\crypto\\ecdh\\ech_ossl.c", 173);
    }
    goto err_208;
  }
  return v18;
}
