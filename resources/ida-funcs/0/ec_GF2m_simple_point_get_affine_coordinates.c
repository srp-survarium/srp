int __cdecl ec_GF2m_simple_point_get_affine_coordinates(
        const ec_group_st *group,
        const ec_point_st *point,
        bignum_st *x,
        bignum_st *y)
{
  int v4; // ebx
  const bignum_st *v6; // eax

  v4 = 0;
  if ( EC_POINT_is_at_infinity(0, group, point) )
  {
    ERR_put_error(0, 0x10u, 162, 106, ".\\crypto\\ec\\ec2_smpl.c", 383);
    return 0;
  }
  v6 = BN_value_one();
  if ( BN_cmp(&point->Z, v6) )
  {
    ERR_put_error(0, 0x10u, 162, 66, ".\\crypto\\ec\\ec2_smpl.c", 389);
    return 0;
  }
  if ( x )
  {
    if ( !BN_copy(x, &point->X) )
      return v4;
    BN_set_negative(x, 0);
  }
  if ( !y )
    return 1;
  if ( BN_copy(y, &point->Y) )
  {
    BN_set_negative(y, 0);
    return 1;
  }
  return v4;
}
