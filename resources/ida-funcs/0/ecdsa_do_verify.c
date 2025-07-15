int __usercall ecdsa_do_verify@<eax>(
        const ec_group_st *a1@<ebx>,
        unsigned __int8 *dgst,
        int dgst_len,
        const ECDSA_SIG_st *sig,
        const env_md_st *eckey)
{
  bignum_ctx *v5; // eax
  bignum_ctx *v6; // esi
  bignum_pool_item *v7; // ebp
  bignum_st *v8; // eax
  bignum_st *s; // eax
  int v10; // eax
  int v11; // ebx
  int v12; // edi
  ec_point_st *v13; // edi
  const ssl_st *v14; // eax
  bignum_pool_item *in; // [esp+Ch] [ebp-1Ch]
  bignum_pool_item *x; // [esp+10h] [ebp-18h]
  bignum_pool_item *r; // [esp+14h] [ebp-14h]
  int v19; // [esp+18h] [ebp-10h]
  ec_point_st *point; // [esp+1Ch] [ebp-Ch]
  ec_group_st *group; // [esp+20h] [ebp-8h]
  bignum_st *v22; // [esp+24h] [ebp-4h]
  bignum_pool_item *md; // [esp+38h] [ebp+10h]

  v19 = -1;
  point = 0;
  if ( !eckey
    || (a1 = (const ec_group_st *)EVP_CIPHER_block_size(eckey), (group = (ec_group_st *)a1) == 0)
    || (v22 = (bignum_st *)EC_KEY_get0_public_key((const engine_st *)eckey)) == 0
    || !sig )
  {
    ERR_put_error((int)a1, 0x2Au, 102, 103, ".\\crypto\\ecdsa\\ecs_ossl.c", 365);
    return -1;
  }
  v5 = BN_CTX_new((int)a1);
  v6 = v5;
  if ( !v5 )
  {
    ERR_put_error((int)a1, 0x2Au, 102, 65, ".\\crypto\\ecdsa\\ecs_ossl.c", 372);
    return -1;
  }
  BN_CTX_start((int)a1, v5);
  v7 = BN_CTX_get((int)a1, v6);
  r = BN_CTX_get((int)a1, v6);
  in = BN_CTX_get((int)a1, v6);
  md = BN_CTX_get((int)a1, v6);
  x = BN_CTX_get((int)a1, v6);
  if ( !x )
  {
    ERR_put_error((int)a1, 0x2Au, 102, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 383);
    goto err_186;
  }
  if ( EC_GROUP_get_order(a1, v7->vals) )
  {
    v8 = sig->r;
    if ( !sig->r->top
      || v8->neg
      || BN_ucmp(v8, v7->vals) >= 0
      || (s = sig->s, !s->top)
      || s->neg
      || BN_ucmp(s, v7->vals) >= 0 )
    {
      ERR_put_error((int)a1, 0x2Au, 102, 100, ".\\crypto\\ecdsa\\ecs_ossl.c", 397);
      v19 = 0;
      goto err_186;
    }
    if ( BN_mod_inverse((int)a1, in->vals, sig->s, v7->vals, v6) )
    {
      v10 = BN_num_bits(v7->vals);
      v11 = dgst_len;
      v12 = v10;
      if ( 8 * dgst_len > v10 )
        v11 = (v10 + 7) / 8;
      if ( BN_bin2bn(dgst, v11, md->vals) )
      {
        if ( 8 * v11 <= v12 || BN_rshift(md->vals, md->vals, 8 - (v12 & 7)) )
        {
          if ( BN_mod_mul(r->vals, md, in, v7->vals, v6) )
          {
            if ( BN_mod_mul(in->vals, (bignum_pool_item *)sig->r, in, v7->vals, v6) )
            {
              v13 = EC_POINT_new((int)group, group);
              point = v13;
              if ( v13 )
              {
                if ( EC_POINT_mul(group, v13, r->vals, v22, in->vals, v6) )
                {
                  v14 = (const ssl_st *)EVP_CIPHER_CTX_cipher((const ssl_st *)group);
                  if ( EVP_CIPHER_CTX_cipher(v14) == 406 )
                  {
                    if ( !EC_POINT_get_affine_coordinates_GFp((int)group, group, v13, x->vals, 0, v6) )
                    {
                      ERR_put_error((int)group, 0x2Au, 102, 16, ".\\crypto\\ecdsa\\ecs_ossl.c", 453);
                      goto err_186;
                    }
                  }
                  else if ( !EC_POINT_get_affine_coordinates_GF2m((int)group, group, v13, x->vals, 0, v6) )
                  {
                    ERR_put_error((int)group, 0x2Au, 102, 16, ".\\crypto\\ecdsa\\ecs_ossl.c", 462);
                    goto err_186;
                  }
                  if ( BN_nnmod((int)group, r->vals, x->vals, v7->vals, v6) )
                    v19 = BN_ucmp(r->vals, sig->r) == 0;
                  else
                    ERR_put_error((int)group, 0x2Au, 102, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 469);
                }
                else
                {
                  ERR_put_error((int)group, 0x2Au, 102, 16, ".\\crypto\\ecdsa\\ecs_ossl.c", 445);
                }
              }
              else
              {
                ERR_put_error((int)group, 0x2Au, 102, 65, ".\\crypto\\ecdsa\\ecs_ossl.c", 440);
              }
            }
            else
            {
              ERR_put_error((int)md, 0x2Au, 102, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 434);
            }
          }
          else
          {
            ERR_put_error((int)md, 0x2Au, 102, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 428);
          }
        }
        else
        {
          ERR_put_error((int)md, 0x2Au, 102, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 422);
        }
      }
      else
      {
        ERR_put_error(v11, 0x2Au, 102, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 416);
      }
    }
    else
    {
      ERR_put_error((int)a1, 0x2Au, 102, 3, ".\\crypto\\ecdsa\\ecs_ossl.c", 404);
    }
  }
  else
  {
    ERR_put_error((int)a1, 0x2Au, 102, 16, ".\\crypto\\ecdsa\\ecs_ossl.c", 389);
  }
err_186:
  BN_CTX_end(v6);
  BN_CTX_free(v6);
  if ( point )
    EC_POINT_free(point);
  return v19;
}
