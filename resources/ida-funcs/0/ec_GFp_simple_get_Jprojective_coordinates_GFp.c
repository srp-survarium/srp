bignum_ctx *__usercall ec_GFp_simple_get_Jprojective_coordinates_GFp@<eax>(
        int a1@<ebx>,
        const ec_group_st *group,
        const ec_point_st *point,
        bignum_st *x,
        bignum_st *y,
        bignum_st *z,
        bignum_ctx *ctx)
{
  bignum_ctx *v7; // ebp
  bignum_ctx *v8; // edi
  bignum_ctx *result; // eax
  int v10; // [esp+10h] [ebp-4h]

  v7 = 0;
  v10 = 0;
  if ( !group->meth->field_decode )
  {
    if ( x && !BN_copy(x, &point->X) || y && !BN_copy(y, &point->Y) || z && !BN_copy(z, &point->Z) )
      return (bignum_ctx *)v10;
LABEL_17:
    v10 = 1;
err_201:
    if ( v7 )
      BN_CTX_free(v7);
    return (bignum_ctx *)v10;
  }
  v8 = ctx;
  if ( ctx || (result = BN_CTX_new(a1), v7 = result, (v8 = result) != 0) )
  {
    if ( x && !group->meth->field_decode(group, x, &point->X, v8)
      || y && !group->meth->field_decode(group, y, &point->Y, v8)
      || z && !group->meth->field_decode(group, z, &point->Z, v8) )
    {
      goto err_201;
    }
    goto LABEL_17;
  }
  return result;
}
