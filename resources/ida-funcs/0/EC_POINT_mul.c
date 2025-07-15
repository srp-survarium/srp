int __cdecl EC_POINT_mul(
        const ec_group_st *group,
        ec_point_st *r,
        const bignum_st *g_scalar,
        bignum_st *point,
        bignum_st *p_scalar,
        bignum_ctx *ctx)
{
  unsigned int v6; // edx
  int (__cdecl *mul)(const ec_group_st *, ec_point_st *, const bignum_st *, unsigned int, const ec_point_st **, const bignum_st **, bignum_ctx *); // ecx
  const ec_point_st *points; // [esp+0h] [ebp-4h] BYREF

  points = (const ec_point_st *)point;
  point = p_scalar;
  v6 = points && p_scalar;
  mul = group->meth->mul;
  if ( mul )
    return mul(group, r, g_scalar, v6, &points, (const bignum_st **)&point, ctx);
  else
    return ec_wNAF_mul(group, r, g_scalar, v6, &points, (const bignum_st **)&point, ctx);
}
