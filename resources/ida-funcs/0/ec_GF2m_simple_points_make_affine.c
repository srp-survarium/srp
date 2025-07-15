int __cdecl ec_GF2m_simple_points_make_affine(
        const ec_group_st *group,
        unsigned int num,
        ec_point_st **points,
        bignum_ctx *ctx)
{
  int v4; // esi

  v4 = 0;
  if ( !num )
    return 1;
  while ( group->meth->make_affine(group, points[v4], ctx) )
  {
    if ( ++v4 >= num )
      return 1;
  }
  return 0;
}
