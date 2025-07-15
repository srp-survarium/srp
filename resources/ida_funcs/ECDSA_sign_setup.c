int __cdecl ecdsa_sign_setup(const env_md_st *eckey, bignum_ctx *ctx_in, bignum_st **kinvp, bignum_st **rp)
{
  const ec_group_st *v4; // edi
  bignum_ctx *v5; // ebx
  bignum_st *v7; // esi
  bignum_st *v8; // ebp
  bignum_st *v9; // eax
  int v10; // ebp
  const ssl_st *v11; // eax
  int v12; // [esp-Ch] [ebp-24h]
  bignum_st *a; // [esp+8h] [ebp-10h]
  bignum_st *x; // [esp+Ch] [ebp-Ch]
  ec_point_st *r; // [esp+10h] [ebp-8h]
  int v16; // [esp+14h] [ebp-4h]
  const env_md_st *md; // [esp+1Ch] [ebp+4h]

  r = 0;
  v16 = 0;
  if ( !eckey || (v4 = (const ec_group_st *)EVP_CIPHER_block_size(eckey)) == 0 )
  {
    ERR_put_error(0x2Au, 103, 67, ".\\crypto\\ecdsa\\ecs_ossl.c", 100);
    return 0;
  }
  v5 = ctx_in;
  if ( !ctx_in )
  {
    v5 = BN_CTX_new();
    if ( !v5 )
    {
      ERR_put_error(0x2Au, 103, 65, ".\\crypto\\ecdsa\\ecs_ossl.c", 108);
      return 0;
    }
  }
  v7 = BN_new();
  a = BN_new();
  v8 = BN_new();
  md = (const env_md_st *)v8;
  v9 = BN_new();
  x = v9;
  if ( !v7 || !a || !v8 || !v9 )
  {
    ERR_put_error(0x2Au, 103, 65, ".\\crypto\\ecdsa\\ecs_ossl.c", 121);
    goto LABEL_32;
  }
  r = EC_POINT_new(v4);
  if ( !r )
  {
    ERR_put_error(0x2Au, 103, 16, ".\\crypto\\ecdsa\\ecs_ossl.c", 126);
    goto LABEL_32;
  }
  if ( !EC_GROUP_get_order(v4, v8) )
  {
    ERR_put_error(0x2Au, 103, 16, ".\\crypto\\ecdsa\\ecs_ossl.c", 131);
LABEL_32:
    if ( v7 )
      BN_clear_free(v7);
    if ( a )
      BN_clear_free(a);
    goto LABEL_36;
  }
  while ( 1 )
  {
    do
    {
      if ( !BN_rand_range(v7, v8) )
      {
        ERR_put_error(0x2Au, 103, 104, ".\\crypto\\ecdsa\\ecs_ossl.c", 142);
        goto LABEL_32;
      }
    }
    while ( !v7->top );
    if ( !BN_add(v7, v7, v8) )
      goto LABEL_32;
    v10 = BN_num_bits(v8);
    if ( BN_num_bits(v7) <= v10 && !BN_add(v7, v7, (const bignum_st *)md) )
      goto LABEL_31;
    if ( !EC_POINT_mul(v4, r, v7, 0, 0, v5) )
    {
      v12 = 158;
      goto LABEL_30;
    }
    v11 = (const ssl_st *)EVP_CIPHER_CTX_cipher((const ssl_st *)v4);
    if ( EVP_CIPHER_CTX_cipher(v11) == 406 )
    {
      if ( !EC_POINT_get_affine_coordinates_GFp(v4, r, x, 0, v5) )
      {
        v12 = 166;
LABEL_30:
        ERR_put_error(0x2Au, 103, 16, ".\\crypto\\ecdsa\\ecs_ossl.c", v12);
LABEL_31:
        v8 = (bignum_st *)md;
        goto LABEL_32;
      }
    }
    else if ( !EC_POINT_get_affine_coordinates_GF2m(v4, r, x, 0, v5) )
    {
      v12 = 175;
      goto LABEL_30;
    }
    if ( !BN_nnmod(a, x, (const bignum_st *)md, v5) )
    {
      ERR_put_error(0x2Au, 103, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 181);
      goto LABEL_31;
    }
    if ( a->top )
      break;
    v8 = (bignum_st *)md;
  }
  if ( !BN_mod_inverse(v7, v7, (const bignum_st *)md, v5) )
  {
    ERR_put_error(0x2Au, 103, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 190);
    goto LABEL_31;
  }
  if ( *rp )
    BN_clear_free(*rp);
  if ( *kinvp )
    BN_clear_free(*kinvp);
  *rp = a;
  v8 = (bignum_st *)md;
  *kinvp = v7;
  v16 = 1;
LABEL_36:
  if ( !ctx_in )
    BN_CTX_free(v5);
  if ( v8 )
    BN_free(v8);
  if ( r )
    EC_POINT_free(r);
  if ( x )
    BN_clear_free(x);
  return v16;
}
