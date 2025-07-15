int __cdecl ec_GFp_simple_group_check_discriminant(bignum_st *group, bignum_ctx *ctx)
{
  bignum_ctx *v2; // esi
  bignum_pool_item *v4; // ebx
  bignum_pool_item *v5; // ebp
  int (__cdecl *v6)(bignum_st *, bignum_pool_item *, int *, bignum_ctx *); // eax
  bignum_pool_item *v7; // edi
  bool v8; // zf
  const bignum_st *v10; // [esp-8h] [ebp-20h]
  int v11; // [esp+Ch] [ebp-Ch]
  bignum_ctx *v12; // [esp+10h] [ebp-8h]
  bignum_st *m; // [esp+14h] [ebp-4h]
  bignum_pool_item *a; // [esp+1Ch] [ebp+4h]
  bignum_pool_item *ctxa; // [esp+20h] [ebp+8h]

  v2 = ctx;
  v11 = 0;
  m = (bignum_st *)((char *)group + 72);
  v12 = 0;
  if ( !ctx )
  {
    v12 = BN_CTX_new(0);
    v2 = v12;
    if ( !v12 )
    {
      ERR_put_error(0, 0x10u, 165, 65, ".\\crypto\\ec\\ecp_smpl.c", 292);
      goto LABEL_25;
    }
  }
  BN_CTX_start(0, v2);
  v4 = BN_CTX_get(0, v2);
  a = BN_CTX_get((int)v4, v2);
  ctxa = BN_CTX_get((int)v4, v2);
  v5 = BN_CTX_get((int)v4, v2);
  if ( BN_CTX_get((int)v4, v2) )
  {
    v6 = (int (__cdecl *)(bignum_st *, bignum_pool_item *, int *, bignum_ctx *))group->d[36];
    if ( v6 )
    {
      if ( !v6(group, v4, &group[5].flags, v2)
        || !(*((int (__cdecl **)(bignum_st *, bignum_pool_item *, int *, bignum_ctx *))group->d + 36))(
              group,
              a,
              &group[6].flags,
              v2) )
      {
        goto err_199;
      }
      v7 = a;
    }
    else
    {
      if ( !BN_copy(v4->vals, (bignum_st *)((char *)group + 116)) )
        goto err_199;
      v10 = (bignum_st *)((char *)group + 136);
      v7 = a;
      if ( !BN_copy(a->vals, v10) )
        goto err_199;
    }
    if ( !v4->vals[0].top )
    {
      v8 = v7->vals[0].top == 0;
      goto LABEL_21;
    }
    if ( !v7->vals[0].top )
    {
LABEL_22:
      v11 = 1;
      goto err_199;
    }
    if ( BN_mod_sqr((int)v4, ctxa, v4, m, v2)
      && BN_mod_mul(v5->vals, ctxa, v4, m, v2)
      && BN_lshift(ctxa->vals, v5->vals, 2)
      && BN_mod_sqr((int)v4, v5, a, m, v2)
      && BN_mul_word((int)v4, v5->vals, 0x1Bu)
      && BN_mod_add((int)v4, v4->vals, ctxa->vals, v5->vals, m, v2) )
    {
      v8 = v4->vals[0].top == 0;
LABEL_21:
      if ( v8 )
        goto err_199;
      goto LABEL_22;
    }
  }
err_199:
  if ( v2 )
    BN_CTX_end(v2);
LABEL_25:
  if ( v12 )
    BN_CTX_free(v12);
  return v11;
}
