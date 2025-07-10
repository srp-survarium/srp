int __cdecl ec_GF2m_simple_set_compressed_coordinates(
        const ec_group_st *group,
        ec_point_st *point,
        const bignum_st *x_,
        int y_bit,
        bignum_ctx *ctx)
{
  bignum_ctx *v5; // esi
  bignum_pool_item *v7; // ebx
  bignum_pool_item *v8; // ebp
  int v9; // eax
  const bignum_st *v10; // ebx
  unsigned int error; // eax
  const bignum_st *v12; // [esp-14h] [ebp-28h]
  bignum_pool_item *r; // [esp+8h] [ebp-Ch]
  int ra; // [esp+8h] [ebp-Ch]
  bignum_ctx *v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]
  int v17; // [esp+24h] [ebp+10h]
  bignum_pool_item *ctxa; // [esp+28h] [ebp+14h]

  v15 = 0;
  v16 = 0;
  ERR_clear_error();
  v5 = ctx;
  if ( !ctx )
  {
    v15 = BN_CTX_new();
    v5 = v15;
    if ( !v15 )
      return 0;
  }
  v17 = y_bit != 0;
  BN_CTX_start(v5);
  v7 = BN_CTX_get(v5);
  v8 = BN_CTX_get(v5);
  ctxa = BN_CTX_get(v5);
  r = BN_CTX_get(v5);
  if ( r && BN_GF2m_mod_arr(v8->vals, x_, group->poly) )
  {
    if ( v8->vals[0].top )
    {
      if ( !group->meth->field_sqr(group, (bignum_st *)v7, (const bignum_st *)v8, v5)
        || !group->meth->field_div(group, (bignum_st *)v7, &group->b, (const bignum_st *)v7, v5)
        || !BN_GF2m_add(v7->vals, &group->a, v7->vals)
        || !BN_GF2m_add(v7->vals, v8->vals, v7->vals) )
      {
        goto err_129;
      }
      v12 = (const bignum_st *)v7;
      v10 = (const bignum_st *)r;
      if ( !BN_GF2m_mod_solve_quad_arr(r->vals, v12, group->poly, v5) )
      {
        error = ERR_peek_last_error();
        if ( (unsigned __int8 *)(error & 0xFF000000) == &vostok::memory::s_CRT_arena[39128632]
          && (error & 0xFFF) == 0x74 )
        {
          ERR_clear_error();
          ERR_put_error(0x10u, 164, 110, ".\\crypto\\ec\\ec2_smpl.c", 468);
        }
        else
        {
          ERR_put_error(0x10u, 164, 3, ".\\crypto\\ec\\ec2_smpl.c", 471);
        }
        goto err_129;
      }
      if ( r->vals[0].top <= 0 || (ra = 1, (*(_BYTE *)v10->d & 1) == 0) )
        ra = 0;
      if ( !group->meth->field_mul(group, (bignum_st *)ctxa, (const bignum_st *)v8, v10, v5) )
        goto err_129;
      if ( ra == v17 )
        goto LABEL_24;
      v9 = BN_GF2m_add(ctxa->vals, ctxa->vals, v8->vals);
    }
    else
    {
      v9 = BN_GF2m_mod_sqrt_arr(ctxa->vals, &group->b, group->poly, v5);
    }
    if ( v9 )
    {
LABEL_24:
      if ( EC_POINT_set_affine_coordinates_GF2m(group, point, v8->vals, ctxa->vals, v5) )
        v16 = 1;
    }
  }
err_129:
  BN_CTX_end(v5);
  if ( v15 )
    BN_CTX_free(v15);
  return v16;
}
