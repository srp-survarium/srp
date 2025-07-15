int __usercall ec_GFp_simple_set_Jprojective_coordinates_GFp@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        ec_point_st *point,
        const bignum_st *x,
        const bignum_st *y,
        const bignum_st *z,
        bignum_ctx *ctx)
{
  bignum_ctx *v7; // edi
  int (__cdecl *v9)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // eax
  int (__cdecl *v10)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // eax
  bignum_st *p_Z; // ebx
  BOOL v12; // ebp
  int (__cdecl *field_encode)(const ec_group_st *, bignum_st *, const bignum_st *, bignum_ctx *); // ecx
  int (__cdecl *field_set_to_one)(const ec_group_st *, bignum_st *, bignum_ctx *); // eax
  int v15; // eax
  bignum_ctx *v16; // [esp+8h] [ebp-8h]
  int v17; // [esp+Ch] [ebp-4h]

  v7 = ctx;
  v16 = 0;
  v17 = 0;
  if ( !ctx )
  {
    v16 = BN_CTX_new(a1);
    v7 = v16;
    if ( !v16 )
      return 0;
  }
  if ( (!x
     || BN_nnmod((int)&point->X, &point->X, x, &group->field, v7)
     && ((v9 = group->meth->field_encode) == 0 || v9(group, &point->X, &point->X, v7)))
    && (!y
     || BN_nnmod((int)&point->Y, &point->Y, y, &group->field, v7)
     && ((v10 = group->meth->field_encode) == 0 || v10(group, &point->Y, &point->Y, v7))) )
  {
    if ( z )
    {
      p_Z = &point->Z;
      if ( !BN_nnmod((int)&point->Z, &point->Z, z, &group->field, v7) )
        goto err_200;
      v12 = point->Z.top == 1 && *p_Z->d == 1 && !point->Z.neg;
      field_encode = group->meth->field_encode;
      if ( field_encode )
      {
        if ( v12 && (field_set_to_one = group->meth->field_set_to_one) != 0 )
          v15 = field_set_to_one(group, p_Z, v7);
        else
          v15 = field_encode(group, p_Z, p_Z, v7);
        if ( !v15 )
          goto err_200;
      }
      point->Z_is_one = v12;
    }
    v17 = 1;
  }
err_200:
  if ( v16 )
    BN_CTX_free(v16);
  return v17;
}
