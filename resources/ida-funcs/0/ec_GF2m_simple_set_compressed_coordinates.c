int __usercall ec_GF2m_simple_set_compressed_coordinates@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        ec_point_st *point,
        const bignum_st *x_,
        int y_bit,
        bignum_ctx *ctx)
{
  bignum_ctx *v6; // esi
  bignum_pool_item *v8; // ebx
  bignum_pool_item *v9; // ebp
  bignum_st *v10; // eax
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
  ERR_clear_error(a1);
  v6 = ctx;
  if ( !ctx )
  {
    v15 = BN_CTX_new(a1);
    v6 = v15;
    if ( !v15 )
      return 0;
  }
  v17 = y_bit != 0;
  BN_CTX_start(a1, v6);
  v8 = BN_CTX_get(a1, v6);
  v9 = BN_CTX_get((int)v8, v6);
  ctxa = BN_CTX_get((int)v8, v6);
  r = BN_CTX_get((int)v8, v6);
  if ( r && BN_GF2m_mod_arr(v9->vals, x_, group->poly) )
  {
    if ( v9->vals[0].top )
    {
      if ( !group->meth->field_sqr(group, (bignum_st *)v8, (const bignum_st *)v9, v6)
        || !group->meth->field_div(group, (bignum_st *)v8, &group->b, (const bignum_st *)v8, v6)
        || !BN_GF2m_add(v8->vals, &group->a, v8->vals)
        || !BN_GF2m_add(v8->vals, v9->vals, v8->vals) )
      {
        goto err_131;
      }
      v12 = (const bignum_st *)v8;
      v8 = r;
      if ( !BN_GF2m_mod_solve_quad_arr(r->vals, v12, group->poly, v6) )
      {
        error = ERR_peek_last_error();
        if ( (error & 0xFF000000) == 0x3000000 && (error & 0xFFF) == 0x74 )
        {
          ERR_clear_error((int)r);
          ERR_put_error((int)r, 0x10u, 164, 110, ".\\crypto\\ec\\ec2_smpl.c", 468);
        }
        else
        {
          ERR_put_error((int)r, 0x10u, 164, 3, ".\\crypto\\ec\\ec2_smpl.c", 471);
        }
        goto err_131;
      }
      if ( r->vals[0].top <= 0 || (ra = 1, (*(_BYTE *)v8->vals[0].d & 1) == 0) )
        ra = 0;
      if ( !group->meth->field_mul(group, (bignum_st *)ctxa, (const bignum_st *)v9, (const bignum_st *)v8, v6) )
        goto err_131;
      if ( ra == v17 )
        goto LABEL_24;
      v10 = BN_GF2m_add(ctxa->vals, ctxa->vals, v9->vals);
    }
    else
    {
      v10 = (bignum_st *)BN_GF2m_mod_sqrt_arr(ctxa->vals, &group->b, group->poly, v6);
    }
    if ( v10 )
    {
LABEL_24:
      if ( EC_POINT_set_affine_coordinates_GF2m((int)v8, group, point, v9->vals, ctxa->vals, v6) )
        v16 = 1;
    }
  }
err_131:
  BN_CTX_end(v6);
  if ( v15 )
    BN_CTX_free(v15);
  return v16;
}
