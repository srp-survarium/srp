int __cdecl ec_GFp_simple_set_compressed_coordinates(
        const ec_group_st *group,
        ec_point_st *point,
        bignum_pool_item *x_,
        int y_bit,
        bignum_ctx *ctx)
{
  bignum_ctx *v5; // esi
  bignum_pool_item *v7; // edi
  bignum_st *p_field; // ebp
  int v9; // eax
  int v10; // eax
  int (__cdecl *field_decode)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // ecx
  int v12; // eax
  int (__cdecl *v13)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // eax
  const bignum_st *v14; // edi
  unsigned int error; // eax
  int top; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  const bignum_st *v20; // [esp-10h] [ebp-28h]
  bignum_pool_item *r; // [esp+8h] [ebp-10h]
  bignum_ctx *v22; // [esp+Ch] [ebp-Ch]
  int v23; // [esp+10h] [ebp-8h]
  bignum_pool_item *in; // [esp+14h] [ebp-4h]
  int v25; // [esp+28h] [ebp+10h]
  bignum_pool_item *ctxa; // [esp+2Ch] [ebp+14h]

  v22 = 0;
  v23 = 0;
  ERR_clear_error();
  v5 = ctx;
  if ( !ctx )
  {
    v22 = BN_CTX_new();
    v5 = v22;
    if ( !v22 )
      return 0;
  }
  v25 = y_bit != 0;
  BN_CTX_start(v5);
  ctxa = BN_CTX_get(v5);
  v7 = BN_CTX_get(v5);
  r = BN_CTX_get(v5);
  in = BN_CTX_get(v5);
  if ( in )
  {
    p_field = &group->field;
    if ( BN_nnmod(r->vals, x_->vals, &group->field, v5) )
    {
      if ( group->meth->field_decode )
      {
        if ( !BN_mod_sqr(v7->vals, x_->vals, p_field, v5) )
          goto err_201;
        v9 = BN_mod_mul(ctxa->vals, v7, x_, p_field, v5);
      }
      else
      {
        if ( !group->meth->field_sqr(group, (bignum_st *)v7, (const bignum_st *)x_, v5) )
          goto err_201;
        v9 = group->meth->field_mul(group, (bignum_st *)ctxa, (const bignum_st *)v7, (const bignum_st *)x_, v5);
      }
      if ( !v9 )
        goto err_201;
      if ( group->a_is_minus3 )
      {
        if ( !BN_mod_lshift1_quick(v7->vals, r->vals, p_field)
          || !BN_mod_add_quick(v7->vals, v7->vals, r->vals, p_field) )
        {
          goto err_201;
        }
        v10 = BN_mod_sub_quick(ctxa->vals, ctxa->vals, v7->vals, p_field);
      }
      else
      {
        field_decode = group->meth->field_decode;
        if ( field_decode )
        {
          if ( !field_decode(group, v7->vals, &group->a, v5) )
            goto err_201;
          v12 = BN_mod_mul(v7->vals, v7, r, p_field, v5);
        }
        else
        {
          v12 = group->meth->field_mul(group, (bignum_st *)v7, &group->a, (const bignum_st *)r, v5);
        }
        if ( !v12 )
          goto err_201;
        v10 = BN_mod_add_quick(ctxa->vals, ctxa->vals, v7->vals, p_field);
      }
      if ( !v10 )
        goto err_201;
      v13 = group->meth->field_decode;
      if ( v13 )
      {
        if ( !v13(group, v7->vals, &group->b, v5) )
          goto err_201;
        v20 = (const bignum_st *)v7;
        v14 = (const bignum_st *)ctxa;
        if ( !BN_mod_add_quick(ctxa->vals, ctxa->vals, v20, p_field) )
          goto err_201;
      }
      else
      {
        if ( !BN_mod_add_quick(ctxa->vals, ctxa->vals, &group->b, p_field) )
          goto err_201;
        v14 = (const bignum_st *)ctxa;
      }
      if ( BN_mod_sqrt(in->vals, v14, p_field, v5) )
      {
        top = in->vals[0].top;
        v17 = top > 0 && (*(_BYTE *)in->vals[0].d & 1) != 0;
        if ( v25 == v17 )
          goto LABEL_47;
        if ( !top )
        {
          v18 = BN_kronecker(r->vals, p_field, v5);
          if ( v18 != -2 )
          {
            if ( v18 == 1 )
              ERR_put_error(0x10u, 169, 109, ".\\crypto\\ec\\ecp_smpl.c", 740);
            else
              ERR_put_error(0x10u, 169, 110, ".\\crypto\\ec\\ecp_smpl.c", 743);
          }
          goto err_201;
        }
        if ( BN_usub(in->vals, p_field, in->vals) )
        {
LABEL_47:
          v19 = in->vals[0].top > 0 && (*(_BYTE *)in->vals[0].d & 1) != 0;
          if ( v25 == v19 )
          {
            if ( EC_POINT_set_affine_coordinates_GFp(group, point, r->vals, in->vals, v5) )
              v23 = 1;
          }
          else
          {
            ERR_put_error(0x10u, 169, 68, ".\\crypto\\ec\\ecp_smpl.c", 750);
          }
        }
      }
      else
      {
        error = ERR_peek_last_error();
        if ( (unsigned __int8 *)(error & 0xFF000000) == &vostok::memory::s_CRT_arena[39128632]
          && (error & 0xFFF) == 0x6F )
        {
          ERR_clear_error();
          ERR_put_error(0x10u, 169, 110, ".\\crypto\\ec\\ecp_smpl.c", 723);
        }
        else
        {
          ERR_put_error(0x10u, 169, 3, ".\\crypto\\ec\\ecp_smpl.c", 726);
        }
      }
    }
  }
err_201:
  BN_CTX_end(v5);
  if ( v22 )
    BN_CTX_free(v22);
  return v23;
}
