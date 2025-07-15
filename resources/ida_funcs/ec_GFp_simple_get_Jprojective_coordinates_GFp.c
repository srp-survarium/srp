bignum_ctx *__cdecl ec_GFp_simple_get_Jprojective_coordinates_GFp(
        const ec_group_st *group,
        const ec_point_st *point,
        bignum_st *x,
        bignum_st *y,
        bignum_st *z,
        bignum_ctx *ctx)
{
  bignum_ctx *v6; // ebp
  bignum_ctx *v7; // edi
  bignum_ctx *result; // eax
  int v9; // [esp+10h] [ebp-4h]

  v6 = 0;
  v9 = 0;
  if ( !group->meth->field_decode )
  {
    if ( x && !BN_copy(x, &point->X) || y && !BN_copy(y, &point->Y) || z && !BN_copy(z, &point->Z) )
      return (bignum_ctx *)v9;
LABEL_17:
    v9 = 1;
err_199:
    if ( v6 )
      BN_CTX_free(v6);
    return (bignum_ctx *)v9;
  }
  v7 = ctx;
  if ( ctx || (result = BN_CTX_new(), v6 = result, (v7 = result) != 0) )
  {
    if ( x && !group->meth->field_decode(group, x, &point->X, v7)
      || y && !group->meth->field_decode(group, y, &point->Y, v7)
      || z && !group->meth->field_decode(group, z, &point->Z, v7) )
    {
      goto err_199;
    }
    goto LABEL_17;
  }
  return result;
}
