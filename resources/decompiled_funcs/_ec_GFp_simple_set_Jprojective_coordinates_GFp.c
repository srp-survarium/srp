int __cdecl ec_GFp_simple_set_Jprojective_coordinates_GFp(
        const ec_group_st *group,
        ec_point_st *point,
        const bignum_st *x,
        const bignum_st *y,
        const bignum_st *z,
        bignum_ctx *ctx)
{
  bignum_ctx *v6; // edi
  int (__cdecl *v8)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // eax
  int (__cdecl *v9)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // eax
  bignum_st *p_Z; // ebx
  BOOL v11; // ebp
  int (__cdecl *field_encode)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // ecx
  int (__cdecl *field_set_to_one)(const ec_group_st *, bignum_st *, bignum_ctx *); // eax
  int v14; // eax
  bignum_ctx *v15; // [esp+8h] [ebp-8h]
  int v16; // [esp+Ch] [ebp-4h]

  v6 = ctx;
  v15 = 0;
  v16 = 0;
  if ( !ctx )
  {
    v15 = BN_CTX_new();
    v6 = v15;
    if ( !v15 )
      return 0;
  }
  if ( (!x
     || BN_nnmod(&point->X, x, &group->field, v6)
     && ((v8 = group->meth->field_encode) == 0 || v8(group, &point->X, &point->X, v6)))
    && (!y
     || BN_nnmod(&point->Y, y, &group->field, v6)
     && ((v9 = group->meth->field_encode) == 0 || v9(group, &point->Y, &point->Y, v6))) )
  {
    if ( z )
    {
      p_Z = &point->Z;
      if ( !BN_nnmod(&point->Z, z, &group->field, v6) )
        goto err_198;
      v11 = point->Z.top == 1 && *p_Z->d == 1 && !point->Z.neg;
      field_encode = group->meth->field_encode;
      if ( field_encode )
      {
        if ( v11 && (field_set_to_one = group->meth->field_set_to_one) != 0 )
          v14 = field_set_to_one(group, p_Z, v6);
        else
          v14 = field_encode(group, p_Z, p_Z, v6);
        if ( !v14 )
          goto err_198;
      }
      point->Z_is_one = v11;
    }
    v16 = 1;
  }
err_198:
  if ( v15 )
    BN_CTX_free(v15);
  return v16;
}
