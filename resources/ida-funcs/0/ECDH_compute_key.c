int __usercall ecdh_compute_key@<eax>(
        int a1@<ebx>,
        unsigned __int8 *out,
        unsigned int outlen,
        bignum_st *pub_key,
        ssl_st *ecdh,
        void *(__cdecl *KDF)(const void *, unsigned int, void *, unsigned int *))
{
  bignum_ctx *v7; // eax
  bignum_ctx *v8; // ebp
  bignum_pool_item *v9; // edi
  bignum_pool_item *v10; // eax
  const env_md_st *v11; // esi
  const ec_group_st *v12; // esi
  ec_point_st *v13; // ebx
  const ssl_st *v14; // eax
  unsigned int v15; // esi
  unsigned int v16; // edi
  unsigned __int8 *v17; // ebx
  unsigned int v18; // edi
  __m128i *src; // [esp+0h] [ebp-18h]
  ec_point_st *v20; // [esp+4h] [ebp-14h]
  unsigned int v21; // [esp+8h] [ebp-10h]
  bignum_st *y; // [esp+Ch] [ebp-Ch]
  bignum_st *v23; // [esp+10h] [ebp-8h]
  bignum_st *a; // [esp+14h] [ebp-4h]

  v21 = -1;
  src = 0;
  if ( outlen > 0x7FFFFFFF )
  {
    ERR_put_error(a1, 0x2Bu, 100, 65, ".\\crypto\\ecdh\\ech_ossl.c", 123);
    return -1;
  }
  v7 = BN_CTX_new(a1);
  v8 = v7;
  if ( v7 )
  {
    BN_CTX_start(a1, v7);
    v9 = BN_CTX_get(a1, v8);
    a = (bignum_st *)v9;
    v10 = BN_CTX_get(a1, v8);
    v11 = (const env_md_st *)ecdh;
    y = (bignum_st *)v10;
    v23 = (bignum_st *)EC_KEY_get0_private_key(ecdh);
    if ( !v23 )
    {
      ERR_put_error(a1, 0x2Bu, 100, 100, ".\\crypto\\ecdh\\ech_ossl.c", 135);
LABEL_31:
      BN_CTX_end(v8);
      BN_CTX_free(v8);
      if ( src )
        CRYPTO_free(src);
      return v21;
    }
    v12 = (const ec_group_st *)EVP_CIPHER_block_size(v11);
    v13 = EC_POINT_new(a1, v12);
    v20 = v13;
    if ( !v13 )
    {
      ERR_put_error(0, 0x2Bu, 100, 65, ".\\crypto\\ecdh\\ech_ossl.c", 142);
      goto err_210;
    }
    if ( !EC_POINT_mul(v12, v13, 0, pub_key, v23, v8) )
    {
      ERR_put_error((int)v13, 0x2Bu, 100, 101, ".\\crypto\\ecdh\\ech_ossl.c", 148);
      goto err_210;
    }
    v14 = (const ssl_st *)EVP_CIPHER_CTX_cipher((const ssl_st *)v12);
    if ( EVP_CIPHER_CTX_cipher(v14) == 406 )
    {
      if ( !EC_POINT_get_affine_coordinates_GFp((int)v13, v12, v13, v9->vals, y, v8) )
      {
        ERR_put_error((int)v13, 0x2Bu, 100, 101, ".\\crypto\\ecdh\\ech_ossl.c", 156);
        goto err_210;
      }
    }
    else if ( !EC_POINT_get_affine_coordinates_GF2m((int)v13, v12, v13, v9->vals, y, v8) )
    {
      ERR_put_error((int)v13, 0x2Bu, 100, 101, ".\\crypto\\ecdh\\ech_ossl.c", 164);
err_210:
      if ( v13 )
        EC_POINT_free(v13);
      goto LABEL_31;
    }
    v15 = (EC_GROUP_get_degree((int)v13, v12) + 7) / 8;
    v16 = (BN_num_bits(v9->vals) + 7) / 8;
    if ( v16 <= v15 )
    {
      src = (__m128i *)CRYPTO_malloc(v15, ".\\crypto\\ecdh\\ech_ossl.c", 176);
      if ( src )
      {
        memset((int)src, 0, v15 - v16);
        v17 = &src->m128i_u8[v15 - v16];
        if ( v16 == BN_bn2bin(a, v17) )
        {
          if ( KDF )
          {
            if ( (int)KDF(src, v15, out, &outlen) )
              v21 = outlen;
            else
              ERR_put_error((int)v17, 0x2Bu, 100, 102, ".\\crypto\\ecdh\\ech_ossl.c", 193);
          }
          else
          {
            v18 = outlen;
            if ( outlen > v15 )
            {
              v18 = v15;
              outlen = v15;
            }
            memcpy((int)out, src, v18);
            v21 = v18;
          }
        }
        else
        {
          ERR_put_error((int)v17, 0x2Bu, 100, 3, ".\\crypto\\ecdh\\ech_ossl.c", 185);
        }
        v13 = v20;
      }
      else
      {
        ERR_put_error((int)v13, 0x2Bu, 100, 65, ".\\crypto\\ecdh\\ech_ossl.c", 178);
      }
    }
    else
    {
      ERR_put_error((int)v13, 0x2Bu, 100, 68, ".\\crypto\\ecdh\\ech_ossl.c", 173);
    }
    goto err_210;
  }
  return v21;
}
