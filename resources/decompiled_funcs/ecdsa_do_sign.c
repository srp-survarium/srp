ECDSA_SIG_st *__usercall ecdsa_do_sign@<eax>(
        unsigned int a1@<edi>,
        unsigned __int8 *dgst,
        int dgst_len,
        bignum_pool_item *in_kinv,
        const bignum_st *in_r,
        ec_key_st *eckey)
{
  bignum_st *v6; // ebx
  ecdsa_data_st *v7; // edi
  const ec_group_st *v8; // esi
  bignum_st *v9; // eax
  ECDSA_SIG_st *v10; // eax
  bignum_ctx *v11; // ebp
  int v12; // eax
  int v13; // edi
  int v14; // esi
  bignum_pool_item *v15; // esi
  bignum_pool_item *v16; // edi
  int v18; // [esp-4h] [ebp-2Ch]
  ECDSA_SIG_st *rp; // [esp+10h] [ebp-18h]
  bignum_st *ret; // [esp+14h] [ebp-14h]
  bignum_st *r; // [esp+18h] [ebp-10h]
  bignum_st *kinvp; // [esp+1Ch] [ebp-Ch] BYREF
  bignum_st *a; // [esp+20h] [ebp-8h]
  bignum_st *s; // [esp+24h] [ebp-4h]

  v6 = 0;
  kinvp = 0;
  ret = 0;
  r = 0;
  v7 = ecdsa_check(a1, eckey);
  v8 = (const ec_group_st *)EVP_CIPHER_block_size((const env_md_st *)eckey);
  v9 = (bignum_st *)EC_KEY_get0_private_key((const ssl_st *)eckey);
  a = v9;
  if ( !v8 || !v9 || !v7 )
  {
    ERR_put_error(0x2Au, 101, 67, ".\\crypto\\ecdsa\\ecs_ossl.c", 238);
    return 0;
  }
  v10 = ECDSA_SIG_new();
  rp = v10;
  if ( !v10 )
  {
    ERR_put_error(0x2Au, 101, 65, ".\\crypto\\ecdsa\\ecs_ossl.c", 245);
    return 0;
  }
  s = v10->s;
  v11 = BN_CTX_new();
  if ( v11 && (v6 = BN_new()) != 0 && (r = BN_new()) != 0 && (ret = BN_new()) != 0 )
  {
    if ( EC_GROUP_get_order(v8, v6) )
    {
      v12 = BN_num_bits(v6);
      v13 = dgst_len;
      v14 = v12;
      if ( 8 * dgst_len > v12 )
        v13 = (v12 + 7) / 8;
      if ( BN_bin2bn(dgst, v13, ret) )
      {
        if ( 8 * v13 <= v14 || BN_rshift(ret, ret, 8 - (v14 & 7)) )
        {
          while ( 1 )
          {
            v15 = in_kinv;
            if ( in_kinv && in_r )
            {
              if ( !BN_copy(rp->r, in_r) )
              {
                v18 = 295;
                goto LABEL_37;
              }
            }
            else
            {
              if ( !ECDSA_sign_setup(eckey, v11, &kinvp, &rp->r) )
              {
                ERR_put_error(0x2Au, 101, 42, ".\\crypto\\ecdsa\\ecs_ossl.c", 285);
                goto LABEL_38;
              }
              v15 = (bignum_pool_item *)kinvp;
            }
            if ( !BN_mod_mul(r, (bignum_pool_item *)a, (bignum_pool_item *)rp->r, v6, v11) )
            {
              ERR_put_error(0x2Au, 101, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 302);
              goto LABEL_38;
            }
            v16 = (bignum_pool_item *)s;
            if ( !BN_mod_add_quick(s, r, ret, v6) )
            {
              ERR_put_error(0x2Au, 101, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 307);
              goto LABEL_38;
            }
            if ( !BN_mod_mul(v16->vals, v16, v15, v6, v11) )
              break;
            if ( v16->vals[0].top )
              goto LABEL_39;
            if ( in_kinv && in_r )
            {
              ERR_put_error(0x2Au, 101, 106, ".\\crypto\\ecdsa\\ecs_ossl.c", 321);
              goto LABEL_38;
            }
          }
          ERR_put_error(0x2Au, 101, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 312);
        }
        else
        {
          ERR_put_error(0x2Au, 101, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 276);
        }
      }
      else
      {
        ERR_put_error(0x2Au, 101, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 270);
      }
    }
    else
    {
      ERR_put_error(0x2Au, 101, 16, ".\\crypto\\ecdsa\\ecs_ossl.c", 259);
    }
  }
  else
  {
    v18 = 253;
LABEL_37:
    ERR_put_error(0x2Au, 101, 65, ".\\crypto\\ecdsa\\ecs_ossl.c", v18);
  }
LABEL_38:
  ECDSA_SIG_free(rp);
  rp = 0;
LABEL_39:
  if ( v11 )
    BN_CTX_free(v11);
  if ( ret )
    BN_clear_free(ret);
  if ( r )
    BN_clear_free(r);
  if ( v6 )
    BN_free(v6);
  if ( kinvp )
    BN_clear_free(kinvp);
  return rp;
}
