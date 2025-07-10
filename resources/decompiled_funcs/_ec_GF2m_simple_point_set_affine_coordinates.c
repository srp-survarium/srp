int __cdecl ec_GF2m_simple_point_set_affine_coordinates(
        const ec_group_st *group,
        ec_point_st *point,
        const bignum_st *x,
        const bignum_st *y)
{
  int v4; // ebp
  const bignum_st *v5; // eax

  v4 = 0;
  if ( x && y )
  {
    if ( BN_copy(&point->X, x) )
    {
      BN_set_negative(&point->X, 0);
      if ( BN_copy(&point->Y, y) )
      {
        BN_set_negative(&point->Y, 0);
        v5 = BN_value_one();
        if ( BN_copy(&point->Z, v5) )
        {
          BN_set_negative(&point->Z, 0);
          v4 = 1;
          point->Z_is_one = 1;
        }
      }
    }
    return v4;
  }
  else
  {
    ERR_put_error(0x10u, 163, 67, ".\\crypto\\ec\\ec2_smpl.c", 355);
    return 0;
  }
}
