int __usercall ec_GF2m_simple_point_set_affine_coordinates@<eax>(
        const bignum_st *a1@<ebx>,
        const ec_group_st *group,
        ec_point_st *point,
        const bignum_st *x,
        const bignum_st *y)
{
  int v5; // ebp
  const bignum_st *v6; // eax

  v5 = 0;
  if ( x && (a1 = y) != 0 )
  {
    if ( BN_copy(&point->X, x) )
    {
      BN_set_negative(&point->X, 0);
      if ( BN_copy(&point->Y, y) )
      {
        BN_set_negative(&point->Y, 0);
        v6 = BN_value_one();
        if ( BN_copy(&point->Z, v6) )
        {
          BN_set_negative(&point->Z, 0);
          v5 = 1;
          point->Z_is_one = 1;
        }
      }
    }
    return v5;
  }
  else
  {
    ERR_put_error((int)a1, 0x10u, 163, 67, ".\\crypto\\ec\\ec2_smpl.c", 355);
    return 0;
  }
}
