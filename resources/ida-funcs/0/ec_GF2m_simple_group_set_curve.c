int __cdecl ec_GF2m_simple_group_set_curve(
        ec_group_st *group,
        const bignum_st *p,
        const bignum_st *a,
        const bignum_st *b)
{
  int *poly; // ebx
  int v5; // eax
  int v7; // kr00_4
  int i; // eax
  int v10; // kr04_4
  int j; // eax

  if ( !BN_copy(&group->field, p) )
    return 0;
  poly = group->poly;
  v5 = BN_GF2m_poly2arr(&group->field, group->poly, 6) - 1;
  if ( v5 != 5 && v5 != 3 )
  {
    ERR_put_error((int)poly, 0x10u, 195, 131, ".\\crypto\\ec\\ec2_smpl.c", 198);
    return 0;
  }
  if ( !BN_GF2m_mod_arr(&group->a, a, group->poly) )
    return 0;
  v7 = *poly + 31;
  if ( !(v7 / 32 > group->a.dmax ? bn_expand2(&group->a, v7 / 32) : &group->a) )
    return 0;
  for ( i = group->a.top; i < group->a.dmax; ++i )
    group->a.d[i] = 0;
  if ( !BN_GF2m_mod_arr(&group->b, b, group->poly) )
    return 0;
  v10 = *poly + 31;
  if ( !(v10 / 32 > group->b.dmax ? bn_expand2(&group->b, v10 / 32) : &group->b) )
    return 0;
  for ( j = group->b.top; j < group->b.dmax; ++j )
    group->b.d[j] = 0;
  return 1;
}
